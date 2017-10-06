/**
 * Métodos do TAD NumeroLinha
 * @author Arthur Marciano
 */

#include <stdio.h>
#include "NumeroLinha.h"
#include <stdlib.h>

// Configura uma nova instância de uma variável do tipo ListaLinhas e inicializa a célula-cabeça.
void criaListaNumeroLinhas(ListaLinhas *lista) {
    lista->primeiro = (ApontadorCelulaLinhas) malloc(sizeof(CelulaLinhas));
    lista->ultimo = lista->primeiro;
    lista->primeiro->proximo = NULL;
    lista->quantidadeItens = 0;
}

// Insere uma nova linha à lista linear, se não existir.
void insereNovoNumeroLinha(ListaLinhas *lista, int numero) {
    int encontrado = verificaNumeroLinha(lista, numero);

    if (encontrado == 0) {
        lista->ultimo->proximo = (ApontadorCelulaLinhas) malloc(sizeof(CelulaLinhas));
        lista->ultimo = lista->ultimo->proximo;
        lista->ultimo->numeroLinha = numero;
        lista->ultimo->proximo = NULL;
        lista->quantidadeItens++;
    }
}

// Remove uma linha do fim da lista linear
void retiraNumeroLinha(ListaLinhas *lista) {
    CelulaLinhas *ultimo = lista->primeiro->proximo;
    CelulaLinhas *penultimo = NULL;
    while(ultimo->proximo != NULL) {
        penultimo = ultimo;
        ultimo = ultimo->proximo;
    }
    free(ultimo);
    penultimo->proximo = NULL;
    lista->ultimo = penultimo;
    lista->quantidadeItens--;
}

// Verifica se uma linha existe na lista linear
int verificaNumeroLinha(ListaLinhas *lista, int numero) {
    CelulaLinhas *ultimo = lista->primeiro->proximo;
    int existe = 0;
    while(ultimo != NULL && existe == 0) {
        if (ultimo->numeroLinha == numero) {
            existe = 1;
        }
        ultimo = ultimo->proximo;
    }
    return (existe);
}

// Retorna a quantdade de linhas na lista linear
int quantidadeLinhas(ListaLinhas *lista) {
    return (lista->quantidadeItens);
}

// Imprime os dados de uma lista linear de linhas.
void imprimeLinhas(ListaLinhas *lista) {
    ApontadorCelulaLinhas ultimo = lista->primeiro->proximo;
    printf("Linhas: \n");
    while(ultimo != NULL) {
        printf("\t -> %d\n", ultimo->numeroLinha);
        ultimo = ultimo->proximo;
    }
    printf("\n");
}
