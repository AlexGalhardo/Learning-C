/*

“Faça um programa que leia duas matrizes 3 x 3 e em seguida calcule e 
apresente a multiplicação dessas matrizes.”

*/

#include <stdlib.h>
#include <stdio.h>

int leMatriz(int l, int c, int **mat);
int multMatriz(int l, int c, int **matA, int **matB, int **matC);

int main(){
	
	int **matA, **matB, **matC, l=3, c=3, i;
	
	// alocando memoria para a MATRIZ A
	matA = (int **) malloc(sizeof(int)*l); // alocar memoria de acordo com o numero de linhas da matriz A
	for(i=0; i<l; i++){
		matA[i] =  (int *) malloc(sizeof(int)*c); // para cada linha, alocar memoria memoria de acordo com o numero de colunas
	}
	
	// alocando memoria para a MATRIZ B
	matB = (int **) malloc(sizeof(int)*l);
	for(i=0; i<l; i++){
		matB[i] = (int *) malloc(sizeof(int)*c);
	}
	
	// alocando memoria para a MATRIZ C
	matC = (int **) malloc(sizeof(int)*l);
	for(i=0; i<l; i++){
		matC[i] = (int *) malloc(sizeof(int)*c);
	}
	
	printf("\n -- MATRIZ A --");
	leMatriz(l, c, matA);
	printf("\n -- MATRIZ B --");
	leMatriz(l, c, matB);
	
	printf("\n\n MULTIPLICACAO DAS MATRIZES \n\n");
	multMatriz(l, c, matA, matB, matC);
	
	return 0;
}


int leMatriz(int l, int c, int **mat){
	
	int i, j;
	
	for(i=0; i<l; i++){
		for(j=0; j<c; j++){
			printf("\nDigite a posicao[%d][%d] da matriz: \n", i+1, j+1);
			scanf("%d", &mat[i][j]);
		}
	}	
}

int multMatriz(int l, int c, int **matA, int **matB, int **matC){
	
	int i, j, k;
	
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			matC[i][j] = 0;
			for(k=0; k<3; k++){
				matC[i][j] += matA[i][k] * matB[k][j];
			printf("%d+", matC[i][j]);
			}
		printf("\n");
		}
	}
	
	
	
}
