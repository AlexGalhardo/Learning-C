/*
Desenvolva um programa em C que solicita ao usu ´ario a quantidade de alunos de
uma turma e aloca um vetor de notas (n ´umeros reais).  Depois de ler as notas, imprime
a média aritmética.  Obs:  não deve ocorrer desperdício de memória; e ap ´os ser utilizada
a memória deve ser liberada.
*/
#include <stdio.h>
#include <stdlib.h>

void imprime(float *vetor, int tam){
	printf("\n");
	
	int i;
	
	for(i=0; i<tam; i++){
		printf("%g\t", vetor[i]);
	}
	printf("\n");
}

int main(){
	
	int n, i;
	float *vetor, media=0;
	
	printf("Digite o numero de alunos: ");
	scanf("%d", &n);
	
	vetor = (float *) malloc(sizeof(float) * n);
	
	for(i=0; i<n; i++){
		printf("Digite nota %d: ", i);
		scanf("%f", &vetor[i]);
	}	
	
	for(i=0; i<n; i++){
		media += vetor[i];
	}
	
	media = media/n;
	imprime(vetor, n);
	printf("A media eh: %g\n", media);
	free(vetor);
	
	return 0;
}
