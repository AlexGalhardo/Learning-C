/*
Escrever em um arquivo texto, uma struct de aluno com 
idade, nome, sexo
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno{
	char nome[20];
	int idade;
	char sexo;
};

int main(){

	FILE *arq = fopen("arquivo-texto.txt", "w");

	/* se não ouver arquivo nomeado "arquivo-texto", pare o programa */
	if (arq == NULL){
		exit(0);
	}

	/* DEFININDO DADOS DAS STRUCTS */
	struct aluno aluno1;
	strcpy(aluno1.nome, "jesimar");
	aluno1.idade = 28;
	aluno1.sexo = 'm';


	struct aluno aluno2;
	strcpy(aluno2.nome, "tiago");
	aluno2.idade = 32;
	aluno2.sexo = 'm';


	struct aluno aluno3;
	strcpy(aluno3.nome, "suzana");
	aluno3.idade = 20;
	aluno3.sexo = 'f';


	// escrevendo componentes dentro do arquivo
	fprintf(arq, "%s %d %c\n", aluno1.nome, aluno1.idade, aluno1.sexo);
	fprintf(arq, "%s %d %c\n", aluno2.nome, aluno2.idade, aluno2.sexo);
	fprintf(arq, "%s %d %c\n", aluno3.nome, aluno3.idade, aluno3.sexo);
	
	// fechando arquivo
	fclose(arq);
	
	return 0;
}
