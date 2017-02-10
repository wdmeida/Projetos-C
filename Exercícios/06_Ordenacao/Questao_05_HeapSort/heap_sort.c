#include <stdio.h>
#include <stdlib.h>
#include "heap_sort.h"

void heap_refaz(TItem* v, int esq, int dir) {
    int i = esq;
    int j = i * 2 + 1; //primeiro filho de i.

    TItem aux = v[i]; //No i, pai de j.

    while (j <= dir) {
        //Verifica qual dos dois filhos é maior.
        if (j < dir && v[j].chave < v[j+1].chave)
            j++; //Recebe o outro filho de i.
        if (aux.chave >= v[j].chave) //Verifica se o pai é maior que o filho.
            break; //heap foi refeito corretamente.
        v[i] = v[j];
        i = j;
        j = i * 2 + 1; //primeiro filho de i.
    }
    v[i] = aux;
}//heap_refaz()

void heap_constroi(TItem* v, int tamanho) {
    int esq;
    esq = (tamanho / 2) - 1;//Nó anterior ao primeiro nó folha do heap.
    while (esq >= 0) {
        heap_refaz(v, esq, tamanho - 1);
        esq--;
    }
}//heap_constroi()

void heap_sort(TItem* v, int tamanho) {
    TItem aux;
    heap_constroi(v, tamanho);
    while(tamanho > 1) {
        aux = v[tamanho - 1];
        v[tamanho - 1] = v[0];
        v[0] = aux;
        tamanho--;
        heap_refaz(v, 0, tamanho - 1);
    }
}//heap_sort()
