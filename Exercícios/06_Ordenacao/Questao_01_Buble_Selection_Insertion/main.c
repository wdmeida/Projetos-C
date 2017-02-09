#include <stdio.h>
#include <stdlib.h>
#include "ordenacao.h"

int main()
{
    TItem itens[10];
    itens[0].chave = 10;
    itens[1].chave = 1;
    itens[2].chave = 54;
    itens[3].chave = 33;
    itens[4].chave = 6;
    itens[5].chave = 23;
    itens[6].chave = 87;
    itens[7].chave = 22;
    itens[8].chave = 3;
    itens[9].chave = 7;


    printf("Itens a ordenar!\n");
    imprime(itens, 10);

    printf("\n\nItens ordenados com bubble sort!\n");
    bubble_sort(itens, 10);
    imprime(itens, 10);

    return 0;
}
