#include <stdlib.h>
#include <stdio.h>
#include "quick_sort.h"

//Pilha auxiliar, criada no mesmo arquivo apenas para fins didádicos.
Pilha cria_pilha() {
    Pilha p = (Pilha) malloc(sizeof(TPilha));
    if (!p) return NULL;

    p->pFundo = NULL;
    p->pTopo = NULL;
    p->tamanho = 0;

    return p;
}

int push(Pilha p, int e) {
    TNodo *novo = (TNodo*) malloc(sizeof(TNodo));
    if (!novo) return 0;

    novo->elemento = e;
    novo->pProximo = p->pTopo;

    if (pilha_vazia(p)) p->pFundo = novo;

    p->pTopo = novo;
    p->tamanho++;

    return 1;
}

int pop(Pilha p, int* e){
    if (pilha_vazia(p)) return 0;

    TNodo *retira = p->pTopo;
    (*e) = retira->elemento;

    p->pTopo = retira->pProximo;
    p->tamanho--;
    if (pilha_vazia(p)) p->pFundo = p->pTopo;
    free(retira);
    return 1;
}

int pilha_vazia(Pilha p){
    return p->tamanho == 0;
}

int tamanho_pilha(Pilha p){
    return p->tamanho;
}

void libera_memoria(Pilha p){
    TNodo *aux;
    while(p->pTopo != NULL){
        aux = p->pTopo;
        p->pTopo = p->pTopo->pProximo;
        free(aux);
    }
    free(p);
}



void quick_sort(TItem* v, int tamanho) {
    quick_sort_ordena(v, 0, tamanho - 1);
}//quick_sort()

void quick_sort_ordena(TItem* v, int esq, int dir) {
    int i, j;
    quick_sort_particao(v, esq, dir, &i, &j);
    if (esq < j) quick_sort_ordena(v, esq, j);
    if (i < dir) quick_sort_ordena(v, i, dir);
}//quick_sort_ordena()

void quick_sort_particao(TItem* v, int esq, int dir, int* i, int* j) {
    TItem pivo, aux;
    *i = esq;
    *j = dir;
    //Obtém o pivo.
    pivo = v[(*i + *j) / 2];
    do {
        while (!(pivo.chave <= v[*i].chave)) (*i)++;
        while (pivo.chave < v[*j].chave) (*j)--;

        if (*i <= *j) {
            aux = v[*i];
            v[*i] = v[*j];
            v[*j] = aux;
            (*i)++;
            (*j)++;
        }
    } while (*i <= *j);
}//quick_sort_particao()


void quick_sort_iterativo(TItem* v, int tamanho) {
    Pilha pilha_dir, pilha_esq;
    int esq, dir, i, j;

    //Aloca mémória para as pilhas auxiliares que será utilizadas.
    pilha_dir = cria_pilha();
    pilha_esq = cria_pilha();
    esq = 0;
    dir = tamanho - 1;

    push(pilha_dir, dir);
    push(pilha_esq, esq);

    do {
        if (dir > esq) {
            quick_sort_particao(v, esq, dir, &i, &j);
            push(pilha_dir, j);
            push(pilha_esq, esq);
            esq = i;
        }
        else
        {
            pop(pilha_dir, &dir);
            pop(pilha_esq, &esq);
        }
    } while (!pilha_vazia(pilha_dir));

}//quick_sort_iterativo()
