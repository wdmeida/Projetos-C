#include <stdio.h>
#include <stdlib.h>
#include "tad_pilha.h"

Pilha cria_pilha() {
    Pilha p = (Pilha) malloc(sizeof(TPilha));
    if (!p) return NULL;

    p->pTopo = NULL;
    p->pFundo = NULL;
    p->tamanho = 0;
    return p;
}//cria_pilha()

int pilha_vazia(Pilha p){
    return p->tamanho == 0;
}//pilha_vazia()

int tamanho_pilha(Pilha p) {
    return p->tamanho;
}//tamanho_pilha()

int push(Pilha, TElemento);
int pop(Pilha, TElemento);
int peek(Pilha, TElemento);

void libera_memoria_alocada(Pilha p){
    TNodo *aux;

    while(p->pTopo != NULL) {
        aux = p->pTopo;
        p->pTopo = p->pTopo->pProximo;
        free(aux);
    }
    free(p);
}//libera_memoria_alocada()
