#include <stdio.h>
#include <stdlib.h>

void towers(int n, char frompeg, char topeg, char auxpeg){

    /*Se existit um disco, faz o movimento e retorna.*/
    if (n == 1) {
        printf("\n%s%c%s%c", "mover disco da estaca ", frompeg, " p/ a estaca ", topeg);
        return;
    } //fim if

    /* Mover os primeiros n-1 discos de A p/ B usando C como auxiliar. */
    towers(n-1, frompeg, auxpeg, topeg);

    /* Mover o último disco de A p/ C */
    printf("\n%s%d%s%c%s%c", "mover disco ", n, " da estaca ", frompeg, " p/ a estaca ", topeg);

    /* Mover n-1 discos de B p/ C usando A como auxiliar. */
    towers(n-1, auxpeg, topeg, frompeg);
}//towers()

int main()
{
    int n;

    scanf("%d", &n);
    towers(n, 'A', 'C', 'B');
    return 0;
}
