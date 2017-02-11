#include <stdio.h>
#include <stdlib.h>
#include "arvore_avl.h"

int FB(TNo* pRaiz) {
    if (pRaiz == NULL) return 0;

    return Altura(pRaiz->pEsq) - Altura(pRaiz->pDir);
}//FB()

int Altura(TNo* pRaiz) {
    if (pRaiz == NULL) return 0;

    int iEsq, iDir;

    iEsq = Altura(pRaiz->pEsq);
    iDir = Altura(pRaiz->pDir);

    if (iEsq > iDir)
        return iEsq + 1;
    else
        return iDir + 1;
}//Altura()

void Rotacao_Simples_Esquerda(TNo** ppRaiz) {
    TNo *pAux;
    pAux = (*ppRaiz)->pDir;
    (*ppRaiz)->pDir = pAux->pEsq;
    pAux->pEsq = (*ppRaiz);
    (*ppRaiz) = pAux;
}

void Rotacao_Simples_Direita(TNo** ppRaiz) {
    TNo *pAux;
    pAux = (*ppRaiz)->pEsq;
    (*ppRaiz)->pEsq = pAux->pDir;
    pAux->pDir = (*ppRaiz);
    (*ppRaiz) = pAux;
}

int Balanceamento_Esquerda(TNo** ppRaiz) {
    int fbe = FB((*ppRaiz)->pEsq);

    if (fbe > 0) {
        Rotacao_Simples_Direita(ppRaiz);
        return 1;
    } else if (fbe < 0) {
        //Rotação dupla direita
        Rotacao_Simples_Esquerda(&((*ppRaiz)->pEsq));
        Rotacao_Simples_Direita(ppRaiz);
        return 1;
    }
    return 0;
}

int Balanceamento_Direita(TNo** ppRaiz) {
    int fbd = FB((*ppRaiz)->pDir);

    if (fbd < 0) {
        Rotacao_Simples_Esquerda(ppRaiz);
        return 1;
    } else if (fbd > 0) {
        //Rotação dupla esquerda.
        Rotacao_Simples_Direita(&((*ppRaiz)->pDir));
        Rotacao_Simples_Esquerda(ppRaiz);
        return 1;
    }
    return 0;
}

int Balanceamento(TNo** ppRaiz) {
    int fb = FB(*ppRaiz);

    if (fb > 1)
        return Balanceamento_Esquerda(ppRaiz);
    else if (fb < -1)
        return Balanceamento_Direita(ppRaiz);
    else
        return 0;
}

int Insere(TNo** ppRaiz, TItem* x) {
    if(*ppRaiz == NULL)
    {
        *ppRaiz = (TNo*) malloc(sizeof(TNo));
        (*ppRaiz)->item = *x;
        (*ppRaiz)->pDir = NULL;
        (*ppRaiz)->pEsq = NULL;
        return 1;
    }
    else if ((*ppRaiz)->item.Chave > x->Chave) {
        if (Insere(&(*ppRaiz)->pEsq, x))
        {
            if(Balanceamento(ppRaiz))
                return 0;
            else
                return 1;
        }
    }
    else if ((*ppRaiz)->item.Chave < x->Chave) {
        if (Insere(&(*ppRaiz)->pDir, x))
        {
            if(Balanceamento(ppRaiz))
                return 0;
            else
                return 1;
        }
        else
            return 0;
    }
    else
        return 0;
}


void TArvore_Antecessor(TNo* q, TNo **r) {
    TNo *pAux;

    if ((*r)->pDir != NULL) {
        TArvore_Antecessor(q, &(*r)->pDir);
        return;
    }
    q->item = (*r)->item;
    pAux = *r;
    *r = (*r)->pEsq;
    free(pAux);
}

int Remove(TNo** ppRaiz, TItem* pX) {
    if (*ppRaiz == NULL)
        return 0;
    else if ((*ppRaiz)->item.Chave == pX->Chave) {
        *pX = (*ppRaiz)->item;
        TArvore_Antecessor(ppRaiz, &((*ppRaiz)->pEsq)); //Registro mais à direita na subárvore esquerda.
        Balanceamento(ppRaiz);
        return 1;
    } else if ((*ppRaiz)->item.Chave > pX->Chave) {
        if (Remove((*ppRaiz)->pEsq, pX)) {
            Balanceamento(ppRaiz);
            return 1;
        } else return 0;
    }
    else
    {
        if (Remove((*ppRaiz)->pDir, pX)) {
            Balanceamento(ppRaiz);
            return 1;
        }else return 0;
    }
}

int EhArvoreAvl(TNo* pRaiz) {
    int fb;

    if (pRaiz == NULL) return 1;

    if(!EhArvoreAvl(pRaiz->pEsq)) return 0;
    if(!EhArvoreAvl(pRaiz->pDir)) return 0;

    fb = FB(pRaiz);

    if ((fb > 1) || (fb < -1)) return 0;
    else return 1;
}
