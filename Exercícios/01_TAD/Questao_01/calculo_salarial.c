#include <stdlib.h>
#include <stdio.h>
#include "calculo_salarial.h"

void inicia_programa() {
   int numero_funcionarios;

   scanf("%d", &numero_funcionarios);

   if(numero_funcionarios > 0) calculo_bonificacao(numero_funcionarios);
}//inicia_programa

void calculo_bonificacao(int numero_funcionarios) {
    //Aloca memória para as informações dos funcionários.
    DadosFuncionario *dados = (DadosFuncionario*) malloc(numero_funcionarios * sizeof(DadosFuncionario));

    //Lê as informações dos funcionários.
    le_informacoes(dados, numero_funcionarios);

    //Imprime o resultado.
    imprime(dados, numero_funcionarios);

    //Libera a memória alocada para o usuário.
    free(dados);
}//calculo_bonificacao()


int efetua_calculo(DadosFuncionario funcionario) {

    //Calculo os anos trabalhados.
    int valor_bonificacao = funcionario.tempo_servico * BONUS_ANO_SERVICO_PRESTADO;

    //Verifica se o funcionário tem mais que 45 anos.
    if(funcionario.idade > 45) valor_bonificacao += ((funcionario.idade - 45) * BONUS_ANO_SERVICO_PRESTADO_ACIMA_45);

    //Calcula a bonificação pelo número de filhos.
    if(funcionario.numero_filhos >= 3) valor_bonificacao += 45;
    else valor_bonificacao += (funcionario.numero_filhos * BONUS_FILHO);

    return valor_bonificacao;
}//efetua_calculo()


//Lé as informações dos funcionários para realizar os cálculos.
void le_informacoes(DadosFuncionario* dados, int tamanho) {
    int i;

    for (i = 0; i < tamanho; i++){

        scanf("%d %d %d %d", &dados[i].numero_inscricao,
                             &dados[i].idade,
                             &dados[i].tempo_servico,
                             &dados[i].numero_filhos);
    }
}//le_informacoes()

void imprime(DadosFuncionario* dados, int tamanho) {
    int i;

    for (i = 0; i < tamanho; i++) {
        printf("\nNumero de inscricao.: %d\nBonus...............: %d\n", dados[i].numero_inscricao, efetua_calculo(dados[i]));
    }
}//imprime

