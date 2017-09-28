#ifndef ALFABETO_H_INCLUDED
#define ALFABETO_H_INCLUDED
#include "ListaDePalavras.h"
#include "NumeroLinha.h"
#include "TadPalavra.h"

typedef struct{
    char caracter;
    ListaDePalavras listaPalavra;
}TLetraAlfabeto;

void criaLetraAlfabeto(TLetraAlfabeto *letra);

void preencheCaracter(TLetraAlfabeto *letra,char caracter);

char retornaCaracter(TLetraAlfabeto *letra);

void imprimeLetraAlfabeto(TLetraAlfabeto *letra);


#endif // ALFABETO_H_INCLUDED
