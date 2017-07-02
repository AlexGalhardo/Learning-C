/* FUNÇÃO PARA COLOCAR CADA CARACTERE DENTRO DE UM ARQUIVO */

#include <stdio.h>
#include <string.h>

int main(){

	FILE *f;
	f = fopen("arquivo.txt", "w");

	if(f !=NULL){
		printf("ERRO NA ABERTURA\n");
		exit(1); // parar o programa
	}

	char texto[20] = "Meu programa em C";

	int i;

	for(i=0; i<strlen(texto); i++){
		fputc(texto[i], f);
	}

	fclose(f);

	return 0;
}
