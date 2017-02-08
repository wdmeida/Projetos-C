#include <stdio.h>
#include <stdlib.h>
#include "tad_lista_encadeada.h"

int main()
{
    //Cria uma nova lista.
    Lista l = nova_lista();

    //Insere elementos no ínicio.
    TElemento elemento;
    elemento.chave = 13;
    insere_inicio(l, elemento);
    elemento.chave = 22;
    insere_inicio(l, elemento);

    printf("Insercao no inicio: \n");
    //Imprime a lista
    imprime(l);

    printf("\n\nRemocao no inicio: \n");
    //Remove elementos do inicio.
    TElemento remover;
    remove_inicio(l, &remover);

    //Imprime a lista.
    imprime(l);

    printf("\nInsercao no final: \n");
    elemento.chave = 34;
    insere_final(l, elemento);
    elemento.chave = 456;
    insere_final(l, elemento);

    //Imprime a lista
    imprime(l);

     printf("\n\nRemocao no final: \n");
    //Remove elementos do final.
    remove_final(l, &remover);

    //Imprime a lista
    imprime(l);

    //Insere por posição.
    elemento.chave = 29;
    insere_posicao(l, 2, elemento);

    printf("\nTestando inserir por posicao 2...\n");
    imprime(l);

    printf("\nTestando remover na posicao 2...\n");
    remove_posicao(l, 2, &remover);
    imprime(l);

    printf("\nTestando remover na posicao 2...\n");
    remove_posicao(l, 2, &remover);
    imprime(l);

    //Libera a memória alocada.
    libera_memoria_lista(l);
    return 0;
}
