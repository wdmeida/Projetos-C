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
    int tamanho;
}TLista;

typedef TLista *Lista;

typedef struct {
    int n; //número de itens na hash.
    int nro_listas; //tamanho do array de listas.
    int nro_pesos; //tamanho do array de pesos.
    int *p; //array de pesos.
    TLista *v; //array de listas.
}THash;

//TAD Tabela Hash
void THash_Inicia(THash*, int, int);
int THash_H(THash*, TChave);
int THash_Pesquisa(THash*, TChave, TItem*);
TCelula *THash_Pesquisa_Celula(THash*, TChave);
int THash_Insere(THash*, TItem);
int THash_Remove(THash*, TItem*);
void THash_Termina(THash*);

//TAD Lista.
void TLista_Inicia(Lista);
int TLista_Insere(Lista, TItem);
int TLista_Remove(Lista, TCelula*, TItem*);
int TLista_EhVazia(Lista);
int TLista_Remove_Inicio(Lista, TItem*);
int TLista_Remove_Final(Lista, TItem*);
void TLista_Termina(Lista);

#endif // HASHING_H_INCLUDED
