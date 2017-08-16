/*
Escrever um programa em C que leia os números inteiros de 1 até
100, gravados no arquivo binário anterior.
*/


#include <stdio.h>

int main(){

	char name[] = "dados.bin";

	FILE *arq = fopen(name, "rb");

	/* SÓ VAI EXECUTAR O CÓDIGO E NÃO PRINTAR ERRO, SE O ARQUIVO
	"dados.bin" ESTIVER NO MESMO DIRETORIO DO PROGRAMA EXECUTAVEL */

	
	if(arq != NULL){		// RETORNA VERDADE SE CHEGOU AO FIM DO ARQUIVO
		while(!feof(arq)){ // ENQUANTO NÃO ESTIVER NO FIM DO ARQUIVO, CONTINUE O LAÇO 
			int i;
			fread(&i, sizeof(int), 1, arq);
			printf("%d", i);
		}
	}
	else{
		printf("erro\n");
		return -1;
	}

	fclose(arq);

	return 0;
}
