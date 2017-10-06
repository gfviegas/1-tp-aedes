/**
 * Definições e Cabeçalhos do TAD ListaDePalavras
 * @author Gustavo Viegas
 */

#ifndef ListaDePalavras_h
#define ListaDePalavras_h

#include <stdio.h>
#include "Palavra.h"

typedef struct CelulaPalavra* ApontadorPalavra; // Ponteiro para uma célula da lista de palavras
typedef struct CelulaPalavra {
    Palavra info;
    ApontadorPalavra proximo;
} CelulaPalavra; // Célula de uma lista encadeada de palavras

typedef struct {
    ApontadorPalavra primeiro;
    ApontadorPalavra ultimo;
    int quantidadePalavras;
} ListaDePalavras;


/**
 * Configura uma nova instância de uma variável do tipo ListaDePalavras e inicializa a célula-cabeça.
 * @method criaListaDePalavras
 * @param  lista               Ponteiro do tipo ListaDePalavras que será manipulado
 */
void criaListaDePalavras(ListaDePalavras* lista);

/**
 * Insere uma palavra no final da lista linear de palavras.
 * @method insereNovaPalavraFinal
 * @param  lista                  Ponteiro do tipo ListaDePalavras que será manipulado
 * @param  palavra                Ponteiro do tipo Palavra que será inserido na lista linear
 */
void insereNovaPalavraFinal(ListaDePalavras* lista, Palavra* palavra);

/**
 * Remove uma palavra específica da lista linear de palavras.
 * @method removePalavra
 * @param  lista         Ponteiro do tipo ListaDePalavras que será manipulado
 * @param  palavra       Ponteiro do tipo Palavra que será removido da lista linear
 */
void removePalavra(ListaDePalavras* lista, Palavra* palavra);

/**
 * Remove uma palavra no final da lista linear de palavras.
 * @method removePalavraFinal
 * @param  lista              Ponteiro do tipo ListaDePalavras que será manipulado
 */
void removePalavraFinal(ListaDePalavras* lista);

/**
 * Verifica se uma palavra existe na lista linear de palavras.
 * Se existe, atribui o argumento Palavra como o ponteiro pra palavra encontrada.
 * @method verificaPalavra
 * @param  lista           Ponteiro do tipo ListaDePalavras que será manipulado
 * @param  valorPalavra    String com a palavra a ser verificada
 * @param  palavra         Ponteiro do tipo Palavra que será atribuido ao endereço da palavra encontrada, se encontrada
 * @return                 Inteiro representando a existência (1) ou não (0) da palavra na lista linear
 */
int verificaPalavra(ListaDePalavras* lista, char* valorPalavra, Palavra* palavra);

/**
 * Retorna o número de palavras em uma lista linear de palavras.
 * @method quantidadePalavras
 * @param  lista              Ponteiro do tipo ListaDePalavras que será manipulado
 * @return                    Inteiro representando a quantidade de palavras existentes na lista linear
 */
int quantidadePalavras(ListaDePalavras* lista);

/**
 * Imprime os dados de uma lista linear de palavras.
 * @method imprimeListaPalavras
 * @param  lista                Ponteiro do tipo ListaDePalavras que será manipulado
 */
void imprimeListaPalavras(ListaDePalavras* lista);

#endif /* ListaDePalavras_h */
