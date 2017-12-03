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
