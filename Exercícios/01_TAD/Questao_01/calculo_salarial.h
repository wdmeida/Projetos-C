#ifndef CALCULO_SALARIAL_H_INCLUDED
#define CALCULO_SALARIAL_H_INCLUDED

/*

    Uma empresa pretende atribuir um Bônus de Natal aos seus empregados, em função da idade, do tempo de serviço
    (em anos) e do número de filhos. O Bônus é calculado da seguinte forma:

        • R$ 20,00 por ano de serviço prestado.
        • R$ 5,00 por cada ano de serviço, acima dos 45 anos de idade.
        • R$ 15,00 por filho, com teto de R$ 45,00.

    Escreva um programa que, a partir da leitura do número de inscrição, da idade, tempo de serviço e número de
    filhos de um empregado, calcule o valor do bônus correspondente. Você deve fazer um programa que receba dados
    numéricos e imprima o valor do bônus natalino.

*/

#define BONUS_ANO_SERVICO_PRESTADO 20
#define BONUS_ANO_SERVICO_PRESTADO_ACIMA_45 5
#define BONUS_FILHO 15

typedef struct{
    int numero_inscricao;
    int idade;
    int tempo_servico;
    int numero_filhos;
    int bonificacao;
}DadosFuncionario;

void inicia_programa();
void calculo_bonificacao(int);
int efetua_calculo(DadosFuncionario);
void le_informacoes(DadosFuncionario*, int);
void imprime(DadosFuncionario*, int);
#endif // CALCULO_SALARIAL_H_INCLUDED
