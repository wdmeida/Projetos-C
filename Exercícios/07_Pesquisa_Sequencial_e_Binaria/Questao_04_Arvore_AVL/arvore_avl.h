#ifndef ARVORE_AVL_H_INCLUDED
#define ARVORE_AVL_H_INCLUDED

/*
    Uma árvore binária balanceada é aquela na qual, para cada nó,
    as alturas de suas sub-árvores esquerda e direita se diferem de,
    no máximo, 1.
    Fator de balanceamento (FB) de um nó é a diferença entre a altura
    de sub-árvore esquerda em relação a subárvore direita.

    FB(p) = altura(arvEsq de p) - altura(arvDir de p)

    Em uma árvore binária balanceada todos os FB de todos os nós
    estão no intervalo -1 <= FB <= 1.
*/

typedef long TipoChave;

typedef struct{
    TipoChave Chave;
}TItem;

typedef struct No{
    TItem item;
    struct No *pEsq, *pDir;
}TNo;

typedef TNo *TArvoreAVL;

int FB(TNo*);
int Altura(TNo*);

void Rotacao_Simples_Esquerda(TNo**);
void Rotacao_Simples_Direita(TNo**);
int Balanceamento_Esquerda(TNo**);
int Balanceamento_Direita(TNo**);

int Balanceamento(TNo**);

int Insere(TNo**, TItem*);
void TArvore_Antecessor(TNo*, TNo**);
int Remove(TNo**, TItem*);
int EhArvoreAvl(TNo*);
#endif // ARVORE_AVL_H_INCLUDED
