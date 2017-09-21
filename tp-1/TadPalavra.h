#ifndef TADPALAVRA_H_INCLUDED
#define TADPALAVRA_H_INCLUDED
#include <string.h>
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
typedef struct{
    char cadeiaDeCaracteres[32];
}Tpalavra;

void criaPalavraVazia(Tpalavra *palavra);

void preencheCadeiaDeCaracteres(Tpalavra *palavra, char *Preenchimento);

void imprimeCadeiaDeCaracteres(Tpalavra *palavra);

void imprimePalavra(Tpalavra *palavra);

//*char retornaCadeiaDeCaraacteres(Tpalavra *palavra);



#endif // TADPALAVRA_H_INCLUDED
