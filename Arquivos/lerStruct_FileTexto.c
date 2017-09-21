/*
Ler arquivo texto de estruturas com struct de aluno, 
imprimindo nome idade e sexo
*/

#include <stdio.h>
#include <stdlib.h>

struct aluno{
	char nome[20];
	int idade;
	char sexo;
};

int main(){

	FILE *arq = fopen("arquivo-texto.txt", "r");

	if (arq == NULL){
		exit(0);
	}
	
	struct aluno aluno1;
	do{
		//struct aluno aluno1;
		fscanf(arq, "%d %c %s\n", &aluno1.idade, &aluno1.sexo, aluno1.nome);
		//fscanf(arq, "%d %c %[a-z A-Z]s\n", &aluno1.idade, &aluno1.sexo, aluno1.nome);
		printf("%s\t%d\t%c\n", aluno1.nome, aluno1.idade, aluno1.sexo);
	}while(!feof(arq)); /* ENQUANTO NÃO CHEGAR FIM DO ARQUIVO (!feof)
							CONTINUE O LAÇO */
	
	fclose(arq);

	return 0;
}
