#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "JogadorDeFutebol.h"

//Aloca espaço de memoria para um jogador
Jogador* inicializa(){
    Jogador* j = (Jogador*) malloc(sizeof(Jogador));
    return j;
}

//Atribui os valores para um jogador.
void atribui(Jogador* j, char nome, int jogos, int assistencias, int gols){
    j->assistencias = assistencias;
    j->jogos = jogos;
    j->gols = gols;
    strcpy(j->nome, nome);
}

//Imprime as informacoes de um jogador.
void imprime(Jogador* j){
    printf("\nEstatisticas do atleta %s\n", j->nome);
    printf("\nGols: %d", j->gols);
    printf("\nAssistencias: %d", j->assistencias);
    printf("\nJogos: %d\n", j->jogos);
}

void soma(Jogador*, Jogador*);


void ehBom(Jogador*);


void libera(Jogador* j){
    free(j);
}
