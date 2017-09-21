#include <stdio.h>
#include <stdlib.h>

/* TYPEDEF DÁ UM APELIDO PARA ALGUM ELEMENTO DE C */

typedef int inteiro;

struct cadastro{
	char nome[50];
	int idade;
}

typedef struct cadastro cad;

int main(){

	int x = 10;
	inteiro y = 20;
	y = y+x;

	printf("Soma = %d\n", y);

	struct cadastro c1;
	cad c2;

	return 0;
}
