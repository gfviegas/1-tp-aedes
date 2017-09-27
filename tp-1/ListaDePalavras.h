//
//  ListaDePalavras.h
//  tp-1
//
//  Created by Viegas on 21/09/17.
//  Copyright © 2017 Ciencia da Computacao - UFV. All rights reserved.
//

/*
 Este TAD representa uma lista linear de elementos do tipo Palavra. Cada item d lista deve ser
 do tipo Palavra. Além da lista encadeada com itens do tipo Palavra, esse TAD deve conter um
 campo que contabiliza o número de palavras da lista. As operações disponíveis devem ser:
 - Cria nova Lista de Palavras
 - Insere nova Palavra (no final)
 - Remove Palavra (dada a palavra)
 - Remove Palavra (do final)
 - Verifica Palavra (dada a palavra, verifica se já existe na lista)
 - Retorna número de palavras
 - Imprime
 */

#ifndef ListaDePalavras_h
#define ListaDePalavras_h

#include <stdio.h>
#include "Palavra.h"

typedef struct Celula* ApontadorPalavra;
typedef struct Celula {
    Palavra info;
    ApontadorPalavra proximo;
} CelulaPalavra;

typedef struct {
    ApontadorPalavra primeiro;
    ApontadorPalavra ultimo;
    int numeroPalavras;
} ListaDePalavras;

// Cria uma lista de palavras.
void criaListaDePalavras(ListaDePalavras * lista);

// Insere uma palavra no final da lista linear de palavras.
void insereNovaPalavraFinal(ListaDePalavras * lista, Palavra * palavra);

// Remove uma palavra específica da lista linear de palavras.
void removePalavra(ListaDePalavras * lista, Palavra * palavra);

// Remove uma palavra no final da lista linear de palavras.
void removePalavraFinal(ListaDePalavras * lista);

// Verifica se uma palavra existe na lista linear de palavras.
// 1 = Existe, 0 = Não Existe.
int verificaPalavra(ListaDePalavras * lista, Palavra * palavra);

// Retorna o número de palavras em uma lista linear de palavras.
int numeroPalavras(ListaDePalavras * lista);

// Imprime os dados de uma lista linear de palavras.
void imprimeListaPalavras(ListaDePalavras * lista);


#endif /* ListaDePalavras_h */
