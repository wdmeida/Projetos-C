#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tad_aluno.h"

void inicia_programa() {
    int quantidade;

    //Obtém a quantidade de registros a serem lidos e limpa o buffer de entrada.
    scanf("%d", &quantidade);
    setbuf(stdin, NULL);

    //Aloca memória para armazenar as informações e inicia a coleta das mesmas.
    Aluno* alunos = (Aluno*) malloc(quantidade * sizeof(Aluno));

    //Inicia a coleta de informações.
    obtem_informacoes(alunos, quantidade);

    //Calcula a média das notas dos alunos.
    calcula_media(alunos, quantidade);

    //Exibe o melhor e o pior aluno.
    relatorio_final(obtem_aluno_criterio(alunos, quantidade, PIOR_ALUNO),
                    obtem_aluno_criterio(alunos, quantidade, MELHOR_ALUNO));

    //Libera a memória alocada.
    free(alunos);
}//inicia_programa

void obtem_informacoes(Aluno* alunos, int quantidade) {
    int cont;

    for(cont = 0; cont < quantidade; cont++) {
        //Obtém os dados dos alunos.
        fgets(alunos[cont].nome, 50, stdin);
        setbuf(stdin, NULL);

        scanf("%d %d %d %d", &alunos[cont].nota1,
                             &alunos[cont].nota2,
                             &alunos[cont].nota3,
                             &alunos[cont].nota4);
        setbuf(stdin, NULL);
    }

}//obtem_informacoes

void calcula_media(Aluno* alunos, int quantidade) {
    int cont;

    for (cont = 0; cont < quantidade; cont++) {
        alunos[cont].media = (float) (alunos[cont].nota1 + alunos[cont].nota2 + alunos[cont].nota3 + alunos[cont].nota4) / 4;
        printf("%.2f", alunos[cont].media);
        imprime_informacao_aluno(alunos[cont]);
    }
}

Aluno obtem_aluno_criterio(Aluno* alunos, int quantidade, int criterio) {
    Aluno aluno = alunos[0];

    int cont;

    switch(criterio){
        case MELHOR_ALUNO:
            for (cont = 1; cont < quantidade; cont++){
                if(alunos[cont].media > aluno.media)
                    aluno = alunos[cont];
            }
        break;

        case PIOR_ALUNO:
            for (cont = 1; cont < quantidade; cont++){
                if(alunos[cont].media < aluno.media)
                    aluno = alunos[cont];
            }
        break;
    }

    return aluno;
}//obtem_aluno_criterio

int valida_nome(Aluno aluno) {
    return 0;
}

void imprime_informacao_aluno(Aluno aluno) {
    printf("\nNome.....: %sMedia....: %.2f\nSituacao.:", aluno.nome, aluno.media);
    (aluno.media >= 6) ? printf(" Aprovado") : printf(" Reprovado");
}//imprime

void relatorio_final(Aluno pior, Aluno melhor) {
    printf("\n\nMelhor Aluno.: %sPior Aluno...: %s", melhor.nome, pior.nome);
}//relatorio_final
