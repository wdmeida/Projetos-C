#ifndef QUICK_SORT_H_INCLUDED
#define QUICK_SORT_H_INCLUDED

typedef struct{
    int chave;
}TItem;

typedef struct nodo{
    struct nodo *pProximo;
    int elemento;
}TNodo;

typedef struct{
    TNodo *pTopo, *pFundo;
    int tamanho;
}TPilha;

typedef TPilha *Pilha;

Pilha cria_pilha();
int push(Pilha, int);
int pop(Pilha, int*);
int pilha_vazia(Pilha);
int tamanho_pilha(Pilha);
void libera_memoria(Pilha);



void quick_sort(TItem*, int);
void quick_sort_ordena(TItem*, int, int);
void quick_sort_particao(TItem*, int, int, int*, int*);
void quick_sort_iterativo(TItem*, int);

#endif // QUICK_SORT_H_INCLUDED
