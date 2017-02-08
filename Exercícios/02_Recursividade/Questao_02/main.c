#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int visita(char** labirinto, int dimensao, int linha, int coluna) {
	if (linha < 0 || linha >= dimensao || coluna < 0 || coluna >= dimensao) return 0;
	char celula = labirinto[linha][coluna]; // armazena para uso futuro na funcao
	labirinto[linha][coluna] = 1; // nao podera mais visitar esta celula
	if (celula == '1') return 0; // nao pode continuar e ainda nao achou
	if (celula == 'S') return 1; // achou, deve parar a procura
	if (celula == '0' || celula == 'E') { // se for '0' ou 'E' deve que tentar os vizinhos
		// tenta todos os movimentos, se conseguir chegar a 'S' por algum deles, retorna verdadeiro
		if (visita(labirinto, dimensao, linha-1, coluna)) return 1; // tenta celula acima
		if (visita(labirinto, dimensao, linha+1, coluna)) return 1; // tenta celula abaixo
		if (visita(labirinto, dimensao, linha, coluna-1)) return 1; // tenta celula a esquerda
		if (visita(labirinto, dimensao, linha, coluna+1)) return 1; // tenta celula a direita
	}
	return 0; // caso nao atenda a nenhum dos criterios anteriores, retorna falso
}

int main() {
	int n, i, lin, col;
	int dimensao, temCaminho, linhaE, colunaE;
	char** labirinto;
	scanf("%d", &n);
	for (i=0; i<n; i++) {
		scanf("%d", &dimensao);
		labirinto = (char**) malloc(dimensao * sizeof(char*));
		for (lin=0; lin<dimensao; lin++){
			labirinto[lin] = (char*) malloc(dimensao * sizeof(char));
			for (col=0; col<dimensao; col++){
				char teste[2];
				scanf("%s ", teste);
				labirinto[lin][col] = teste[0];
				if(labirinto[lin][col] == 'E') {
					linhaE = lin;
					colunaE = col;
				}
			}
		}
		temCaminho = visita(labirinto, dimensao, linhaE, colunaE);
		printf("Labirinto %d: %s\n", i+1, temCaminho ? "SIM" : "NAO");
		// liberando a memoria
		for (lin=0; lin<dimensao; lin++){
			free(labirinto[lin]);
		}
		free(labirinto);
	}
	return 0;
}
