// burble sort slide

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#define MAX 100
#define Aleatorio() (-10+rand()%(((10)-(-10)+1))

void iniciaVet(int *vector, int n);
void imprimeVet(int *vector, int n);
void bubbleSort(int *, int);

int main(){
	
	int v[MAX], n=10;
	srand(time(NULL));
	
	iniciaVet(v, n);
	printf("--- Vetor aleatorio ---\n");
	imprimeVet(v, n);
	bubbleSort(v, n);
	printf("--- Vetor Ordenado ---\n");
	imprimeVet(v, n);
	
	return 0;
}


void iniciaVet(int *vector, int n){
	int i;
	
	for(i=0; i<n; i++){
		vector[i] = rand() % 20 + 1; // aleatorios de 1 a 20
	}
}

void imprimeVet(int *vector, int n){
	int i;
	
	printf("[");
	for(i=0; i<n; i++){
		printf(" %d", vector[i]);
	}
	printf("]\n");
}

void bubbleSort(int *vector, int size){
	
	int i, j, aux;
	for(i=0; i<size-1; i++){
		for(j=size-1; j>i; --j){
			if(vector[j-1]>vector[j]){
				aux = vector[j-1];
				vector[j-1] = vector[j];
				vector[j] = aux;
			}
		}
	}
}
