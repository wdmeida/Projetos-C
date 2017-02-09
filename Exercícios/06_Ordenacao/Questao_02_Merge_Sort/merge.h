#ifndef MERGE_H_INCLUDED
#define MERGE_H_INCLUDED

typedef struct{
    int chave;

}TItem;

void merge_sort(TItem*, int);
void merge_sort_ordena(TItem*, int, int);
void merge_sort_intercala(TItem*, int, int, int);

void merge_sort_iterativo(TItem*, int);
#endif // MERGE_H_INCLUDED
