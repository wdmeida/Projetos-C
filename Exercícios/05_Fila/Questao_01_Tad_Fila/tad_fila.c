#include <stdlib.h>
#include <stdio.h>
#include "tad_fila.h"

Fila cria_fila() {
    Fila f = (Fila) malloc(sizeof(TFila));
    if(!f) return NULL;

    f->pPrimeiro = NULL;
    f->pUltimo = NULL;
    f->tamanho = 0;
    return f;
}//cria_fila()

int tamanho_fila(Fila);
int fila_vazia(Fila);
int enfileira(Fila, TElemento);
int desenfileira(Fila, TElemento*);
void libera_memoria_alocada(Fila);
