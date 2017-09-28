#include "alfabeto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void criaLetraAlfabeto(TLetraAlfabeto *letra){
    letra->caracter = ' ';
    criaListaDePalavras(&letra->listaPalavra);
}
void preencheCaracter(TLetraAlfabeto *letra,char caracter){
    letra->caracter = caracter;
}

char retornaCaracter(TLetraAlfabeto *letra){
    return letra->caracter;
}

void imprimeLetraAlfabeto(TLetraAlfabeto *letra){
    printf("%c\n", letra->caracter);
    imprimeListaPalavras(&letra->listaPalavra);

}
