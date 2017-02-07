#include <stdlib.h>
#include <stdio.h>
#include "calculo_salarial.h"

void inicia_programa() {
   int numero_funcionarios;

   scanf("%d", &numero_funcionarios);

   if(numero_funcionarios > 0) calculo_bonificacao(numero_funcionarios);
   else return;
}//inicia_programa

void calculo_bonificacao(int numero_funcionarios) {
    DadosFuncionario *dados = (DadosFuncionario*) malloc(numero_funcionarios * sizeof(DadosFuncionario));

    int i;
    for (i = 0; i < numero_funcionarios; i++){

        scanf("%d %d %d %d", &dados[i].numero_inscricao,
                             &dados[i].idade,
                             &dados[i].tempo_servico,
                             &dados[i].numero_filhos);
    }

    imprime(dados, numero_funcionarios);

    free(dados);
}//calculo_bonificacao()

void imprime(DadosFuncionario* dados, int tamanho) {
    int i;

    for (i = 0; i < tamanho; i++) {
        printf("\nMatrícula: %d\nIdade: %d", dados[i].numero_inscricao, dados[i].idade);
    }
}//imprime

