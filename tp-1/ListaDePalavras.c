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
    printf("\t Tempo gasto: %.3f ms. \n", tempo);
    printf("\t Núm aprox. de comparações feitas: %d. \n", comparacoes);
    printf("\t Núm aprox. de trocas feitas: %d. \n", trocas);
}

// Faz as particoes e trocas do método Quick Sort
void qsParticao(int esq, int dir, int *i, int *j, Palavra *palavras, int *comparacoes, int *trocas) {
    Palavra pivo, aux;
    *i = esq;
    *j = dir;

    pivo = palavras[(*i + *j)/2]; /* obtem o pivo x */
    do {
        while (strcmp(pivo.valor, palavras[*i].valor) > 0) {
            (*i)++;
            (*comparacoes)++;
        }
        while (strcmp(pivo.valor, palavras[*j].valor) < 0) {
            (*j)--;
            (*comparacoes)++;
        }

        if (*i <= *j) {
            aux = palavras[*i];
            palavras[*i] = palavras[*j];
            palavras[*j] = aux;

            (*i)++; (*j)--;
            (*comparacoes)++;
            (*trocas)++;
        }
    } while (*i <= *j);
}

// Manipula os valores de esquerda e direita e particiona o vetor até ser ordenado pelo método Quick Sort
void qsOrdena(int esq, int dir, Palavra *palavras, int *comparacoes, int *trocas) {
    int i, j;
    qsParticao(esq, dir, &i, &j, palavras, comparacoes, trocas);
    if (esq < j) qsOrdena(esq, j, palavras, comparacoes, trocas);
    if (i < dir) qsOrdena(i, dir, palavras, comparacoes, trocas);
}

// Imprime os dados de uma lista de palavras ordenados pelo método Quick Sort
void quickSort(ListaDePalavras lista) {
    clock_t ticks[2];
    double tempo;
    int n = lista.quantidade;
    int comparacoes = 0, trocas = 0;

    ticks[0] = clock();
    qsOrdena(0, n - 1, lista.info, &comparacoes, &trocas);

    ticks[1] = clock();
    tempo = (ticks[1] - ticks[0]) * 1000.0 / CLOCKS_PER_SEC;

    printf("\n**Lista ordenada pelo método de Quick Sort**\n");

    imprimeListaPalavras(&lista);
    printf("\t Tempo gasto: %.3f ms. \n", tempo);
    printf("\t Núm aprox. de comparações feitas: %d. \n", comparacoes);
    printf("\t Núm aprox. de trocas feitas: %d. \n", trocas);
}

// Imprime os dados de uma lista de palavras ordenados pelo método Bubble Sort
void bubbleSort(ListaDePalavras lista){
    clock_t ticks[2];
    int i,j,comparacoes = 0, trocas = 0;
    double tempo;
    Palavra troca;
    
    ticks[0] = clock();
    for (i = 0; i < lista.quantidade - 1; i++){
        for (j= i + 1; j < lista.quantidade; j++) {
            comparacoes++;
            if (strcmp(lista.info[i].valor,lista.info[j].valor) > 0) {
                troca = lista.info[j];
                lista.info[j] = lista.info[i];
                lista.info[i] = troca;
                trocas++;
            }
        }
    }
    
    ticks[1] = clock();
    tempo = (ticks[1] - ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    
    printf("\n**Lista ordenada pelo método Bubble Sort**\n");
    
    imprimeListaPalavras(&lista);
    printf("\t Tempo gasto: %.3f ms. \n", tempo);
    printf("\t Núm aprox. de comparações feitas: %d. \n", comparacoes);
    printf("\t Núm aprox. de trocas feitas: %d. \n", trocas);

}

// Imprime os dados de uma lista de palavras ordenados pelo método Shell Sort
void shellSort(ListaDePalavras lista){
    clock_t ticks[2];
    int h = 1, i, j, trocas = 0, comparacoes = 0;
    double tempo;
    Palavra troca;
    ticks[0] = clock();
    
    do {
        h = h * 3 + 1;
    } while (h < lista.quantidade);

    do {
        h = h / 3;
        for (i = h; i < lista.quantidade; i++) {
            troca = lista.info[i];
            j = i;
            while (strcmp(lista.info[j - h].valor,troca.valor) > 0) {
                lista.info[j] = lista.info[j - h];
                j -= h;
                comparacoes++;
                if (j < h)
                    break;
            }
            lista.info[j] = troca;
            trocas++;
        }
    } while(h != 1);


    ticks[1] = clock();
    tempo = (ticks[1] - ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("\n**Lista ordenada pelo método Shell Sort**\n");
    
    imprimeListaPalavras(&lista);
    printf("\t Tempo gasto: %.30f ms. \n", tempo);
    printf("\t Núm aprox. de comparações feitas: %d. \n", comparacoes);
    printf("\t Núm aprox. de trocas feitas: %d. \n", trocas);

}

// Imprime os dados de uma lista de palavras ordenados pelo método Insertion Sort
void insertionSort(ListaDePalavras lista) {
    clock_t ticks[2];
    double tempo;
    int i,j,trocas = 0,comparacoes = 0;
    Palavra troca;
    ticks[0] = clock();
    
    for (i = 1; i < lista.quantidade; i++) {
        troca = lista.info[i];
        j = i - 1;
        while((j>=0) && (strcmp(lista.info[j].valor,troca.valor) > 0)){
            lista.info[j + 1] = lista.info[j];
            trocas++;
            j--;
            comparacoes++;
        }
        lista.info[j+1] = troca;
        trocas++;
    }
    
    ticks[1] = clock();
    tempo = (ticks[1] - ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    
    printf("\n**Lista ordenada pelo método Insertion sort**\n");
    
    imprimeListaPalavras(&lista);
    printf("\t Tempo gasto: %.30f ms. \n", tempo);
    printf("\t Núm aprox. de comparações feitas: %d. \n", comparacoes);
    printf("\t Núm aprox. de trocas feitas: %d. \n", trocas);
}

// Imprime os dados de uma lista de palavras ordenados pelo método Heap Sort
void heapSort(ListaDePalavras lista) {
}
