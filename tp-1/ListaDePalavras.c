//
//  ListaDePalavras.c
//  tp-1
//
//  Created by Viegas on 21/09/17.
//  Copyright © 2017 Ciencia da Computacao - UFV. All rights reserved.

#include "Palavra.h"
#include "ListaDePalavras.h"
#include <string.h>
#include <stdlib.h>

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
// 1 = Existe, 0 = Não Existe.
int verificaPalavra(ListaDePalavras * lista, Palavra * palavra) {
    ApontadorPalavra  i = lista->primeiro->proximo;
    int encontrado = 0;

    while (i != NULL && encontrado == 0) {
        encontrado = (strcmp(i->info.valor, palavra->valor) == 0);
        //encontrado = (i->info.valor == palavra->valor);
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
    printf("***** Imprimindo Lista de Palavras *****\n");
    while (i != NULL) {
        printf("Dados da palavra: %s... \n", i->info.valor);
        i = i->proximo;
    }
    printf("***___***\n");
}
