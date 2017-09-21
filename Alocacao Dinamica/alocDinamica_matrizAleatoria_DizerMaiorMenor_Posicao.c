/*
Desenvolva um programa em C que gere dois n ´umeros positivos M e N aleat ´orios
e gere automaticamente uma matriz MxN (M e N gerados previamente) com n ´umero
aleat ´orios.   Imprima  as  coordenadas  (linha  x  coluna)  do  maior  e  do  menor  elemento.
Obs:  n ~ao deve ocorrer desperd ´icio de mem ´oria; e ap ´os ser utilizada a mem ´oria deve ser
liberada.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define MAX 20
#define MAX_V 1000
#define MIN_V -1000

int main(){
	
	int m, n, i, j;
	int **matriz;
	int valMax = INT_MIN, valMin = INT_MAX;
	int linMax, colMax, linMin, colMin;
	
	srand(time(NULL));
	
	m = (rand() % MAX)+1;
	n = (rand() % MAX)+1;
	
	matriz = (int **) malloc(sizeof(int*)*m);
	
	for(i=0; i<m; i++){
		matriz[i] = (int *) malloc(sizeof(int) * n);
	}
	
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			matriz[i][j] = (rand() % (MAX_V + 1 - MIN_V)) + MIN_V;
		}
	}
	
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			if(matriz[i][j]>valMax){
				valMax = matriz[i][j];
				linMax = i;
				colMax = j;
			}
			if(matriz[i][j]<valMin){
				valMin = matriz[i][j];
				linMin = i;
				colMin = j;
			}
		}
	}
	
	printf("\n\n");
	
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			printf("%d\t", matriz[i][j]);
		}
		printf("\n");
	}
	
	printf("\nMaior valor eh %d, que se encontra na linha %d e na coluna %d\n", valMax, linMax, colMax);
	printf("\nMenor valor eh %d, que se encontra na linha %d e na coluna %d\n", valMin, linMin, colMin);
	
	
	for(i=0; i<m; i++){
		free(matriz[i]);
	}
	free(matriz[i]);
	
	return 0;
}
