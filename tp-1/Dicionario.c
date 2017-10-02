//
//  Dicionario.c
//  tp-1
//
//  Created by Viegas on 28/09/17.
//  Copyright © 2017 Ciencia da Computacao - UFV. All rights reserved.
//

#include <stdio.h>
#include "Dicionario.h"
#include "Alfabeto.h"

// Insere uma nova palavra e sua linha no dicionario.
// Caso seja uma palavra já existente, somente a linha será inserida na palavra já cadastrada.
void inserePalavraDicionario(Dicionario* dicionario, char* palavra, int linha) {
}

// Remove uma palavra do dicionário.
// Se a palavra não existir, uma mensagem será printada.
void removePalavraDicionario(Dicionario* dicionario, char* palavra) {
}

// Imprime a lista de palavras de uma determinada letra do dicionario.
void imprimeLetraDicionario(Dicionario* dicionario, char letra) {
}

// Imprime todas as palavras do dicionário em ordem alfabética das letras.
void imprimeDicionario(Dicionario* dicionario) {
}

// Retorna a posição do indice de uma letra, ex: a == 0, b == 1, c == 2, etc.
int retornaIndiceLetra(char letra) {
    return ((int) letra) - 97;
}
