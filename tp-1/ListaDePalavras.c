/**
 * Métodos do TAD ListaDePalavras
 * @author Gustavo Viegas
 */

#include "Palavra.h"
#include "ListaDePalavras.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Cria uma lista de palavras.
void criaListaDePalavras(ListaDePalavras * lista) {
    lista->quantidade = 0;
}

int listaVazia(ListaDePalavras * lista) {
    return (lista->quantidade == 0);
}

// Insere uma palavra no final da lista linear de palavras.
void insereNovaPalavraFinal(ListaDePalavras * lista, Palavra * palavra) {
    lista->info[lista->quantidade] = *palavra;
    lista->quantidade++;
}

// Remove uma palavra no final da lista linear de palavras.
void removePalavraFinal(ListaDePalavras * lista) {
    if (!listaVazia(lista))
        lista->quantidade--;
}

// Remove uma palavra específica da lista linear de palavras.
void removePalavra(ListaDePalavras * lista, Palavra * palavra) {
    int i, j;

    for (i = 0; i < lista->quantidade; i++) {
        if (strcmp(lista->info[i].valor, palavra->valor) == 0) {
            for(j = i+1; j < lista->quantidade; j++){
                lista->info[j-1] = lista->info[j];
            }
            break;
        }
    }
    
    lista->quantidade--;
}


// Verifica se uma palavra existe na lista linear de palavras.
int verificaPalavra(ListaDePalavras * lista, char * valorPalavra, Palavra * palavra) {
    int i, encontrado = 0;
    for (i = 0; i < lista->quantidade; i++) {
        encontrado = (strcmp(lista->info[i].valor, valorPalavra) == 0);

        if (encontrado == 1) {
            *palavra = lista->info[i];
            break;
        }
    }

    return encontrado;
}

// Retorna o número de palavras em uma lista linear de palavras.
int quantidadePalavras(ListaDePalavras * lista) {
    return lista->quantidade;
}

// Imprime os dados de uma lista linear de palavras.
void imprimeListaPalavras(ListaDePalavras * lista) {
    int i;
    if (listaVazia(lista)) {
        printf("Nenhuma palavra!\n");
    } else {
        for(i = 0; i < lista->quantidade; i++){
            imprimePalavra(&lista->info[i]);
        }
    }
}

// Imprime os dados de uma lista de palavras ordenados pelo método Selection Sort
void selectionSort(ListaDePalavras lista) {
    clock_t ticks[2];
    double tempo;
    int i, j, min;
    int n = lista.quantidade;
    int comparacoes = 0, trocas = 0;
    Palavra aux;

    ticks[0] = clock();
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            comparacoes++;
            if (strcmp(lista.info[j].valor, lista.info[min].valor) < 0) min = j;
        }
        
        aux = lista.info[min];
        lista.info[min] = lista.info[i];
        lista.info[i] = aux;
        trocas++;
    }
    
    ticks[1] = clock();
    tempo = (ticks[1] - ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    
    printf("\n**Lista ordenada pelo método de Selection Sort**\n");

    imprimeListaPalavras(&lista);
    printf("\t Tempo gasto: %g ms. \n", tempo);
    printf("\t Comparações feitas: %d. \n", comparacoes);
    printf("\t Trocas feitas: %d. \n", trocas);
}
