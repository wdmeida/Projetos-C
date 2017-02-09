#include <stdlib.h>
#include <stdio.h>
#include "tad_fila.h"

Fila cria_fila() {
    Fila f = (Fila) malloc(sizeof(TFila));
    if(!f) return NULL;

    f->pPrimeiro = NULL;
    f->pUltimo = NULL;
    f->tamanho = 0;
    return f;
}//cria_fila()

int tamanho_fila(Fila f) {
    return f->tamanho;
}//tamanho_fila()

int fila_vazia(Fila f) {
    return f->pPrimeiro == NULL;
}//fila_vazia()

int enfileira(Fila f, TElemento e) {
    TNodo *novo = (TNodo*) malloc(sizeof(TNodo));
    if (!novo) return 0;

    novo->elemento = e;
    if(fila_vazia(f)){
        novo->pProximo = f->pUltimo;
        f->pPrimeiro = novo;
    }
    else
    {
        novo->pProximo = f->pUltimo->pProximo;
        f->pUltimo->pProximo = novo;
    }
    f->pUltimo = novo;
    f->tamanho++;
    return 1;
}//enfileira()

int desenfileira(Fila f, TElemento* e) {
    if (fila_vazia(f)) return 0;

    TNodo *retira = f->pPrimeiro;
    *e = retira->elemento;
    f->pPrimeiro = retira->pProximo;
    f->tamanho--;
    if (fila_vazia(f))
        f->pUltimo = f->pPrimeiro;
    return 1;
}//desenfileira()

void imprime(Fila f) {
    TNodo *aux = f->pPrimeiro;

    while (aux != NULL){
        printf("%d\t", aux->elemento.matricula);
        aux = aux->pProximo;
    }
}//imprime()

void libera_memoria_alocada(Fila f) {
    TNodo *aux;

    while (f->pPrimeiro != NULL){
        aux = f->pPrimeiro;
        f->pPrimeiro = f->pPrimeiro->pProximo;
        free(aux);
    }
    free(f);
}//libera_memoria_alocada()
