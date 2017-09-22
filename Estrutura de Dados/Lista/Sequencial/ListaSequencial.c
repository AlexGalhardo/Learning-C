#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencial.h" //inclui os Protótipos

//Definição do tipo lista
struct lista{
    int qtd;
    struct aluno dados[MAX];
};

Lista* cria_lista(){
    Lista *li;
    li = (Lista*) malloc(sizeof(struct lista));
    if(li != NULL)
        li->qtd = 0;
    return li;
}

void libera_lista(Lista* li){
    free(li);
}

int consulta_lista_pos(Lista* li, int pos, struct aluno *al){
    if(li == NULL || pos <= 0 ||  pos > li->qtd)
        return 0;
    *al = li->dados[pos-1];
    return 1;
}

int consulta_lista_mat(Lista* li, int mat, struct aluno *al){
    if(li == NULL)
        return 0;
    int i = 0;
    while(i<li->qtd && li->dados[i].matricula != mat)
        i++;
    if(i == li->qtd)//elemento nao encontrado
        return 0;

    *al = li->dados[i];
    return 1;
}

int insere_lista_final(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    if(li->qtd == MAX)//lista cheia
        return 0;
    li->dados[li->qtd] = al;
    li->qtd++;
    return 1;
}

int insere_lista_inicio(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    if(li->qtd == MAX)//lista cheia
        return 0;
    int i;
    for(i=li->qtd-1; i>=0; i--)
        li->dados[i+1] = li->dados[i];
    li->dados[0] = al;
    li->qtd++;
    return 1;
}

int insere_lista_ordenada(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    if(li->qtd == MAX)//lista cheia
        return 0;
    int k,i = 0;
    while(i<li->qtd && li->dados[i].matricula < al.matricula)
        i++;

    for(k=li->qtd-1; k >= i; k--)
        li->dados[k+1] = li->dados[k];

    li->dados[i] = al;
    li->qtd++;
    return 1;
}

int remove_lista(Lista* li, int mat){
    if(li == NULL)
        return 0;
    if(li->qtd == 0)
        return 0;
    int k,i = 0;
    while(i<li->qtd && li->dados[i].matricula != mat)
        i++;
    if(i == li->qtd)//elemento nao encontrado
        return 0;

    for(k=i; k< li->qtd-1; k++)
        li->dados[k] = li->dados[k+1];
    li->qtd--;
    return 1;
}

int remove_lista_otimizado(Lista* li, int mat){
    if(li == NULL)
        return 0;
    if(li->qtd == 0)
        return 0;
    int i = 0;
    while(i<li->qtd && li->dados[i].matricula != mat)
        i++;
    if(i == li->qtd)//elemento nao encontrado
        return 0;

    li->qtd--;
    li->dados[i] = li->dados[li->qtd];
    return 1;
}

int remove_lista_inicio(Lista* li){
    if(li == NULL)
        return 0;
    if(li->qtd == 0)
        return 0;
    int k = 0;
    for(k=0; k< li->qtd-1; k++)
        li->dados[k] = li->dados[k+1];
    li->qtd--;
    return 1;
}

int remove_lista_final(Lista* li){
    if(li == NULL)
        return 0;
    if(li->qtd == 0)
        return 0;
    li->qtd--;
    return 1;
}

int tamanho_lista(Lista* li){
    if(li == NULL)
        return -1;
    else
        return li->qtd;
}

int lista_cheia(Lista* li){
    if(li == NULL)
        return -1;
    return (li->qtd == MAX);
}

int lista_vazia(Lista* li){
    if(li == NULL)
        return -1;
    return (li->qtd == 0);
}

void imprime_lista(Lista* li){
    if(li == NULL)
        return;
    int i;
    for(i=0; i< li->qtd; i++){
        printf("Matricula: %d\n",li->dados[i].matricula);
        printf("Nome: %s\n",li->dados[i].nome);
        printf("Notas: %f %f %f\n",li->dados[i].n1,
                                   li->dados[i].n2,
                                   li->dados[i].n3);
        printf("-------------------------------\n");
    }
}

/* 

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
