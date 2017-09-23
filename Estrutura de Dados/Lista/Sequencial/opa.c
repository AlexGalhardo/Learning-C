/*
	Autores:

	Alex Galhardo
	Numero USP: 10408344

	Ian Brant
	Numero USP:

	ICMC USP - São Carlos 2017
*/

/* Função principal da Biblioteca Estatica */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define MAX 31
#define TEL 14 
#define USP 9


#define tamAlunos 101
#define tamLivros 101
#define tamEspera 101


typedef struct{
	char nome[MAX];
	int numUSP;
	char telefone[TEL];
	char email[MAX];
	int emprestados;
}ALUNO;


typedef struct{
	char titulo[MAX];
	char autor[MAX];
	int ISBN;
	char editora[MAX];
	int ano;
	int edicao;
	int copias;
}LIVRO;


typedef struct{
	int ISBN;
	int numUSP;
}DADOS;


typedef struct{
	int qtd;
	ALUNO aluno[tamAlunos];
}LISTA_ALUNOS;


typedef struct{
	int qtd;
	LIVRO livro[tamLivros];
}LISTA_LIVROS;


typedef struct{
	int qtd;
	DADOS dados[tamEspera];
}LISTA_ESPERA;


/* definições */

/* cria as listas */
LISTA_LIVROS* criaLivros();
LISTA_ALUNOS* criaAlunos();
LISTA_ESPERA* criaEspera();

/* mostrar dados do aluno */
void mostrarDadosAluno(LISTA_ALUNOS *alunos, int numUSP, int *erro);
/* mostrar dados do livro */
void mostrarDadosLivro(LISTA_LIVROS *livros, int ISBN, int *erro);

/* mostrar menu de opções */
int mostrarMenu();

/* cadastrar livros e alunos na biblioteca */
void cadastrarLivro(LISTA_LIVROS *livros, LIVRO li, int *erro);
void cadastrarAluno(LISTA_ALUNOS *alunos, ALUNO al, int *erro);

/* descadastrar livros e alunos da biblioteca */
void descadastrarLivro(LISTA_LIVROS *livros, int ISBN, int *erro);
void descadastrarAluno(LISTA_ALUNOS *alunos, int numUSP, int *erro);


/* retirar algum livro da biblioteca */
void retirarLivro(LISTA_LIVROS *livros, LISTA_ALUNOS *alunos, LISTA_ESPERA *espera, int ISBN, int numUSP, int *erro);
/* devolver algum livro para a  biblioteca */
void devolverLivro(LISTA_LIVROS *livros, LISTA_ALUNOS *alunos, LISTA_ESPERA *espera, int ISBN, int numUSP, int *erro);

/* função do menu das alternâncias digitadas pelo usuário */
void menu(int op, LISTA_ALUNOS *alunos, LISTA_LIVROS *livros, LISTA_ESPERA *espera, int *erro);

/* adicionar aluno e isbn do livro na lista de espera, caso livro não esteja disponivel */
void pushEspera(LISTA_ESPERA *espera, int ISBN, int numUSP);
/* remover aluno que estav esperando na lista de espera */
void removeEspera(LISTA_ESPERA *espera, int numUSP, int *erro);



int main(){


	LISTA_ALUNOS *alunos;
	LISTA_LIVROS *livros;
	LISTA_ESPERA *espera;

	alunos = criaAlunos();
	livros = criaLivros();
	espera = criaEspera();


	int op, erro;

    printf("      ---------    BIBLIOTECA USP      ---------\n\n\n");
	printf("                   SEJA BEM VINDO       \n\n\n");

	do{
		op = mostrarMenu();
		menu(op, alunos, livros, espera, &erro);
	}while(op); 

	return 0;
}


void mostrarDadosLivro(LISTA_LIVROS *livros, int ISBN, int *erro){

	*erro = 0;

	printf("\n    ...Procurando livro...\n\n");

	int i, achouLivro=0;

	for(i=0; i< tamLivros; i++){
		if(livros->livro[i].ISBN == ISBN){
			achouLivro = 1;
			printf("    Titulo: %s\n", livros->livro[i].titulo);
			printf("    Autor: %s\n", livros->livro[i].autor);
			printf("    ISBN: %d\n", livros->livro[i].ISBN);
			printf("    Editora: %s\n", livros->livro[i].editora);
			printf("    Ano: %d\n", livros->livro[i].ano);
			printf("    Edicao: %d\n", livros->livro[i].edicao);
			printf("    Copias disponiveis: %d\n\n", livros->livro[i].copias);
			break;
		}
	}
	if(achouLivro != 1){
        printf("\nLivro não encontrado na biblioteca!\n\n");
        *erro = 1;
        return;
	}
}

