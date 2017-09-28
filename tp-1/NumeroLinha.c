#include <stdio.h>
#include "NumeroLinha.h"
#include <stdlib.h>

void CriaListaNLinhas(ListaLinhas *lista){
    lista->primeiro = (ApontadorCelulaLinhas) malloc(sizeof(CelulaLinhas));
    lista->ultimo = lista->primeiro;
    lista->primeiro->proximo = NULL;
    lista->quantidadeItens = 0;

printf("Criou a lista de numeros linha\n");
};

void InsereNovoNumeroLinha(ListaLinhas *lista, int numero){
    CelulaLinhas *i;
    int encontrado = 0;
    i = lista->primeiro->proximo;
    while(i != NULL && encontrado == 0){
        encontrado = (i->numeroLinha == numero);
        i = i->proximo;
    }
    if(encontrado == 0){
        lista->ultimo->proximo = (ApontadorCelulaLinhas) malloc(sizeof(CelulaLinhas));
        lista->ultimo = lista->ultimo->proximo;
        lista->ultimo->numeroLinha = numero;
        lista->ultimo->proximo = NULL;
        lista->quantidadeItens++;
    }
};

void RetiraNumeroLinha(ListaLinhas *lista){
    CelulaLinhas *ultimo = lista->primeiro->proximo;
    CelulaLinhas *penultimo = NULL;
    while(ultimo->proximo != NULL){
        penultimo = ultimo;
        ultimo = ultimo->proximo;
    }
    free(ultimo);
    penultimo->proximo = NULL;
    lista->ultimo = penultimo;
    lista->quantidadeItens--;

};

int VerificaNLinha(ListaLinhas *lista, int numero){
    CelulaLinhas *ultimo = lista->primeiro->proximo;
    int Existe = 0;
    while(ultimo != NULL && Existe == 0){
        if(ultimo->numeroLinha == numero){
            printf("lista -> ultimo -> linhas = %d\nnumero = %d",ultimo->numeroLinha, numero);
            Existe = 1;
        }
        ultimo = ultimo->proximo;
    }
    return(Existe);
};

int RetornaQntdLinhas(ListaLinhas *lista){
    return(lista->quantidadeItens);
};

void ImprimeLinhas(ListaLinhas *lista){
   ApontadorCelulaLinhas ultimo = lista->primeiro->proximo;
   while(ultimo != NULL){
        printf("%d\n", ultimo->numeroLinha);
        ultimo = ultimo->proximo;
   }
};
