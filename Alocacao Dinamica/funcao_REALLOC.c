#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int *p = (int *) malloc(50 * sizeof(int)); // 200 byes alocados
	
	/* MAS, digamos que eu tenha errado e gostaria de alocar mais 200 bytes */
	p = (int *) realloc(p, 50 * sizeof(int));
	
	if(p==NULL){
		printf("ERRO: Memoria insuficiente!");
	}
	
	// também posso alocar usando REALLOC como MALLOC
	
	int *b = (int *) realloc(NULL, 50 * sizeof(int));
	// mesma coisa que se eu fazer
	int *c = (int *) malloc(50 * sizeof(int));
	
	//também posso usar realloc para zerar a alocação de memoria
	int *a = (int *) malloc(20 * sizeof(int));
	a = (int *) realloc(a, 0); // -> equivalente a free(a);
	
	return 0;
}
