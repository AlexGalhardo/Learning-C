/* FGETS == FILE GET STRING */

#include <stdio.h>
#include <stdlib.h>

int main(){

	/* para ler uma string de um arquivo */

	/* DEFINIÇÃO

	char *fgets(char *str, int tamanho, FILE *fp);
	
	*/

	char str[20];
	FILE *arq;

	arq = fopen("arquivo.txt", "r");

	if(arq == NULL){
		printf("\nERRO na abertura\n");
		exit(1);
	}


	/*A função fgets() lê uma string até encontrar
	um caractere de nova linha (\n) ou *tamanho-1 caracteres */


	char *result = fgets(str, 20, arq); // lê 11 character do file arq e guarde na string str

	if(result==NULL){
		printf("erro na leitura\n");
	}
	else{
		printf("%s", str);
	}

	printf("\n");

	fclose(arq);

	return 0;
}