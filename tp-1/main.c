#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Dicionario.h"

#define BUFFERSIZE 255
#define FILENAMESIZE 200

/**
 * Imprime um cabeçalho com instruções e descrição do programa
 * @method imprimeCabecalho
 */
void imprimeCabecalho () {
    printf("|| ||\n");
    printf("|| ||\t\tDicionariozator 1.0\n");
    printf("|| ||\t\tTrabalho Prático 1 de \"Algoritmos e Estruturas de Dados\"\n");
    printf("|| ||\t\tOutubro de 2017 - UFV Campus Florestal\n");
    printf("|| ||\t\tArthur Marciano, Gustavo Viegas e Heitor Passeado\n");
    printf("|| ||\n");
    printf("\nO programa irá pedir pra que você digite um código após cada operação executada. Basta digitar o código requisitado pra a operação ser executada. \n\n");
}

/**
 * Imprime uma linha para dividir o conteúdo no buffer
 * @method imprimeLinha
 */
void imprimeLinha () {
    int i;
    printf("\n");
    for (i = 0; i < 50; i++) {
        printf("-");
    }
    printf("\n\n");
}

/**
 * Imprime instruções de códigos a serem inseridos para o programa executar
 * @method imprimeInstrucoes
 */
void imprimeInstrucoes () {
    printf("Os códigos e operações disponíveis são: \n\n");
    printf("Insira 0 \t->\t Interromper execução\n");
    printf("Insira 1 \t->\t Ler arquivo e preencher Dicionário\n");
    printf("Insira 2 \t->\t Imprimir todos os dados do Dicionário\n");
    printf("Insira 3 \t->\t Imprimir Dados de uma letra do Dicionário\n");
    printf("Insira 4 \t->\t Verificar se uma palavra existe no Dicionário\n");
    printf("Insira 5 \t->\t Remove palavra do dicionario\n");
    printf("Insira 6 \t->\t Insere palavra no dicionario");
}

/**
 * Lê um arquivo a partir do caminho inserido pelo usuário e insere as palavras encontradas no dicionario já incializado
 * @method configuraDicionario
 * @param  dicionario          Ponteiro do tipo Dicionario que será manipulado
 * @return                     Inteiro representando se o arquivo existe e foi bem sucedido a configuração (1) ou não (0)
 */
int configuraDicionario (Dicionario * dicionario) {
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
        return 0;
    }

    while (fgets(buffer, BUFFERSIZE, (FILE*) arquivo)) {
        palavraAtual = strtok (buffer, " \n\r\t");
        while (palavraAtual != NULL) {
            inserePalavraDicionario(dicionario, palavraAtual, linhaAtual);
            palavraAtual = strtok (NULL, " \n\r\t");
        }
        linhaAtual++;
    }

    fclose(arquivo);
    return 1;
}

/**
 * Lê uma letra para se imprimir as palavras do dicionário inicializados por essa letra
 * @method promptLetraDicionario
 * @param  dicionario          Ponteiro do tipo Dicionario que será manipulado
 */
void promptLetraDicionario (Dicionario * dicionario) {
    char letraDesejada;
    printf("Entre a letra que deseja imprimir os dados: ");
    scanf(" %c", &letraDesejada);
    imprimeLetraDicionario(dicionario, letraDesejada);
}

/**
 * Lê uma palavra para se verificar se ela existe no dicionário
 * @method promptPalavraDicionario
 * @param  dicionario          Ponteiro do tipo Dicionario que será manipulado
 */
void promptPalavraDicionario (Dicionario * dicionario) {
    char palavraDesejada[50];
    printf("Entre a palavra que deseja verificar (max 50 caracteres): ");
    scanf(" %[^\n]s", palavraDesejada);

    if (verificaPalavraExisteDicionario(dicionario, palavraDesejada) == 0) {
        printf("A palavra %s não existe no dicionário. \n", palavraDesejada);
    }
}

/**
 * Lê uma palavra e uma linha, e as insere no dicionário
 * @method promptInserePalavra
 * @param  dicionario          Ponteiro do tipo Dicionario que será manipulado
 */
void promptInserePalavra(Dicionario * dicionario) {
    char palavraDesejada[50];
    int linha;
    printf("Entre a palavra a ser inserida: \n");
    scanf(" %[^\n]s", palavraDesejada);
    printf("Entre com a linha a ser inserida: \n");
    scanf(" %d", &linha);
    inserePalavraDicionario(dicionario, palavraDesejada, linha);

}

/**
 * Lê uma palavra e a remove do dicionário, se existir
 * @method promptRemovePalavra
 * @param  dicionario          Ponteiro do tipo Dicionario que será manipulado
 */
void promptRemovePalavra(Dicionario *dicionario) {
    char palavraDesejada[50];
    printf("Entre a palavra que deseja remover (max 50 caracteres): ");
    scanf(" %[^\n]s", palavraDesejada);
    removePalavraDicionario(dicionario, palavraDesejada);
}

/**
 * Lê um código e executa a ação a ela vinculada
 * @method lerOperacao
 * @param  dicionario          Ponteiro do tipo Dicionario que será manipulado
 * @return                     Inteiro representando se o programa deve continuar executando (1) ou não (0)
 */
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
        case 5:
            promptRemovePalavra(dicionario);
            break;
        case 6:
            promptInserePalavra(dicionario);
            break;
        default:
            printf("Código inválido!! \n");
            lerOperacao(dicionario);
            break;
    }

    return retorno;
}

/**
 * Função principal que manipula todo o programa
 */
int main () {
    Dicionario dicionario; // Inicializa o dicionario
    criaDicionario(&dicionario);

    imprimeCabecalho(); // Imprime cabeçalho ao executar o script.

    while (lerOperacao(&dicionario) == 1) {
        printf("\n\n Operação executada! \n\n");
    }

    printf("\n\n Execução Interrompida! (usuário inseriu o código 0).\n");

    return 0;
}
