#include <stdio.h>
#include <stdlib.h>

int main(){

	/* definição 

		void *calloc(unsigned int num, unsigned int size);

	*/

	// Exemplo:
	// criar array de 50 inteiros(4 bytes cada)
	int *v = (int *) calloc(50, 4);
	// cria array de 200 char(1 byte cada)
	char *c = (char*) calloc(200, 1);

	int *v = (int *) calloc(50, sizeof(int));

	/* DIFERENÇA ENTRE MALLOC E CALLOC

		ambas servem para alocar memória, mas calloc() inicializa
		todos os BITS do espaço alocado com 0's 

	*/

	int i;
	int *p, *p1;

	p = (int *) malloc(5*sizeof(int));
	p1 = (int *) calloc(5, sizeof(int));

	printf("calloc\t\t malloc\n");

	for(i=0; i<5; i++){
		printf("p1[%d] = %d \t", i, p1[i]);
		printf(" p[%d] = %d\n", i, p[i]);
	}

	free(p);
	free(p1);

	return 0;
}