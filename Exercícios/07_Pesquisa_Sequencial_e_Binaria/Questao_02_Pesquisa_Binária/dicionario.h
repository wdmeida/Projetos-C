#ifndef DICIONARIO_H_INCLUDED
#define DICIONARIO_H_INCLUDED

typedef long TChave;

typedef struct{
    TChave Chave;
}TItem;

typedef struct {
    TItem *v;
    int tamanho, capacidade;
}TDicionario;

void TDicionario_inicio(TDicionario*);
void TDicionario_insere(TDicionario*, TItem);
//Recursiva.
int TDicionario_Find(TDicionario*, TChave);
int TDicionario_Binaria(TDicionario*, int, int, TChave);
//Interatica
int TDicionario_Find_Iterativa(TDicionario*, TChave);

#endif // DICIONARIO_H_INCLUDED
