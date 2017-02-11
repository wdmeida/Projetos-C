#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "end_aberto.h"

void TDicionario_Inicia(TDicionario dic){
    int i;
    for (i = 0; i < M; i++)
        memcpy(dic[i].Chave, VAZIO, N);
}

int TDicionario_Pesquisa(TDicionario dic, TChave chave, int* p){
    int i = 0;
    int ini = H(chave, p);

    while (strcmp(dic[(ini + i) % M].Chave, VAZIO) != 0 &&
            strcmp(dic[(ini + i) % M].Chave, chave) != 0 &&
            i < M)
            i++;

    if (strcmp(dic[(ini + i) % M].Chave, chave) == 0)
        return (ini + i) % M;

    return -1;
}

int H(TChave chave, int* p){
    return 1;
}

int TDicionario_Insere(TDicionario dic, TItem x, int* p) {
    if (TDicionario_Pesquisa(dic, x.Chave, p) > 0)
        return 0;

    int i = 0;
    int ini = H(x.Chave, p);

    while (strcmp(dic[(ini + i) % M].Chave, VAZIO) != 0 && i < M)
        i++;

    if (i < M){
        dic[(ini + i) % M] = x;
        return 1;
    }
    return 0;
}
int TDicionario_Retira(TDicionario dic, TItem* x, int* p) {
    int i = TDicionario_Pesquisa(dic, x->Chave, p);
    if (i == -1) return 0;

    (*x) = dic[i];
    memcpy(dic[i].Chave, VAZIO, N);
    return 1;
}

void Gera_Pesos(int* p, int tam_p) {
    int i;

    srand(time(NULL));
    for (i = 0; i < tam_p; i++)
        p[i] = 1 + (int) (10000.0 * rand() / RAND_MAX);
}

int h(char* chave, int* p, int m, int tam_p){
    int i;
    unsigned int soma = 0;
    int comp = strlen(chave);

    for (i = 0; i < comp; i++)
        soma += (unsigned int) chave[i] * p[i % tam_p];

    return (soma % m);
}
