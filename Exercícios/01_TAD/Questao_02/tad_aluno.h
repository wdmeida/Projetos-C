#ifndef TAD_ALUNO_H_INCLUDED
#define TAD_ALUNO_H_INCLUDED
#define PIOR_ALUNO 1
#define MELHOR_ALUNO 0

typedef struct{
    char nome[50];
    int nota1,
        nota2,
        nota3,
        nota4;
    float media;
}Aluno;

void inicia_programa();
void obtem_informacoes(Aluno*, int);
void calcula_media(Aluno*, int);
Aluno obtem_aluno_criterio(Aluno*, int, int);
int valida_nome(Aluno);
void imprime_informacao_aluno(Aluno);
void relatorio_final(Aluno, Aluno);
#endif // TAD_ALUNO_H_INCLUDED
