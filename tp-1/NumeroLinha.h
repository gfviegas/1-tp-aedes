/**
 * Definições e Cabeçalhos do TAD NumeroLinha
 * @author Arthur Marciano
 */

#ifndef NUMEROLINHA_H_INCLUDED
#define NUMEROLINHA_H_INCLUDED

typedef struct CelulaLinhas* ApontadorCelulaLinhas; // Ponteiro para uma célula da lista de números
typedef struct CelulaLinhas {
    int numeroLinha;
    ApontadorCelulaLinhas proximo;
} CelulaLinhas; // Célula de uma lista encadeada de números

typedef struct {
    ApontadorCelulaLinhas primeiro;
    ApontadorCelulaLinhas ultimo;
    int quantidadeItens;
} ListaLinhas;

/**
 * Configura uma nova instância de uma variável do tipo ListaLinhas e inicializa a célula-cabeça.
 * @function criaListaDePalavras
 * @param  lista               Ponteiro do tipo ListaLinhas que será manipulado
 */
void criaListaNumeroLinhas(ListaLinhas *lista);

/**
 * Insere uma nova linha à lista linear, se não existir.
 * @function insereNovoNumeroLinha
 * @param  lista                 Ponteiro do tipo ListaLinhas que será manipulado
 * @param  numero                Inteiro representando o número da linha a ser inserido
 */
void insereNovoNumeroLinha(ListaLinhas *lista, int numero);

/**
 * Remove uma linha do fim da lista linear
 * @function insereNovoNumeroLinha
 * @param  lista                 Ponteiro do tipo ListaLinhas que será manipulado
 */
void retiraNumeroLinha(ListaLinhas *lista);

/**
 * Verifica se uma linha existe na lista linear
 * @function verificaNumeroLinha
 * @param  lista               Ponteiro do tipo ListaLinhas que será manipulado
 * @param  numero              Inteiro representando o número da linha a ser inserido
 * @return                     Inteiro representando a existência (1) ou não (0) da linha na lista linear
 */
int verificaNumeroLinha(ListaLinhas *lista, int numero);

/**
 * Retorna a quantdade de linhas na lista linear
 * @function quantidadeLinhas
 * @param  lista            Ponteiro do tipo ListaLinhas que será manipulado
 * @return                  Inteiro representando a quantidade de linhas existentes na lista linear
 */
int quantidadeLinhas(ListaLinhas *lista);

/**
 * Imprime os dados de uma lista linear de linhas.
 * @function imprimeLinhas
 * @param  lista         Ponteiro do tipo ListaLinhas que será manipulado
 */
void imprimeLinhas(ListaLinhas *lista);

#endif // NUMEROLINHA_H_INCLUDED
