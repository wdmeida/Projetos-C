#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct{
    /*Componentes de um item */
    int chave;
}TItem;

typedef struct celula {
    struct celula *pProx;
    TItem item;
}TCelula;

typedef struct {
    TCelula *pPrimeiro, *pUltimo;
    int tamanho;
}TLista;

typedef TLista *Lista;

Lista cria_lista();
int tamanho(Lista);
int eh_vazia(Lista);
int insere_inicio(Lista, TItem);
int insere_final(Lista, TItem);
int insere_posicao(Lista, TItem, int);
int remove_inicio(Lista, TItem*);
int remove_final(Lista, TItem*);
int remove_posicao(Lista, TItem*, int);
void imprime(Lista);
void libera_memoria(Lista);

#endif // LISTA_H_INCLUDED
