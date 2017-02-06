#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef struct{
    int elemento;
}tipo_elemento;

typedef struct nodo{
    tipo_elemento elemento;
    struct nodo *proximo;
}tipo_nodo;

typedef struct{
    int tamanho;
    tipo_nodo *topo;
}tipo_pilha;

typedef tipo_pilha *Pilha;

Pilha cria_pilha();
int push(Pilha, tipo_elemento);
int pop(Pilha, tipo_elemento*);
int peek(Pilha, tipo_elemento*);
int pilha_vazia(Pilha);
int tamanho_pilha(Pilha);

void termina_pilha(Pilha);

#endif // STACK_H_INCLUDED
