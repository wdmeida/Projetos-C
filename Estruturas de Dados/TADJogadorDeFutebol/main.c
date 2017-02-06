#include <stdio.h>
#include <stdlib.h>
#include "JogadorDeFutebol.h"

int main()
{
    Jogador* j = inicializa();

    atribui(j, 'Wagner', 12, 3, 4);

    imprime(j);

    libera(j);
    return 0;
}
