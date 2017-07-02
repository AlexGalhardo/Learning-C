#include <stdio.h>
#include <stdlib.h>

int main(){

	/* serve para alocar ou realocar memória durante a execução
	do programa. Ela faz o pedido de memória do computador, 
	e retorna um ponteiro com o endereço do inicio do espaço de memoria alocado. 

		void *realloc(void *ptr, unsigned int num);

	*/

	int *v = (int *) malloc(50 * sizeof(int)); // alocado 200 bytes primeiramente
	// MAS, eu percebo que preciso de mais memória
	v = (int *) realloc(100 * sizeof(int));

	/* também posso usar realloc para alocar memória */

	int *p;
	p = (int *) realloc(NULL, 50*sizeof(int));
	// equivale a
	p = (int *) malloc(50*sizeof(int));




	return 0;
}