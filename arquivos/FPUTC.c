/* FUNÇÃO PARA PEGAR CADA CHARACTER DENTRO DE UM ARQUIVO */ 
#include <stdio.h>
#include <stdlib.h>

int mian(){

	FILE *f;

	f = fopen("arquivo.txt", "r");

	if(f != NULL){
		printf("ERRO\n");
	}

	/* SUPONDO QUE DENTRO DO ARQUIVO "arquivo.txt" ESTEJA ESCRITO

		Meu programa em C

	*/

	/* NESSE PRIMEIRO CASO ABAIXO, ELE TAMBÉM CONTA OS CHARACTER "ESPAÇO"
	ou seja, vai imprimir somente 

			Meu progra

	*/

	char c;
	int i;

	for(i=1; i<=10; i++){
		c = fgetc(f);
		printf("%c", c);
	}
	printf("\nFIM\n");

	fclose(f);


	/* CASO 2 -- IMPRIMIR CORRETAMENTE */

	char c = fgetc(f);
	while(c != EOF){ // EOF == End Of File
		printf("%c", c);
		c = fgect(f);
	}
	printf("\nFIM\n");

	fclose(f);
	
	return 0;
}
