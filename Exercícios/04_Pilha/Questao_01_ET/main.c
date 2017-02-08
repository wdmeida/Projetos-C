#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tad_pilha.h"

int main()
{
    Pilha pilha = cria_pilha();
    TElemento x;

    x.chave = getchar();

    while (x.chave != Marca_Eof) {

        if (x.chave == Cancela_Caractere) {
            if (!pilha_vazia(pilha)) pop(pilha, &x);
        } else if (x.chave == Calcela_Linha)
            pilha = cria_pilha();
        else if (x.chave == Salta_Linha)
            imprime(pilha);
        else
            push(pilha, x);
        x.chave = getchar();
    }//fim_while()

    if (!pilha_vazia(pilha)) imprime(pilha);

    libera_memoria_alocada(pilha);
    return 0;
}
