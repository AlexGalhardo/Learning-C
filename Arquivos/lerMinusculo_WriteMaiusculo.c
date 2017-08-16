#include <stdio.h>
#include <stdlib.h>

int main(){

	FILE *f1, *f2;

	f1 = fopen("minusculo.txt", "r"); // ler arquivos aqui
	f2 = fopen("MAIUSCULO.txt", "w"); // escrever aqui

	if(f1 == NULL || f2 == NULL){
		printf("ERRO na abertura\n");
		exit(1);
	}

	char c = fgetc(f1); // variavel c recebe primeiro caractere do arquivo f1
	while(c != EOF){ // enquanto caractere não chegar no final, continue laço
		fputc(toupper(c), f2); // FILE PUT CARACTERE, coloque em maiuscula a variavel c, e adicione no arquivo f2
		c = fgetc(f1); // variavel c recebe proximo caractere do arquivo f1
	}

	fclose(f1);
	fclose(f2);

	return 0;
}