#include "Palavra.h"
#include <stdlib.h>
#include <string.h>
#include "NumeroLinha.h"

void criaPalavraVazia(Palavra *palavra) {

    strcpy(palavra->valor, " ");
    CriaListaNLinhas(&palavra->lista);
}

void preencheCadeiaDeCaracteres(Palavra *palavra, char *Preenchimento){
    strcpy(palavra->valor,Preenchimento);
};

void imprimeCadeiaDeCaracteres(Palavra *palavra){
    printf("%s\n", palavra->valor);
};

void printPrimeiro(ListaLinhas *lista) {
    ApontadorCelulaLinhas teste = lista->primeiro->proximo;

    printf("%d", teste->numeroLinha);
}

void imprimePalavra(Palavra *palavra) {

    imprimeCadeiaDeCaracteres(palavra);
    ImprimeLinhas(&palavra->lista);
}

char *retornaCadeiaDeCaracteres(Palavra *palavra){
    return palavra->valor;
};
