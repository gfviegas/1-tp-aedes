#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Palavra.h"
#include "NumeroLinha.h"

int main(){

    Palavra palavra;
    char *string;

    string = "biscoito";

    criaPalavraVazia(&palavra);

    preencheCadeiaDeCaracteres(&palavra, string);

    imprimeCadeiaDeCaracteres(&palavra);
    InsereNovoNumeroLinha(&palavra.lista, 2);
    InsereNovoNumeroLinha(&palavra.lista, 4);
    InsereNovoNumeroLinha(&palavra.lista, 5);
    InsereNovoNumeroLinha(&palavra.lista, 12);
    InsereNovoNumeroLinha(&palavra.lista, 15);
    RetiraNumeroLinha(&palavra.lista);
    ImprimeLinhas(&palavra.lista);

    printf("-------------------------\n");

    imprimePalavra(&palavra);

    return 0;
}
