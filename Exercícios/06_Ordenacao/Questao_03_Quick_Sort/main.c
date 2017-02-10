#include <stdio.h>
#include <stdlib.h>
#include "quick_sort.h"

int main()
{
    TItem itens[6];

    itens[0].chave = 100;
    itens[1].chave = 300;
    itens[2].chave = 600;
    itens[3].chave = 30;
    itens[4].chave = 10;
    itens[5].chave = 223;

    printf("Array de teste:\n");
    int i;
    for(i = 0; i < 6; i++)
        printf("%d\t", itens[i].chave);

    quick_sort_iterativo(itens, 6);

    printf("\n\nOrdenado com Quick Sort:\n");
    for(i = 0; i < 6; i++)
        printf("%d\t", itens[i].chave);
    return 0;
}
