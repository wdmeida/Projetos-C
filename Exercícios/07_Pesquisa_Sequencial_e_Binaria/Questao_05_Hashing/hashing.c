#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "hashing.h"

//Função de hash que retorna o índice de uma chave (String).
void THash_Inicia(THash*, int, int);

//Retorna o indice (Número inteiro) de uma chave (string)
int THash_H(THash* hash, TChave chave) {
    int i;
    unsigned int soma = 0;
    int comp = strlen(chave);

    for (i = 0; i < comp; i++)
        soma += (unsigned int) chave[i] * hash->p[i % hash->nro_pesos];

    return (soma % hash->nro_pesos);
}//THash_H

int THash_Pesquisa(THash*, TChave, TItem*);
TCelula *THash_Pesquisa_Celula(THash*, TChave);
int THash_Insere(THash*, TItem);
int THash_Remove(THash*, TItem);


//Gera valores randomicos entre 1 e 10000.
void GeraPesos(int* p, int n) {
    int i;

    srand(time(NULL));
    for (i = 0; i < n; i++)
        p[i] = 1 + (int) (10000.0 * rand() / RAND_MAX);
}
