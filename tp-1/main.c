#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Palavra.h"
#include "NumeroLinha.h"
#include "ListaDePalavras.h"
#include "Alfabeto.h"

int main(){

    Palavra palavra,palavra2,palavra3,palavra4;
    char *string, *string2, *string3, *string4, caracter;
    ListaDePalavras lista;
    TLetraAlfabeto letra;
    caracter = 'b';

    string = "biscoito";
    string2 = "cafe";
    string3 = "trabson";
    string4 = "Batata";
    printf("\n\nLetraAlfabeto------------------------\n\n\n");
    criaLetraAlfabeto(&letra);
    preencheCaracter(&letra, caracter);
    printf("%c\n", retornaCaracter(&letra));
    criaPalavraVazia(&palavra);
    preencheCadeiaDeCaracteres(&palavra,string);
    criaPalavraVazia(&palavra2);
    preencheCadeiaDeCaracteres(&palavra2,string4);
    insereNovaPalavraFinal(&letra.listaPalavra, &palavra);
    insereNovaPalavraFinal(&letra.listaPalavra, &palavra2);
    imprimeLetraAlfabeto(&letra);


    return 0;
}
