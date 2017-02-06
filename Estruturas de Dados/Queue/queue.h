#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

typedef struct{
    int chave;
    /* Outros elementos */
}tipo_elemento;

typedef struct nodo{
    struct nodo *proximo;
    tipo_elemento elemento;
}tipo_nodo;

typedef struct{
    tipo_nodo *inicio, *fim;
    int tamanho;
}tipo_fila;

typedef tipo_fila *Fila;

Fila cria_fila();
int tamanho_fila(Fila f);
int fila_vazia(Fila f);
int enfileira(Fila f, tipo_elemento e);
int desenfileira(Fila f, tipo_elemento* e);
void destroi(Fila f);
void imprime(Fila f);

#endif // QUEUE_H_INCLUDED
