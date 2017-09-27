#ifndef NUMEROLINHA_H_INCLUDED
#define NUMEROLINHA_H_INCLUDED


typedef struct CelulaLinhas* ApontadorCelulaLinhas;
typedef struct CelulaLinhas{
    int numeroLinha;
    ApontadorCelulaLinhas proximo;
}CelulaLinhas;


typedef struct{
    ApontadorCelulaLinhas primeiro;
    ApontadorCelulaLinhas ultimo;
    int quantidadeItens;
}ListaLinhas;


void CriaListaNLinhas(ListaLinhas *lista);

void InsereNovoNumeroLinha(ListaLinhas *lista, int numero);

void RetiraNumeroLinha(ListaLinhas *lista);

int VerificaNLinha(ListaLinhas *lista, int numero);

int RetornaQntdLinhas(ListaLinhas *lista);

void ImprimeLinhas(ListaLinhas *lista);


#endif // NUMEROLINHA_H_INCLUDED
