#include <stdio.h>
#include <stdlib.h>

int x(int n, int m)
{
    if (n == m || n == 0)
        return 1;
    else return x(n - 1, m) + x(n-1,m+1);
}

//Pesquisa binária recursiva.
int pesquisa_binaria(int* v, int esq, int dir, int valor){
    int meio = (esq + dir) / 2;

    if (v[meio] != valor && esq >= dir)
        return -1;
    else if (valor < v[meio])
        return pesquisa_binaria(v, esq, meio - 1, valor);
    else if (valor > v[meio])
        return pesquisa_binaria(v, meio + 1, dir, valor);
    else
        return meio;
}

int soma(int a , int b) {
    if (b == 0)
        return a;
    else
        return 1 + soma(a, b - 1);
}

int fatorial(int n){
    if (n == 0)
        return 1;
    else
        return n * fatorial(n - 1);
}

void dec2Bin(int num) {
    if (num == 0)
        printf("0");
    else if (num == 1)
        printf("1");
    else{
        dec2Bin(num/2);
        printf("%d", num%2);
    }
}

float serie(int n){
    if(n == 1)
        return 1;
    else
        return 1.0 / fatorial(n) + serie(n - 1);
}

int **cria_matriz(int linhas, int colunas){
    int **m = (int**) malloc(linhas * sizeof(int*));

    if(m){
        int i;
        for (i = 0; i < linhas; i++)
            m[i] = (int*) malloc(colunas * sizeof(int));
    }
    return m;
}

void libera_matriz(int **m, int num_linhas){
    int i;
    for (i = 0; i < num_linhas; i++)
        free(m[i]);
    free(m);
}

int soma_matriz(int **m, int linhas, int colunas, int l, int c){
    if(l < linhas && c < colunas)
        return m[l][c] + soma_matriz(m, linhas, colunas, l, c + 1);
    else
        if(l < linhas)
            return soma_matriz(m, linhas, colunas, l + 1, 0);
    else
        return 0;
}

int main()
{
    int v[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    int resp = pesquisa_binaria(v, 0, 9, 12);
    if(resp != -1)
        printf("O valor foi encontrado na posição %d", resp);
    else
        printf("O valor não foi encontrado");

    printf("\n\nSoma 5 + 3 = %d", soma(5, 3));

    printf("\n\nFatorial de 7 = %d", fatorial(7));

    printf("\n\nSerie de 7 = %.2f", serie(7));

    printf("\n\n128 em binário: ");

    dec2Bin(2);

    printf("\n\n");
    int **m = cria_matriz(2, 2);

    m[0][0] = 3;
    m[0][1] = 4;
    m[1][0] = 5;
    m[1][1] = 6;

    printf("Soma da matriz: %d\n",soma_matriz(m, 2, 2, 0, 0));

    libera_matriz(m, 2);

    return 0;
}
