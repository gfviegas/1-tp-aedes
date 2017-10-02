#ifndef DICIONARIO_H_INCLUDED
#define DICIONARIO_H_INCLUDED
#include "Alfabeto.h"

#define TAMLETRAS 26
    
typedef struct Dicionario {
    LetraAlfabeto letras[TAMLETRAS];
} Dicionario;


// Insere uma nova palavra e sua linha no dicionario.
// Caso seja uma palavra já existente, somente a linha será inserida na palavra já cadastrada.
void inserePalavraDicionario(Dicionario* dicionario, char* palavra, int linha);

// Remove uma palavra do dicionário.
// Se a palavra não existir, uma mensagem será printada.
void removePalavraDicionario(Dicionario* dicionario, char* palavra);

// Imprime a lista de palavras de uma determinada letra do dicionario.
void imprimeLetraDicionario(Dicionario* dicionario, char letra);

// Imprime todas as palavras do dicionário em ordem alfabética das letras.
void imprimeDicionario(Dicionario* dicionario);

// Retorna a posição do indice de uma letra, ex: a == 0, b == 1, c == 2, etc.
int retornaIndiceLetra(char letra);

#endif // DICIONARIO_H_INCLUDED
