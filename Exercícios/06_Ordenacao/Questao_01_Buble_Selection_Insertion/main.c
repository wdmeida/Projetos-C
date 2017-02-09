#include <stdio.h>
#include <stdlib.h>
#include "ordenacao.h"

int main()
{
    printf("\n\nVetor 1:\n\n");
    TItem itens[10];
    itens[0].chave = 1;
    itens[1].chave = 2;
    itens[2].chave = 3;
    itens[3].chave = 4;
    itens[4].chave = 5;
    itens[5].chave = 6;
    itens[6].chave = 7;
    itens[7].chave = 8;
    itens[8].chave = 9;
    itens[9].chave = 10;


    printf("-Vetor Original:\n");
    imprime(itens, 10);

    bubble_sort(itens, 10);
    imprime(itens, 10);

    itens[0].chave = 1;
    itens[1].chave = 2;
    itens[2].chave = 3;
    itens[3].chave = 4;
    itens[4].chave = 5;
    itens[5].chave = 6;
    itens[6].chave = 7;
    itens[7].chave = 8;
    itens[8].chave = 9;
    itens[9].chave = 10;

    selection_sort(itens, 10);
    imprime(itens, 10);

    itens[0].chave = 1;
    itens[1].chave = 2;
    itens[2].chave = 3;
    itens[3].chave = 4;
    itens[4].chave = 5;
    itens[5].chave = 6;
    itens[6].chave = 7;
    itens[7].chave = 8;
    itens[8].chave = 9;
    itens[9].chave = 10;

    insertion_sort(itens, 10);
    imprime(itens, 10);

    printf("\n\nVetor 2:\n\n");
    itens[0].chave = 5;
    itens[1].chave = 4;
    itens[2].chave = 3;
    itens[3].chave = 2;
    itens[4].chave = 1;
    itens[5].chave = 6;
    itens[6].chave = 7;
    itens[7].chave = 8;
    itens[8].chave = 9;
    itens[9].chave = 10;


    printf("-Vetor Original:\n");
    imprime(itens, 10);

    bubble_sort(itens, 10);
    imprime(itens, 10);

    itens[0].chave = 5;
    itens[1].chave = 4;
    itens[2].chave = 3;
    itens[3].chave = 2;
    itens[4].chave = 1;
    itens[5].chave = 6;
    itens[6].chave = 7;
    itens[7].chave = 8;
    itens[8].chave = 9;
    itens[9].chave = 10;

    selection_sort(itens, 10);
    imprime(itens, 10);

    itens[0].chave = 5;
    itens[1].chave = 4;
    itens[2].chave = 3;
    itens[3].chave = 2;
    itens[4].chave = 1;
    itens[5].chave = 6;
    itens[6].chave = 7;
    itens[7].chave = 8;
    itens[8].chave = 9;
    itens[9].chave = 10;

    insertion_sort(itens, 10);
    imprime(itens, 10);


    return 0;
}
