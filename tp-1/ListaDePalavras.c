//
//  ListaDePalavras.c
//  tp-1
//
//  Created by Viegas on 21/09/17.
//  Copyright © 2017 Ciencia da Computacao - UFV. All rights reserved.

#include "Palavra.h"
#include "ListaDePalavras.h"
#include <string.h>

// Cria uma lista de palavras.
void criaListaDePalavras(ListaDePalavras * lista) {
    lista->primeiro = (ApontadorPalavra) malloc(sizeof(CelulaPalavra));
    lista->ultimo = lista->primeiro;
    lista->primeiro->proximo = NULL;
    lista->numeroPalavras = 0;
}


// Insere uma palavra no final da lista linear de palavras.
void insereNovaPalavraFinal(ListaDePalavras * lista, Palavra * palavra) {
    lista->ultimo->proximo = (ApontadorPalavra) malloc(sizeof(CelulaPalavra));
    lista->ultimo = lista->ultimo->proximo;

    lista->ultimo->info = *palavra;
    lista->ultimo->proximo = NULL;
    lista->numeroPalavras++;
}

// Remove uma palavra no final da lista linear de palavras.
void removePalavraFinal(ListaDePalavras * lista) {
    CelulaPalavra *ultimo = lista->primeiro->proximo;
    CelulaPalavra *penultimo = NULL;

    while (ultimo->proximo != NULL) {
        penultimo = ultimo;
        ultimo = ultimo->proximo;
    }
    free(ultimo);
    penultimo->proximo = NULL;
    lista->ultimo = penultimo;
    lista->numeroPalavras--;
}

// Remove uma palavra específica da lista linear de palavras.
void removePalavra(ListaDePalavras * lista, Palavra * palavra) {
    CelulaPalavra *ultimo = lista->primeiro->proximo;
    CelulaPalavra *penultimo = NULL;

    while (ultimo->proximo != NULL && strcmp(ultimo->info.texto, palavra->texto) != 0) {
        penultimo = ultimo;
        ultimo = ultimo->proximo;
    }

    if (ultimo->proximo == NULL) {
        lista->ultimo = penultimo;
    }

    penultimo->proximo = ultimo->proximo;
    free(ultimo);
    lista->numeroPalavras--;
}


// Verifica se uma palavra existe na lista linear de palavras.
// 1 = Existe, 0 = Não Existe.
int verificaPalavra(ListaDePalavras * lista, Palavra * palavra) {
    CelulaPalavra * i = lista->primeiro->proximo;
    int encontrado = 0;

    while (i != NULL && encontrado == 0) {
        encontrado = (strcmp(i->info.texto, palavra->texto) == 0);
        //encontrado = (i->info.texto == palavra->texto);
        i = i->proximo;
    }

    return encontrado;
}

// Retorna o número de palavras em uma lista linear de palavras.
int numeroPalavras(ListaDePalavras * lista) {
    return lista->numeroPalavras;
}

// Imprime os dados de uma lista linear de palavras.
void imprimeListaPalavras(ListaDePalavras * lista) {
    CelulaPalavra * i = lista->primeiro->proximo;
    printf("***** Imprimindo Lista de Palavras *****\n");
    while (i != NULL) {
        printf("Dados da palavra: %s... \n", i->info.texto);
        i = i->proximo;
    }
    printf("***___***\n");
}
