#include <stdio.h>
#include <stdlib.h>

int main(){

	/* definição

		fscanf(FILE *f,"tipos de entrada", variáveis);

	*/

	FILE *f = fopen("arquivo.txt", "r");

	if(f == NULL){
		printf("ERRO ma abetura\n");
		exit(1);
	}

	char texto[20], nome[20];

	int id;
	float h;

	fscanf(f, "%s %s", texto, nome); // ler dados do arquivo e armazenar em variaveis dentro do programa C
	printf("%s %s\n", texto, nome); // imprimir os dados armazenados

	fscanf(f, "%s %d", texto, &id); // ler dados do arquivo e armazenar em variaveis dentro do programa C
	printf("%s %d\n", texto, id); // imprimir os dados armazenados

	fscanf(f, "%s %s", texto, &h); // ler dados do arquivo e armazenar em variaveis dentro do programa C
	printf("%s %f\n", texto, h); // imprimir os dados armazenados

	fclose(f);

	return 0;
}
