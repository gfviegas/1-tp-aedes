/**
 * Métodos do TAD LetraAlfabeto
 * @author Heitor Passeado / Arthur Marciano
 */

#include "LetraAlfabeto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Configura uma nova instância de uma variável do tipo Dicionário.
void criaLetraAlfabeto(LetraAlfabeto *letra) {
    letra->caracter = ' ';
    criaListaDePalavras(&letra->listaPalavra);
}

// Preenche o struct LetraAlfabeto com o caracter desejado
void preencheCaracter(LetraAlfabeto *letra, char caracter) {
    letra->caracter = caracter;
}

// Retorna o caracter do struct LetraAlfabeto
char retornaCaracter(LetraAlfabeto *letra) {
    return letra->caracter;
}

// Imprime a letra representada e as palavras e suas linhas que comecam com essa letra
void imprimeLetraAlfabeto(LetraAlfabeto *letra) {
    int quantidadePalavrasLetra = quantidadePalavras(&letra->listaPalavra);
    if(quantidadePalavrasLetra == 1)
        printf("=== LETRA: %c     ||     Total de %d palavra. ===\n", letra->caracter, quantidadePalavrasLetra);
    else
        printf("=== LETRA: %c     ||     Total de %d palavras. ===\n", letra->caracter, quantidadePalavrasLetra);
    imprimeListaPalavras(&letra->listaPalavra);
}
