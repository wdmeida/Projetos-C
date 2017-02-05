#include <stdlib.h>
#include <stdio.h>
#include "arvore_binaria.h"

Arvore cria_arvore(){
    return NULL;
}

int insere_recursivo(Arvore *arvore, Elemento e) {
    //Verifica se é a primeira inserção na árvore.
    if(!*arvore) {

        (*arvore) = (Arvore) malloc(sizeof(TNodo));
        (*arvore)->pEsquerda = NULL;
        (*arvore)->pDireita = NULL;
        (*arvore)->info = e;

        return 1;
    }
    else
    {
        //Verifica a posição da chave. Caso seja menor que a raiz, insere o valor
        //na árvore da esquerda, caso contrário, insere na árvore da direita.
        if(e.chave < (*arvore)->info.chave)
            return insere_recursivo(&(*arvore)->pEsquerda, e);
        else if(e.chave > (*arvore)->info.chave)
            return insere_recursivo(&(*arvore)->pDireita, e);
        else return 0;
    }
}//insere_recursivo()

int insere_sem_recursao(Arvore *arvore, Elemento e) {
    Arvore *aux = arvore;

    while (*aux){
        if((*aux)->info.chave > e.chave)
            aux = (&(*aux)->pEsquerda);
        else if((*aux)->info.chave < e.chave)
            aux = (&(*aux)->pDireita);
        else
            return 0;
    }

    (*aux) = (Arvore) malloc(sizeof(TNodo));
    (*aux)->pDireita = NULL;
    (*aux)->pEsquerda = NULL;
    (*aux)->info = e;

    return 1;
}//insere_sem_recursao()


int remover_recursivo(Arvore*, Elemento*);

int remover_sem_recursao(Arvore* arvore, Elemento* e) {
    Arvore *percorre, *aux;
    percorre = arvore;

    while(*percorre){
        if (e->chave > (*percorre)->info.chave)
            percorre = &(*percorre)->pDireita;
        else if (e->chave < (*percorre))
            percorre = &(*percorre)->pEsquerda;
        else
        {

            aux = &(*percorre);

            if (!(*percorre)->pDireita)
                *percorre = (*percorre)->pEsquerda;
            else if (!(*percorre)->pEsquerda)
                *percorre = (*percorre)->pDireita;
            else
            {
                percorre = &(*aux)->pEsquerda;
                while((*percorre)->pDireita){
                    percorre = &(*percorre)->pDireita;
                }
                (*aux)->info = (*percorre)->info;
                *aux = *p;
                *percorre = (*percorre)->pEsquerda;
            }
            free(aux);
        }else
            return 0;
    }

    return 1;
}//remover_sem_recursao()


int altura_arvore(Arvore arvore) {
    if(!arvore) return -1;

    int arv_esq = altura_arvore(arvore->pEsquerda),
        arv_dir = altura_arvore(arvore->pDireita);

    return arv_esq < arv_dir ? arv_dir + 1 : arv_esq + 1;
}//altura_arvore()


int eh_vazia(Arvore arvore){
    return arvore == NULL;
}//eh_vazia()

int quantidade_nos(Arvore arvore) {
    return !arvore ? 0 : (1 + quantidade_nos(arvore->pEsquerda) + quantidade_nos(arvore->pDireita));
}

void in_ordem(Arvore arvore) {
    if(arvore) {
        in_ordem(arvore->pEsquerda);
        printf("\n\t%d\n", arvore->info.chave);
        in_ordem(arvore->pDireita);
    }
}//in_ordem()

void pos_ordem(Arvore arvore) {
    if(arvore) {
        pos_ordem(arvore->pEsquerda);
        pos_ordem(arvore->pDireita);
        printf("\n\t%d\n", arvore->info.chave);
    }
}//pos_ordem()

void pre_ordem(Arvore arvore) {
    if(arvore) {
        printf("\n\t%d\n", arvore->info.chave);
        pre_ordem(arvore->pEsquerda);
        pre_ordem(arvore->pDireita);
    }
}//pre_ordem()

void libera_memoria_arvore(Arvore arvore){
    if(arvore){
        libera_memoria_arvore(arvore->pEsquerda);
        libera_memoria_arvore(arvore->pDireita);
        free(arvore);
    }
}

int procura_recursivo(Arvore arvore, Elemento *e, int chave) {
    if(!arvore) return 0;

    if(arvore->info.chave == chave){
        (*e) = arvore->info;
        return 1;
    }

    return chave < arvore->info.chave ?
               procura_recursivo(arvore->pEsquerda, e, chave) :
               procura_recursivo(arvore->pDireita, e, chave);
}//procura_recursivo()

int procura_sem_recursao(Arvore arvore, Elemento *e, int chave) { return 0; }//procura_sem_recursao()
