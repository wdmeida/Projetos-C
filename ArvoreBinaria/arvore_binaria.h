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

int insere_recursivo(Arvore*, Elemento);
int insere_sem_recursao(Arvore*, Elemento);

int altura_arvore(Arvore);

void in_ordem(Arvore);

void Libera_memoria_arvore(Arvore);

int procura_recursivo(Arvore, Elemento*, int chave);
int procura_sem_recursao(Arvore, Elemento*, int chave);

#endif // ARVORE_BINARIA_H_INCLUDED
