/*
Escrever um programa em C que escreve os números inteiros de 1 até
100 em um arquivo de texto, pulando uma linha entre cada número
lido.

*/

#include <stdio.h>

int main(){

	char name[] = "teste.txt"; // pode ser arquivo já existente ("TEM QUE ESTAR NO MESMO DIRETORIO DO PROGRAMA C"), ou irá criar um novo arquivo

	FILE *arq = fopen(name, "w"); // write 

	int i;
	if(arq != NULL){ // verifica se o ponteiro está apontando para um tipo file
		for(i=0; i<100; i++){
			fprintf(arq, "i = %d\n", i); // writing in file
		}
	}
	else{
		printf("erro\n");
	}
	fclose(arq); // close arquivo

	return 0;
}
