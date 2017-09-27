#include "TadPalavra.h"
#include <stdlib.h>
#include <string.h>
#include "NumeroLinha.h"
void criaPalavraVazia(Tpalavra *palavra, Tlista *lista){
    palavra = (Tpalavra *)malloc(sizeof(Tpalavra));
    palavra->lista = *lista;
};

void preencheCadeiaDeCaracteres(Tpalavra *palavra, char *Preenchimento){
    strcpy(palavra->cadeiaDeCaracteres,Preenchimento);
};

void imprimeCadeiaDeCaracteres(Tpalavra *palavra){
    printf("%s", palavra->cadeiaDeCaracteres);
};

void imprimePalavra(Tpalavra *palavra){
  printf("Palavra: %s. Linhas: ", palavra->cadeiaDeCaracteres);
  ImprimeLinhas((palavra->&lista));
  //printf("%d", RetornaQntdLinhas(&(palavra->lista)));
};

char *retornaCadeiaDeCaracteres(Tpalavra *palavra){
    return palavra->cadeiaDeCaracteres;
};
