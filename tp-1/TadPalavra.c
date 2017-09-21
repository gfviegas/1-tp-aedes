#include "TadPalavra.h"
#include <stdlib.h>
#include <string.h>

void criaPalavraVazia(Tpalavra *palavra){
    palavra = (Tpalavra *)malloc(32 * sizeof(char));
};

void preencheCadeiaDeCaracteres(Tpalavra *palavra, char *Preenchimento){
    strcpy(palavra->cadeiaDeCaracteres,Preenchimento);
};
