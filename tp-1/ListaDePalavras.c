/**
 * Métodos do TAD ListaDePalavras
 * @author Gustavo Viegas
 */

#include "Palavra.h"
#include "ListaDePalavras.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// Cria uma lista de palavras.
void criaListaDePalavras(ListaDePalavras * lista) {
    lista->primeiro = (ApontadorPalavra) malloc(sizeof(CelulaPalavra));
    lista->ultimo = lista->primeiro;
    lista->primeiro->proximo = NULL;
    lista->quantidadePalavras = 0;
}


// Insere uma palavra no final da lista linear de palavras.
void insereNovaPalavraFinal(ListaDePalavras * lista, Palavra * palavra) {
    lista->ultimo->proximo = (ApontadorPalavra) malloc(sizeof(CelulaPalavra));
    lista->ultimo = lista->ultimo->proximo;

    lista->ultimo->info = *palavra;
    lista->ultimo->proximo = NULL;
    lista->quantidadePalavras++;
}

// Remove uma palavra no final da lista linear de palavras.
void removePalavraFinal(ListaDePalavras * lista) {
    ApontadorPalavra ultimo = lista->primeiro->proximo;
    ApontadorPalavra penultimo = NULL;

    while (ultimo->proximo != NULL) {
        penultimo = ultimo;
        ultimo = ultimo->proximo;
    }
    free(ultimo);
    penultimo->proximo = NULL;
    lista->ultimo = penultimo;
    lista->quantidadePalavras--;
}

// Remove uma palavra específica da lista linear de palavras.
void removePalavra(ListaDePalavras * lista, Palavra * palavra) {
    ApontadorPalavra ultimo = lista->primeiro->proximo;
    ApontadorPalavra penultimo = NULL;

    while (ultimo->proximo != NULL && strcmp(ultimo->info.valor, palavra->valor) != 0) {
        penultimo = ultimo;
        ultimo = ultimo->proximo;
    }

    if (ultimo->proximo == NULL) {
        lista->ultimo = penultimo;
    }

    penultimo->proximo = ultimo->proximo;
    free(ultimo);
    lista->quantidadePalavras--;
}


// Verifica se uma palavra existe na lista linear de palavras.
int verificaPalavra(ListaDePalavras * lista, char * valorPalavra, Palavra * palavra) {
    ApontadorPalavra  i = lista->primeiro->proximo;
    int encontrado = 0;

    while (i != NULL) {
        encontrado = (strcmp(i->info.valor, valorPalavra) == 0);
        if (encontrado == 1) {
            *palavra = i->info; // Atribui o ponteiro passado por parâmetro a palavra encontrada.
            break;
        }

        i = i->proximo;
    }

    return encontrado;
}

// Retorna o número de palavras em uma lista linear de palavras.
int quantidadePalavras(ListaDePalavras * lista) {
    return lista->quantidadePalavras;
}

// Imprime os dados de uma lista linear de palavras.
void imprimeListaPalavras(ListaDePalavras * lista) {
    ApontadorPalavra  i = lista->primeiro->proximo;
    while (i != NULL) {
        imprimePalavra(&i->info);
        i = i->proximo;
    }
}
