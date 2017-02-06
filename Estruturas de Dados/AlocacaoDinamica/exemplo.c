#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int idade;
    float salario;
}TRegistro;

void preenche_registro(TRegistro *t, int qtd){
    TRegistro a;
    int i;

    for(i = 0; i < qtd; i++){
        //a = (TRegistro*) malloc(sizeof(TRegistro));
        printf("\nIdade: ");
        scanf("%d", &a.idade);
        printf("\nSalario: ");
        scanf("%f", &a.salario);

        t[i] = a;
    }
}

void imprime_resultado(TRegistro *t, int qtd){
    int i;

    for(i = 0; i < qtd; i++){
        printf("\nRegistro %d:\n", i + 1);
        printf("\nIdade: %d", t[i].idade);
        printf("\nSalario: %.2f\n\n", t[i].salario);
    }
}

void libera_memoria(TRegistro *t, int qtd){
    int i;

    for(i = 0; i < qtd; i++){
        //free(&t[i]);
    }
    free(t);
}

int main()
{
   TRegistro *t;
   int qtd;

   printf("\nDigite a quantidade de registros: ");
   scanf("%d", &qtd);

   //Aloca a memoria utilizada para o vetor.
   t = (TRegistro*) malloc(qtd * sizeof(TRegistro));

   //Preenche os registros.
   preenche_registro(t, qtd);

   //Imprime o resultado.
   imprime_resultado(t, qtd);

   //Libera a memoria utilizada.
   libera_memoria(t, qtd);
   return 0;
}
