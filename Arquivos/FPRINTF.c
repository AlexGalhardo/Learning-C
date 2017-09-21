#include <stdio.h>
#include <stdlib.h>

int main(){

	/* definição
	
		fprintf(FILE *f, "tipos de saída", variáveis);

	*/

	char nome[20] = "Ricardo";
	int i = 31;
	float a = 1.74;

	FILE *arq = fopen("arquivo.txt", "w");

	if(arq == NULL){
		printf("ERRO na abertura\n");
		exit(1);
	}

	fprintf(arq, "Nome: %s\nIdade: %d\nAltura: %f\n", nome, i, a);

	fclose(arq);


	return 0;
}