#ifndef PALAVRA_H_INCLUDED
#define PALAVRA_H_INCLUDED
#include <string.h>
#include "NumeroLinha.h"
/*Em seguida, será necessário que você implemente o TAD Palavra. Cada elemento do tipo
Palavra deverá ser representado por uma cadeia de caracteres (a palavra efetivamente) e uma
lista linear que informa as linhas em que a palavra apareceu (TAD Lista de Números de Linha).
As operações deste TAD devem ser, pelo menos:
- Cria Palavra vazia
- Preenche cadeia de caracteres
- Retorna cadeia de caracteres
- Imprime cadeia de caracteres
- Imprime Palavra (cadeia de caracteres + TAD Lista de Números de linha)
*/

//TAD do tipo palavra(falta lista de numero de linhas)
#define MAXTAMPALAVRA 32
typedef struct{
    char valor[MAXTAMPALAVRA];
    ListaLinhas lista;
}Palavra;

void criaPalavraVazia(Palavra *palavra);

void preencheCadeiaDeCaracteres(Palavra *palavra, char *Preenchimento);

void imprimeCadeiaDeCaracteres(Palavra *palavra);

void imprimePalavra(Palavra *palavra);

char *retornaCadeiaDeCaracteres(Palavra *palavra);



#endif // PALAVRA_H_INCLUDED
