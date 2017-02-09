#ifndef ORDENACAO_H_INCLUDED
#define ORDENACAO_H_INCLUDED

typedef int Chave;

typedef struct{
    Chave chave;
}TItem;

//bubble_sort()
void bubble_sort(TItem*, int);
void bubble_sort_melhorado(TItem*, int);

void imprime(TItem*, int);
#endif // ORDENACAO_H_INCLUDED
