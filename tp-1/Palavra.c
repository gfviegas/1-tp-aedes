//
//  Palavra.c
//  tp-1
//
//  Created by Viegas on 21/09/17.
//  Copyright © 2017 Ciencia da Computacao - UFV. All rights reserved.
//

#include <string.h>
#include "Palavra.h"


void criaPalavra(Palavra* novaPalavra, char *texto) {
    strcpy(novaPalavra->texto, texto);
};
