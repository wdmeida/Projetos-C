#ifndef HASHING_H_INCLUDED
#define HASHING_H_INCLUDED
#define N 16 //Tamanho da chave (string).

//TAD Hash Lista Encadeada.

typedef char TChave[N];

typedef struct{
    TChave chave;
}TItem;

typedef struct celula{
    struct celula *pProx;
    TItem item;
}TCelula;

typedef struct{
    TCelula *pPrimeiro, *pUltimo;
}TLista;

typedef struct {
    int n; //número de itens na hash.
    int nro_listas; //tamanho do array de listas.
    int nro_pesos; //tamanho do array de pesos.
    int *p; //array de pesos.
    TLista *v; //array de listas.
}THash;

void THash_Inicia(THash*, int, int);
int THash_H(THash*, TChave);
int THash_Pesquisa(THash*, TChave, TItem*);
TCelula *THash_Pesquisa_Celula(THash*, TChave);
int THash_Insere(THash*, TItem);
int THash_Remove(THash*, TItem);

void GeraPesos(int*, int);

#endif // HASHING_H_INCLUDED
