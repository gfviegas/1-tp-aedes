/**
 * Métodos do TAD Dicionário
 * @author Gustavo Viegas
 */

#include <stdio.h>
#include "Dicionario.h"
#include "LetraAlfabeto.h"

#define BUFFERSIZE 255
#define FILENAMESIZE 200

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


// Lê um arquivo a partir do caminho inserido pelo usuário e insere as palavras encontradas no dicionario já incializado
int configuraDicionario (Dicionario * dicionario) {
    int linhaAtual = 1; // Inteiro que armazena a linha onde a palavra estará
    char nomeArquivo[FILENAMESIZE]; // Caminho pro arquivo
    char buffer[BUFFERSIZE]; // Buffer de uma linha (255 caracteres)
    char * palavraAtual; // Armazenará a palavra atual em cada iteração
    FILE *arquivo = NULL; // Arquivo TXT lido
    
    printf("Entre o caminho do arquivo, com extensão: ");
    scanf(" %[^\n]s", nomeArquivo);
    arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("O arquivo %s não existe. Encerrando a execução. \n", nomeArquivo);
        return 0;
    }
    
    while (fgets(buffer, BUFFERSIZE, (FILE*) arquivo)) {
        palavraAtual = strtok (buffer, " \n\r\t");
        while (palavraAtual != NULL) {
            inserePalavraDicionario(dicionario, palavraAtual, linhaAtual);
            palavraAtual = strtok (NULL, " \n\r\t");
        }
        linhaAtual++;
    }
    
    fclose(arquivo);
    return 1;
}

// Lê uma letra para se imprimir as palavras do dicionário inicializados por essa letra
void promptLetraDicionario (Dicionario * dicionario) {
    char letraDesejada;
    printf("Entre a letra que deseja imprimir os dados: ");
    scanf(" %c", &letraDesejada);
    imprimeLetraDicionario(dicionario, letraDesejada);
}

// Lê uma palavra para se verificar se ela existe no dicionário
void promptPalavraDicionario (Dicionario * dicionario) {
    char palavraDesejada[50];
    printf("Entre a palavra que deseja verificar (max 50 caracteres): ");
    scanf(" %[^\n]s", palavraDesejada);
    
    if (verificaPalavraExisteDicionario(dicionario, palavraDesejada) == 0) {
        printf("A palavra %s não existe no dicionário. \n", palavraDesejada);
    }
}

// Lê uma palavra e uma linha, e as insere no dicionário
void promptInserePalavra(Dicionario * dicionario) {
    char palavraDesejada[50];
    int linha;
    printf("Entre a palavra a ser inserida: \n");
    scanf(" %[^\n]s", palavraDesejada);
    printf("Entre com a linha a ser inserida: \n");
    scanf(" %d", &linha);
    inserePalavraDicionario(dicionario, palavraDesejada, linha);
    
}

// Lê uma palavra e a remove do dicionário, se existir
void promptRemovePalavra(Dicionario *dicionario) {
    char palavraDesejada[50];
    printf("Entre a palavra que deseja remover (max 50 caracteres): ");
    scanf(" %[^\n]s", palavraDesejada);
    removePalavraDicionario(dicionario, palavraDesejada);
}

// Pede um método de ordenação ao usuário e retorna o seu código
int promptMetodoOrdenacao() {
    int codigo;
    
    printf("\nOs métodos de ordenação disponíveis são: \n\n");
    printf("Insira 0 \t->\t Bubble Sort (Método da Bolha)\n");
    printf("Insira 1 \t->\t Selection Sort (Método da Seleção)\n");
    printf("Insira 2 \t->\t Insert Sort (Método de Inserção)\n");
    printf("Insira 3 \t->\t Shell Sort\n");
    printf("Insira 4 \t->\t Quick Sort\n");
    printf("Insira 5 \t->\t Heap Sort\n");

    printf("Digite o código desejado: ");
    scanf(" %d", &codigo);
    
    return codigo;
}

// Lê uma letra e um método de ordenação de algoritmo
int promptOrdenarLetraAlfabeto(Dicionario *dicionario) {
    char letraDesejada;
    int codigoOrdenacao;
    int indiceLetraDesejada;
    
    printf("Entre a letra (minúscula) que deseja visualizar ordenados: ");
    scanf(" %c", &letraDesejada);
    indiceLetraDesejada = (int) letraDesejada - 97;
    
    if (indiceLetraDesejada > 25 || indiceLetraDesejada < 0) {
        printf("\nA letra desejada é inválida!! \n");
        return 0;
    }
    
    codigoOrdenacao = promptMetodoOrdenacao();
    switch (codigoOrdenacao) {
        case 0:
            // CHAMADA PRA OPERACAO DE BUBBLE SORT
            // ex: ordenarListaBubble(dicionario->letras[indiceLetraDesejada]->listaPalavra);
            break;
        case 1:
            // CHAMADA PRA OPERACAO DE SELECTION SORT
            break;
        case 2:
            // CHAMADA PRA OPERACAO DE INSERT SORT
            break;
        case 3:
            // CHAMADA PRA OPERACAO DE SHELL SORT
            break;
        case 4:
            // CHAMADA PRA OPERACAO DE QUICK SORT
            break;
        case 5:
            // CHAMADA PRA OPERACAO DE HEAP SORT
            break;
        default:
            printf("\nCódigo de ordenação inválido!! \n");
            return 0;
    }

    return 1;
}

// Lê um método de ordenação de algoritmo para o dicionário completo
void promptOrdenarDicionario(Dicionario *dicionario) {
    // Isso é por ultimo, é basicamente o metodo acima dentro de um loop, pra fazer todas as letras.
}
