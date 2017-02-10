#include <stdlib.h>
#include <stdio.h>
#include "dicionario.h"

/*
    Análise:
        Pesquisa com sucesso:
            Melhor caso: C(n) = 1
            Pior caso: C(n) = n
            Caso médio: C(n) = (n + 1) / 2
        Pesquisa sem sucesso:
            C(n) = n + 1
*/
void TDicionario_Inico(TDicionario* dict) {
    dict->tamanho = 0;
    dict->maximo = 10;
    dict->v = (TItem*) malloc(sizeof(TItem) * dict->maximo);
}

int TDicionario_Find(TDicionario* dict, TChave c) {
    int i;
    for (i = dict->maximo - 1; i >= 0; i--)
        if (dict->v[i].Chave == c)
            return i;

    return -1;
}

void TDicionario_Insere(TDicionario* dict, TItem e){
    if (dict->tamanho == dict->maximo) {
        dict->maximo *= 2;
        dict->v = (TItem*) realloc(dict->v, sizeof(TItem) * dict->maximo);
    }

    dict->v[dict->tamanho++] = e;
}

TItem TDicionario_get(TDicionario* dict, int indice) {
    if (indice >= 0 && indice < dict->tamanho) return dict->v[indice];
}
