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
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX 101
#define TEL 14 
#define USP 9

typedef struct noa{
	char nome[MAX];
	int numUSP;
	char telefone[TEL];
	char email[MAX];
	int emprestados;
	struct noa *prox;
}ALUNO;


typedef struct nol{
	char titulo[MAX];
	char autor[MAX];
	int ISBN;
	char editora[MAX];
	int ano;
	int edicao;
	int copias;
	struct nol *prox;
}LIVRO;


typedef struct noe{
	int ISBN;
	int numUSP;
	struct noe *prox;
}DADOS;


typedef struct{
	int qtd;
	ALUNO *inicio, *fim;
}LISTA_ALUNOS;


typedef struct{
	int qtd;
	LIVRO *inicio, *fim;
}LISTA_LIVROS;


typedef struct{
	int qtd;
	DADOS *inicio, *fim;
}LISTA_ESPERA;


/* definições */

/* aloca memoria para as listas */
LISTA_LIVROS* criaLivros();
LISTA_ALUNOS* criaAlunos();
LISTA_ESPERA* criaEspera();

void freeEspera(LISTA_ESPERA *espera);
void freeAlunos(LISTA_ALUNOS *alunos);
void freeLivros(LISTA_LIVROS *livros);

int verificaISBN(LISTA_LIVROS *livros, int ISBN);
bool verificaTitulo(LISTA_LIVROS *livros, char titulo[]);

int verificaTelefone(LISTA_ALUNOS *alunos, char telefone[]);
int verificaEmail(LISTA_ALUNOS *alunos, char email[]);
int verificaNome(LISTA_ALUNOS *alunos, char nome[]);
int verificaNumUSP(LISTA_ALUNOS *alunos, int numUSP);

void quantidadeLivros(LISTA_LIVROS *livros);
void quantidadeAlunos(LISTA_ALUNOS *alunos);
void quantidadeEspera(LISTA_ESPERA *espera);

/* mostrar dados do aluno */
void mostrarDadosAluno(LISTA_ALUNOS *alunos, int numUSP, int *erro);
/* mostrar dados do livro */
void mostrarDadosLivro(LISTA_LIVROS *livros, int ISBN, int *erro);

/* mostrar menu de opções */
int mostrarMenu();

/* cadastrar livros e alunos na biblioteca */
void cadastrarLivro(LISTA_LIVROS *livros, int *erro);
void cadastrarAluno(LISTA_ALUNOS *alunos, int *erro);

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

void mostrarTodosAlunos(LISTA_ALUNOS *alunos, int *erro);
void mostrarTodosEspera(LISTA_ESPERA *espera, int *erro);
void mostrarTodosLivros(LISTA_LIVROS *livros, int *erro);

int main(){

	LISTA_ALUNOS *alunos;
	LISTA_LIVROS *livros;
	LISTA_ESPERA *espera;

	alunos = criaAlunos();
	livros = criaLivros();
	espera = criaEspera();

	int op, erro;

    printf("\n    ------------------       BIBLIOTECA USP      -------------------\n\n");
	printf("                             SEJA BEM VINDO       \n\n");

	do{
		op = mostrarMenu();
		menu(op, alunos, livros, espera, &erro);
	}while(op); 

	return 0;
}

