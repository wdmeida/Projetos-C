#include <stdio.h>
#include <stdlib.h>
#include "tad_lista.h"

void TLista_cria(TLista* pLista) {
    pLista->primeiro = INICIO;
    pLista->ultimo = pLista->primeiro;
}//TLista_cria()

int TLista_eh_vazia(TLista* pLista) {
    return (pLista->ultimo == pLista->primeiro);
}//Tlista_eh_vazia()

int TLista_insere(TLista* pLista, TItem item) {
    if (pLista->ultimo == MAXTAM) return 0;

    pLista->item[pLista->ultimo++] = item;
    return 1;
}//TLista_insere()

int TLista_retira(TLista* pLista, int pos, TItem* item) {
    if (TLista_eh_vazia(pLista) || pos >= pLista->ultimo || pos < 0) return 0;

    int cont;
    *item = pLista->item[pos];
    pLista->ultimo--;

    //Reorganiza a lista para que os itens adjascentes ocupem a posição que foi removida.
    for(cont = pos + 1; cont <= pLista->ultimo; cont++)
        pLista->item[cont - 1] = pLista->item[cont];
    return 1;
}//TLista_retira()

void TLista_imprime(TLista* pLista) {
    int i;
    for (i = pLista->primeiro; i < pLista->ultimo; i++)
        printf("%d\n", pLista->item[i].chave);
}

int TLista_get(TLista* pLista, int pos, TItem* item) {
    if (TLista_eh_vazia(pLista) || pos >= pLista->ultimo || pos < 0) return 0;

    *item = pLista->item[pos];
    return 1;
}//TLista_get()

int TLista_tamanho(TLista* pLista) {
    return pLista->ultimo;
}//Tlista_tamanho()

//Voltar e otimizar depois.
int TLista_concatena(TLista* l1, TLista* l2, TLista* novaLista) {
    if (TLista_eh_vazia(l1) || TLista_eh_vazia(l2)) return 0;

    if (TLista_tamanho(l1) + TLista_tamanho(l2) > MAXTAM) return 0;

    int i;
    for (i = l1->primeiro; i < l1->ultimo; i++){
        TLista_insere(novaLista, l1->item[i]);
    }

    for (i = 0; i < l2->ultimo; i++) {
        TLista_insere(novaLista, l2->item[i]);
    }

    return 1;
}//TLista_concatena()


int TLista_divide(TLista* l1, TLista* l2) {
    if (TLista_eh_vazia(l1)) return 0;

    //Obtém o meio da lista.
    int i, meio = TLista_tamanho(l1) / 2;
    TItem item;

    for (i = l1->ultimo - 1; i > meio; i--){
        TLista_retira(l1, i, &item);
        TLista_insere(l2, item);
    }

    return 1;
}//TLista_divive()

int TLista_copia(TLista* l1, TLista* l2){
    if(TLista_eh_vazia(l1)) return 0;

    int i;
    TItem item;

    for (i = 0; i < l1->ultimo; i++)
        TLista_insere(l2, l1->item[i]);

    return 1;
}//TLista_copia()

int TLista_pesquisa(TLista* l, TItem item) {
    int i;

    for (i = 0; i < l->ultimo; i++)
        if (l->item[i].chave == item.chave)
            return 1;
    return 0;
}//TLista_pesquisa()
