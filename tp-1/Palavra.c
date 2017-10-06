/**
 * Métodos do TAD Palavra
 * @author Heitor Passeado
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "NumeroLinha.h"
#include "Palavra.h"

// Configura uma nova instância de uma variável do tipo Palavra e inicializa a lista de linhas
void criaPalavraVazia(Palavra *palavra) {
    strcpy(palavra->valor, " ");
    criaListaNumeroLinhas(&palavra->lista);
}

// Preenche o struct Palavra com a string desejada
void preencheCadeiaDeCaracteres(Palavra *palavra, char *preenchimento) {
    strcpy(palavra->valor, preenchimento);
}

// Imprime a string vinculada ao TAD
void imprimeCadeiaDeCaracteres(Palavra *palavra) {
    printf("PALAVRA: %s\n", palavra->valor);
}

// Imprime os dados de uma palavra
void imprimePalavra(Palavra *palavra) {
    imprimeCadeiaDeCaracteres(palavra);
    imprimeLinhas(&palavra->lista);
}

// Retorna a string vinculada a uma palavra
char *retornaCadeiaDeCaracteres(Palavra *palavra) {
    return palavra->valor;
}
