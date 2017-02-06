#ifndef JOGADORDEFUTEBOL_H_INCLUDED
#define JOGADORDEFUTEBOL_H_INCLUDED

typedef struct{
    char nome[50];
    int jogos;
    int gols;
    int assistencias;
}Jogador;

Jogador* inicializa();
void atribui(Jogador*, char, int, int, int);
void imprime(Jogador*);
void soma(Jogador*, Jogador*);
void ehBom(Jogador*);
void libera(Jogador*);

#endif // JOGADORDEFUTEBOL_H_INCLUDED
