#include <stdio.h>
#include <stdlib.h>
#include "tad_lista.h"

void msg(char* msg) {
    printf("%s", msg);
}

int main()
{
    msg("Inicia testes com a Lista implementada com array:\n");

    TLista l1;

    TLista_cria(&l1);

    msg("\nInserindo itens na lista");
    TItem item, retira;
    int i;

    for (i = 0; i < 30; i++){
        item.chave = i + 1;
        TLista_insere(&l1, item);
    }

    msg("\nImprimindo o conteudo da lista...\n");
    TLista_imprime(&l1);

    msg("\nRetirando um elemento na lista... \n");
    TLista_retira(&l1, 10, &retira);

    msg("\nElemento removido: ");
    printf("%d", retira.chave);

    msg("\nImprimindo o conteudo da lista...\n");
    TLista_imprime(&l1);

    TLista l2;
    TLista_cria(&l2);

    //Copiando uma lista para outra.
    TLista_copia(&l1, &l2);

    msg("\nImprimindo a segunda lista...\n");
    TLista_imprime(&l2);

    TLista l3;
    TLista_cria(&l3);

    msg("\nConcatenando duas listas...\n");
    TLista_concatena(&l1, &l2, &l3);
    TLista_imprime(&l3);

    msg("\nDivide ums lista em duas...\n");
    TLista l4;
    TLista_cria(&l4);

    TLista_divide(&l1, &l4);

    TLista_imprime(&l4);

    return 0;
}
