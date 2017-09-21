#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *criaVetor(int *);
int *criaVetor_B(int *);
void imprimeVet(int *vector, int n);

int main(){
	
	int *v, n;
	
	srand(time(NULL));
	
	v = criaVetor_B(&n);
	
	imprimeVet(v, n);
	
	free(v);
	
	return 0;
}

int *criaVetor(int *size){
	
	int *vector, i;
	printf("Tamanho vetor: ");
	scanf("%d", size);
	vector = (int *) malloc((*size)*sizeof(int));
	
	if(vector==NULL){
		printf("Erro de alocação!!!");
		return 0;
	}
	
	for(i=0; i<(*size); i++){
		vector[i] = -5 + rand() % 10+1;
	}
	return vector;
}

int *criaVetor_B(int *size){
	
	int *vector=NULL, aux;
	*size = 0;
	
	aux = -5 + rand() % 20 +1;
	
	while(aux!=-1){
		*size = *size +1;
		vector = (int *) realloc(vector, (*size)*sizeof(int));
		if(vector==NULL){
			printf("Erro na alocação!!!");
			return 0;
		}
		vector[*size-1] = aux;
		aux = -5 + rand() % 10 + 1;
	}
	
	return vector;
}

void imprimeVet(int *vector, int n){
	
	int i;
	
	printf("[ ");
	for(i=0; i<n; i++){
		//printf("[ ");
		printf("%d ", vector[i]);
	}
	printf(" ]");
}
