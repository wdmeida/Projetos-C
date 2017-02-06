#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
    Pilha p;
    tipo_elemento e, remover;

    p = cria_pilha();

    e.elemento = 12;
    push(p, e);

    printf("\nTamanho da pilha: %d", tamanho_pilha(p));

    e.elemento = 13;
    push(p, e);

    printf("\nTamanho da pilha: %d", tamanho_pilha(p));

    e.elemento = 15;
    push(p, e);

    printf("\nTamanho da pilha: %d", tamanho_pilha(p));

    pop(p, &remover);

    printf("\nElemento removido: %d", remover.elemento);

    printf("\nTamanho da pilha: %d", tamanho_pilha(p));

    termina_pilha(p);

    return 0;
}
