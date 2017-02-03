#ifndef ARVORE_BINARIA_H_INCLUDED
#define ARVORE_BINARIA_H_INCLUDED

typedef struct{
    int chave;
}Elemento;

typedef struct nodo{
    Elemento info;
    struct nodo *pEsquerda, *pDireita;
}TNodo;

typedef TNodo *Arvore;

Arvore cria_arvore();

//Inserção.
int insere_recursivo(Arvore*, Elemento);
int insere_sem_recursao(Arvore*, Elemento);

//Remoção.

//Auxiliares.
int altura_arvore(Arvore);
int eh_vazia(Arvore);
int quantidade_nos(Arvore);

//Caminhamento.
void in_ordem(Arvore);
void pos_ordem(Arvore);
void pre_ordem(Arvore);

//Busca.
int procura_recursivo(Arvore, Elemento*, int chave);
int procura_sem_recursao(Arvore, Elemento*, int chave);

//Liberar memória alocada.
void libera_memoria_arvore(Arvore);

#endif // ARVORE_BINARIA_H_INCLUDED
