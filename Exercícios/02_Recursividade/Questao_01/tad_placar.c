#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tad_placar.h"

void inicia_programa(){

    int quantidade_jogos;
    scanf("%d", &quantidade_jogos);

    //Aloca a memória necessária para armazenar os resultados.
    Resultado *resultados = (Resultado*) malloc(quantidade_jogos * sizeof(Resultado));

    //Obtem os placares dos jogos.
    obtem_placares(resultados, quantidade_jogos);

    exibe_ordens_gols(resultados, quantidade_jogos);

    free(resultados);
}//inicia_programa()

void gera_combinacoes(int marcados_timea, int marcados_timeb, int i, char time, int gols_timea, int gols_timeb, char comb[]){

    if (time != ' ') comb[i] = time;

    //Verifica se todos os gols já foram marcados, caso tenham sido, imprime o resultado.
    if ((marcados_timea + marcados_timeb) == (gols_timea + gols_timeb)) {
        comb[i + 1] = '\0';
        printf("%s\n", comb);
    }
    else
    {   //Verifica se faltam computar gols do timea, caso faltem incrementa os valores e chama a função de forma recursiva.
        if (marcados_timea < gols_timea) {
            gera_combinacoes(marcados_timea + 1, marcados_timeb, i + 1, 'A', gols_timea, gols_timeb, comb);
        }

        //Faz a mesma verificação anterios, mas agora par ao timeb.
        if (marcados_timeb < gols_timeb) {
            gera_combinacoes(marcados_timea, marcados_timeb + 1, i + 1, 'B', gols_timea, gols_timeb, comb);
        }
    }
}//gera_combinacoes


void obtem_placares(Resultado* resultados, int quantidade){
    int pos;
    char X[1];

    for (pos = 0; pos < quantidade; pos++)
        scanf("%d %s %d", &resultados[pos].timea, X, &resultados[pos].timeb);
}//obtem_placares()

void exibe_ordens_gols(Resultado* resultados, int quantidade) {
    int pos;

    for (pos = 0; pos < quantidade; pos++){
        printf("\nJogo %d:\n", pos + 1);
        char* vet = (char*) malloc(10 * sizeof(char));
        gera_combinacoes(0, 0, -1, ' ', resultados[pos].timea, resultados[pos].timeb, vet);
        free(vet);
    }
}//exibe_ordens_gols
