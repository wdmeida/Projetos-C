#ifndef END_ABERTO_H_INCLUDED
#define END_ABERTO_H_INCLUDED

/*
    No endereçamento aberto todas as chaves são armazenadas
    na própria tabela, sem uso de ponteiros explícitos.
    Existem várias propostas para a escolha de localizações alternativas.
    A mais simples é chamada de hashing linear, onde a posição h
    na tabela é dada por:

    h = (h(x) + J) mod M, para 0 <= j <= M - 1.
*/

#define VAZIO "!!!!!!!!!\0"
#define N 10 //tamanho da chave
#define M 100 //Tamanho da tabela.

typedef char TChave[N];

typedef struct{
    TChave Chave;

}TItem;

typedef TItem TDicionario[M];

void TDicionario_Inicia(TDicionario);
int TDicionario_Pesquisa(TDicionario, TChave, int*);
int TDicionario_Insere(TDicionario, TItem, int*);
int TDicionario_Retira(TDicionario, TItem*, int*);
int H(TChave, int*);
void Gera_Pesos(int*, int);
int h(char*, int*, int, int);
#endif // END_ABERTO_H_INCLUDED
