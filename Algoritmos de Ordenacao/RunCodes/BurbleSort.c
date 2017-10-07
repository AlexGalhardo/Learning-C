/*

Bubble Sort
Faça uma implementação do algoritmo de ordenação "bubble sort". O algoritmo deverá ler um número N que indica a quantidade de valores a serem ordenados. Em seguida, numa outra linha, o algoritmo deverá ler um número binário (0 ou 1) que indica se a ordenação deve ser feita em ordem crescente (valor 0) ou decrescente (valor 1). Em uma outra linha, por fim, o algoritmo deverá ler os N valores a serem ordenados, separados par a par por um único espaço. A saída do método deverá ser os valores ordenados e separados par a par por um único espaço.

Exemplo de Entrada e Saída
Entrada:

10
0
5 3 2 7 6 8 9 1 0 4
Saída:

0 1 2 3 4 5 6 7 8 9
*/

#include <stdio.h>
#include <stdlib.h>


int main(){

	int n, op;
	scanf("%d", &n);
	scanf("%d", &op);
	int vetor[n], aux, k, j, i;
	if(op == 0){
		for(i=0; i<n; i++){
			scanf("%d", &vetor[i]);
		}

		for (k = 1; k < n; k++) {
        	for (j = 0; j < n - 1; j++) {
            	if (vetor[j] > vetor[j + 1]) {
                	aux          = vetor[j];
                	vetor[j]     = vetor[j + 1];
                	vetor[j + 1] = aux;
            	}
        	}
        }

		for(i=0; i<n; i++){
			printf("%d ", vetor[i]);
		}

	}
	else{
		for(i=0; i<n; i++){
			scanf("%d", &vetor[i]);
		}

		for (k = 1; k < n; k++) {
        	for (j = 0; j < n-1; j++) {
            	if (vetor[j] < vetor[j + 1]) {
                	aux          = vetor[j];
                	vetor[j]     = vetor[j + 1];
                	vetor[j + 1] = aux;
        		}
        	}
        }

		for(i=0; i<n; i++){
			printf("%d ", vetor[i]);
		}
	}


	return 0;
}
