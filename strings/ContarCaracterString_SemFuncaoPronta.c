// Contar caracteres de uma string
#include <stdio.h>

int main(){
	
	int tamanhoString(char string[]);
	char stringUsuario[20];
	
	printf("Digite uma palavra(string): \n");
	scanf("%s", stringUsuario);
	
	int num = tamanhoString(stringUsuario);
	
	printf("A palavra %s possui %d caracteres!\n", stringUsuario, num);
	return 0;
}

int tamanhoString(char stringUsuario[]){

	int contador;

	while(stringUsuario[contador] != '\0'){
		++contador;
	}
	return contador;
}
