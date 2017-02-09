#include <stdlib.h>
#include <stdio.h>
#include "ordenacao.h"

void bubble_sort(TItem* itens, int tamanho) {
    int i, j;
    TItem aux;

    //Faz percorrer várias vezes.
    for(i = 0; i < tamanho - 1; i++) {
        //Responsável pelas comparações.
        for(j = 1; j < tamanho; j++) {
            if(itens[j].chave < itens[j - 1].chave) {
                aux = itens[j];
                itens[j] = itens[j - 1];
                itens[j - 1] = aux;
            }
        }
    }
}//bubble_sort()


void bubble_sort_melhorado(TItem* itens, int tamanho) {
    int i, j, troca;
    TItem aux;

    for(i = 0; i < tamanho - 1; i++) {
        troca = 0;
        for(j = 1; j < tamanho; j++) {
            if(itens[j].chave < itens[j - 1].chave) {
                aux = itens[j];
                itens[j] = itens[j - 1];
                itens[j - 1] = aux;
                troca++;
            }
        }
        //Utiliza um flag para interromper o algoritmo quando não existirem
        //mais trocas.
        if (troca == 0) break;
    }
}//bubble_sort_melhorado()



void imprime(TItem* itens, int tamanho) {
    int i;

    for (i = 0; i < tamanho; i++) {
        printf("%d\t", itens[i].chave);
    }
}//imprime()
