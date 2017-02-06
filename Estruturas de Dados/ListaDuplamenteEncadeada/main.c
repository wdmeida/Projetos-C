#include <stdio.h>
#include <stdlib.h>
#include "lista_dup.h"

int main()
{

    Lista l = cria_lista();

    Elemento e;
    e.chave = 23;

    inserir_lista_vazia(l, e);

    e.chave = 24;
    inserir_lista_final(l, e);

    e.chave = 54;
    inserir_lista_apos(l, e, 2);

    remove_lista(l, &e, 1);

    printf("\nElemento removido: %d", e.chave);

    imprime_inicio(l);

    termina_lista(l);
    return 0;
}
