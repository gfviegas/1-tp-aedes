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
    printf("=== LETRA: %c     ||     Total de %d palavras. ===\n", letra->caracter, quantidadePalavrasLetra);
    imprimeListaPalavras(&letra->listaPalavra);

}
