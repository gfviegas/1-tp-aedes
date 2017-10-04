#ifndef ALFABETO_H_INCLUDED
#define ALFABETO_H_INCLUDED
#include "ListaDePalavras.h"
#include "NumeroLinha.h"
#include "Palavra.h"

typedef struct{
    char caracter;
    ListaDePalavras listaPalavra;
}LetraAlfabeto;

void criaLetraAlfabeto(LetraAlfabeto *letra);

void preencheCaracter(LetraAlfabeto *letra, char caracter);

char retornaCaracter(LetraAlfabeto *letra);

void imprimeLetraAlfabeto(LetraAlfabeto *letra);


#endif // ALFABETO_H_INCLUDED
