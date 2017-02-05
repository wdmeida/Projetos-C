#include <stdlib.h>
#include <stdio.h>
#include "ordenacao.h"

//Compara elementos adjacentes e os troca de lugar se
//estiverem na ordem errada.

/*
    Melhor Caso: O(N)
    Pior Caso: O(N^2)
    Não recomendado para grande conjunto de dados.
*/
void bubble_sort(int *v, int tamanho) {
    int i, continua, aux, fim = tamanho;

    do {
        continua = 0;

        for (i = 0; i < fim - 1; i++) {
            if(v[i] > v[i+1]){
                aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                continua = i;
            }
        }
        fim--;

    } while(continua != 0);
}//bubble_sort()


//Similar a ordenação de cartas de baralho com as mãos.
//Pega-se uma carta de cada vez e a coloca em seu devido lugar.

/*
    Melhor caso: O(N)
    Pior caso: O(N^2)
    Eficiente para conjuntos pequenos de dados.
    Estável: Não altera a ordem de dados iguais.
    Capaz de ordenar os dados a medida em que os recebe (tempo real).
*/
void insection_sort(int *v, int tamanho) {
    int i, j, aux;

    for (i = 1; i < tamanho; i++) {
        aux = V[i];

        for (j = i; (j > 0) && (aux < v[j - 1]); j--)
            v[j] = v[j - 1];
        v[j] = aux;
    }
}//inserction_sort()


//A cada passo, procura o menor valor do array e o coloca na primeira posição.
//Descarta-se a primeira posição do array e repete-se o processo para a segunda posição.

/*
    Melhor caso: O(N^2)
    Pior caso: O(N^2)
    Ineficiente para grandes conjuntos de dados.
    Instável: Altera a ordem de dados iguais (pode ser modificado para ser estável).
*/
void selection_sort(int *v, int tamanho) {
    int i, j, menor, troca;

    for (i = 0; i < tamanho - 1; i++) {
        menor = i;

        //Procura o menor elemento em relação a "i".
        for(j = i + 1; j < tamanho; j++) {
            if (v[j] < v[menor])
                menor = j;
        }

        //Troca os valore da posição autal com a "menor".
        if (i != menor) {
            troca = v[i];
            v[i] = v[menor];
            v[menor] = troca;
        }
    }
}//selection_sort()
