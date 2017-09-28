#include <stdio.h>
#include "NumeroLinha.h"
#include <stdlib.h>

void CriaListaNLinhas(Tlista *lista){
    lista->pPrimeiro = (Apontador) malloc(sizeof(Tcelula));
    lista->pUltimo = lista->pPrimeiro;
    lista->pPrimeiro->pProx = NULL;
    lista->QntdItens = 0;
};

void InsereNovoNumeroLinha(Tlista *lista, int numero){
    Tcelula *i;
    int encontrado = 0;
    i = lista->pPrimeiro->pProx;
    while(i != NULL && encontrado == 0){
        encontrado = (i->Nlinha == numero);
        i = i->pProx;
    }
    if(encontrado == 0){
        lista->pUltimo->pProx = (Apontador) malloc(sizeof(Tcelula));
        lista->pUltimo = lista->pUltimo->pProx;
        lista->pUltimo->Nlinha = numero;
        lista->pUltimo->pProx = NULL;
        lista->QntdItens++;
    }
};

void RetiraNumeroLinha(Tlista *lista){
    Tcelula *ultimo = lista->pPrimeiro->pProx;
    Tcelula *penultimo = NULL;
    while(ultimo->pProx != NULL){
        penultimo = ultimo;
        ultimo = ultimo->pProx;
    }
    free(ultimo);
    penultimo->pProx = NULL;
    lista->pUltimo = penultimo;
    lista->QntdItens--;

};

int VerificaNLinha(Tlista *lista, int numero){
    Tcelula *ultimo = lista->pPrimeiro->pProx;
    int Existe = 0;
    while(ultimo != NULL && Existe == 0){
        if(ultimo->Nlinha == numero){
            printf("lista -> ultimo -> linhas = %d\nnumero = %d",ultimo->Nlinha, numero);
            Existe = 1;
        }
        ultimo = ultimo->pProx;
    }
    return(Existe);
};

int RetornaQntdLinhas(Tlista *lista){
    return(lista->QntdItens);
};

void ImprimeLinhas(Tlista *lista){
   Apontador ultimo = lista->pPrimeiro->pProx;
   while(ultimo != NULL){
        printf("%d\n", ultimo->Nlinha);
        ultimo = ultimo->pProx;
   }
};
