#ifndef TAD_ALUNO_H_INCLUDED
#define TAD_ALUNO_H_INCLUDED

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
void verifica_status_alunos(Aluno*, int);
int valida_nome(Aluno);
void imprime(Aluno);

#endif // TAD_ALUNO_H_INCLUDED
