//
//  main.c
//  tp-1
//
//  Created by Viegas on 19/09/17.
//  Copyright © 2017 Ciencia da Computacao - UFV. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
//#include "TadPalavra.h"
#include "NumeroLinha.h"
#include "TadPalavra.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    Tpalavra palavra;
    Tlista lista;
    CriaListaNLinhas(&lista);
    InsereNovoNumeroLinha(&lista,2);
    InsereNovoNumeroLinha(&lista,3);
    InsereNovoNumeroLinha(&lista,4);
    InsereNovoNumeroLinha(&lista,5);
    RetiraNumeroLinha(&lista);
    printf("Imprimindo quantidade: %d \n", RetornaQntdLinhas(&lista));

    char nome[64] = "cafttyffghhgfhfh", *nome2;
    criaPalavraVazia(&palavra,&lista);
    preencheCadeiaDeCaracteres(&palavra,nome);
    imprimeCadeiaDeCaracteres(&palavra);

    printf("\nnome2 =  %s\n", retornaCadeiaDeCaracteres(&palavra));
    imprimePalavra(&palavra);
    return 0;
}
