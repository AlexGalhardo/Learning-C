/* FWRITE = FILE WIRTE EM BINÁRIO */

#include <stdio.h>
#include <stdlib.h>

int main(){

	/* DEFINIÇÃO

	int fwrite(void *buffer, int bytes, int count, file *fp);
	
	Parâmetros:
		buffer: ponteiro genérico para os dados

		bytes: tamanho, em bytes, de cada unidade de dado a ser gravada
		
		count: total de unidades de dados que devem ser gravadas

		fp: o ponteiro para o arquivo */

	/* Retorno: total de unidades de dados gravadas com sucesso */
	
	FILE *arq;

	arq = fopen("vetor.txt", "wb"); // WRITE BINARIO

	if(arq == NULL){
		printf("ERRO na abertura\n");
		exit(1);
	}	

	// EXEMPLO 1
	int total_gravado, v[5] = {1, 2, 3, 4, 5};
	// grava todo o array no arquivo (5 posições)

	total_gravado = fwrite(v, sizeof(int), 5, arq);

	if(total_gravado != 5){
		printf("Erro na escrita do arquivo!");
		exit(1);
	}
	fclose(arq);


	// EXEMPLO 2
	char str[20] = "Hello World!";
	float x = 5;
	int v[5] = {1, 2, 3, 4, 5};

	fwrite(str, sizeof(char), 20, arq); // escreva os elementos de str, de tamanho sizeof(tipo), quantidade, no arquivo arq
	fwirte(&x, sizeof(float), 1, arq);
	fwrite(v, sizeof(int), 5, arq);

	fclose(arq);


	//EXEMPLO 3 - Structs
	struct cadastro{
		char nome[30];
		char endereco[30];
		int idade;
	}

	struct cadastro cad = {"Andre", "Rua 1", 31};

	fwrite(&cad, sizeof(struct cadastro), 1, arq);

	fclose(arq);

	return 0;
}