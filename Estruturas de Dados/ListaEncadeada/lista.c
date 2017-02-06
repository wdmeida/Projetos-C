#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

Lista cria_lista() {
    //Aloca memória para a lista.
    Lista l = (Lista) malloc(sizeof(TLista));

    if (!l) return NULL;

    //Seta os valores default.
    l->pPrimeiro = NULL;
    l->pUltimo = NULL;
    l->tamanho = 0;

    return l;
}//cria_lista()

int tamanho(Lista l) {
    return l->tamanho;
}//tamanho()

int eh_vazia(Lista l) {
    return l->tamanho == 0;
}//eh_vazia()

int insere_inicio(Lista l, TItem e) {
    //Aloca memória para a nova célula e verifica se a mesma foi alocada com sucesso.
    TCelula *novo = (TCelula*) malloc(sizeof(TCelula));

    if (!novo) return 0;

    //Seta o item a ser inserido.
    novo->item = e;

    //Caso seja uma lista vazia, faz com a cabeça que indica fim da lista aponte para o novo elemento.
    if (eh_vazia(l)) {
        l->pUltimo = novo;
    }

    novo->pProx = l->pPrimeiro;
    l->pPrimeiro = novo;

    l->tamanho++;

    return 1;

}//insere_inicio()

int insere_final(Lista l, TItem e) {

    TCelula *novo = (TCelula*) malloc(sizeof(TCelula));

    if (!novo) return 0;

    novo->item = e;
    novo->pProx = NULL;

    if (eh_vazia(l)) l->pPrimeiro = novo;

    l->pUltimo->pProx = novo;
    l->pUltimo = novo;
    l->tamanho++;

    return 1;
}//insere_final

int insere_posicao(Lista l, TItem e, int pos) {
    if (pos > l->tamanho) return 0;

    int contador = 1;

    TCelula *atual = l->pPrimeiro,
            *anterior;

    TCelula *novo = (TCelula*) malloc(sizeof(TCelula));

    if (!novo) return 0;

    novo->item = e;

    while(contador < pos){
        anterior = atual;
        atual = atual->pProx;
        contador++;
    }

    novo->pProx = anterior->pProx;
    anterior->pProx = novo;
    l->tamanho++;

    return 1;
}//insere_posicao()

int remove_inicio(Lista l, TItem* e){

    if (eh_vazia(l)) return 0;

    TCelula *retira = l->pPrimeiro;
    (*e) = retira->item;

    l->pPrimeiro = retira->pProx;
    l->tamanho--;

    if (eh_vazia(l)) l->pUltimo = l->pPrimeiro;

    free(retira);

    return 1;
}//remove_inicio()

int remove_final(Lista l, TItem* e) {

    if (eh_vazia(l)) return 0;

    TCelula *ultimo = l->pPrimeiro->pProx,
            *penultimo = l->pPrimeiro;

    while(ultimo->pProx != NULL){
        penultimo = ultimo;
        ultimo = ultimo->pProx;
    }

    (*e) = ultimo->item;
    penultimo->pProx = NULL;
    l->pUltimo = penultimo;
    l->tamanho--;
    free(ultimo);

    if(eh_vazia(l)) l->pPrimeiro = NULL;

    return 1;
}//remove_final()

int remove_posicao(Lista l, TItem* e, int pos) {

    //Verifica se a posição é válida.
    if (pos > l->tamanho || eh_vazia(l)) return 0;

    int contador = 1;

    TCelula *atual = l->pPrimeiro,
            *anterior;

    while(contador < pos) {
        anterior = atual;
        atual = atual->pProx;
        contador++;
    }

    anterior->pProx = atual->pProx;
    (*e) = atual->item;
    free(atual);
    l->tamanho--;
    return 1;
}//remove_posicao()

void imprime(Lista l) {
    TCelula *aux = l->pPrimeiro;
    int cont = 1;
    while (aux != NULL) {
        printf("\nElemento %d da lista: %d", cont, aux->item.chave);
        aux = aux->pProx;
        cont++;
    }
}//imprime()

void libera_memoria(Lista l) {
    TCelula *aux;

    aux = l->pPrimeiro;

    while(aux != NULL) {
        l->pPrimeiro = aux->pProx;
        free(aux);
        aux = l->pPrimeiro;
    }
    free(l);
}//libera_memoria()
