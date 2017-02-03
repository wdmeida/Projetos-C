#include <stdio.h>
#include <stdlib.h>

//Faz a multiplicação utilizando soma de forma iterativa.
int multiplicacao_iterativa(int a, int b) {
    return (b == 1)? a : multiplicacao_iterativa(a, b - 1) + a;
}//multiplicacao_iterativa

int fibonacci(int n) {
    int x, y;

    if (n <= 1) return n;

    x = fibonacci(n - 1);
    y = fibonacci(n - 2);
    return x + y;
}//fibonacci

//Busca binaria recursiva
int binsrch(int *v, int valor, int low, int high) {
    int mid;

    if (low > high) return -1;

    mid = (low + high) / 2;

    return valor == v[mid] ? mid : valor < v[mid] ?
                                binsrch(v, valor, low, mid - 1) :
                                binsrch(v, valor, mid + 1, high);
}//binsrch

int main()
{
    int valor_a, valor_b;

    printf("Primeiro valor: ");
    scanf("%d", &valor_a);

    printf("\nSegundo valor: ");
    scanf("%d", &valor_b);


    printf("\nResultado da multiplicacao de %d * %d = %d", valor_a, valor_b, multiplicacao_iterativa(valor_a, valor_b));

    printf("\n\nSexto termo da sequencia Fibonacci: %d\n", fibonacci(6));

    int v[10] = {0, 2, 4, 5, 7, 8, 9, 7, 11 ,12};

    printf("\nPosicao do valor '4': %d", binsrch(v, 4, 0, 9));

    return 0;
}
