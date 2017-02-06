#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b;

    a = 10;
    b = 20;
    printf("Hello world!\n");

    printf("Valor A = %d\n", a);
    printf("Valor B = %d\n", b);

    printf("Soma de A + B = %d\n", a + b);

    printf("\nDigite o novo valor de a: ");
    scanf("%d",&a);

    printf("\n\nNovo valor de A = %d", a);
    return 0;
}
