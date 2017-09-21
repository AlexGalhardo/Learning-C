/* FPUTS = FILE PUT STRING */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	/* escrever uma string dentro de um arquivo */
	FILE *f;

	f = open("arquivo.txt", "w");

	// EXEMPLO 1
	if(f == NULL){
		printf("ERRO\n");
		exit(1);	
	}

	char texto[20] = "Meu programa em C";

	int retorno = fputs(texto, f); // coloque string texto dentro do file f

	if(retornp == EOF){
		printf("Erro na gravação\n");
	}

	fclose(f);

	// EXEMPLO 2

	fputs("Hello", f);
	fputs("World!", f);

	fclose(f);


	return 0;
}