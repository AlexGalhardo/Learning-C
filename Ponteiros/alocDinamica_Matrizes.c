#include <stdio.h>
#include <stdlib.h>

int main(){

	/* Alocação de arrays multidimensionais:
	Para alocar um array com mais de 1 dimensão 
	precisamos utilizar o conceito de "ponteiro para ponteiro"
	*/

	/* ponteiro(1 nivel): cria um vetor */
	int *p = (int *) malloc(5*sizeof(int));


	/*ponteiro para ponteiro(2 nivel): cria uma matriz */
	int **m;


	/* ponteiro para ponteiro para ponteiro(3 nivel): 
	permite criar um array de 3 dimensões */
	int ***d;


	int **p; // 2 * = 2 niveis = 2 dimensões
	int i, j, N = 2;

	p = (int **) malloc(N * sizeof(int*));

	for(i=0; i<N; i++){
		//criar um array de int
		p[i] = (int *) malloc(N * sizeof(int));
	}

	// LIBERAR MEMORIA É O PROCESSO INVERSO

	for(i=0; i<N; i++){
		free(p[i]);
	}
	
	return 0;
}