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
    lista->primeiro = 0;
    lista->ultimo = lista->primeiro;
}


// Insere uma palavra no final da lista linear de palavras.
void insereNovaPalavraFinal(ListaDePalavras * lista, Palavra * palavra) {
    lista->ultimo++;
    lista->info[lista->ultimo] = *palavra;
}

// Remove uma palavra no final da lista linear de palavras.
void removePalavraFinal(ListaDePalavras * lista) {
    if(quantidadePalavras(lista) != 0)
        lista->ultimo--;
}

// Remove uma palavra específica da lista linear de palavras.
void removePalavra(ListaDePalavras * lista, Palavra * palavra) {
    int i,j;
    for(i=lista->primeiro;i<=lista->ultimo;i++){
        if(strcmp(lista->info[i].valor,palavra->valor) == 0){
           for(j= i+1; j<=lista->ultimo;j++){
                lista->info[j-1] = lista->info[j];
           }
        lista->ultimo--;
        }
    }
}


// Verifica se uma palavra existe na lista linear de palavras.
int verificaPalavra(ListaDePalavras * lista, char * valorPalavra, Palavra * palavra) {
    int i,cond = 0;
    for(i= lista->primeiro;i<=lista->ultimo;i++){
        if(strcmp(lista->info[i].valor,*palavra->valor) == 0)
            cond = 1;
    }
    return cond;
}

// Retorna o número de palavras em uma lista linear de palavras.
int quantidadePalavras(ListaDePalavras * lista) {
    return lista->ultimo;
}

// Imprime os dados de uma lista linear de palavras.
void imprimeListaPalavras(ListaDePalavras * lista) {
    int i;
    for(i=lista->primeiro;i<=lista->ultimo;i++){
        imprimePalavra(&lista->info[i]);
    }
}
