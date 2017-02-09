#ifndef TAD_FILA_H_INCLUDED
#define TAD_FILA_H_INCLUDED

typedef struct{
    int matricula;
    //Demais elementos.
}TElemento;

typedef struct nodo{
    struct nodo *pProximo;
    TElemento elemento;
}TNodo;

typedef struct{
    TNodo *pPrimeiro, *pUltimo;
    int tamanho;
}TFila;

typedef TFila *Fila;

Fila cria_fila();
int tamanho_fila(Fila);
int fila_vazia(Fila);
int enfileira(Fila, TElemento);
int desenfileira(Fila, TElemento*);
void imprime(Fila);
void libera_memoria_alocada(Fila);


#endif // TAD_FILA_H_INCLUDED
