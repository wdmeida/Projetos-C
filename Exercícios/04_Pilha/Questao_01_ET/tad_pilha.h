#ifndef TAD_PILHA_H_INCLUDED
#define TAD_PILHA_H_INCLUDED
#define Cancela_Caractere '#'
#define Marca_Eof '!'
#define Calcela_Linha '\'
#define Salta_Linha '*'

typedef struct{
    char chave;
}TElemento;

typedef struct nodo{
    struct nodo *pProximo;
    TElemento elemento;
}TNodo;

typedef struct{
    TNodo *pTopo, *pFundo;
    int tamanho;
}TPilha;

typedef TPilha *Pilha;

Pilha cria_pilha();
int pilha_vazia(Pilha);
int tamanho_pilha(Pilha);
int push(Pilha, TElemento);
int pop(Pilha, TElemento*);
int peek(Pilha, TElemento*);
void imprime(Pilha);
void libera_memoria_alocada(Pilha);

#endif // TAD_PILHA_H_INCLUDED
