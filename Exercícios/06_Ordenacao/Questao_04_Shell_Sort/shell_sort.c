#include <stdio.h>
#include <stdlib.h>
#include "shell_sort.h"

/*
    Vantagens:
        Shellsort é uma ótima opção para arquivos de tamanho moderado.
        Sua implementação é simples e requer uma quantidade de código pequena.

    Desvantagens:
        O tempo de execução do algoritmo é sensível à ordem inicial do arquivo.
        O método não é estável.
*/
void shell_sort(TItem* v, int tamanho){
    int i, j, h;
    TItem aux;

    //Gera a sequencia inicial.
    for (h = 1; h < tamanho; h = 3 * h + 1);

    do {

        h = (h - 1) / 3; //Atualiza o valor de h.
        for (i = h; i < tamanho; i++) {
            aux = v[i];
            j = i;

            //Compara os elementos com a distância h.
            while (v[j - h].chave > aux.chave) {
                v[j] = v[j - h];
                j -= h;
                if (j < h) break;
            }
            v[j] = aux;
        }
    } while (h != 1);

}//shell_sort()
