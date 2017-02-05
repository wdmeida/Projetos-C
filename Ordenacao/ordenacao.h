#ifndef ORDENACAO_H_INCLUDED
#define ORDENACAO_H_INCLUDED

//Algoritmos básicos de ordenação.
void bubble_sort(int *v, int tamanho);
void insection_sort(int *v, int tamanho);
void selection_sort(int *v, int tamanho);

//Algoritmos sofisticados de ordenação.
void merge_sort(int *v, int inicio, int fim);
void etp_merge(int *v, int inicio, int meio, int fim);
void quick_sort(int *v, int inicio, int fim);
int particiona(int *v, int inicio, int fim);

#endif // ORDENACAO_H_INCLUDED
