#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

Pilha cria_pilha() {
    Pilha p;

    //Aloca memória para a pilha criada.
    p = (Pilha) malloc(sizeof(tipo_pilha));

    //Verifica se a memória foi alocada corretamente.
    if (!p) return NULL;

    //Seta os valores default.
    p->tamanho = 0;
    p->topo = NULL;
    return p;
}//cria_pilha

int push(Pilha p, tipo_elemento e) {
    //Aloca memória para um novo nodo que será inserido.
    tipo_nodo *novo;
    novo = (tipo_nodo*) malloc(sizeof(tipo_nodo));

    if(!novo) return 0;

    novo->elemento = e;
    novo->proximo = p->topo;
    p->topo = novo;
    p->tamanho++;
    return 1;
}//push

int pop(Pilha p, tipo_elemento *e){
    tipo_nodo *remover;

    if(pilha_vazia(p)) return 0;

    remover = p->topo;
    p->topo = remover->proximo;
    (*e) = remover->elemento;
    free(remover);
    p->tamanho--;
    return 1;
}//pop

int peek(Pilha p, tipo_elemento* e) {
    if(pilha_vazia(p)) return 0;

    (*e) = p->topo->elemento;
    return 1;
}//peek


int pilha_vazia(Pilha p) {
    return p->tamanho == 0;
}//pilha_vazia

int tamanho_pilha(Pilha p) {
    return p->tamanho;
}//tamanho_pilha

void termina_pilha(Pilha p) {
    tipo_nodo *aux;

    while (p->topo != NULL) {
        aux = p->topo;
        p->topo = p->topo->proximo;
        free(aux);
    }
    free(p);
}//terminha_pilha
