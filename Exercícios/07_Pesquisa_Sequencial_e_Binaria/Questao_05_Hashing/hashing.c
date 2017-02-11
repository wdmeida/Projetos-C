#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "hashing.h"

/*
    Análise
        Assumindo que qualquer item do conjunto tem igual probabilidade
        de ser endereçãdo para qualquer entrada de T, então o comprimento
        esperado de cada lista encadeada é de N/M onde:
            N representa o número de registro na tabela.
            M representa o tamanho da tabela.

        Logo: as operações Pesquisa, Insere e Retira custam O(1 + N/M)
        operações em média, onde a contante 1 representa o tempo para encontrar
        a tabela e N/M o tempo para percorrer a lista.

        Se os valores forem bem distribuídos (poucas colisões) e N for igual a M,
        teremos que Pesquisa, Inserção e Remoção serão O(1).

    Inicializa a hash. Parametros:
        p = nro de pesos.
        m = tamanho vetor de listas.
*/
void THash_Inicia(THash* hash, int nro_listas, int nro_pesos) {
    int i;
    hash->n = 0;
    hash->nro_listas = nro_listas;
    hash->nro_pesos = nro_pesos;

    //Inicializando as listas.
    hash->v = (TLista*) malloc(sizeof(TLista) * nro_listas);
    for (i = 0; i < nro_listas; i++)
        TLista_Inicia(&hash->v[i]);

    //Inicializando os pesos.
    hash->p = (int*) malloc(sizeof(int) * nro_pesos);
    for (i = 0; i < nro_pesos; i++)
        hash->p[i] = rand() % 100000;
}//THash_Inicia

//Retorna o indice (Número inteiro) de uma chave (string)
int THash_H(THash* hash, TChave chave) {
    int i;
    unsigned int soma = 0;
    int comp = strlen(chave);

    for (i = 0; i < comp; i++)
        soma += (unsigned int) chave[i] * hash->p[i % hash->nro_pesos];

    return (soma % hash->nro_pesos);
}//THash_H


int THash_Pesquisa(THash* hash, TChave chave, TItem *e) {
    TCelula *aux = THash_Pesquisa_Celula(hash, chave);

    if (!aux) return 0;
    *e = aux->pProx->item;
    return 1;
}

//Retorna um ponteiro para a celula ANTERIOR da lista.
TCelula *THash_Pesquisa_Celula(THash* hash, TChave chave) {
    int i = THash_H(hash, chave);
    TCelula *aux;

    if (TLista_EhVazia(&hash->v[i])) return NULL;

    aux = hash->v[i].pPrimeiro;
    while (aux->pProx->pProx != NULL && strcmp(chave, aux->pProx->item.chave) != 0)
        aux = aux->pProx;

    if (!strncmp(chave, aux->pProx->item.chave, sizeof(TChave)))
        return aux;
    else
        return NULL;
}

int THash_Insere(THash* hash, TItem x) {
    if (THash_Pesquisa_Celula(hash, x.chave) == NULL) {
        TLista_Insere(&hash->v[THash_H(hash, x.chave)], x);
        hash->n++;
        return 1;
    }
    return 0;
}

int THash_Remove(THash* hash, TItem* x) {
    TCelula *aux = THash_Pesquisa_Celula(hash, x->chave);

    if (!aux) return 0;
    TLista_Remove(&hash->v[THash_H(hash, x->chave)], aux, x);
    hash->n--;
    return 1;
}

void THash_Termina(THash* hash){
    free(hash->v);
    free(hash->p);
}

//TAD Lista.
void TLista_Inicia(Lista l){
    l->pPrimeiro = NULL;
    l->pUltimo = NULL;
    l->tamanho = 0;
}

int TLista_Insere(Lista l, TItem e){
    TCelula *novo = (TCelula*) malloc(sizeof(TCelula));
    if (!novo) return 0;

    novo->item = e;
    if (l->tamanho == 0){
        novo->pProx = l->pPrimeiro;
        l->pPrimeiro = novo;
    }
    else
    {
        novo->pProx = l->pUltimo->pProx;
        l->pUltimo->pProx = novo;
    }
    l->pUltimo = novo;
    l->tamanho++;
    return 1;

}

//Célula é a referência anterior a célula que será removida..
int TLista_Remove(Lista l, TCelula* celula, TItem* e) {

    if (l->tamanho == 0) return 0;

    if (l->pPrimeiro == celula)
        return (TLista_Remove_Inicio(l, e)) ? 1 : 0;
    else if (l->pUltimo == celula)
            return (TLista_Remove_Final(l, e)) ? 1 : 0;
    else
    {
        *e = celula->pProx->item;
        celula->pProx = celula->pProx->pProx;
        l->tamanho--;
        free(celula);
        return 1;
    }
}

int TLista_Remove_Inicio(Lista l, TItem* e) {
    if (l->tamanho == 0) return 0;

    TCelula *retirar = l->pPrimeiro;
    *e = retirar->item;

    l->pPrimeiro = retirar->pProx;
    l->tamanho--;

    if (l->tamanho == 0)
        l->pUltimo = l->pPrimeiro;

    free(retirar);

    return 1;
}

int TLista_Remove_Final(Lista l, TItem* e){
    if (l->tamanho == 0) return 0;

    TCelula *retirar = l->pUltimo;
    *e = retirar->item;

    if (l->pPrimeiro == l->pUltimo) {
        l->pPrimeiro = retirar->pProx;
        l->pUltimo = retirar->pProx;
    }
    else
    {
        TCelula *aux = l->pPrimeiro;
        while (aux->pProx != l->pUltimo)
            aux = aux->pProx;

        aux->pProx = retirar->pProx;
        l->pUltimo = aux;
    }
    free(retirar);
    l->tamanho--;

    return 1;
}

int TLista_EhVazia(Lista l) {
    return l->tamanho == 0;
}

void TLista_Termina(Lista l) {
    TCelula* aux;
    while (l->pPrimeiro != NULL){
        aux = l->pPrimeiro;
        l->pPrimeiro = l->pPrimeiro->pProx;
        free(aux);
    }
    free(l);
}

