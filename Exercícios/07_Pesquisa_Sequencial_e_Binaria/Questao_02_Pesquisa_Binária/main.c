#include <stdio.h>
#include <stdlib.h>
#include "dicionario.h"

//No teste foram inseridos valores em ordem certa apenas para testar o funcionameno
//da busca binária.
int main()
{
    TItem item;

    TDicionario dicionario;
    TDicionario_inicio(&dicionario);

    item.Chave = 12;
    TDicionario_insere(&dicionario, item);

    item.Chave = 15;
    TDicionario_insere(&dicionario, item);

    item.Chave = 17;
    TDicionario_insere(&dicionario, item);

    item.Chave = 19;
    TDicionario_insere(&dicionario, item);

    item.Chave = 21;
    TDicionario_insere(&dicionario, item);

    item.Chave = 23;
    TDicionario_insere(&dicionario, item);

    item.Chave = 25;
    TDicionario_insere(&dicionario, item);

    item.Chave = 27;
    TDicionario_insere(&dicionario, item);

    item.Chave = 29;
    TDicionario_insere(&dicionario, item);

    item.Chave = 32;
    TDicionario_insere(&dicionario, item);

    printf("\nPesquisando o valor 27 no sistema:\n");
    (TDicionario_Find_Iterativa(&dicionario, 27) != -1) ? printf("\nAchou...") : printf("\nNão achou...");

    return 0;
}
