#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main()
{
    Fila fila;
    tipo_elemento elemento;

    fila = cria_fila();

    elemento.chave = 12;
    enfileira(fila, elemento);

    printf("\nTamanho da fila: %d\n", tamanho_fila(fila));

    elemento.chave = 14;
    enfileira(fila, elemento);

    printf("\nTamanho da fila: %d\n", tamanho_fila(fila));

    imprime(fila);

    elemento.chave = 17;
    enfileira(fila, elemento);

    printf("\nTamanho da fila: %d\n", tamanho_fila(fila));


    elemento.chave = 19;
    enfileira(fila, elemento);

    printf("\nTamanho da fila: %d\n", tamanho_fila(fila));

    imprime(fila);

    tipo_elemento remove;
    desenfileira(fila, &remove);

    printf("\nRemovendo o primeiro item: %d", remove.chave);

    imprime(fila);

    destroi(fila);

    return 0;
}
