#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int *p, *b;
	//b = (int *) malloc(sizeof(int)); // lembrar que, a função malloc RETORNA O ENDEREÇO da memoria alocada.
	
	p = (int *) calloc(5, sizeof(int));
	
	//printf("\n\n%d", *b); 
	// vai retornar o lixo de memoria na memoria alocada pelo MALLOC
	
	
	printf("%d\n\n", *p); 
	// vai retornar 0 (zero), porque ao usarmos a função CALLOC, pedimos para a memoria ram
	// para alocar 5 espaços de tamanho sizeof(int) == 5 * 4bytes = 20 bytes de memoria 
	// onde toda essa memoria alocada vai receber o valor 0
	
	
	int i;
	for(i=0; i<5; i++){
		printf("Endereco de p%d = %p  | Valor de p%d = %d\n", i, (p+1), i, *(p+1));
	}
	
	return 0;
}
