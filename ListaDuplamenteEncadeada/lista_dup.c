#include <stdlib.h>
#include <stdio.h>
#include "lista_dup.h"

Lista cria_lista() {
    Lista l = (Lista) malloc(sizeof(TLista));

    if (!l) return NULL;

    l->pPrimeiro = NULL;
    l->pUltimo = NULL;
    l->tamanho = 0;
    return l;
}//cria_lista()

//Inserir
int inserir_lista_vazia(Lista l, Elemento e) {

    TNodo novo = (TNodo*) malloc(sizeof(TNodo));

    if(!novo) return 0;

    novo->elemento = e;
    novo->pAnterior = l->pPrimeiro;
    novo->pProximo = l->pUltimo;
    l->pPrimeiro = novo;
    l->pUltimo = novo;
    l->tamanho++;

    return 1;
}

int inserir_lista_inicio(Lista l, Elemento e) {
    TNodo *novo = (TNodo*) malloc(sizeof(TNodo));

    if (!novo) return 0;

    novo->elemento = e;
    novo->pAnterior = NULL;
    novo->pProximo = l->pPrimeiro;
    l->pPrimeiro->pAnterior = novo;
    l->pPrimeiro = novo;
    l->tamanho++;
    return 1;
}


int inserir_lista_final(Lista l, Elemento e) {
    TNodo *novo = (TNodo*) malloc(sizeof(TNodo));

    if (!novo) return 0;

    novo->elemento = e;
    novo->pProximo = NULL;
    novo->pAnterior = l->pUltimo;
    l->pUltimo->pProximo = novo;
    l->pUltimo = novo;
    l->tamanho++;
    return 1;
}

int inserir_lista_antes(Lista l, Elemento e, int pos) {
    TNodo *atual,
          *novo = (TNodo*) malloc(sizeof(TNodo));

    if (!novo) return 0;

    novo->elemento = e;

    atual = l->pPrimeiro;

    int i;

    for(i = 1; i < pos; ++i) atual = atual->pProximo;

    novo->pProximo = atual;
    novo->pAnterior = atual->pAnterior;

    if (atual->pAnterior == NULL)
        l->pPrimeiro = novo;
    else
        atual->pAnterior->pProximo = novo;

    atual->pAnterior = novo;
    l->tamanho++;

    return 1;
}

int inserir_lista_apos(Lista l, Elemento e, int pos) {
    int i;

    TNodo *atual,
          *novo = (TNodo*) malloc(sizeof(TNodo));

    if (!novo) return 0;

    novo->elemento = e;

    atual = l->pPrimeiro;

    for(i = 1; i < pos; ++i) atual = atual->pProximo;

    novo->pProximo = atual->pProximo;
    novo->pAnterior = atual;

    if(atual->pProximo == NULL)
        l->pUltimo = novo;
    else
        atual->pProximo->pAnterior = novo;
    atual->pProximo = novo;
    l->tamanho++;

    return 1;
}

//Remover
int remove_lista(Lista l, Elemento e, int pos) {
    int i;
    TNodo *atual, *remover;

    if (l->tamanho == 0) return ;

    /* Remoção na primeira posição; */
    if (pos == 1)
    {
        remover = l->pPrimeiro;
        l->pPrimeiro = l->pPrimeiro->pProximo;

        if (l->pPrimeiro == NULL) l->pUltimo = NULL;
        else l->pPrimeiro->pAnterior = NULL;
    }
    else if(pos == l->tamanho) //Remoção na última posição.
    {
        remover = l->pUltimo;
        l->pUltimo->pAnterior->pProximo = NULL;
        l->pUltimo = l->pUltimo->pAnterior;
    }
    else //Remoção em qualquer posição.
    {
        atual = l->pPrimeiro;

        //Desloca até a posição que será removida
        for(i = 1; i < pos; ++i) atual = atual->pProximo;

        remover = atual;
        atual->pAnterior->pProximo = atual->pProximo;
        atual->pProximo->pAnterior = atual->pAnterior;
    }
    (*e) = remover->elemento;

    free(remover);
    l->tamanho--;
    return 1;
}

void termina_lista(Lista l) {
    TNodo *aux = l->pPrimeiro;

    while(aux != NULL) {
        l->pPrimeiro = aux->pProximo;
        free(aux);
        aux = l->pPrimeiro;
    }
    free(l);
}//termina_lista()
