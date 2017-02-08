#ifndef TAD_LISTA_ENCADEADA_H_INCLUDED
#define TAD_LISTA_ENCADEADA_H_INCLUDED

typedef struct{
    int chave;
}TElemento;

typedef struct nodo{
    struct nodo *pProximo;
    TElemento elemento;
}TNodo;

typedef struct{
    TNodo *pPrimeiro, *pUltimo;
    int tamanho;
}TLista;

typedef TLista *Lista;

Lista nova_lista();
int lista_vazia(Lista);
int tamanho_lista(Lista);
int insere_inicio(Lista, TElemento);
int insere_final(Lista, TElemento);
int insere_posicao(Lista, int, TElemento);
int remove_inicio(Lista, TElemento*);
int remove_final(Lista, TElemento*);
int remove_posicao(Lista, int, TElemento*);
void imprime(Lista);
void libera_memoria_lista(Lista);

#endif // TAD_LISTA_ENCADEADA_H_INCLUDED
