#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Dicionario.h"

#define BUFFERSIZE 255
#define FILENAMESIZE 200

void imprimeCabecalho () {
    printf("|| ||\n");
    printf("|| ||\t\tDicionariozator 1.0\n");
    printf("|| ||\t\tTrabalho Prático 1 de \"Algoritmos e Estruturas de Dados\"\n");
    printf("|| ||\t\tOutubro de 2017 - UFV Campus Florestal\n");
    printf("|| ||\t\tArthur Marciano, Gustavo Viegas e Heitor Passeado\n");
    printf("|| ||\n");
    printf("\nO programa irá pedir pra que você digite um código após cada operação executada. Basta digitar o código requisitado pra a operação ser executada. \n\n");
}

void imprimeLinha () {
    int i;
    for (i = 0; i < 50; i++) {
        printf("-");
    }
    printf("\n");
}

void imprimeInstrucoes () {
    printf("Os códigos e operações disponíveis são: \n\n");
    printf("Insira 0 \t->\t Interromper execução\n");
    printf("Insira 1 \t->\t Ler arquivo e preencher Dicionário\n");
    printf("Insira 2 \t->\t Imprimir todos os dados do Dicionário\n");
    printf("Insira 3 \t->\t Imprimir Dados de uma letra do Dicionário\n");
    printf("Insira 4 \t->\t Verificar se uma palavra existe no Dicionário\n");
}

void configuraDicionario (Dicionario * dicionario) {
    int linhaAtual = 1; // Inteiro que armazena a linha onde a palavra estará
    char nomeArquivo[FILENAMESIZE]; // Caminho pro arquivo
    char buffer[BUFFERSIZE]; // Buffer de uma linha (255 caracteres)
    char * palavraAtual; // Armazenará a palavra atual em cada iteração
    FILE *arquivo = NULL; // Arquivo TXT lido
    
    printf("Entre o caminho do arquivo, com extensão: ");
    scanf(" %[^\n]s", nomeArquivo);
    arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("O arquivo %s não existe. Encerrando a execução. \n", nomeArquivo);
        exit(-1);
    }
    
    criaDicionario(dicionario);
    
    while (fgets(buffer, 255, (FILE*) arquivo)) {
        palavraAtual = strtok (buffer, " \n\r\t");
        while (palavraAtual != NULL) {
            inserePalavraDicionario(dicionario, palavraAtual, linhaAtual);
            palavraAtual = strtok (NULL, " \n\r\t");
        }
        
        linhaAtual++;
    }
    
    fclose(arquivo);
}

void promptLetraDicionario (Dicionario * dicionario) {
    char letraDesejada;
    printf("Entre a letra que deseja imprimir os dados: ");
    scanf(" %c", &letraDesejada);
    imprimeLetraDicionario(dicionario, letraDesejada);
}

void promptPalavraDicionario (Dicionario * dicionario) {
    char palavraDesejada[50];
    printf("Entre a palavra que deseja verificar (max 50 caracteres): ");
    scanf(" %[^\n]s", palavraDesejada);
    
    if (verificaPalavraExisteDicionario(dicionario, palavraDesejada) == 0) {
        printf("A palavra %s não existe no dicionário. \n", palavraDesejada);
    }
}

int lerOperacao (Dicionario * dicionario) {
    int codigo, retorno = 1;
    
    imprimeLinha();
    imprimeInstrucoes();

    printf("\nInsira o código da operação que deseja executar: ");
    scanf("%d", &codigo);
    
    switch (codigo) {
        case 0:
            retorno = 0;
            break;
        case 1:
            configuraDicionario(dicionario);
            break;
        case 2:
            imprimeDicionario(dicionario);
            break;
        case 3:
             promptLetraDicionario(dicionario);
            break;
        case 4:
            promptPalavraDicionario(dicionario);
            break;
        default:
            printf("Código inválido!! \n");
            lerOperacao(dicionario);
            break;
    }
    
    return retorno;
}

int main(){
    Dicionario dicionario;
    
    imprimeCabecalho();
    
    while (lerOperacao(&dicionario) == 1) {
        printf("\n Operação executada... \n");
    }
    
    printf("\n\n Execução Interrompida! (usuário inseriu o código 0).\n");

    return 0;
}
