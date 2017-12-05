/**
 * Definições e Cabeçalhos do TAD Dicionário
 * @author Gustavo Viegas
 */

#ifndef DICIONARIO_H_INCLUDED
#define DICIONARIO_H_INCLUDED
#include "LetraAlfabeto.h"
#include "ListaDePalavras.h"

#define TAMLETRAS 26

typedef struct Dicionario {
    LetraAlfabeto letras[TAMLETRAS]; // Array de tamanho 26 (TAMLETRAS) onde cada posição representa uma letra do alfabeto
} Dicionario;

/**
 * Configura uma nova instância de uma variável do tipo Dicionário.
 * @function criaDicionario
 * @param  dicionario     Ponteiro do tipo Dicionário que será manipulado
 */
void criaDicionario (Dicionario* dicionario);

/**
 * Insere uma nova palavra e a linha do arquivo onde foi encontrado.
 * Caso seja uma palavra já existente no dicionário apenas a linha será inserida no registro da palavra já cadastrada.
 * @function inserePalavraDicionario
 * @param  dicionario              Ponteiro do tipo Dicionário que será manipulado
 * @param  palavra                 String da palavra a ser inserida
 * @param  linha                   Inteiro da linha onde a palavra foi encontrada no texto
 */
void inserePalavraDicionario(Dicionario* dicionario, char* palavra, int linha);

/**
 * Remove uma palavra do dicionário. Se a palavra não existir, uma mensagem de aviso será printada.
 * @function removePalavraDicionario
 * @param  dicionario              Ponteiro do tipo Dicionário que será manipulado
 * @param  palavra                 String da palavra a ser inserida
 * @return                         Inteiro representando sucesso (1) ou não (0) da remoção da palavra
 */
int removePalavraDicionario(Dicionario* dicionario, char* palavra);

/**
 * Imprime a lista de palavras de uma determinada letra do dicionario.
 * @function imprimeLetraDicionario
 * @param  dicionario             Ponteiro do tipo Dicionário que será manipulado
 * @param  letra                  Char letra representando a letra inicial das palavras que se deseja imprimir
 */
void imprimeLetraDicionario(Dicionario* dicionario, char letra);

// Imprime todas as palavras do dicionário em ordem alfabética das letras.
/**
 * Imprime todas as palavras do dicionário em ordem alfabética, crescente, das letras iniciais das palavras.
 * @function imprimeDicionario
 * @param  dicionario        Ponteiro do tipo Dicionário que será manipulado
 */
void imprimeDicionario(Dicionario* dicionario);

/**
 * Retorna a posição do indice de uma letra
 * Por exemplo: a == 0, b == 1, c == 2, etc.
 * @function retornaIndiceLetra
 * @param  letra              Letra que se deseja obter o indice
 * @return                    Inteiro que representa o indice do array onde o caracter é representado
 */
int retornaIndiceLetra(char letra);

/**
 * Verifica se uma palavra existe no dicionario. Se existir, imprime os seus dados.
 * @function verificaPalavraExisteDicionario
 * @param  dicionario                      Ponteiro do tipo Dicionário que será manipulado
 * @param  palavra                         String da palavra a ser consultada
 * @return                                 Inteiro representando se a palavra existe (1) ou não (0)
 */
int verificaPalavraExisteDicionario(Dicionario* dicionario, char* palavra);

/**
 * Lê um arquivo a partir do caminho inserido pelo usuário e insere as palavras encontradas no dicionario já incializado
 * @function configuraDicionario
 * @param  dicionario          Ponteiro do tipo Dicionario que será manipulado
 * @return                     Inteiro representando se o arquivo existe e foi bem sucedido a configuração (1) ou não (0)
 */
int configuraDicionario (Dicionario * dicionario);

/**
 * Lê uma letra para se imprimir as palavras do dicionário inicializados por essa letra
 * @function promptLetraDicionario
 * @param  dicionario          Ponteiro do tipo Dicionario que será manipulado
 */
void promptLetraDicionario (Dicionario * dicionario);

/**
 * Lê uma palavra para se verificar se ela existe no dicionário
 * @function promptPalavraDicionario
 * @param  dicionario          Ponteiro do tipo Dicionario que será manipulado
 */
void promptPalavraDicionario (Dicionario * dicionario);

/**
 * Lê uma palavra e uma linha, e as insere no dicionário
 * @function promptInserePalavra
 * @param  dicionario          Ponteiro do tipo Dicionario que será manipulado
 */
void promptInserePalavra(Dicionario * dicionario);

/**
 * Lê uma palavra e a remove do dicionário, se existir
 * @function promptRemovePalavra
 * @param  dicionario          Ponteiro do tipo Dicionario que será manipulado
 */
void promptRemovePalavra(Dicionario *dicionario);

/**
 * Pede um método de ordenação ao usuário e retorna o seu código
 * @function promptRemovePalavra
 */
int promptMetodoOrdenacao();

/**
 * Lê uma letra e um método de ordenação de algoritmo
 * @function promptOrdenarLetraAlfabeto
 * @param  dicionario          Ponteiro do tipo Dicionario que será manipulado
 * @return                    Inteiro que representa o sucesso ou não da entrada
 */
int promptOrdenarLetraAlfabeto(Dicionario *dicionario);

/**
 * Lê um método de ordenação de algoritmo para o dicionário completo
 * @function promptOrdenarLetraAlfabeto
 * @param  dicionario          Ponteiro do tipo Dicionario que será manipulado
 */
void promptOrdenarDicionario(Dicionario *dicionario);

#endif // DICIONARIO_H_INCLUDED
