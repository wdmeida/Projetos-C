#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "ordenacao.h"

//Compara elementos adjacentes e os troca de lugar se
//estiverem na ordem errada.

/*
    Melhor Caso: O(N)
    Pior Caso: O(N^2)
    Não recomendado para grande conjunto de dados.
*/
void bubble_sort(int *v, int tamanho) {
    int i, continua, aux, fim = tamanho;

    do {
        continua = 0;

        for (i = 0; i < fim - 1; i++) {
            if(v[i] > v[i+1]){
                aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                continua = i;
            }
        }
        fim--;

    } while(continua != 0);
}//bubble_sort()


//Similar a ordenação de cartas de baralho com as mãos.
//Pega-se uma carta de cada vez e a coloca em seu devido lugar.

/*
    Melhor caso: O(N)
    Pior caso: O(N^2)
    Eficiente para conjuntos pequenos de dados.
    Estável: Não altera a ordem de dados iguais.
    Capaz de ordenar os dados a medida em que os recebe (tempo real).
*/
void insection_sort(int *v, int tamanho) {
    int i, j, aux;

    for (i = 1; i < tamanho; i++) {
        aux = v[i];

        for (j = i; (j > 0) && (aux < v[j - 1]); j--)
            v[j] = v[j - 1];
        v[j] = aux;
    }
}//inserction_sort()


//A cada passo, procura o menor valor do array e o coloca na primeira posição.
//Descarta-se a primeira posição do array e repete-se o processo para a segunda posição.

/*
    Melhor caso: O(N^2)
    Pior caso: O(N^2)
    Ineficiente para grandes conjuntos de dados.
    Instável: Altera a ordem de dados iguais (pode ser modificado para ser estável).
*/
void selection_sort(int *v, int tamanho) {
    int i, j, menor, troca;

    for (i = 0; i < tamanho - 1; i++) {
        menor = i;

        //Procura o menor elemento em relação a "i".
        for(j = i + 1; j < tamanho; j++) {
            if (v[j] < v[menor])
                menor = j;
        }

        //Troca os valore da posição autal com a "menor".
        if (i != menor) {
            troca = v[i];
            v[i] = v[menor];
            v[menor] = troca;
        }
    }
}//selection_sort()



//Dividir e conquistar.
//Divide, recursivamente, o conjunto de dados até que cada subconjunto possua 1 elemento.
//Combina 2 subconjuntos de forma a obter 1 conjunto maior e ordenado.
//Esse processo se repete até que exista apenas 1 conjunto.

/*
    Melhor Caso: O(N log N)
    Pior Caso: O(N log N)
    Estável: Não altera a ordem de dados iguais.
    Desvantagens: recursivo e usa um vetor auxiliar durante a ordenação.
*/
void merge_sort(int *v, int inicio, int fim) {
    int meio;

    if(inicio < fim) {
        meio = floor((inicio + fim) / 2);
        //Chama a função para as duas metades.
        merge_sort(v, inicio, meio);
        merge_sort(v, meio + 1, fim);

        //Combina as 2 metades ordenadas.
        etapa_merge(v, inicio, meio, fim);
    }
}//merge_sort()

void etapa_merge(int *v, int inicio, int meio, int fim) {
    int *temp, p1, p2, tamanho, i, j, k;

    int fim1 = 0, fim2 = 0;
    tamanho = fim - inicio + 1;

    p1 = inicio;
    p2 = meio + 1;

    temp = (int*) malloc(sizeof(tamanho * sizeof(int)));

    if(temp != NULL) {
        for (i = 0; i < tamanho; i++) {
            if(!fim1 && !fim2) {
                if(v[p1] < v[p2])
                    temp[i] = v[p1++];
                else
                    temp[i] = v[p2++];

                if(p1 > meio) fim1 = 1;
                if(p2 > meio) fim2 = 1;
            }
            else
            {
                if(!fim1)
                    temp[i] = v[p1++];
                else
                    temp[i] = v[p2++];
            }
        }//for()

        for (j = 0, k = inicio; j < tamanho; j++, k++)
            v[k] = temp[j];
    }
    free(temp);
}//merge()


//Idéia básica: Dividir e Conquistar.
//Um elemento é escolhido como pivô.
//Particionar: Os dados são rearranjados (valores menores do que o pivô são
//colocados antes dele e os maiores, depois.
//Recursivamente ordena as 2 partições.

/*
    Melhor Caso: O(N log N)
    Pior Caso (raro): O(N^2)
    Estável: Altera a ordem de dados iguais, pode ser modificado para ser estável.
    Desvantagens: Como escolher um bom pivô?
*/
void quick_sort(int *v, int inicio, int fim) {
    int pivo;

    if(fim > inicio) {
        pivo = particiona(v, inicio, fim);
        quick_sort(v, inicio, pivo + 1);
        quick_sort(v, pivo + 1, fim);
    }
}//quick_sort()

int particiona(int *v, int inicio, int fim) {
    int esq, dir, pivo, aux;

    esq = inicio;
    dir = fim;
    pivo = v[inicio];

    while (esq < dir) {
        //Avança a posição da esquerda.
        while(v[esq] <= pivo) esq++;

        //Avança a posição da direita.
        while(v[dir] > pivo) dir--;

        //Troca esq e dir.
        if (esq < dir) {
            aux = v[esq];
            v[esq] = v[dir];
            v[dir] = aux;
        }
    }
    v[inicio] = v[dir];
    v[dir] = pivo;
    return dir;
}//particiona()


//Heap: vetor que simula uma árvore binária completa (exceção do último nível).
//Todo elemento pai do vetor possui dois elementos como filhos.
//"pai" (i) -> "filhos": (2 * i + 1) e (2 * i + 2).

void heap_sort(int *v, int tamanho) {
    int i, aux;

    //Criar heap a partir dos dados.
    for (i = (tamanho - 1) / 2; i >= 0; i--) {
        cria_heap(v, i, tamanho - 1);
    }

    for (i = tamanho - 1; i >= 1; i--) {
        //Pega o maior elemento do heap e coloca na sua posição correspondente no array.
        aux = v[0];
        v[0] = v[i];
        v[i] = aux;
        //Recontrói o heap.
        cria_heap(v, 0, i - 1);
    }
}//heap_sort()

void cria_heap(int *v, int inicio, int fim) {
    int aux = v[inicio];

    //Cálcula um dos filhos.
    int j = inicio * 2 + 1;

    while (j <= fim) {
        //Verifica se o pai tem 2 filhos e quem é maior.
        if (j < fim) {
            //Compara os dois filhos.
            if (v[j] < v[j + 1]) {
                j = j + 1;
            }
        }
        //Caso o filho for maior que o pai, ele se torna o pai.
        if (aux < v[j]) {
            v[inicio] = v[j];
            inicio = j;
            j = 2 * inicio + 1;
        }
        else
        {
            j = fim + 1;
        }
    }
    //Antigo pai ocupa o lugar do último filho analisado.
    v[inicio] = aux;
}//cria_heap()
