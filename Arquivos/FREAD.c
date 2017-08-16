#include <stdio.h>
#include <stdlib.h>

int main(){

	/* Função para ler um bloco de bytes de um arquivo */

	/* Definição

		int fread(void *buffer, int bytes, int count, FILE *fp);

	Parâmetros:
		buffer: ponteiro genérico para dados
		bytes: tamanho, em bytes, de cada unidade de dado a ser lida
		cout: total de unidades de dados que devem ser lidas
		fp: o ponteiro para o arquivo

	Retorno: total de unidades de dados lidas com sucesso 
	*/

	FILE *arq = fopen("Vetor.txt", "rb"); // READ BINARIO

	if(arq == NULL){
		printf("ERRO na abertura!\n");
		exit(1);
	}

	// EXEMPLO 1
	int total_lido, v[5];

	total_lido = fread(v, sizeof(int), 5, arq);

	if(total_lido !=5){
		printf("Erro na leitura do arquivo!");
		exit(1);
	}

	fclose(arq);

	printf("%d %d %d %d %d\n", v[0], v[1], v[2], v[3], v[4]);



	// EXEMPLO 2
	char str[20]; // = "Hello world!"
	float x; // = 5

	fread(str, sizeof(char), 20, arq);
	fread(&x, sizeof(float), 1, arq);

	printf("%s\n%f\n", str, x);

	fclose(arq);


	// EXEMPLO 3

	struct cadastro{
		char nome[30];
		char endereco[30];
		int idade;
	}

	struct cadastro cad; // = {"ANDRÉ", "rua 1", 30}

	fread(&cad, sizeof(struct cadastro), 1, arq);

	printf("%s\n%s\n%d\n", cad.nome, cad.endereco, cad.idade);

	fclose(arq);

	return 0;
}