#ifndef TAD_PLACAR_H_INCLUDED
#define TAD_PLACAR_H_INCLUDED

typedef struct{
    int timea;
    int timeb;
}Resultado;

void inicia_programa();
void gera_combinacoes(int, int, int, char, int, int, char*);
void obtem_placares(Resultado*, int);
void exibe_ordens_gols(Resultado*, int);
#endif // TAD_PLACAR_H_INCLUDED
