#include <stdlib.h>
#include <stdio.h>
#include "tad_placar.h"

void gera_combinacoes(int marcados_timea, int marcados_timeb, int i, char time, int gols_timea, int gols_timeb, char comb[]){

   if (time != ' ') {
      comb[i] = time;
   }

   if ((marcados_timea + marcados_timeb) == (gols_timea + gols_timeb)) {
      comb[i + 1] = '\0';
      printf("%s\n", comb);
   }
   else {
      if (marcados_timea < gols_timea) {
         gera_combinacoes(marcados_timea + 1, marcados_timeb, i + 1, 'A', gols_timea, gols_timeb, comb);
      }

      if (marcados_timeb < gols_timeb) {
         gera_combinacoes(marcados_timea, marcados_timeb + 1, i + 1, 'B', gols_timea, gols_timeb, comb);
      }
  }
}//gera_combinacoes

void inicia_programa(){

    int quantidade_jogos;
    scanf("%d", &quantidade_jogos);


    char vet[10];

    gera_combinacoes(0, 0, -1, ' ', 3, 1, vet);

}//inicia_programa()
