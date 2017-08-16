/*
Escrever um programa em C que armazena uma struct de dados de
um aluno contendo (nome[40], idade, sexo, e matrícula), em um
arquivo binário.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno{
	char nome[40];
	int idade;
	char sexo;
	int matricula;
};

int main(){

	FILE *arq = fopen("conteudo-bin-aluno.bin", "wb"); /* NÃO SE ESQUECER DE QUE QUANDO É ARQUIVO BINÁRIO, 
                                                        AS CHAMADAS TERMINAM EM b */
	if (arq == NULL){
		exit(0);
	}

	typedef struct aluno tAluno; // definindo estrutura tAluno da struct Aluno

	tAluno aluno1;
	strcpy(aluno1.nome, "jesimar da silva arantes");
	aluno1.idade = 28;
	aluno1.sexo = 'm';
	aluno1.matricula = 12345;
	
	tAluno aluno2;
	strcpy(aluno2.nome, "marcio da silva arantes");
	aluno2.idade = 30;
	aluno2.sexo = 'm';
	aluno2.matricula = 45522;
	
	tAluno aluno3;
	strcpy(aluno3.nome, "suzana oliveira");
	aluno3.idade = 23;
	aluno3.sexo = 'f';
	aluno3.matricula = 63452;
	
	// armazenando structs dentro do arquivo
	fwrite(&aluno1, sizeof(tAluno), 1, arq);
	fwrite(&aluno2, sizeof(tAluno), 1, arq);
	fwrite(&aluno3, sizeof(tAluno), 1, arq);

	// fechar arquivo
	fclose(arq);

	return 0;
}
