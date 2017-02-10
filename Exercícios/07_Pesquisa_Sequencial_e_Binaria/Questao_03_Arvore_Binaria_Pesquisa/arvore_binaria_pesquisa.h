#ifndef ARVORE_BINARIA_PESQUISA_H_INCLUDED
#define ARVORE_BINARIA_PESQUISA_H_INCLUDED

typedef long TChave;

typedef struct{
    TChave Chave;
}TItem;

typedef struct No {
    TItem item;
    struct No *pEsq, *pDir;
} TNo;

typedef TNo *TArvore;

void TArvore_Inicia(TNo**);
TNo* TNo_Cria(TItem);

int TArvore_Pesquisa_Recursiva(TArvore, TChave, TItem*);
int TArvore_Pesquisa_Iterativa(TArvore, TChave, TItem*);

int TArvore_Insere_Retursivo(TNo**, TItem);
int TArvore_Insere_Arvore_Nao_Vazia(TNo*, TItem);
int TArvore_Insere_Iterativo(TNo**, TItem);

#endif // ARVORE_BINARIA_PESQUISA_H_INCLUDED
