#include "TadPalavra.h"
#include <stdlib.h>
#include <string.h>
#include "NumeroLinha.h"

void criaPalavraVazia(Tpalavra *palavra) {

    strcpy(palavra->cadeiaDeCaracteres, " ");
    CriaListaNLinhas(&palavra->lista);
}

void preencheCadeiaDeCaracteres(Tpalavra *palavra, char *Preenchimento){
    strcpy(palavra->cadeiaDeCaracteres,Preenchimento);
};

void imprimeCadeiaDeCaracteres(Tpalavra *palavra){
    printf("%s\n", palavra->cadeiaDeCaracteres);
};

void printPrimeiro(Tlista *lista) {
    Apontador teste = lista->pPrimeiro->pProx;

    printf("%d", teste->Nlinha);
}

void imprimePalavra(Tpalavra *palavra) {

    imprimeCadeiaDeCaracteres(palavra);
    ImprimeLinhas(&palavra->lista);
}

char *retornaCadeiaDeCaracteres(Tpalavra *palavra){
    return palavra->cadeiaDeCaracteres;
};
