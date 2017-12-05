/**
 * Definições e Cabeçalhos do TAD LetraAlfabeto
 * @author Heitor Passeado / Arthur Marciano
 */

#ifndef ALFABETO_H_INCLUDED
#define ALFABETO_H_INCLUDED
#include "ListaDePalavras.h"
#include "NumeroLinha.h"
#include "Palavra.h"

typedef struct{
    char caracter;
    ListaDePalavras listaPalavra;
}LetraAlfabeto;

/**
 * Configura uma nova instância de uma variável do tipo Dicionário.
 * @function criaLetraAlfabeto
 * @param  letra            Ponteiro do tipo LetraAlfabeto que será manipulado
 */
void criaLetraAlfabeto(LetraAlfabeto *letra);

/**
 * Preenche o struct LetraAlfabeto com o caracter desejado
 * @function preencheCaracter
 * @param  letra            Ponteiro do tipo LetraAlfabeto que será manipulado
 * @param  caracter         Caracter da letra que será preenchido (Ex: a, b, j, etc..)
 */
void preencheCaracter(LetraAlfabeto *letra, char caracter);

/**
 * Retorna o caracter do struct LetraAlfabeto
 * @function retornaCaracter
 * @param  letra           Ponteiro do tipo LetraAlfabeto que será manipulado
 * @return                 Char representando a letra referente ao struct (Ex: a, b, j, etc...)
 */
char retornaCaracter(LetraAlfabeto *letra);

/**
 * Imprime a letra representada e as palavras e suas linhas que comecam com essa letra
 * @function imprimeLetraAlfabeto
 * @param  letra            Ponteiro do tipo LetraAlfabeto que será manipulado
 */
void imprimeLetraAlfabeto(LetraAlfabeto *letra);

#endif // ALFABETO_H_INCLUDED
