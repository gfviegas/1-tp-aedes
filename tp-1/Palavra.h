/**
 * Definições e Cabeçalhos do TAD Palavra
 * @author Heitor Passeado
 */

#ifndef PALAVRA_H_INCLUDED
#define PALAVRA_H_INCLUDED
#include <string.h>
#include "NumeroLinha.h"

#define MAXTAMPALAVRA 50 // Tamanho máximo da palavra
typedef struct {
    char valor[MAXTAMPALAVRA];
    ListaLinhas lista;
} Palavra;

/**
 * Configura uma nova instância de uma variável do tipo Palavra e inicializa a lista de linhas
 * @method criaPalavraVazia
 * @param  palavra          Ponteiro do tipo Palavra que será manipulado
 */
void criaPalavraVazia(Palavra *palavra);

/**
 * Preenche o struct Palavra com a string desejada
 * @method preencheCadeiaDeCaracteres
 * @param  palavra                    Ponteiro do tipo Palavra que será manipulado
 * @param  preenchimento              String que se deseja preencher no struct
 */
void preencheCadeiaDeCaracteres(Palavra *palavra, char *preenchimento);

/**
 * Imprime a string vinculada ao TAD
 * @method imprimeCadeiaDeCaracteres
 * @param  palavra                   Ponteiro do tipo Palavra que será manipulado
 */
void imprimeCadeiaDeCaracteres(Palavra *palavra);

/**
 * Imprime os dados de uma palavra
 * @method imprimePalavra
 * @param  palavra        Ponteiro do tipo Palavra que será manipulado
 */
void imprimePalavra(Palavra *palavra);

/**
 * Retorna a string vinculada a uma palavra
 * @method retornaCadeiaDeCaracteres
 * @param  palavra                   Ponteiro do tipo Palavra que será manipulado
 * @return                           String vinculada a uma palavra
 */
char *retornaCadeiaDeCaracteres(Palavra *palavra);

#endif // PALAVRA_H_INCLUDED
