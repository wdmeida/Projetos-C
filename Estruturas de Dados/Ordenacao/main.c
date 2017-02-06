#include <stdio.h>
#include <stdlib.h>
#include "ordenacao.h"

void imprime(int *v, int tamanho){
    int i;
    for(i = 0; i < tamanho; i++)
        printf("%d\t", v[i]);
}

int main()
{
    int v[7] = {23, 4, 67, -8, 90, 54, 21};

    printf("Vetor original: \n\n");
    imprime(v, 7);

    heap_sort(v, 6);

    printf("\n\nVetor Ordenado: \n\n");
    imprime(v, 7);

    return 0;
}
