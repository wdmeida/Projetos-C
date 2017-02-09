#include <stdlib.h>
#include <stdio.h>
#include "ordenacao.h"

//Bubble Sort

void bubble_sort(TItem* itens, int tamanho) {
    int i, j, comparacoes = 0, movimentacoes = 0;
    TItem aux;

    //Faz percorrer várias vezes.
    for(i = 0; i < tamanho - 1; i++) {
        //Responsável pelas comparações.
        for(j = 1; j < tamanho; j++) {
            if(itens[j].chave < itens[j - 1].chave) {
                comparacoes++;
                movimentacoes++;
                aux = itens[j];
                itens[j] = itens[j - 1];
                itens[j - 1] = aux;
            }
        }
    }
    printf("\n\n -Bubble.......: C%d | M%d\n", comparacoes, movimentacoes);
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


//Selection Sort
void selection_sort(TItem* itens, int tamanho) {
    int i, j, menor, comparacoes = 0, movimentacoes = 0;
    TItem aux;

    for (i = 0; i < tamanho - 1; i++){
        menor = i;
        for (j = i + 1; j < tamanho; j++) {
            if (itens[j].chave < itens[menor].chave)
            {
                comparacoes++;
                menor = j;
            }
        }
        //Caso seja diferente, signigica que houve troca.
        if (menor != i) {
            aux = itens[menor];
            itens[menor] = itens[i];
            itens[i] = aux;
            movimentacoes++;
        }
    }
    printf("\n\n -Selection...: C%d | M%d\n", comparacoes, movimentacoes);
}//selection_sort()


//Insertion Sort
void insertion_sort(TItem* itens, int tamanho) {
    int i, j, comparacoes = 0, movimentacoes = 0;
    TItem aux;

    for (i = 1; i < tamanho; i++) {
        aux = itens[i];
        j = i - 1;

        while (j >= 0 && aux.chave < itens[j].chave) {
            itens[j + 1] = itens[j];
            j--;
            comparacoes++;
            movimentacoes++;
        }
        itens[j + 1] = aux;
    }

    printf("\n\n -Inserction...: C%d | M%d\n", comparacoes, movimentacoes);
}//insertion_sort()


void imprime(TItem* itens, int tamanho) {
    int i;

    for (i = 0; i < tamanho; i++) {
        printf("%d\t", itens[i].chave);
    }
}//imprime()
