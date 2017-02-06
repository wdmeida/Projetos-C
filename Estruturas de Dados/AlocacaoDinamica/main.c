/*#include <stdio.h>
#include <stdlib.h>

//Preenche o vetor.
void preenche_vetor(int *vetor, int quantidade){
    int i;
    for (i = 0; i < quantidade; i++){
        printf("\nPosição do vetor %d: ", i);
        scanf("%d", &vetor[i]);
    }
}

//Imprime os valores do vetor.
void imprime_valores(int *vetor, int quantidade){
    int i;
    for (i = 0; i < quantidade; i++){
        printf("\nPosição do vetor %d: ", vetor[i]);
    }
}

int main()
{
    int qtd, *vetor;

    //Obtem a quantidade de entradas do usuario.
    printf("\nDigite o tamanho do vetor: ");
    scanf("%d", &qtd);

    //Aloca o vetor dinamicamente.
    vetor = (int*) malloc(qtd * sizeof(int));

    preenche_vetor(vetor, qtd);
    imprime_valores(vetor, qtd);

    //Libera a memoria alocada.
    free(vetor);

    return 0;
}*/
