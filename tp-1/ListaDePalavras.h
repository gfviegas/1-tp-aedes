/**
 * Definições e Cabeçalhos do TAD ListaDePalavras
 * @author Gustavo Viegas
 */

#ifndef ListaDePalavras_h
#define ListaDePalavras_h
#define MAXTAM 500

#include <stdio.h>
#include "Palavra.h"

typedef struct {
    Palavra info[MAXTAM];
    int quantidade;
} ListaDePalavras; // Célula de uma lista encadeada de palavras


/**
 * Configura uma nova instância de uma variável do tipo ListaDePalavras e inicializa a célula-cabeça.
 * @function criaListaDePalavras
 * @param  lista               Ponteiro do tipo ListaDePalavras que será manipulado
 */
void criaListaDePalavras(ListaDePalavras* lista);

/**
 * Insere uma palavra no final da lista linear de palavras.
 * @function insereNovaPalavraFinal
 * @param  lista                  Ponteiro do tipo ListaDePalavras que será manipulado
 * @param  palavra                Ponteiro do tipo Palavra que será inserido na lista linear
 */
void insereNovaPalavraFinal(ListaDePalavras* lista, Palavra* palavra);

/**
 * Remove uma palavra específica da lista linear de palavras.
 * @function removePalavra
 * @param  lista         Ponteiro do tipo ListaDePalavras que será manipulado
 * @param  palavra       Ponteiro do tipo Palavra que será removido da lista linear
 */
void removePalavra(ListaDePalavras* lista, Palavra* palavra);

/**
 * Remove uma palavra no final da lista linear de palavras.
 * @function removePalavraFinal
 * @param  lista              Ponteiro do tipo ListaDePalavras que será manipulado
 */
void removePalavraFinal(ListaDePalavras* lista);

/**
 * Verifica se uma palavra existe na lista linear de palavras.
 * Se existe, atribui o argumento Palavra como o ponteiro pra palavra encontrada.
 * @function verificaPalavra
 * @param  lista           Ponteiro do tipo ListaDePalavras que será manipulado
 * @param  valorPalavra    String com a palavra a ser verificada
 * @param  palavra         Ponteiro do tipo Palavra que será atribuido ao endereço da palavra encontrada, se encontrada
 * @return                 Inteiro representando a existência (1) ou não (0) da palavra na lista linear
 */
int verificaPalavra(ListaDePalavras* lista, char* valorPalavra, Palavra* palavra);

/**
 * Retorna o número de palavras em uma lista linear de palavras.
 * @function quantidadePalavras
 * @param  lista              Ponteiro do tipo ListaDePalavras que será manipulado
 * @return                    Inteiro representando a quantidade de palavras existentes na lista linear
 */
int quantidadePalavras(ListaDePalavras* lista);

/**
 * Imprime os dados de uma lista linear de palavras.
 * @function imprimeListaPalavras
 * @param  lista                Ponteiro do tipo ListaDePalavras que será manipulado
 */
void imprimeListaPalavras(ListaDePalavras* lista);

/**
 * Imprime os dados de uma lista de palavras ordenados pelo método Selection Sort
 * @function selectionSort
 * @param  lista                A copia de uma lista do tipo ListaDePalavras que será ordenado
 */
void selectionSort(ListaDePalavras lista);


/**
 * Imprime os dados de uma lista de palavras ordenados pelo método Quick Sort
 * @function quickSort
 * @param  lista                A copia de uma lista do tipo ListaDePalavras que será ordenado
 */
void quickSort(ListaDePalavras lista);

/**
 * Faz as particoes e trocas do método Quick Sort
 * @function qsParticao
 * @param  esq          Um inteiro representando o indice da esquerda
 * @param  dir          Um inteiro representando o indice da direita
 * @param  i            Um ponteiro de inteiro representando onde está a particao pela direita
 * @param  j            Um ponteiro de inteiro representando onde está a particao pela esquerda
 * @param  palavras     O vetor de palavras a ser ordenado
 * @param  comparacoes  Um ponteiro de inteiro representando a quantidade de comparacoes feita
 * @param  trocas       Um ponteiro de inteiro representando a quantidade de trocas feita
 */
void qsParticao(int esq, int dir, int *i, int *j, Palavra *palavras, int *comparacoes, int *trocas);

/**
 * Manipula os valores de esquerda e direita e particiona o vetor até ser ordenado pelo método Quick Sort
 * @function qsOrdena
 * @param  esq          Um inteiro representando o indice da esquerda
 * @param  dir          Um inteiro representando o indice da direita
 * @param  palavras     O vetor de palavras a ser ordenado
 * @param  comparacoes  Um ponteiro de inteiro representando a quantidade de comparacoes feita
 * @param  trocas       Um ponteiro de inteiro representando a quantidade de trocas feita
 */
void qsOrdena(int esq, int dir, Palavra *palavras, int *comparacoes, int *trocas);

/**
 * Imprime os dados de uma lista de palavras ordenados pelo método Bubble Sort
 * @function bubbleSort
 * @param  lista                A copia de uma lista do tipo ListaDePalavras que será ordenado
 */
void bubbleSort(ListaDePalavras lista);

/**
 * Imprime os dados de uma lista de palavras ordenados pelo método Shell Sort
 * @function shellSort
 * @param  lista                A copia de uma lista do tipo ListaDePalavras que será ordenado
 */
void shellSort(ListaDePalavras lista);

/**
 * Imprime os dados de uma lista de palavras ordenados pelo método Insertion Sort
 * @function insertionSort
 * @param  lista                A copia de uma lista do tipo ListaDePalavras que será ordenado
 */
void insertionSort(ListaDePalavras lista);

/**
 * Imprime os dados de uma lista de palavras ordenados pelo método Heap Sort
 * @function heapSort
 * @param  lista                A copia de uma lista do tipo ListaDePalavras que será ordenado
 */
void heapSort(ListaDePalavras lista);


void hsRefaz(int esq, int dir, Palavra *palavras, int *trocas, int *comparacoes);
void hsConstroi(Palavra *palavras, int n, int *trocas, int*comparacoes);
#endif /* ListaDePalavras_h */