void mostrarDadosAluno(LISTA_ALUNOS *alunos, int numUSP, int *erro){

	*erro = 0;

	printf("\n\n...Procurando dados do aluno...\n");

	int i, achouAluno=0;

	for(i=0; i< tamAlunos; i++){
		if(alunos->aluno[i].numUSP == numUSP){
			achouAluno = 0;
			printf("    Nome: %s\n", alunos->aluno[i].nome);
			printf("    Numero USP: %d\n", alunos->aluno[i].numUSP);
			printf("    Telefone: %s\n", alunos->aluno[i].telefone);
			printf("    Email: %s\n", alunos->aluno[i].email);
			printf("    Livros emprestados: %d\n", alunos->aluno[i].emprestados);
			break;
		}
	}
	if(achouAluno != 1){
		printf("\nAluno não encontrado na biblioteca!\n\n");
		*erro = 1;
		return;
	}
}


int mostrarMenu(){

	int op;

	printf("                     -- Escolha uma opcao --   \n\n");
	printf("    Digite [1] para --> Cadastrar dados de algum livro na biblioteca.\n");
	printf("    Digite [2] para --> Cadastrar dados de algum aluno na biblioteca.\n");
	printf("    Digite [3] para --> Descadastrar dados do livro na biblioteca.\n");
	printf("    Digite [4] para --> Descadastrar dados do aluno na biblioteca.\n");
	printf("    Digite [5] para --> Retirar algum livro da biblioteca.\n");
	printf("    Digite [6] para --> Devolver algum livro para a biblioteca.\n");
	printf("    Digite [7] para --> Mostrar dados de algum livro.\n");
	printf("    Digite [8] para --> Mostrar dados de algum aluno.\n");
	printf("    Digite [0] para --> SAIR\n\n");
	printf("    Opcao: ");
	scanf("%d", &op);

	return op;
}



LISTA_ALUNOS* criaAlunos(){
	LISTA_ALUNOS *alunos;
    alunos = (LISTA_ALUNOS*) malloc(sizeof(LISTA_ALUNOS));
    if(alunos != NULL)
        alunos->qtd = 0;
    return alunos;
}

LISTA_LIVROS* criaLivros(){
	LISTA_LIVROS *livros;
    livros = (LISTA_LIVROS*) malloc(sizeof(LISTA_LIVROS));
    if(livros != NULL)
        livros->qtd = 0;
    return livros;
}

LISTA_ESPERA* criaEspera(){
	LISTA_ESPERA *espera;
    espera = (LISTA_ESPERA*) malloc(sizeof(LISTA_ESPERA));
    if(espera != NULL)
        espera->qtd = 0;
    return espera;
}


