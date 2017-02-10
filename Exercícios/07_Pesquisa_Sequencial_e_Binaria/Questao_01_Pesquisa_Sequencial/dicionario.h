#ifndef DICIONARIO_H_INCLUDED
#define DICIONARIO_H_INCLUDED

typedef long TChave;

typedef struct{
    TChave Chave;
}TItem;

typedef struct {
    TItem *v;
    int tamanho,
        maximo;
}TDicionario;

void TDicionario_Inico(TDicionario*);
int TDicionario_Find(TDicionario*, TChave);
void TDicionario_Insere(TDicionario*, TItem);
TItem TDicionario_get(TDicionario*, int);

#endif // DICIONARIO_H_INCLUDED
