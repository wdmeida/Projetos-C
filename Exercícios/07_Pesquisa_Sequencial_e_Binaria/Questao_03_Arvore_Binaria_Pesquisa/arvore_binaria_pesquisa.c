#include <stdlib.h>
#include <stdio.h>
#include "arvore_binaria_pesquisa.h"

/*
    Melhor caso C(n) = O(1)
    Pior caso C(n) = O(n)
    Caso Médio C(n) = O(log n)

    O tempo de execução dos algoritmos para árvores binárias de pesquisa
    dependem muito do formado das árvores, ou seja, se ela está balanceada
    ou não.
*/

void TArvore_Inicia(TNo** pRaiz) {
    *pRaiz = NULL;
}//TArvore_Inicia()

//Criar um nó para ser inserido na árvore.
TNo* TNo_Cria(TItem x) {
    TNo *pAux = (TNo*) malloc(sizeof(TNo));
    pAux->item = x;
    pAux->pDir = NULL;
    pAux->pEsq = NULL;
    return pAux;
}//TNo_Cria()

/*
    Para encontrar um registro com uma chave x:
        Compare-a com a chave que está na raiz;
        Se x é menor, vá para a subárvore esquerda;
        Se x é maior, vá para a subárvore direita;
        Repita o processo recursivamente, até que a chave procurada
        seja encontrada ou um nó folha seja atingido.
        Se a pesquisa tiver sucesso então o conteúdo do registro
        retorna no próprio registro x.
*/
int TArvore_Pesquisa_Recursiva(TArvore pRaiz, TChave c, TItem* pX) {
    if (pRaiz == NULL) return 0;

    if (c < pRaiz->item.Chave)
        return TArvore_Pesquisa_Recursiva(pRaiz->pEsq, c, pX);
    if (c > pRaiz->item.Chave)
        return TArvore_Pesquisa_Recursiva(pRaiz->pDir, c, pX);

    *pX = pRaiz->item;
    return 1;
}//TArvore_Pesquisa_Recursiva()

int TArvore_Pesquisa_Iterativa(TArvore pRaiz, TChave c, TItem* pX) {
    TNo *pAux;

    pAux = pRaiz;
    while (pAux != NULL) {
        if (c == pAux->item.Chave){
            *pX = pAux->item;
            return 1;
        }
        else if (c > pAux->item.Chave)
            pAux = pAux->pDir;
        else
            pAux = pAux->pEsq;
    }

    //Registro não encontrado
    return 0;
}//TArvore_Pesquisa_Iterativa()

/*  Procedimento para Inserir na Àrvore.
        Onde inserir?
            Atingir um ponteiro nulo em um processo de pesquisa significa
            uma pesquisa sem sucesso.
            O ponteiro nulo atingido é o ponto de inserção.
        Como inserir?
            Cria célula contendo registro.
            Procurar o lugar na árvore.
            Se o registro não estiver na árvore, insere-o.
*/
int TArvore_Insere_Recursivo(TNo** ppR, TItem x) {
    //Verifica se o conteúdo do ppr é NULL, caso seja, cria o NO neste local.
    if (*ppR == NULL) {
        //*ppR = TNo_Cria(x);
        (*ppR) = (TNo*) malloc(sizeof(TNo));
        (*ppR)->pDir = NULL;
        (*ppR)->pEsq = NULL;
        (*ppR)->item = x;
        return 1;
    }

    if (x.Chave < (*ppR)->item.Chave)
        return TArvore_Insere_Recursivo(&(*ppR)->pEsq , x);
    else if (x.Chave > (*ppR)->item.Chave)
        return TArvore_Insere_Recursivo(&(*ppR)->pDir, x);
    else return 0;
}//TArvore_Insere_Recursivo()

int TArvore_Insere_Arvore_Nao_Vazia(TNo* pRaiz, TItem x) {
    if (pRaiz == NULL) return -1; //árvore vazia

    if (x.Chave < pRaiz->item.Chave) {
        if (pRaiz->pEsq == NULL) {
            pRaiz->pEsq = TNo_Cria(x);
            return 1;
        }
        return TArvore_Insere_Arvore_Nao_Vazia(pRaiz->pEsq, x);
    }
    if (x.Chave > pRaiz->item.Chave) {
        if (pRaiz->pDir == NULL) {
            pRaiz->pDir = TNo_Cria(x);
            return 1;
        }
        return TArvore_Insere_Arvore_Nao_Vazia(pRaiz->pDir, x);
    }
    return 0; //elemento já existe.
}//TArvore_Insere_Arvore_Nao_Vazia()

