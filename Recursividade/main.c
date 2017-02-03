#include <stdio.h>
#include <stdlib.h>

int busca_binaria_recursiva(int* v, int valor, int posicao_inicial, int posicao_final){
    if(posicao_inicial > posicao_final) return -1;

    int pos = (posicao_inicial + posicao_final) / 2;

    if(v[pos] == valor) return pos;

    if(v[pos] < valor) return busca_binaria_recursiva(v, valor, posicao_inicial, pos - 1);
    else return busca_binaria_recursiva(v, valor, pos + 1, posicao_final);
}

int main()
{
    int v[10] = {1, 3, 5, 6, 8, 23, 45, 67, 89, 90};

    int pos = busca_binaria_recursiva(v, 67, 0, 9);

    printf("Pos: %d", pos);
    return 0;
}