void cadastrarLivro(LISTA_LIVROS *livros, int *erro){

	LIVRO *nol;
	nol = (LIVRO*)malloc(sizeof(LIVRO));
	if(nol == NULL){
		*erro = 1;
		printf(" ERRO na alocacao para o nó auxiliar livro!\n");
		return;
	}
	*erro = 0;

	printf ("    Digite o ISBN do Livro [Deve conter 4 numeros inteiros]: ");
	int ISBN;
	scanf ("%d", &ISBN);
	getchar();
	while(1){
		int verISBN = verificaISBN(livros, ISBN);
		if(verISBN == 1){
			printf("    [ERRO]   --> Livro já cadastrado no sistema!\n    Digite outro ISBN:");
			scanf("%d", &ISBN);
			getchar();
		}else if(verISBN == 2){
			printf("    [ERRO]  --> ISBN deve conter 4 numeros inteiros!\n    Digite outro ISBN: ");
			scanf("%d", &ISBN);
			getchar();
		}else{
			nol->ISBN = ISBN;
			break;
		}
	}

	printf ("    Digite o Titulo do Livro: ");
	char titulo[MAX];
	scanf ("%[^\n]s", titulo);
	getchar();
	while(1){
		bool valida = verificaTitulo(livros, titulo);
		if(valida == 1){
			strcpy(nol->titulo, titulo);
			break;
		}else{
			printf("    [ERRO]  --> Titulo ja cadastrado no sistema!\n    Digite outro titulo: ");
			scanf("%s", titulo);
			getchar();
		}
	}

	printf ("    Digite o Autor do Livro: ");
	scanf ("%[^\n]s", nol->autor);
	getchar();
	printf ("    Digite a Editora do Livro: ");
	scanf ("%[^\n]s", nol->editora);
	getchar();

	printf ("    Digite o Ano do Livro: ");
	int ano;
	scanf ("%d", &ano);
	while(ano < 1800 || ano > 2017){
		printf("    [ERRO]  -> Digite um ano valido para o livro: ");
		scanf("%d", &ano);
	}
	nol->ano = ano;

	printf ("    Digite a Edicao do Livro: ");
	int edicao;
	scanf ("%d", &edicao);
	while(edicao < 1 || edicao > 99){
		printf("    [ERRO]  -> Digite uma edicao valida para o livro: ");
		scanf("%d", &edicao);
	}
	nol->edicao = edicao;
	
	printf("    Digite a Quantidade de Copias do Livro [Maximo 5 copias]: ");
	int copias;
	scanf ("%d",&copias);
	while(copias < 1 || copias > 5){
		printf("    Digite uma quantidade de copias valida: ");
		scanf("%d", &copias);
	}
	nol->copias = copias;
	nol->prox = NULL;

	if(livros->inicio == NULL){
		livros->inicio = nol;
		livros->qtd++;
		printf("\n    LIVRO CADASTRADO COM SUCESSO!\n");
	}
	else{
		livros->fim->prox = nol;
		livros->qtd++;
		printf("\n    LIVRO CADASTRADO COM SUCESSO!\n");
	}
	livros->fim = nol;	
}

void cadastrarAluno(LISTA_ALUNOS *alunos, int *erro){

	ALUNO *noa;
	noa = (ALUNO*)malloc(sizeof(ALUNO));
	if(noa == NULL){
		*erro = 1;
		printf(" ERRO na alocacao de memoria para o no aluno!\n");
		return;
	}
	*erro = 0;

	printf ("    Digite o Numero USP do Aluno: ");
	int numUSP;
	scanf ("%d", &numUSP);
	getchar();
	while(1){
		int verNum = verificaNumUSP(alunos, numUSP);
		if(verNum == 1){
			printf("    [ERRO]  -> Numero USP já cadastrado no sistema!\n");
			printf("    Digite outro numero USP: ");
			scanf("%d", &numUSP);
			getchar();
		}else if(verNum == 2){
			printf("    [ERRO]  -> Numero USP deve conter exatamente 8 digitos inteiros!\n");
			printf("    Digite outro numero USP: ");
			scanf("%d", &numUSP);
			getchar();
		}
		else{
			noa->numUSP = numUSP;
			break;
		}
	}
	
	printf ("    Digite o Nome do Aluno: ");
	char nome[MAX];
	scanf ("%[^\n]s", nome);
	getchar();
	while(1){
		int verNome = verificaNome(alunos, nome);
		if(verNome==1){
			strcpy(noa->nome, nome);
			break;
		}else{
			printf("    [ERRO]  -> Nome já cadastrado no sistema!\n");
			printf("    Digite outro nome: ");
			scanf("%[^\n]s", nome);
			getchar();
		}
	}

	printf ("    Digite o Telefone do Aluno: ");
	char telefone[MAX];
	scanf ("%[^\n]s", telefone);
	getchar();
	while(1){
		int verTel = verificaTelefone(alunos, telefone);
		if(verTel == 1){
			printf("    [ERRO]  -> Telefone já cadastrado no sistema!\n");
			printf("    Digite um telefone valido: ");
			scanf("%s", telefone);
			getchar();
		}
		else if(verTel == 2){
			printf("    [ERRO]  -> Telefone deve ter no minimo 13 digitos!\n");
			printf("    Digite um telefone valido: ");
			scanf("%s", telefone);
			getchar();
		}
		else if(verTel == 3){
			printf("    [ERRO]  -> Telefone deve ter no maximo 13 digitos!\n");
			printf("    Digite um telefone valido: ");
			scanf("%s", telefone);
			getchar();
		}
		else if(verTel == 4){
			printf("    [ERRO]  -> Telefone deve começar com '551899' !\n");
			printf("    Digite um telefone valido: ");
			scanf("%s", telefone);
			getchar();
		}
		else{
			strcpy(noa->telefone, telefone);
			break;
		}
	}

	printf ("    Digite o Email do Aluno [Deve terminar com '@usp.br']: ");
	char email[MAX];
	scanf ("%[^\n]s", email);
	getchar();
	while(1){
		bool verEmail = verificaEmail(alunos, email);
		if(verEmail){
			strcpy(noa->email, email);
			break;
		}else{
			printf("    [ERRO]  -> Email invalido ou ja cadastrado na biblioteca!\n");
			printf("    Digite um email evalido: ");
			scanf("%s", email);
			getchar();
		}
	}
	noa->emprestados = 0;
	noa->prox = NULL;

	if(alunos->inicio == NULL){
		alunos->inicio = noa;
		alunos->qtd++;
		printf("\n    ALUNO CADASTRADO COM SUCESSO!\n\n");
	}
	else{
		alunos->fim->prox = noa;
	    alunos->qtd++;
	    printf("\n    ALUNO CADASTRADO COM SUCESSO!\n\n");
	}
	alunos->fim = noa;
}


