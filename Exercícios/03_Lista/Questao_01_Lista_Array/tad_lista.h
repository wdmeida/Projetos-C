#ifndef TAD_LISTA_H_INCLUDED
#define TAD_LISTA_H_INCLUDED

#define INICIO 0
#define MAXTAM 1000

/*
    Vantagens:
        Economia de memória (apontadores implícitos).
        Acesso a qualquer elemento da lista é feito em tempo 0(1).

    Desvantagens:
        Custo para inserir da lista pode ser O(n).
        Custo para retirar da lista pode ser O(n).
        Quando não existe previsão sobre o crescimento da lista, o array
        que define a lista deve ser alocado de forma dinâmica.
        Pode ser necessária a realocação do array.
*/

typedef struct{
    int chave;
    //Demais elementos.
}TItem;

typedef struct{
    TItem item[MAXTAM];
    int primeiro,
        ultimo;
}TLista;

void TLista_cria(TLista*);
int TLista_eh_vazia(TLista*);
int TLista_insere(TLista*, TItem);
int TLista_retira(TLista*, int, TItem*);
void TLista_imprime(TLista*);
int TLista_get(TLista*, int, TItem*);
int TLista_tamanho(TLista*);
int TLista_concatena(TLista*, TLista*, TLista*);
int TLista_divide(TLista*, TLista*);
int TLista_copia(TLista*, TLista*);
int TLista_pesquisa(TLista*, TItem);

#endif // TAD_LISTA_H_INCLUDED
