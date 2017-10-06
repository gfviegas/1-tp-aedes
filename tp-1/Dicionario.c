/**
 * Métodos do TAD Dicionário
 * @author Gustavo Viegas
 */

#include <stdio.h>
#include "Dicionario.h"
#include "LetraAlfabeto.h"

// Configura uma nova instância de uma variável do tipo Dicionário.
void criaDicionario (Dicionario* dicionario) {
    int i;

    for (i = 0; i < TAMLETRAS; i++) {
        criaLetraAlfabeto(&dicionario->letras[i]);
        preencheCaracter(&dicionario->letras[i], (char) i + 97);
    }
}

// Insere uma nova palavra e a linha do arquivo onde foi encontrado.
void inserePalavraDicionario(Dicionario* dicionario, char* palavra, int linha) {
    int indicePalavra = retornaIndiceLetra(palavra[0]);
    Palavra palavraAInserir;
    int palavraExisteLista = verificaPalavra(&dicionario->letras[indicePalavra].listaPalavra, palavra, &palavraAInserir);

    if (palavraExisteLista == 0) {
        criaPalavraVazia(&palavraAInserir);
        preencheCadeiaDeCaracteres(&palavraAInserir, palavra);
        insereNovoNumeroLinha(&palavraAInserir.lista, linha);
        insereNovaPalavraFinal(&dicionario->letras[indicePalavra].listaPalavra, &palavraAInserir);
    } else {
        insereNovoNumeroLinha(&palavraAInserir.lista, linha);
    }
}

// Remove uma palavra do dicionário. Se a palavra não existir, uma mensagem de aviso será printada.
int removePalavraDicionario(Dicionario* dicionario, char* palavra) {
    int indicePalavra = retornaIndiceLetra(palavra[0]);
    Palavra Aux;
    int palavraExisteLista = verificaPalavra(&dicionario->letras[indicePalavra].listaPalavra, palavra, &Aux);
    if (palavraExisteLista == 0) {
        printf("A palavra %s nao existe no dicionario e portanto nao tem como ser removido.\n", palavra);
        return 0;
    } else {
        removePalavra(&dicionario->letras[indicePalavra].listaPalavra, &Aux);
        return 1;
    }
}

// Imprime a lista de palavras de uma determinada letra do dicionario.
void imprimeLetraDicionario(Dicionario* dicionario, char letra) {
    int indicePalavra = retornaIndiceLetra(letra);
    imprimeLetraAlfabeto(&dicionario->letras[indicePalavra]);
}

// Imprime todas as palavras do dicionário em ordem alfabética, crescente, das letras iniciais das palavras.
void imprimeDicionario(Dicionario* dicionario) {
    printf("********    IMPRIMINDO TODO O DICIONÁRIO    ********\n");
    int i;
    for (i = 0; i < TAMLETRAS; i++) {
        printf("________________________________________________\n");
        imprimeLetraAlfabeto(&dicionario->letras[i]);
    }
}

// Retorna a posição do indice de uma letra
int retornaIndiceLetra(char letra) {
    return ((int) letra) - 97;
}

// Verifica se uma palavra existe no dicionario. Se existir, imprime os seus dados.
int verificaPalavraExisteDicionario(Dicionario* dicionario, char* palavra) {
    int indicePalavra = retornaIndiceLetra(palavra[0]);
    Palavra palavraDesejada;
    int palavraExiste = verificaPalavra(&dicionario->letras[indicePalavra].listaPalavra, palavra, &palavraDesejada);

    if (palavraExiste) {
        printf("*** Palavra encontrada!! *** \n");
        printf("Dados => ");
        imprimePalavra(&palavraDesejada);
    }

    return palavraExiste;
}
