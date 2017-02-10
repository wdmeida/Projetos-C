#include <stdio.h>
#include <stdlib.h>
#include "dicionario.h"

int main()
{
    TDicionario dict;
    TDicionario_Inico(&dict);

    TItem insere;
    insere.Chave = 12;

    TDicionario_Insere(&dict, insere);

    TDicionario_Find(&dict, 11) != -1 ? printf("Achoou...") : printf("Não achou");

    return 0;
}
