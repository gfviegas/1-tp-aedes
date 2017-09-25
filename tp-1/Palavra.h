//
//  Palavra.h
//  tp-1
//
//  Created by Viegas on 21/09/17.
//  Copyright © 2017 Ciencia da Computacao - UFV. All rights reserved.
//

#ifndef Palavra_h
#define Palavra_h

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char texto[300];
} Palavra;


void criaPalavra(Palavra* novaPalavra, char *texto);

#endif /* Palavra_h */
