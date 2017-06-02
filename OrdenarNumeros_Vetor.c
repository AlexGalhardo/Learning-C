// fonte: https://www.youtube.com/watch?v=CbRYQ9fi4dQ&index=36&list=PLa75BYTPDNKZWYypgOFEsX3H2Mg-SzuLW
// ORDENAR NUMEROS DENTRO DE UM VETOR
#include <stdio.h>

int main(void){
	
	int vetor[10] = {6, 1, 1, 9, 8, 0, 5, 7, 3, 2};
	int i;
	
	void ordemCrescente(int vetor[], int n); // declaração da função
	
	
	ordemCrescente(vetor, 10); // quando eu passo um vetor para chamar uma função, eu so preciso falar o nome do vetor
	
	for(i=0; i<10; i++){
		printf("%d", vetor[i]);	
	}
	
	return 0;
}

void ordemCrescente(int vetor[], int n){
	
	int i, j, aux;
	
	for(i=0; i<n; i++){
		for(j=i+1; j<n; j++){
			if(vetor[i] > vetor[j]){
				aux = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = aux;
			}
		}
	}
}