void descadastrarLivro(LISTA_LIVROS *livros, int ISBN, int *erro){

	*erro = 0;

	int achouLivro=0;

	LIVRO *aux;
	aux = (LIVRO*)malloc(sizeof(LIVRO));
	if(aux == NULL){
		printf(" ERRO na alocacao de memoria do auxliar livro!\n");
		exit(1);
	}
	aux = livros->inicio;

	LIVRO *deletar;
	deletar = (LIVRO*)malloc(sizeof(LIVRO));
	if(deletar == NULL){
		printf(" ERRO na alocacao de memoria do auxliar livro!\n");
		exit(1);
	}

	printf("\n    ...Procurando livro...\n\n");

	while(aux != NULL){
		if(aux->ISBN == ISBN){
			achouLivro = 1;
			printf("    [......Dados do livro.....]\n");
			printf("    Titulo: %s\n", aux->titulo);
			printf("    Autor: %s\n", aux->autor);
			printf("    ISBN: %d\n", aux->ISBN);
			printf("    Editora: %s\n", aux->editora);
			printf("    Ano: %d\n", aux->ano);
			printf("    Edicao: %d\n", aux->edicao);
			printf("    Copias disponiveis: %d\n\n", aux->copias);


			int opcao;
			printf("    Tem certeza que quer descadastrar esse livro?\n");
			printf("    Digite [1] -> SIM\n");
			printf("    Digite [2] -> NAO\n");
			printf("    Opcao: ");
			scanf("%d", &opcao);

			if(opcao == 1){
				deletar = aux;
				aux = aux->prox;
				free(deletar);

				livros->qtd--;
				printf("    LIVRO DESCADASTRADO COM SUCESSO!\n\n");
				break;
			}else{
				printf("    DESCADASTRADO CANCELADO!\n\n");
				break;
			}
		}
		aux = aux->prox;
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

	ALUNO *aux;
	aux = (ALUNO*)malloc(sizeof(ALUNO));
	if(aux == NULL){
		printf(" ERRO na alocacao do auxiliar aluno!\n");
		exit(1);
	}
	aux = alunos->inicio;

	ALUNO *deletar;
	deletar = (ALUNO*)malloc(sizeof(ALUNO));
	if(deletar == NULL){
		printf(" ERRO na alocacao do deletar aluno!");
		exit(1);
	}

	printf("\n    ...Procurando aluno...\n\n");

	int achouAluno = 0;

	while(aux != NULL){
		if(aux->numUSP == numUSP){
			achouAluno = 1;
			printf("    [......Dados do aluno.....]\n");
			printf("    Nome: %s\n", aux->nome);
			printf("    Numero USP: %d\n", aux->numUSP);
			printf("    Telefone: %s\n", aux->telefone);
			printf("    Email: %s\n", aux->email);
			printf("    Livros emprestados: %d\n\n", aux->emprestados);


			int opcao;
			printf("    Tem certeza que quer descadastrar esse aluno?\n");
			printf("    Digite [1] -> SIM\n");
			printf("    Digite [2] -> NAO\n");
			printf("    Opcao: ");
			scanf("%d", &opcao);

			if(opcao == 1){
				deletar = aux;
				aux = aux->prox;
				free(deletar);

				alunos->qtd--;
				printf("    ALUNO DESCADASTRADO COM SUCESSO!\n\n");
				break;
			}else{
				printf("    DESCADASTRADO CANCELADO!\n\n");
				break;
			}
		}
	}

	if(achouAluno != 1){
        printf("\n\n    Aluno não encontrado na biblioteca!\n\n");
        *erro = 1;
        return;
	}
}

void pushEspera(LISTA_ESPERA *espera, int ISBN, int numUSP){

    espera->qtd++;

    DADOS *aux;
    aux = (DADOS*)malloc(sizeof(DADOS));
    if(aux == NULL){
        printf(" ERRO na alocação do auxiliar de espera!\n");
        exit(1);
    }
    aux = espera->inicio;

    if(espera->inicio == NULL){
        espera->inicio->ISBN = ISBN;
        espera->inicio->numUSP = numUSP;
    }
    else{
        while(aux != NULL){
            aux = aux->prox;
        }
        aux->ISBN = ISBN;
        aux->numUSP = numUSP;
    }
    free(aux);
}

void removeEspera(LISTA_ESPERA *espera, int numUSP, int *erro){

    *erro = 0;

    DADOS *aux;
    aux = (DADOS*)malloc(sizeof(DADOS));
    if(aux == NULL){
        printf(" ERRO na alocacao de memoria para o auxiliar de espera!\n");
        exit(1);
    }
    aux = espera->inicio;

    DADOS *deletar;
    deletar = (DADOS*)malloc(sizeof(DADOS));
    if(deletar == NULL){
        printf(" ERRO na alocacao de memoria para o auxiliar deletar de espera!\n");
        exit(1);
    }

    int achouAluno=0;

    while(aux != NULL){
        if(aux->numUSP == numUSP){
            achouAluno = 1;

            deletar = aux;
            aux = aux->prox;
            free(deletar);
            break;
        }
        aux = aux->prox;
    }

    if(achouAluno != 1){
        printf("\n\n   Aluno não encontrado na lista de espera! -- \n\n\n");
        *erro = 1;
        return;
    }
    espera->qtd--;
    free(aux);
    free(deletar);
}


int mostrarMenu(){

	int op;

	printf("\n                          -- Escolha uma opcao --   \n");
	printf("    Digite [1] para --> Cadastrar dados de algum livro na biblioteca.\n");
	printf("    Digite [2] para --> Cadastrar dados de algum aluno na biblioteca.\n");
	printf("    Digite [3] para --> Descadastrar dados de algum livro na biblioteca.\n");
	printf("    Digite [4] para --> Descadastrar dados de algum aluno na biblioteca.\n");
	printf("    Digite [5] para --> Retirar algum livro da biblioteca.\n");
	printf("    Digite [6] para --> Devolver algum livro para a biblioteca.\n");
	printf("    Digite [7] para --> Mostrar dados de algum livro.\n");
	printf("    Digite [8] para --> Mostrar dados de algum aluno.\n");
	printf("    Digite [9] para --> Mostrar todos os livros cadastrados na biblioteca.\n");
	printf("    Digite [10] para -> Mostrar todos os alunos cadastrados na biblioteca.\n");
	printf("    Digite [11] para -> Mostrar todos os alunos que estão na lista de espera.\n");
	printf("    Digite [12] para -> Mostrar quantidade de livros cadastrados na biblioteca.\n");
	printf("    Digite [13] para -> Mostrar quantidade de alunos cadastrados na biblioteca.\n");
	printf("    Digite [14] para -> Mostrar quantidade de alunos na lista de espera.\n");
	printf("    Digite [15] para -> Apagar todos os dados dos alunos.\n");
	printf("    Digite [16] para -> Apagar todos os dados dos livros.\n");
	printf("    Digite [17] para -> Apagar lista de espera.\n");
	printf("\n    Digite [0] para --> SAIR\n\n");
	printf("    Opcao: ");
	scanf("%d", &op);

	return op;
}

void menu(int op, LISTA_ALUNOS *alunos, LISTA_LIVROS *livros, LISTA_ESPERA *espera, int *erro){

	int ISBN, numUSP;
	switch(op){
		
		case 1:
			cadastrarLivro(livros, erro);
			break;
	
		
		case 2:
			//printf("\n    ...Cadastrando aluno...\n");
			cadastrarAluno(alunos, erro);
			break;

		
		case 3:
			printf("    Digite o ISBN do livro que sera descadastrado: ");
			scanf("%d", &ISBN);
			descadastrarLivro(livros, ISBN, erro);
			break;

		
		case 4:
			printf("    Digite o numero USP do aluno que sera descadastrado: ");
			scanf("%d", &numUSP);
			descadastrarAluno(alunos, numUSP, erro);
			break;

		
		case 5:
			printf("    Digite o ISBN do livro que o aluno gostaria de retirar: ");
			scanf("%d", &ISBN);
			printf("    Digite o numero USP do aluno que gostaria de retirar o livro: ");
			scanf("%d", &numUSP);

			retirarLivro(livros, alunos, espera, ISBN, numUSP, erro);
			break;

		
		case 6:
			printf("    Digite o ISBN do livro que vai ser devolvido: ");
			scanf("%d", &ISBN);
			printf("    Digite o numero USP do aluno que esta devolvendo o livro: ");
			scanf("%d", &numUSP);

			devolverLivro(livros, alunos, espera, ISBN, numUSP, erro);
			break;

		
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

		case 9:
			mostrarTodosLivros(livros, erro);
			break;

		case 10:
			mostrarTodosAlunos(alunos, erro);
			break;

		case 11:
			mostrarTodosEspera(espera, erro);
			break;

		case 12:
			quantidadeLivros(livros);
			break;

		case 13:
			quantidadeAlunos(alunos);
			break;

		
		case 14:
			quantidadeEspera(espera);
			break;

		
		case 15:
			freeAlunos(alunos);
			printf("\n\n    ...Deletando todos os dados dos alunos da biblioteca...\n\n");
			break;

		case 16:
			freeLivros(livros);
			printf("\n\n    ...Deletando todos os dados dos livros da biblioteca...\n\n");
			break;

		case 17:
			freeEspera(espera);
			printf("\n\n    ...Deletando todos os dados dos livros da biblioteca...\n\n");
			break;

		case 0:
			printf("\n    [........Saindo da biblioteca........]\n\n");
			break;

		default:
			printf("\n\n    Por favor, digite um comando valido: ");
	}
}


void mostrarDadosLivro(LISTA_LIVROS *livros, int ISBN, int *erro){

	*erro = 0;

	printf("\n    ...Procurando livro...\n\n");

	int achouLivro=0;

	LIVRO *aux;
	aux = (LIVRO*)malloc(sizeof(LIVRO));
	if(aux == NULL){
		printf(" ERRO\n");
		exit(1);
	}
	aux = livros->inicio;

	while(aux != NULL){
		if(aux->ISBN == ISBN){
			achouLivro = 1;

			printf("    Titulo: %s\n", aux->titulo);
			printf("    Autor: %s\n", aux->autor);
			printf("    ISBN: %d\n", aux->ISBN);
			printf("    Editora: %s\n", aux->editora);
			printf("    Ano: %d\n", aux->ano);
			printf("    Edicao: %d\n", aux->edicao);
			printf("    Copias disponiveis: %d\n\n", aux->copias);
			break;
		}
	}
	if(achouLivro != 1){
        printf("\n    Livro não encontrado na biblioteca!\n\n");
        *erro = 1;
        return;
	}

	free(aux);
}

void mostrarDadosAluno(LISTA_ALUNOS *alunos, int numUSP, int *erro){

	*erro = 0;

	printf("\n    ...Procurando dados do aluno...\n\n");

	int achouAluno = 0;

	ALUNO *aux;
	aux = (ALUNO*)malloc(sizeof(ALUNO));
	if(aux == NULL){
		printf(" ERRO\n");
		exit(1);
	}
	aux = alunos->inicio;

	while(aux != NULL){
		if(aux->numUSP == numUSP){
			achouAluno = 1;

			printf("    Nome: %s\n", aux->nome);
			printf("    Numero USP: %d\n", aux->numUSP);
			printf("    Telefone: %s\n", aux->telefone);
			printf("    Email: %s\n", aux->email);
			printf("    Livros emprestados: %d\n\n", aux->emprestados);
			break;
		}
	}
	if(achouAluno != 1){
		printf("\n\n    Aluno não encontrado na biblioteca!\n\n");
		*erro = 1;
		return;
	}
}


void mostrarTodosLivros(LISTA_LIVROS *livros, int *erro){

	*erro = 0;
	if(livros->qtd == 0){
		printf("    Nao há livros cadastrados na biblioteca no momento!\n\n");
		*erro = 1;
		return;
	}

	LIVRO *aux;
	aux = (LIVRO*)malloc(sizeof(LIVRO));
	if(aux == NULL){
		printf(" ERRO\n");
		exit(1);
	}
	aux = livros->inicio;

	while(aux != NULL){
		printf("    Titulo: %s\n", aux->titulo);
		printf("    Autor: %s\n", aux->autor);
		printf("    ISBN: %d\n", aux->ISBN);
		printf("    Editora: %s\n", aux->editora);
		printf("    Ano: %d\n", aux->ano);
		printf("    Edicao: %d\n", aux->edicao);
		printf("    Copias disponiveis: %d\n\n", aux->copias);

		aux = aux->prox;
	}
	free(aux);
}


void mostrarTodosAlunos(LISTA_ALUNOS *alunos, int *erro){

	*erro = 0;
	if(alunos->qtd == 0){
		printf("    Nao ha alunos cadastrados na biblioteca no momento!\n\n");
		*erro = 1;
		return;
	}

	ALUNO *aux;
	aux = (ALUNO*)malloc(sizeof(ALUNO));
	if(aux == NULL){
		printf(" ERRO\n");
		exit(1);
	}
	aux = alunos->inicio;

	while(aux != NULL){
		printf("    Nome: %s\n", aux->nome);
		printf("    Numero USP: %d\n", aux->numUSP);
		printf("    Telefone: %s\n", aux->telefone);
		printf("    Email: %s\n", aux->email);
		printf("    Livros emprestados: %d\n\n", aux->emprestados);

		aux = aux->prox;
	}

	free(aux);
}



void mostrarTodosEspera(LISTA_ESPERA *espera, int *erro){
	
	*erro =0;
	if(espera->qtd == 0){
		printf("    Nao ha alunos na lista de espera no momento!\n\n");
		*erro = 1;
		return;
	}

	DADOS *noe;
	noe = (DADOS*)malloc(sizeof(DADOS));
	if(noe == NULL){
		printf(" ERRO\n");
		exit(1);
	}
	noe = espera->inicio;

	while(noe != NULL){
		printf("    Numero USP do aluno: %d\n", noe->numUSP);
		printf("    ISBN do livro esperado: %d\n\n", noe->ISBN);

		noe = noe->prox;
	}

	free(noe);
}

void retirarLivro(LISTA_LIVROS *livros, LISTA_ALUNOS *alunos, LISTA_ESPERA *espera, int ISBN, int numUSP, int *erro){

	*erro = 0;

	int achouAluno =0;

	ALUNO *noa;
	noa = (ALUNO*)malloc(sizeof(ALUNO));
	if(noa == NULL){
		printf(" ERRO na alocacao do auxliar aluno!\n");
		exit(1);
	}
	noa = alunos->inicio;

	while(noa != NULL){
		if(noa->numUSP == numUSP){
			achouAluno = 1;

			if(noa->emprestados > 2){
				printf("    O aluno nao pode ter mais de 2 livros em posse de uma vez!\n");
				*erro = 1;
				return;
			}
			else{
				break;
			}
		}
	}

    if (achouAluno==0){
        printf("\n\n    O Aluno não foi encontrado cadastrado na biblioteca!\n\n");
        *erro = 1;
        return;
    }
    int achouLivro=0;

    LIVRO *nol;
    nol = (LIVRO*)malloc(sizeof(LIVRO));
    if(nol == NULL){
    	printf(" ERRO na alocacao de memoria do auxliar livro!\n");
    	exit(1);
    }
    nol = livros->inicio;

    while(nol != NULL){
        if(nol->ISBN == ISBN){
            achouLivro = 1;

            if(nol->copias < 1){
                printf("    Nenhuma copia do livro disponivel no momento!\n");
                printf("    Gostaria de adicionar o aluno na lista de espera?\n");
                printf("    Digite [1] --> SIM\n");
                printf("    Digite [2] --> NAO\n");
                printf("    Opcao: ");
                int escolha = 0;
                scanf("%d", &escolha);
                while(escolha != 1 || escolha != 2){
	                if(escolha == 1){
	                	pushEspera(espera, ISBN, numUSP);
	                	printf("    ALUNO ADICIONADO NA LISTA DE ESPERA!\n\n");
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
                nol->copias--;
                while(noa != NULL){
					if(noa->numUSP == numUSP){
						noa->emprestados++;
					}
				}
                printf("\n    LIVRO RETIRADO COM SUCESSO!\n\n");
                printf("    ...Atualizando dados...\n");
                printf("    Copias do livro [%s]: %d\n", nol->titulo, nol->copias);
                printf("    Livros pegos pelo aluno [%s]: %d\n\n", noa->nome, noa->emprestados);
                break;
            }
        }
    }

    if(achouLivro == 0){
        printf("\n\n    Livro não encontrado na biblioteca!!\n\n");
        *erro = 1;
        return;
    }

    free(nol);
    free(noa);
}



void devolverLivro(LISTA_LIVROS *livros, LISTA_ALUNOS *alunos, LISTA_ESPERA *espera, int ISBN, int numUSP, int *erro){

	*erro = 0;

	ALUNO *noa;
	noa = (ALUNO*)malloc(sizeof(ALUNO));
	if(noa == NULL){
		printf(" ERRO na alocacao do auxliar aluno!\n");
		exit(1);
	}
	noa = alunos->inicio;

	int achouAluno=0, achouLivro=0;

	printf("\n    ...Procurando aluno com esses dados...\n");

	while(noa != NULL){
		if(noa->numUSP == numUSP){
			achouAluno = 1;
			break;
		}
	}
	if(achouAluno != 1){
		printf("\n\n    Aluno não encontrado na biblioteca!!!\n\n");
		*erro = 1;
		return;
	}

	printf("\n    ...Procurando livro com esses dados...\n\n");

	LIVRO *nol;
    nol = (LIVRO*)malloc(sizeof(LIVRO));
    if(nol == NULL){
    	printf(" ERRO na alocacao de memoria do auxliar livro!\n");
    	exit(1);
    }
    nol = livros->inicio;

	while(nol != NULL){
		if(nol->ISBN == ISBN){
			achouLivro = 1;

			nol->copias++;
			while(noa != NULL){
				if(noa->numUSP == numUSP){
					noa->emprestados--;
				}
			}
			printf("    LIVRO DEVOLVIDO COM SUCESSO!\n\n");
			printf("    ...Atualizando dados...\n");
            printf("    Copias do livro [%s]: %d\n", nol->titulo, nol->copias);
            printf("    Livros pegos pelo aluno [%s]: %d\n\n", noa->nome, noa->emprestados);
			break;
		}
	}
	if(achouLivro != 1){
		printf("\n\n  Livro não encontrado na biblioteca!!!\n");
		*erro = 1;
		return;
	}

	/* verifique se algum aluno na lista de espera, espera esse livro que acabou de ser devolvido! */

	DADOS *noe;
	noe = (DADOS*)malloc(sizeof(DADOS));
	if(noe == NULL){
		printf(" ERRO na alocacao de memoria do auxiliar de espera!\n");
		exit(1);
	}
	noe = espera->inicio;

	while(noe != NULL){
		if(noe->ISBN == ISBN){
			printf("       ---  EMAIL  ---\n\n");
			printf("   O aluno com ISBN [%d] ja pode retirar o livro que estava esperando!\n\n", noe->numUSP);
			printf("   O aluno foi retirado da lista de espera!\n\n");
			removeEspera(espera, numUSP, erro);
			break;
		}
	}

	free(nol);
	free(noa);
	free(noe);
}

LISTA_ALUNOS* criaAlunos(){
	LISTA_ALUNOS *alunos;
    alunos = (LISTA_ALUNOS*) malloc(sizeof(LISTA_ALUNOS));
    if(alunos != NULL)
    	alunos->inicio = NULL;
		alunos->fim = NULL;
        alunos->qtd = 0;
    return alunos;
}

LISTA_LIVROS* criaLivros(){
	LISTA_LIVROS *livros;
    livros = (LISTA_LIVROS*) malloc(sizeof(LISTA_LIVROS));
    if(livros != NULL)
    	livros->inicio=NULL;
		livros->fim = NULL;
        livros->qtd = 0;
    return livros;
}

LISTA_ESPERA* criaEspera(){
	LISTA_ESPERA *espera;
    espera = (LISTA_ESPERA*) malloc(sizeof(LISTA_ESPERA));
    if(espera != NULL)
    	espera->inicio=NULL;
		espera->fim = NULL;
        espera->qtd = 0;
    return espera;
}

void quantidadeLivros(LISTA_LIVROS *livros){
    printf("\n    A biblioteca tem [%d] livros cadastrados no momento!\n\n", livros->qtd);
}

void quantidadeAlunos(LISTA_ALUNOS *alunos){
    printf("\n    A biblioteca tem [%d] alunos cadastrados no momento!\n\n", alunos->qtd);
}

void quantidadeEspera(LISTA_ESPERA *espera){
    printf("\n    A biblioteca possui [%d] alunos na lista de espera no momento!\n\n", espera->qtd);
}

/* libera memoria de todos os nós da lista de alunos */
void freeAlunos(LISTA_ALUNOS *alunos){
    
    ALUNO *aux;
    aux = (ALUNO*)malloc(sizeof(ALUNO)); 
    if(aux == NULL){
        printf(" ERRO na alocacao de memoria para o auxiliar do tipo aluno!\n");
        exit(1);
    }
    aux = alunos->inicio;

    ALUNO *deletar;
    deletar = (ALUNO*)malloc(sizeof(ALUNO));
	if(deletar != NULL){
		exit(1);
	}
	
	while(aux != NULL){
			deletar = aux;
			aux = aux->prox;
			free(deletar);
	}
}

void freeLivros(LISTA_LIVROS *livros){
    
    LIVRO *aux;
    aux = (LIVRO*)malloc(sizeof(LIVRO));
    if(aux == NULL){
        printf(" ERRO\n");
        exit(1);
    }
    aux = livros->inicio;
	
    LIVRO *deletar;
    deletar = (LIVRO*)malloc(sizeof(LIVRO));
    if(deletar == NULL){
        printf(" ERRO na alocacao de memoria para o auxiliar do tipo deletar!\n");
        exit(1);
    }

    while(aux != NULL){
        deletar = aux;
        aux = aux->prox;
        free(deletar);
    }
    free(aux);
	free(deletar);
}

void freeEspera(LISTA_ESPERA *espera){
    
    DADOS *aux;
    aux = (DADOS*)malloc(sizeof(DADOS));
    if(aux == NULL){
        printf(" ERRO na alocacao de memoria para o auxilia do tipo deletar!\n");
        exit(1);
    }
    aux = espera->inicio;

    DADOS *deletar;
    deletar = (DADOS*)malloc(sizeof(DADOS));
    if(deletar == NULL){
        printf(" ERRO na alocacao de memoria para o auxilia do tipo deletar!\n");
        exit(1);
    }

    while(aux != NULL){
        deletar = aux;
        aux = aux->prox;
        free(deletar);
    }
    
    free(aux);
    free(deletar);
}


int verificaISBN(LISTA_LIVROS *livros, int ISBN){

	LIVRO *aux;
	aux = (LIVRO*)malloc(sizeof(LIVRO));
	if(aux == NULL){
		printf(" ERRO na alocação para o nó livro auxiliar!\n");
	}
	aux = livros->inicio;

	while(aux != NULL){
		if(aux->ISBN == ISBN){
			return 1;
			break;
		}
		aux = aux->prox;
	}
	free(aux);

	if(ISBN < 1000 || ISBN > 9999){
		return 2;
	}
	return;
}


bool verificaTitulo(LISTA_LIVROS *livros, char titulo[]){

	int valido=1;
	LIVRO *aux;
	aux = (LIVRO*)malloc(sizeof(LIVRO));
	if(aux == NULL){
		printf(" ERRO na alocação para o nó livro auxiliar!\n");
	}
	aux = livros->inicio;

	while(aux != NULL){
		if(strcmp(aux->titulo, titulo)==0){
			return false;
			valido = 0;
			break;
		}
		aux = aux->prox;
	}
	free(aux);

	if(valido!=0){
		return true;
	}
}

int verificaNumUSP(LISTA_ALUNOS *alunos, int numUSP){

	ALUNO *aux;
	aux = (ALUNO*)malloc(sizeof(ALUNO));
	if(aux == NULL){
		printf(" ERRO na alocação para o nó aluno auxiliar!\n");
	}
	aux = alunos->inicio;

	while(aux != NULL){
		if(aux->numUSP == numUSP){
			return 1;
			break;
		}
		aux = aux->prox;
	}
	free(aux);

	if(numUSP < 10000000 || numUSP > 99999999){
		return 2;
	}
}

int verificaEmail(LISTA_ALUNOS *alunos, char email[]){

	ALUNO *aux;
	aux = (ALUNO*)malloc(sizeof(ALUNO));
	if(aux == NULL){
		printf(" ERRO na alocação para o nó aluno auxiliar!\n");
		exit(1);
	}
	aux = alunos->inicio;

	/* verifica se email já esta cadastrado no sistema */
	while(aux != NULL){
		if(strcmp(aux->email, email)==0){
			return 1;
			break;
		}
		aux = aux->prox;
	}
	free(aux);

	/* verifica se o email digitado é valido, terminado em @usp.br */
	char verifica [7];
	strcpy(verifica, "@usp.br");

	int tamanho = strlen(email);
	int k;
	for(k=0; k < 7; k++){
		if(email[tamanho-7+k] != verifica[k]){
			return 2;
			break;
		}
	}
}

int verificaTelefone(LISTA_ALUNOS *alunos, char telefone[]){

	ALUNO *aux;
	aux = (ALUNO*)malloc(sizeof(ALUNO*));
	if(aux == NULL){
		printf(" ERRO na alocacao!\n");
		exit(1);
	}
	aux = alunos->inicio;

	while(aux != NULL){
		if(strcmp(aux->telefone, telefone)==0){
			break;
			return 1;
		}
	}
	free(aux);

	char verifica[6];
	strcpy(verifica, "551899");

	if(strlen(telefone)<13){
		return 2;
	}
	else if(strlen(telefone)>13){
		return 3;
	}

	int k;
	for(k=0; k< 6; k++){
		if(telefone[k] != verifica[k]){
			return 4;
		}
	}
}

int verificaNome(LISTA_ALUNOS *alunos, char nome[]){

	int valido=1;
	ALUNO *aux;
	aux = (ALUNO*)malloc(sizeof(ALUNO));
	if(aux == NULL){
		printf(" ERRO na alocaçao de memoria para o nó aluno!\n");
		exit(1);
	}
	aux = alunos->inicio;

	while(aux != NULL){
		if(strcmp(aux->nome, nome)==0){
			valido = 0;
			return 0;
			break;
		}
	}

	if(valido!=0){
		return 1;
	}

	free(aux);
}
