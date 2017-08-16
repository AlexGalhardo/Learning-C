/*
Escrever um programa em C que leia a struct de dados aluno
contendo os campos (nome[40], idade, sexo, e matrícula), do arquivo
binário e imprima na tela as informações.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno{
	int matricula;
	char nome[40];
	char sexo;
	int idade;
};

int main(){
	
	FILE *arq = fopen("conteudo-bin-aluno.bin", "rb"); /*NÃO SE ESQUECER DE TERMINAR EM b AS CHAMADAS
                                                        PARA LER ARQUIVO BINÁRIO */

	if (arq == NULL){
		exit(0);
	}

	typedef struct aluno tAluno;

	tAluno a1;
	while(fread(&a1, sizeof(tAluno), 1, arq)){
		printf("%s %d %c %d\n", a1.nome, a1.idade, a1.sexo, a1.matricula);
	}

	// fechar arquivo
	fclose(arq);

	return 0;
}