/* Menu das opções */
void menu(int op, LISTA_ALUNOS *alunos, LISTA_LIVROS *livros, LISTA_ESPERA *espera, int *erro){

	LIVRO li;
	ALUNO al;
	int ISBN, numUSP;

	switch(op){
		case 1:
			//LIVRO li;
			printf ("    Digite o ISBN do Livro: ");
			scanf ("%d", &li.ISBN);
			getchar();
			printf ("    Digite o Titulo do Livro: ");
			scanf ("%[^\n]s", li.titulo);
			getchar();
			printf ("    Digite o Autor do Livro: ");
			scanf ("%[^\n]s", li.autor);
			getchar();
			printf ("    Digite a Editora do Livro: ");
			scanf ("%[^\n]s", li.editora);
			getchar();
			printf ("    Digite o Ano do Livro: ");
			scanf ("%d",&li.ano);
			//getchar();
			printf ("    Digite a Edicao do Livro: ");
			scanf ("%d",&li.edicao);
			//getchar();
			printf ("    Digite a Quantidade de Copias do Livro: ");
			scanf ("%d",&li.copias);
			cadastrarLivro(livros, li, erro);
			break;
		case 2:
			//ALUNO al;
			printf ("    Digite o Nome do Aluno: ");
			scanf ("%[^\n]s", al.nome);
			//getchar();
			printf ("    Digite o Numero USP do Aluno: ");
			scanf ("%d", &al.numUSP);
			getchar();
			printf ("    Digite o Telefone do Aluno, com codigo de area + 9 digitos: ");
			scanf ("%[^\n]s", al.telefone);
			getchar();
			printf ("    Digite o Email do Aluno: ");
			scanf ("%[^\n]s", al.email);
			getchar();
			al.emprestados = 0;

			printf("\n    ...Cadastrando aluno...\n");
			cadastrarAluno(alunos, al, erro);
			break;
		case 3:
			//int ISBN;

			printf("    Digite o ISBN do livro que vocÃª quer descadastrar: ");
			scanf("%d", &ISBN);

			descadastrarLivro(livros, ISBN, erro);
			break;

		/* descadastrar aluno */
		case 4:
			printf("    Digite o numero USP do aluno que vocÃª quer descadastrar: ");
			scanf("%d", &numUSP);

			descadastrarAluno(alunos, numUSP, erro);
			break;

		/* retirar livro */
		case 5:
			printf("    Digite o ISBN do livro que vocÃª quer descadastrar: ");
			scanf("%d", &ISBN);
			printf("    Digite o numero USP do aluno que gostaria de retirar o livro: ");
			scanf("%d", &numUSP);

			retirarLivro(livros, alunos, espera, ISBN, numUSP, erro);
			break;

		/* devolver livro */
		case 6:
			printf("    Digite o ISBN do livro que irÃ¡ ser devolvido: ");
			scanf("%d", &ISBN);
			printf("    Digite o numero USP do aluno que estÃ¡ devolvendo o livro: ");
			scanf("%d", &numUSP);

			devolverLivro(livros, alunos, espera, ISBN, numUSP, erro);
			break;

		/* mostrar dados de algum livro */
		case 7:
			printf("    Digite o ISBN do livro que voce quer ver os dados: ");
			scanf("%d", &ISBN);
			mostrarDadosLivro(livros, ISBN, erro);
			break;
		case 8:
			printf("    Digite o numero USP do aluno que voce quer ver os dados: ");
			scanf("%d", &numUSP);
			mostrarDadosAluno(alunos, numUSP, erro);
			break;
		default:
			printf("   Adeus :( \n");
	}
}

void retirarLivro(LISTA_LIVROS *livros, LISTA_ALUNOS *alunos, LISTA_ESPERA *espera, int ISBN, int numUSP, int *erro){

	*erro = 0;

	int k, indice=0, achouAluno =0;

	for(k=0; k <alunos->qtd; k++){
		if(alunos->aluno[k].numUSP == numUSP){
			achouAluno = 1;
			indice = k;

			if(alunos->aluno[k].emprestados>1){
				printf("O aluno nao pode ter mais de 2 livros em posse de uma vez!");
				*erro = 1;
				return;
			}
			else{
				break;
			}
		}
	}

    if (achouAluno==0){
        printf("Aluno não encontrado!\n\n");
        *erro = 1;
        return;
    }


    int i,achouLivro=0;

    for(i=0; i < livros->qtd; i++){
        if(livros->livro[i].ISBN == ISBN){
            achouLivro = 1;
            if(livros->livro[livros->qtd].copias < 0){
                printf("Nenhuma copia do livro disponivel no momento!\n");
                printf("Gostaria de adicionar o aluno na lista de espera?\n");
                printf("Digite [1] para SIM\n");
                printf("Digite [2] para NAO\n");
                int escolha = 0;
                scanf("%d", &escolha);
                while(escolha != 1 || escolha != 2){
	                if(escolha == 1){
	                	pushEspera(espera, ISBN, numUSP);
	                	break;
	                }
	                else {
	                	break;
	                }
	                printf("Escolha uma opcao entre 1 ou 2: ");
	                scanf("%d", &escolha);
	            }
            }
            else{
                livros->livro[i].copias--;
                alunos->aluno[indice].emprestados++;
                break;
            }
        }
    }

    if(achouLivro == 0){
        printf("\n\n   Livro não encontrado na biblioteca!!\n\n");
        *erro = 1;
        return;
    }
}


