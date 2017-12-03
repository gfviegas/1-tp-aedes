#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Dicionario.h"

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
    printf("Insira 6 \t->\t Insere palavra no dicionario\n");
    printf("\t **NOVOS MÉTODOS:**\n");
    printf("Insira 7 \t->\t Ordena uma lista de palavras de uma letra com um algoritmo desejado\n");
    printf("Insira 8 \t->\t Ordena todo o dicionário com um algoritmo desejado");
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
        case 7:
            promptOrdenarLetraAlfabeto(dicionario);
            break;
        case 8:
            promptOrdenarDicionario(dicionario);
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
