#include "LetraAlfabeto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void criaLetraAlfabeto(LetraAlfabeto *letra){
    letra->caracter = ' ';
    criaListaDePalavras(&letra->listaPalavra);
}
void preencheCaracter(LetraAlfabeto *letra, char caracter){
    letra->caracter = caracter;
}

char retornaCaracter(LetraAlfabeto *letra){
    return letra->caracter;
}

void imprimeLetraAlfabeto(LetraAlfabeto *letra) {
    int quantidadePalavrasLetra = quantidadePalavras(&letra->listaPalavra);
    if(quantidadePalavrasLetra == 1)
        printf("=== LETRA: %c     ||     Total de %d palavra. ===\n", letra->caracter, quantidadePalavrasLetra);
    else
        printf("=== LETRA: %c     ||     Total de %d palavras. ===\n", letra->caracter, quantidadePalavrasLetra);
    imprimeListaPalavras(&letra->listaPalavra);

}
