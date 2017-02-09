#include <stdio.h>
#include <stdlib.h>
#include "merge.h"

//Ordena o vetor v[0..n-1]
void merge_sort(TItem* itens, int tamanho) {
    merge_sort_ordena(itens, 0, tamanho - 1);
}//merge_sort()

void merge_sort_ordena(TItem* itens, int esq, int dir) {
    if (esq >= dir) return;

    int meio = (esq + dir) / 2;
    merge_sort_ordena(itens, esq, meio);
    merge_sort_ordena(itens, meio + 1, dir);
    merge_sort_intercala(itens, esq, meio, dir);
    return;
}//merge_sort_ordena()

void merge_sort_intercala(TItem* itens, int esq, int meio, int dir) {
    int i, j, k;
    int a_tam = meio - esq + 1;
    int b_tam = dir - meio;

    TItem *a = (TItem*) malloc(sizeof(TItem) * a_tam);
    TItem *b = (TItem*) malloc(sizeof(TItem) * b_tam);

    for (i = 0; i < a_tam; i++) a[i] = itens[i + esq];
    for (i = 0; i < b_tam; i++) b[i] = itens[i + meio + 1];

    for (i = 0, j = 0, k = esq; k <= dir; k++) {
        if (i == a_tam) itens[k] = b[j++];
        else if (j == b_tam) itens[k] = a[i++];
        else if (a[i].chave < b[j].chave) itens[k] = a[i++];
        else itens[k] = b[j++];
    }
    free(a);
    free(b);
}//merge_sort_intercala()


void merge_sort_iterativo(TItem* itens, int tamanho) {
    int esq, dir;
    int b = 1;

    while (b < tamanho) {
        esq = 0;
        while (esq + b < tamanho) {
            dir = esq + 2 *b;
            if (dir > tamanho) dir = tamanho;
            merge_sort_intercala(itens, esq, esq + b -1, dir - 1);
            esq = esq + 2 * b;
        }
        b *= 2;
    }
}//merge_sort_iterativo()
