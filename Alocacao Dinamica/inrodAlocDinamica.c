#include <stdio.h>
#include <stdlib.h>

int main(){

	/*
	char: 1 byte
	int: 4 bytes
	float: 4bytes
	double: 8 bytes
	*/
	sizeof(nome_do_tipo); // diz quantos bytes é necessário para armazenar na memoria

	int x = sizeof(int);

	printf("%d", x); // vai retornar 4

	/* função malloc()
	serve para alocar memória durante a execução do programa.
	Ela faz o pedido de memória ao computador
	e retorna um ponteiro com o endereço do início do espaço de memória alocado 

		void * malloc(unsigned int num);

	*/

	// quero array de 50 inteiros
	int *v = malloc(50 * sizeof(int));
	// quero array de 200 char (1 char = 1 byte)
	char *c = malloc(200 * sizeof(char));

	// EXEMPLO 
	/* se não houver memória suficiente para alocar a memória requisitada,
	a função malloc() retorna NULL */

	int *p;
	p = (int *) malloc(5*sizeof(int));

	if(p==NULL){
		printf("ERRO: SEM MEMÓRIA!");
		exit(1); // termina o programa
	}

	int i;
	for(i=0; i<5; i++){
		printf("Digite p[%d]: ", i);
		scanf("%d", &p[i]);
	}

	free(p); // quando eu não usar mais o programa, eu libero memoria usando free()
	return 0;
}