#include <stdlib.h>
#include <stdlib.h>
#include "tad_lista_encadeada.h"

Lista nova_lista() {
    Lista l = (Lista) malloc(sizeof(TLista));

    if(!l) return NULL;
    l->pPrimeiro = NULL;
    l->pUltimo = NULL;
    l->tamanho = 0;
    return l;
}//nova_lista()

int lista_vazia(Lista l) {
    return l->tamanho == 0;
}//lista_vazia()

int tamanho_lista(Lista l) {
    return l->tamanho;
}//tamanho_lista()

int insere_inicio(Lista l, TElemento e) {

    TNodo *novo = (TNodo*) malloc(sizeof(TNodo));

    if (!novo) return NULL;

    novo->elemento = e;
    novo->pProximo = l->pPrimeiro;

    if(lista_vazia(l))
        l->pUltimo = novo;
    l->pPrimeiro = novo;
    l->tamanho++;

    return 1;
}//insere_inicio()

int insere_final(Lista l, TElemento e) {
    TNodo *novo = (TNodo*) malloc(sizeof(TNodo));

    if (!novo) return 0;

    novo->elemento = e;
    novo->pProximo = NULL;

    if (lista_vazia(l))
        l->pPrimeiro = novo;
    else
        l->pUltimo->pProximo = novo;

    l->pUltimo = novo;
    l->tamanho++;
    return 1;
}//insere_final()

int insere_posicao(Lista l, int pos, TElemento e);

int remove_inicio(Lista l, TElemento* e) {

    if (lista_vazia(l)) return 0;

    TNodo *retirar = l->pPrimeiro;
    *e = retirar->elemento;

    l->pPrimeiro = retirar->pProximo;
    l->tamanho--;

    if (lista_vazia(l))
        l->pUltimo = l->pPrimeiro;

    free(retirar);

    return 1;
}//remove_inicio()

int remove_final(Lista l, TElemento* e) {
    if (lista_vazia(l)) return 0;

    TNodo *retirar = l->pUltimo;
    *e = retirar->elemento;

    if (l->pPrimeiro == l->pUltimo) {
        l->pPrimeiro = retirar->pProximo;
        l->pUltimo = retirar->pProximo;
    }
    else
    {
        TNodo *aux = l->pPrimeiro;
        while (aux->pProximo != l->pUltimo){
            aux = aux->pProximo;
        }
        aux->pProximo = retirar->pProximo;
        l->pUltimo = aux;
    }
    free(retirar);
    l->tamanho--;

    return 1;
}//remove_final()

int remove_posicao(Lista l, int pos, TElemento* e);

void imprime(Lista l) {
    TNodo* aux;
    aux = l->pPrimeiro;

    while(aux != NULL){
        printf("%d\t", aux->elemento.chave);
        aux = aux->pProximo;
    }
}//imprime()

void libera_memoria_lista(Lista l) {
    TNodo* aux;
    aux = l->pPrimeiro;

    while(aux != NULL){
        l->pPrimeiro = aux->pProximo;
        free(aux);
        aux = l->pPrimeiro;
    }
    free(l);
}//libera_memoria_lista()
