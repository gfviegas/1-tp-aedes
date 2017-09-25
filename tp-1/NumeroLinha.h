#ifndef NUMEROLINHA_H_INCLUDED
#define NUMEROLINHA_H_INCLUDED


typedef struct celula* Apontador;
typedef struct celula{
    int Nlinha;
    Apontador pProx;
}Tcelula;


typedef struct{
    Apontador pPrimeiro;
    Apontador pUltimo;
    int NumeroLinhas;
}Tlista;


void CriaListaNLinhas(Tlista *lista);

void InsereNovoNumeroLinha(Tlista *lista, int numero);

void RetiraNumeroLinha(Tlista *lista);





#endif // NUMEROLINHA_H_INCLUDED
