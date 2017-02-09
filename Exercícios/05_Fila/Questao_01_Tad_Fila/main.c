#include <stdio.h>
#include <stdlib.h>
#include "tad_fila.h"

int main()
{
    printf("Inserindo elementos!!!\n");
    Fila f = cria_fila();
    TElemento e;

    e.matricula = 1234;
    enfileira(f, e);
    printf("\nFila atual:\n");
    imprime(f);

    e.matricula = 4746;
    enfileira(f, e);
    printf("\nFila atual:\n");
    imprime(f);

    e.matricula = 987;
    enfileira(f, e);
    printf("\nFila atual:\n");
    imprime(f);

    e.matricula = 8767;
    enfileira(f, e);
    printf("\nFila atual:\n");
    imprime(f);

    TElemento remove;
    desenfileira(f, &remove);
    printf("\nRemovido o elemento \"%d\", imprimindo a fila atual:\n", remove.matricula);
    imprime(f);

    desenfileira(f, &remove);
    printf("\nRemovido o elemento \"%d\", imprimindo a fila atual:\n", remove.matricula);
    imprime(f);

    desenfileira(f, &remove);
    printf("\nRemovido o elemento \"%d\", imprimindo a fila atual:\n", remove.matricula);
    imprime(f);

    libera_memoria_alocada(f);
    return 0;
}
