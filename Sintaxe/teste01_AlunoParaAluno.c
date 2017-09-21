// system("pause"); comando para o DOS do windows parar~ má prática de programação

#include <stdio.h>
#include <stdlib.h>

int main(){
	/*
	\a -> fazer som ao compilar programa
	\0 -> dizer onde é o final da string
	\b -> mover cursor para esquerda
	\t -> da um espaço
	\"Alex\" -> imprimir comando com aspas
	*/
	
	int x = 136; // -> a na tabela ASCII
	printf("%c", x);
	
	char c = 'c'; // -> 99 na tabela ASCII
	printf("\n%i", c);
	
	if(x < 'a'){
		printf("\nEH menor!");
	}
	
	printf("\n\"Alex Galhardo\""); // imprimir com aspas
	
	getchar();
	
	return 0;
}