/* devolver livro 
* se o aluno não for encontrado na biblioteca ou
* se o livro não for encontrado na biblioteca 
* retorne erro */
void devolverLivro(LISTA_LIVROS *livros, LISTA_ALUNOS *alunos, LISTA_ESPERA *espera, int ISBN, int numUSP, int *erro){

	*erro = 0;

	int i, k, indice, achouAluno=0, achouLivro=0;

	printf("\n\n...Procurando aluno com esses dados...\n\n");

	for(k=0; k < alunos->qtd; k++){
		if(alunos->aluno[k].numUSP == numUSP){
			achouAluno = 1;
			indice = k;
			break;
		}
	}
	if(achouAluno != 1){
		printf("\n\n    Aluno não encontrado na biblioteca!!!\n\n");
		*erro = 1;
		return;
	}


	printf("\n\n    ...Procurando livro com esses dados...\n\n");

	for(i=0; i < livros->qtd; i++){
		if(livros->livro[i].ISBN == ISBN){
			achouLivro = 1;
			livros->livro[i].copias++;
			alunos->aluno[indice].emprestados--;
			break;
		}
	}
	if(achouLivro != 1){
		printf("\n\n  Livro não encontrado na biblioteca!!!\n");
		*erro = 1;
		return;
	}

	/* verifique se algum aluno na lista de espera, espera esse livro que acabou de ser devolvido! */
	int j;
	for(j=0; j < espera->qtd; j++){
		/* se houver algum aluno na lista de espera, que esteja esperando esse ISBN
		que acabou de ser devolvido, avise */
		if(espera->dados[j].ISBN == ISBN){
			printf("   O aluno com ISBN [%d] pode retirar o livro que estava esperando\n", espera->dados[j].numUSP);
			removeEspera(espera, numUSP, erro);
			break;
		}
	}
}

void pushEspera(LISTA_ESPERA *espera, int ISBN, int numUSP){
	espera->qtd++;
	espera->dados[espera->qtd].ISBN = ISBN;
	espera->dados[espera->qtd].numUSP = numUSP;
}

void removeEspera(LISTA_ESPERA *espera, int numUSP, int *erro){

	*erro = 0;

	int i, k, achouAluno=0;
	for(i=0; i< espera->qtd; i++){
		if(espera->dados[espera->qtd].numUSP == numUSP){
			achouAluno = 1;
			espera->dados[i] = espera->dados[tamEspera-1];
			break;
		}
	}

	if(achouAluno != 1){
		printf("\n\n   Aluno não encontrado na lista de espera! -- \n\n\n");
		*erro = 1;
		return;
	}
	espera->qtd--;
}

void descadastrarLivro(LISTA_LIVROS *livros, int ISBN, int *erro){

	*erro = 0;

	int i, achouLivro=0;

	printf("\n    ...Procurando livro com esses dados...\n\n");

	for(i=0; i < tamLivros; i++){
		if(livros->livro[i].ISBN == ISBN){
			livros->livro[i] = livros->livro[livros->qtd-1];
			achouLivro = 1;
			livros->qtd--;
			printf("    LIVRO DESCADASTRADO COM SUCESSO!\n\n");
			break;
		}
	}
	if(achouLivro != 1){
        printf("\n\n    Livro não encontrado na biblioteca!\n\n");
        *erro = 1;
        return;
	}
}


/* descadastrar aluno */
void descadastrarAluno(LISTA_ALUNOS *alunos, int numUSP, int *erro){

	*erro = 0;

    printf("\n    ...Descadastrar aluno...\n\n");

	int achouAluno = 0, i;

	for(i=0; i < tamAlunos; i++){
		if(alunos->aluno[i].numUSP == numUSP){
			alunos->aluno[i] = alunos->aluno[alunos->qtd-1];
			achouAluno = 1;
			alunos->qtd--;
			printf("    ALUNO DESCADASTRADO COM SUCESSO!\n\n");
			break;
		}
	}
	if(achouAluno != 1){
        printf("\n\n    Aluno não encontrado na biblioteca!\n\n");
        *erro = 1;
        return;
	}
}


/* cadastrar livro na biblioteca */
void cadastrarLivro(LISTA_LIVROS *livros, LIVRO li, int *erro){

	*erro = 0;

	if(livros == NULL){
		*erro = 1;
		return;
	}
	else if(livros->qtd == tamLivros){
		*erro = 1;
		return;
	}
	livros->qtd++;
			
	livros->livro[livros->qtd] = li;
	
	printf("\n\n\n    LIVRO CADASTRADO COM SUCESSO! \n\n\n");
}



/* cadstrar aluno na biblioteca */
void cadastrarAluno(LISTA_ALUNOS *alunos, ALUNO al, int *erro){

	*erro = 0;

	if(alunos == NULL){
		*erro = 1;
		return;
	}
	else if(alunos->qtd == tamAlunos){
		*erro = 1;
		return;
	}
	alunos->qtd++;


	alunos->aluno[alunos->qtd] = al;

	printf("\n\n\n    ALUNO CADASTRADO COM SUCESSO! \n\n\n");
}
