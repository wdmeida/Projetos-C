#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Fila cria_fila(){
    Fila f = (Fila) malloc(sizeof(tipo_fila));

    if(!f) return NULL;

    f->tamanho = 0;
    f->fim = NULL;
    f->inicio = NULL;

    return f;
}//cria_fila()

int tamanho_fila(Fila f){
    return f->tamanho;
}//tamanho_fila()

int fila_vazia(Fila f){
    return f->tamanho == 0;
}//fila_vazia()

int enfileira(Fila f, tipo_elemento e){
    tipo_nodo *novo = (tipo_nodo*) malloc(sizeof(tipo_nodo));

    if(!novo) return 0;

    novo->elemento = e;
    novo->proximo = NULL;

    if (fila_vazia(f))
    {
        f->inicio = novo;
    }
    else
    {
        f->fim->proximo = novo;
    }//if

    f->fim = novo;
    f->tamanho++;

    return 1;
}//enfileira()

int desenfileira(Fila f, tipo_elemento* e){
    if(fila_vazia(f)) return 0;

    tipo_nodo *retira = f->inicio;

    (*e) = retira->elemento;
    f->inicio = retira->proximo;
    f->tamanho--;

    if (fila_vazia(f))
    {
        f->fim = retira->proximo;
    }

    free(retira);

    return 1;
}//desenfileira()

void destroi(Fila f){
    tipo_nodo *aux;

    while(f->inicio != NULL){
        aux = f->inicio;
        f->inicio = f->inicio->proximo;
        free(aux);
    }
    free(f);
}//destroi

void imprime(Fila f){
    tipo_nodo *aux = f->inicio;

    while(aux != NULL){
        printf("\nChave = %d", aux->elemento.chave);
        aux = aux->proximo;
    }
}
