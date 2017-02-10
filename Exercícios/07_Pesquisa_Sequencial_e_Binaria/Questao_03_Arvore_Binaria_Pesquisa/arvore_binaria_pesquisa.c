#include <stdlib.h>
#include <stdio.h>
#include "arvore_binaria_pesquisa.h"

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
int TArvore_Insere_Retursivo(TNo** ppR, TItem x) {
    //Verifica se o conteúdo do ppr é NULL, caso seja, cria o NO neste local.
    if (*ppR == NULL) {
        *ppR = TNo_Cria(x);
        return 1;
    }

    if (x.Chave < (*ppR)->item.Chave)
        return TArvore_Insere_Retursivo(&((*ppR)->pEsq) , x);
    if (x.Chave > (*ppR)->item.Chave)
        return TArvore_Insere_Retursivo(&((*ppR)->pDir), x);

    return 0;
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
