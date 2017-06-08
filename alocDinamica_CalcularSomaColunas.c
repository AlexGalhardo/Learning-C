/*
4.
(Médio)
Desenvolva  um  programa  em  C  que  leia  uma  matriz  NxN  de  inteiros.   Em
seguida, calcule a soma dos elementos de cada coluna, armazenando o resultado da soma
em um vetor de N elementos.  Obs:  n ~ao deve ocorrer desperd ´icio de mem ´oria; e ap ´os ser
utilizada a mem ´oria deve ser liberada.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	int lin, col;
	int **matriz;
	int *vet_soma;
	int i, j;
	
	printf("Digite o tamanho da matriz: \n");
	printf("Numero de linhas: \n");
	scanf("%d", &lin);
	matriz = (int **) malloc(sizeof(int*) * lin);
	
	for(i=0; i<lin; i++){
		matriz[i] = (int *) malloc(sizeof(int) * col);
	}
	
	vet_soma = (int *) calloc(col, sizeof(int));
	printf("Digite os elementos da matriz: \n");
	int k, l;
	for(k=0; k<lin; k++){
		printf("\nLinha %d: \n", i+1);
		for(l=0; l<col; l++){
			printf("\tColuna %d: ", j+1);
			scanf("%d", &matriz[i][j]);
		}
	}
	
	printf("\n\nMatriz: \n\n");
	for(i=0; i<lin; i++){
		for(j=0; j<col; j++){
			printf("%d\t", matriz[i][j]);
		}
		printf("\n");
	}
	
	for(i=0; i<col; i++){
		for(j=0; j<lin; j++){
			vet_soma[j] += matriz[i][j];
		}
	}
	
	printf("\n\nVetor soma: \n\n");
	for(j=0; j<col; j++){
		printf("%d\t", vet_soma[j]);
	}
	
	printf("\n");
	for(i=0; i<lin; i++){
		free(matriz[i]);
	}
	
	free(matriz);
	free(vet_soma);
	
	return 0;
}
