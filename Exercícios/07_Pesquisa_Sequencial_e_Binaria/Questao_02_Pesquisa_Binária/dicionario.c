#include <stdio.h>
#include <stdlib.h>
#include "dicionario.h"

/*
    Análise:
        A cada iteração do algoritmo, o tamanho da tabela é dividido ao meio.
        Logo o número de vezes que o tamanho da tabela é dividido ao meio é cerca
        de log n.
        Ressalta-se que o custo para manter a tabela ordenada é alto: a cada inserção
        na posição p da tabala implica no deslocamento dos registros a partir da posição
        p para as posições seguintes.
        Consequentemente, a pesquisa binária não deve ser usada em aplicações muito dinâmicas.
*/
void TDicionario_inicio(TDicionario* dict) {
    dict->tamanho = 0;
    dict->capacidade = 10;
    dict->v = (TItem*) malloc(sizeof(TItem) * dict->capacidade);
}

void TDicionario_insere(TDicionario* dict, TItem item) {
    if (dict->tamanho == dict->capacidade) {
        dict->capacidade *= 2;
        dict->v = (TItem*) realloc(dict->v, sizeof(TItem) * dict->capacidade);
    }
    dict->v[dict->tamanho++] = item;
}

//Recursiva.
int TDicionario_Find(TDicionario* dict, TChave ch) {
    return TDicionario_Binaria(dict, 0, dict->tamanho - 1, ch);
}

int TDicionario_Binaria(TDicionario* dict, int esq, int dir, TChave ch) {
    int meio = (esq + dir) / 2;

    //Verifica se a busca terminou e o valor não foi encontrado.
    if (dict->v[meio].Chave != ch && esq >= dir)
        return -1;
    else if (ch > dict->v[meio].Chave)
        return TDicionario_Binaria(dict, meio + 1, dir, ch);
    else if (ch < dict->v[meio].Chave)
        return TDicionario_Binaria(dict, esq, meio - 1, ch);
    else
        return meio;
}

//Interatica
int TDicionario_Find_Iterativa(TDicionario* dict, TChave ch) {
    int meio, esq, dir;

    if (dict->tamanho == 0) return -1;

    esq = 0;
    dir = dict->tamanho - 1;

    do {
        meio = (esq + dir) / 2;
        if (ch > dict->v[meio].Chave)
            esq = meio + 1;
        else
            dir = meio -1;
    } while (ch != dict->v[meio].Chave && esq <= dir);

    if (ch == dict->v[meio].Chave)
        return meio;
    else
        return -1;
}
