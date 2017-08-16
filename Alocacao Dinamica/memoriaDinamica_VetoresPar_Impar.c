/*
3.
(Médio)
Desenvolva um programa em C que leia um n ´umero inteiro
n
e um conjunto
n
de valores reais, guarde-os em um vetor e ent ~ao crie outros dois vetores um com os valores
impares e outros com valores pares.  Obs:  n ~ao deve ocorrer desperd ´icio de mem ´oria; e
ap ´os ser utilizada a mem ´oria deve ser liberada.
*/

#include <stdio.h>
#include <stdlib.h>

void imprime(int *vetor, int tam){
	int i;
	printf("\n");
	for(i=0; i<tam; i++){
		printf("%d\t", vetor[i]);
	}
	printf("\n");
}

int main(){
	
	int n, i, num_par=0, num_impar = 0;
	int *vetor, *vet_par = NULL, *vet_impar = NULL;
	
	printf("Digite o tamanho do vetor: ");
	scanf("%d", &n);
	vetor = (int *) malloc(sizeof(int)* n);
	
	for(i=0; i<n; i++){
		printf("Digite o valor %d: ", i);
		scanf("%d", &vetor[i]);
	}
	
	for(i=0; i<n; i++){
		if(vetor[i] % 2==0){
			num_par++;
			vet_par = (int *) realloc(vet_par, sizeof(int) * num_par);
			vet_par[num_par-1] = vetor[i];
		}
		else{
			num_impar++;
			vet_impar = (int *) realloc(vet_impar, sizeof(int) * num_impar);
			vet_impar[num_impar-1] = vetor[i];
		}
	}
	
	imprime(vetor, n);
	imprime(vet_par, num_par);
	imprime(vet_impar, num_impar);
	free(vetor);
	free(vet_par);
	free(vet_impar);
	
	return 0;
}
