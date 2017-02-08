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

int push(Pilha p, TElemento e) {

    TNodo *novo = (TNodo*) malloc(sizeof(TNodo));
    if(!novo) return 0;

    novo->elemento = e;
    novo->pProximo = p->pTopo;
    p->pTopo = novo;

    if (pilha_vazia(p))
        p->pFundo = novo;

    p->tamanho++;
    return 1;
}//push()

int pop(Pilha p, TElemento* e) {
    if (pilha_vazia(p)) return 0;

    TNodo *retira = p->pTopo;
    *e = retira->elemento;
    p->pTopo = retira->pProximo;
    p->tamanho--;

    if(pilha_vazia(p))
        p->pFundo = p->pTopo;

    free(retira);
    return 1;
}//pop()

int peek(Pilha p, TElemento* e) {
    if (pilha_vazia(p)) return 0;
    *e = p->pTopo->elemento;
    return 1;
}//peek()

void imprime(Pilha p){
    TNodo *aux = p->pTopo;

    while(aux != NULL){
        printf("%c", aux->elemento.chave);
        aux = aux->pProximo;
    }
}//imprime()

void libera_memoria_alocada(Pilha p){
    TNodo *aux;

    while(p->pTopo != NULL) {
        aux = p->pTopo;
        p->pTopo = p->pTopo->pProximo;
        free(aux);
    }
    free(p);
}//libera_memoria_alocada()
