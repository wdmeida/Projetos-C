#ifndef LISTA_DUP_H_INCLUDED
#define LISTA_DUP_H_INCLUDED

typedef struct{
    int chave;
}Elemento;

typedef struct nodo{
    struct nodo *pAnterior, *pProximo;
    Elemento elemento;
}TNodo;

typedef struct{
    TNodo *pPrimeiro, *pUltimo;
    int tamanho;
}TLista;

typedef TLista *Lista;

Lista cria_lista();
void termina_lista(Lista);

//Inserir na lista.
int inserir_lista_vazia(Lista, Elemento);
int inserir_lista_inicio(Lista, Elemento);
int inserir_lista_final(Lista, Elemento);
int inserir_lista_antes(Lista, Elemento, int);
int inserir_lista_apos(Lista, Elemento, int);

//Retirar na lista.
int remove_lista(Lista, Elemento, int);

#endif // LISTA_DUP_H_INCLUDED
