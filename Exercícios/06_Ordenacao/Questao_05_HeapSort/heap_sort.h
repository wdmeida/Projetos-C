#ifndef HEAP_SORT_H_INCLUDED
#define HEAP_SORT_H_INCLUDED

typedef struct{
    int chave;
}TItem;

void heap_refaz(TItem*, int, int);
void heap_constroi(TItem*, int);
void heap_sort(TItem*, int);

#endif // HEAP_SORT_H_INCLUDED
