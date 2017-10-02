#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Dicionario.h"

// Nenhum desses includes devem estar no oficial!!
#include "Palavra.h"
#include "NumeroLinha.h"
#include "ListaDePalavras.h"
#include "Alfabeto.h"

int main(){
    /*
    Palavra palavra, palavra2;
    char *string, *string2, *string3, *string4, caracter;
    LetraAlfabeto letra;
    caracter = 'b';

    string = "biscoito";
    string2 = "cafe";
    string3 = "trabson";
    string4 = "Batata";
    printf("\n\nLetraAlfabeto------------------------\n\n\n");
    criaLetraAlfabeto(&letra);
    preencheCaracter(&letra, caracter);
    printf("%c\n", retornaCaracter(&letra));
    criaPalavraVazia(&palavra);
    preencheCadeiaDeCaracteres(&palavra,string);
    criaPalavraVazia(&palavra2);
    preencheCadeiaDeCaracteres(&palavra2,string4);
    insereNovaPalavraFinal(&letra.listaPalavra, &palavra);
    insereNovaPalavraFinal(&letra.listaPalavra, &palavra2);
    imprimeLetraAlfabeto(&letra);
     */
    
    
    /**
     * Daqui pra frente é o código oficial!
     **/
    // Dicionario dicionario;
    char nomeArquivo[50];
    FILE *arquivo = NULL;
    
    printf("Entre o caminho do arquivo, com extensão: ");
    gets(nomeArquivo);
    arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("O arquivo %s não existe. Encerrando a execução. \n", nomeArquivo);
        exit(-1);
    }
    
    char palavraAtual[100];
    // A logica que to usando aqui é de ler palavra por palavra, mas acho q vou ter q mudar pra ler linha por linha e dividir a linha em palavras depois
    while (fscanf(arquivo, " %1023s", palavraAtual) == 1) {
        int indicePalavraDicionario = retornaIndiceLetra(palavraAtual[0]);
        int linhaPalavraAtual;
        // Palavra atual aqui vai ter o valor de cada palavra no arquivo.
        //printf("Palavra: %s ; Primeira Letra: %c \n", palavraAtual, palavraAtual[0]);
        printf("Palavra %s com indice %d na linha %d", palavraAtual, indicePalavraDicionario, linhaPalavraAtual);
    }

    return 0;
}
