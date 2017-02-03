#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{
    Lista l = cria_lista();

    TItem item;

    printf("\nInserindo elementos na lista...\n");

    item.chave = 3;
    insere_inicio(l, item);
    printf("\nTamanho da lista: %d", tamanho(l));

    item.chave = 4;
    insere_inicio(l, item);
    printf("\nTamanho da lista: %d", tamanho(l));

    item.chave = 56;
    insere_inicio(l, item);
    printf("\nTamanho da lista: %d", tamanho(l));

    item.chave = 43;
    insere_final(l, item);
    printf("\nTamanho da lista: %d", tamanho(l));

    item.chave = 26;
    insere_final(l, item);
    printf("\nTamanho da lista: %d", tamanho(l));

    item.chave = 999;
    insere_posicao(l, item, 2);
    printf("\nTamanho da lista: %d", tamanho(l));

     printf("\n\nConteudo da lista: \n");
    imprime(l);

    TItem remove;

    printf("\nRemovendo elementos da lista...\n");

    remove_posicao(l, &remove, 2);
    printf("\nRemovido o elemento da pos 2: %d", remove.chave);

    printf("\n\nConteudo da lista: \n");
    imprime(l);

    remove_final(l, &remove);
    printf("\nRemovido o elemento: %d", remove.chave);

    remove_final(l, &remove);
    printf("\nRemovido o elemento: %d", remove.chave);

    remove_inicio(l, &remove);
    printf("\nRemovido o elemento: %d\n", remove.chave);

    printf("\nTamanho da lista: %d\n", tamanho(l));

    remove_inicio(l, &remove);
    printf("\nRemovido o elemento: %d\n", remove.chave);

    printf("\nTamanho da lista: %d", tamanho(l));

    imprime(l);

    //teste
    remove_inicio(l, &remove);
    printf("\nRemovido o elemento: %d\n", remove.chave);

    printf("\nTamanho da lista: %d\n", tamanho(l));

    imprime(l);

    printf("\nTentando remover mais elementos da lista...\n");

    printf("\nRemovendo no ínicio...");
    if (!remove_inicio(l, &remove)) printf ("\nImpossivel remover no inicio, lista vazia.\n");

    printf("\nRemovendo no ínicio...");
    if (!remove_final(l, &remove)) printf("\nImpossivel remover no final, lista vazia.\n");

    printf("\nRemovendo na posicao 2");
    if (!remove_posicao(l, &remove, 2)) printf("\nImpossivel remover na posicao, lista vazia.\n");

    printf("\nLiberando memoria alocada para a lista.");
    libera_memoria(l);

    return 0;
}
