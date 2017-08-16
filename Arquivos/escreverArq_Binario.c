/*
Escrever um programa em C que escreve os números inteiros de 1 até
100, em um arquivo binário.
*/


#include <stdio.h>

int main(){
	
	char name[] = "dados.bin";

	FILE *arq = fopen(name, "wb"); // WRITE BINÁRIO

	/* CASO O ARQUIVO NÃO EXISTE, VAI CRIAR UM CHAMADO "dados.bin" */
	int i;
	if(arq != NULL){
		for(i=0; i<100; i++){
			fwrite(&i, sizeof(int), 1, arq);
		}
	}
	else{
		printf("erro\n");
		return -1;
	}

	fclose(arq);


	return 0;
}
