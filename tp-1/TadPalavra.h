#ifndef TADPALAVRA_H_INCLUDED
#define TADPALAVRA_H_INCLUDED
#include <string.h>
#include "NumeroLinha.h"
/*Em seguida, ser� necess�rio que voc� implemente o TAD Palavra. Cada elemento do tipo
Palavra dever� ser representado por uma cadeia de caracteres (a palavra efetivamente) e uma
lista linear que informa as linhas em que a palavra apareceu (TAD Lista de N�meros de Linha).
As opera��es deste TAD devem ser, pelo menos:
- Cria Palavra vazia
- Preenche cadeia de caracteres
- Retorna cadeia de caracteres
- Imprime cadeia de caracteres
- Imprime Palavra (cadeia de caracteres + TAD Lista de N�meros de linha)
*/

//TAD do tipo palavra(falta lista de numero de linhas)
#define MAXTAMPALAVRA 32
typedef struct{
    char cadeiaDeCaracteres[MAXTAMPALAVRA];
    Tlista lista;
}Tpalavra;

void criaPalavraVazia(Tpalavra *palavra, Tlista *lista);

void preencheCadeiaDeCaracteres(Tpalavra *palavra, char *Preenchimento);

void imprimeCadeiaDeCaracteres(Tpalavra *palavra);

void imprimePalavra(Tpalavra *palavra);

char *retornaCadeiaDeCaracteres(Tpalavra *palavra);



#endif // TADPALAVRA_H_INCLUDED
