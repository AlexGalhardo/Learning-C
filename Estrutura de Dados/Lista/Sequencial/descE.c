/*
	Autores:

	Alex Galhardo
	Numero USP: 10408344

	Ian Brant
	Numero USP:

	ICMC USP - São Carlos 2017
*/

/* Funcões para descadastrar livros e alunos da biblioteca estatica */

#include "estatico.h"

/* descadastrar livro da biblioteca */
void descadastrarLivro(LISTA_LIVROS *livros, int ISBN, int *erro){

	*erro = 0;

    printf("\n...Descadastrar livro...\n\n");

	int i, achouLivro=0;

	printf("...Procurando livro com esses dados...\n\n");

	for(i=0; i < livros->qtd; i++){
		if(livros->livro[livros->qtd].ISBN == ISBN){
			livros->livro[i] = livros->livro[livros->qtd-1];
			achouLivro = 1;
			livros->qtd--;
			break;
		}
	}
	if(achouLivro != 1){
        printf("\n\nLivro não encontrado na biblioteca!\n\n");
        *erro = 1;
        return;
	}
}


/* descadastrar aluno */
void descadastrarAluno(LISTA_ALUNOS *alunos, int numUSP, int *erro){

	*erro = 0;

    printf("\n...Descadastrar aluno...\n\n");

	int achouAluno = 0, i;

	for(i=0; i < alunos->qtd; i++){
		if(alunos->aluno[i].ISBN == ISBN){
			alunos->aluno[i] = alunos->aluno[alunos->qtd-1];
			achouAluno = 1;
			alunos->qtd--;
			break;
		}
	}
	if(achouAluno != 1){
        printf("\n\nAluno não encontrado na biblioteca!\n");
        *erro = 1;
        return;
	}
}
