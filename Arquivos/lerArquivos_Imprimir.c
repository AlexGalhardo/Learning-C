/*
Escrever um programa em C que leia os números inteiros de 1 até
100, gravados no arquivo de texto e os imprima na tela
*/

#include <stdio.h>

int main(){

	char name[] = "opaa.txt";

	FILE *arq = fopen(name, "r"); // fopen()-> abre arquivo
								  // "r" -> read = ler o que está dentro do arquivo

	/* NO CASO DE LER OS DADOS DE ALGUM ARQUIVO E IMPRIMIR,
	O PROGRAMA SÓ VAI SER EXECUTADO SE O ARQUIVO "opaa.txt" ESTIVER NO MESMO
	DIRETORIO QUE O PROGRAMA ESTÁ SENDO EXECUTADO */
	
	if(arq != NULL){
		while(!feof(arq)){ // RETORNA VERDADE SE CHEGOU AO FIM DO ARQUIVO
			int value;
			fscanf(arq, "%d", &value);
			printf("%d\n", value);
		}
	}
	else{
		printf("erro\n");
		return -1;
	}

	fclose(arq);

	return 0;
}
