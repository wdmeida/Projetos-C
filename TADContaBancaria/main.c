#include <stdio.h>
#include <stdlib.h>
#include "conta_bancaria.h"


int main()
{
    ContaBancaria* conta = inicializa(1234, 1200);
    imprime(conta);

    deposito(conta, 1200);
    imprime(conta);

    saque(conta, 1000);
    imprime(conta);

    free(conta);
    return 0;
}
