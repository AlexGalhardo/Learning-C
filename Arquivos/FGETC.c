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

	char c;
	int i;

	for(i=1; i<=10; i++){
		c = fgetc(f);
		printf("%c", c);
	}

	printf("\nFIM\n");

	fclose(f);

	return 0;
}