int TArvore_Insere_Iterativo(TNo** ppRaiz, TItem x) {
    TNo **ppAux;
    ppAux = ppRaiz;

    while (*ppAux != NULL) {
        if (x.Chave < (*ppAux)->item.Chave)
            ppAux = &((*ppAux)->pEsq);
        else if (x.Chave > (*ppAux)->item.Chave)
            ppAux = &((*ppAux)->pDir);
        else
            return 0;
    }
    *ppAux = TNo_Cria(x);
    return 1;
}//TArvore_Insere_Iterativo()

/*
    Procedimento para Retirar X da Árvore
    A retirada de um registro não é tão simples quanto a inserção.
    Se o nó que contém o registro a ser retirado possuir no máximo um
    descendente, a operação é simples.
    No caso do nó conter dois descendentes o registro a ser retirado
    deve ser primeiro:
        Substituído pelo registro mais à direita na subárvore esquerda;
        Substituído pelo registro mais à direita na subárvore direita.
*/

void TArvore_Sucessor(TNo* q, TNo** r) {
    TNo *pAux;

    if ((*r)->pEsq != NULL) {
        TArvore_Sucessor(q, &(*r)->pEsq);
        return;
    }
    q->item = (*r)->item;
    pAux = *r;
    *r = (*r)->pDir;
    free(pAux);
}//TArvore_Sucessor()

int TArvore_Retira(TNo **p, TItem x) {
    TNo *pAux;

    if (*p == NULL) return 0;

    if (x.Chave < (*p)->item.Chave)
        return TArvore_Retira(&((*p)->pEsq), x);
    if (x.Chave > (*p)->item.Chave)
        return TArvore_Retira(&((*p)->pDir), x);

    //Caso o nó seja folha.
    if ((*p)->pEsq == NULL && (*p)->pDir == NULL) {
        free(*p);
        *p = NULL;
        return 1;
    }

    //Possui apenas subarvores à esquerda.
    if ((*p)->pEsq != NULL && (*p)->pDir == NULL) {
        pAux = *p;
        *p = (*p)->pEsq;
        free(pAux);
        return 1;
    }

    if ((*p)->pEsq == NULL && (*p)->pDir != NULL) {
        pAux = *p;
        *p = (*p)->pDir;
        free(pAux);
        return 1;
    }

    // No possui dois filhos.
    TArvore_Sucessor(*p, &((*p)->pDir));
    return 1;
}//TArvore_Retira()

/*
    Lista o nó raiz, seguido de suas subárvores (da esquerda para direita),
    cada uma em prè-ordem.
*/
void Pre_Ordem(TNo* p){
    if(p == NULL) return;
    printf("%ld\n", p->item.Chave);
    Pre_Ordem(p->pEsq);
    Pre_Ordem(p->pDir);
}//Pre_Ordem()

/*
    Em árvores de pesquisa a ordem de caminhamento mais útil é chamada
    ordem de caminhamento central (In Ordem ou ordem simétrica).
    O caminhamento central é mais bem expresso em termos recursivos:

    1. Caminha na subárvore esquerda na ordem central;
    2. Visita a raiz;
    3. Caminha na árvore direita na ordem central.
*/
void In_Ordem(TNo* p) {
    if (p == NULL) return;
    In_Ordem(p->pEsq);
    printf("%ld\n", p->item.Chave);
    In_Ordem(p->pDir);
}//In_Ordem()

/*
    Lista os nós das subárvores (da esquerda para a diretia) cada uma em
    pós-ordem, lista o nó raiz.
*/
void Pos_Ordem(TNo* p) {
    if (p == NULL) return;
    Pos_Ordem(p->pEsq);
    Pos_Ordem(p->pDir);
    printf("%ld\n", p->item.Chave);
}//Pos_Ordem()


void TArvore_destroi(TArvore* arv){
    if (*arv != NULL){
        TArvore_destroi(&(*arv)->pEsq);
        TArvore_destroi(&(*arv)->pDir);
        free(arv);
    }
}
