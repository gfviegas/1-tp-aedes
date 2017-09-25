#include "TadPalavra.h"
#include <stdlib.h>
#include <string.h>

void criaPalavraVazia(Tpalavra *palavra){
    palavra = (Tpalavra *)malloc(32 * sizeof(char));
};

void iniciaNlinhas(Tlista *lista){
    lista->numero = 32;
};

void preencheCadeiaDeCaracteres(Tpalavra *palavra, char *Preenchimento){
    strcpy(palavra->cadeiaDeCaracteres,Preenchimento);
};

void imprimeCadeiaDeCaracteres(Tpalavra *palavra){
    printf("%s", palavra->cadeiaDeCaracteres);
};

void imprimePalavra(Tpalavra *palavra){
  printf("%s", palavra->cadeiaDeCaracteres);
  printf("%d", palavra->TadNumeroLinhas->primeiro->info.numero);
};

char *retornaCadeiaDeCaracteres(Tpalavra *palavra){
    return palavra->cadeiaDeCaracteres;
}
