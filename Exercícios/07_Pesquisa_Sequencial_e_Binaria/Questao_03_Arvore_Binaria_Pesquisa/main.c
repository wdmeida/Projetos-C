#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria_pesquisa.h"

int main()
{
    TArvore arvore;

    TArvore_Inicia(&arvore);

    TItem item;
    item.Chave = 23;

    TArvore_Insere_Recursivo(&arvore, item);

    TArvore_destroi(&arvore);

    printf("Hello world!\n");
    return 0;
}
