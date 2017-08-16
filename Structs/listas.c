#include <stdio.h>
#include <stdlib.h>

/*
O que é Lista?
➔
Estrutura que armazena uma sequência de dados
➔
Pode ser uma lista linear sequencial
◆
Pilhas, filas, deques
*
➔
Ou uma lista linear encadeada
◆
Elementos não são consecutivos na memória 
(necessariamente)


Lista Encadeada
➔
É uma representação de uma sequência de objetos do 
mesmo tipo na memória RAM do computador
➔
Cada elemento (
nó
) é armazenado em uma célula
◆
O primeiro na primeira célula
◆
O segundo na segunda célula
◆
Etc.

Lista Simplesmente Encadeada
➔
Cada elemento possui
◆
Espaço para armazenar informação
◆
Espaço para armazenar referência do local na 
memória do próximo elemento (ou do anterior

*/

struct Nodo{
	int info;
	struct Nodo *prox;
};


struct ListaSimplesEnc{
	struct Nodo *prim;
};

// CRIAR E MOSTRAR LISTA
void criarLista(struct ListaSimplesEnc *pList){
	pList-> prim = NULL;
}

void mostrarLista(struct ListaSimplesEnc *pList){
	struct Nodo *p;
	for(p= pList->prim; p!=NULL; p= p->prox){
		printf("%d\t", p->info);
	}
	printf("\n");
}

// INSERIR ITEM NO INICIO
void inserirIni(struct ListaSimplesEnc *pList, int v){

	struct Nodo *novo;
	novo = (struct Nodo *) malloc(sizeof(struct Nodo));
	novo -> info = v;
	novo -> prox = pList -> prim;
	pList -> prim = novo;
}

// REMOVER ITEM NO INICIO

void removerIni(struct ListaSimplesEnc *pList){

	struct Nodo *pAux = pList -> prim;
	pList ->prim = pList ->prim->prox;
	free(pAux);
}

// INSERIR ITEM EM ORDEM
void inserirOrd(struct ListaSimplesEnc *pList, int v){
	struct Nodo *novo;
	novo = (struct Nodo*) malloc(sizeof(struct Nodo));
	novo -> info = v;
	struct Nodo *pAtu, *pAnt;
	pAnt = NULL;
	pAtu = pList -> prim;

	while(pAtu != NULL && pAtu->info < v){
		pAnt = pAtu;
		pAtu = pAtu->prox;
	}

	novo->prox = pAtu->prox;
	pAnt->prox = novo;
}

// VERIFICA SE ESTÁ VAZIA
int estaVazia(struct ListaSimplesEnc *pList){
	return(pList->prim==NULL);
}




// TESTANDO
void main(){
	struct ListaSimplesEnc minhaLista;

	int valor, op;

	criarLista(&minhaLista);

	while(1){
		printf( "1 - Inserir elemento no inicio\n" );
		printf( "2 - Inserir elemento em ordem (so se a lista estiver ordenada)\n" );
		printf( "3 - Remover elemento no inicio\n" );
		printf( "4 - Remover elemento\n" );
		printf( "5 - Mostrar lista\n" );
		printf( "6 - Sair\n" );
		printf( "Opcao? " );
		scanf( "%d", &op );

		switch(op){
			case 1: // inserir elemento no inicio
				printf("Valor?");
				scanf("%d", &valor);
				inserirIni(&minhaLista, valor);
				break;
			case 2: // inserir elemento ordenado
				printf("Valor?");
				scanf("%d", &valor);
				inserirOrd(&minhaLista, valor);
				break;
			case 3: // remover o primeiro
				removerIni(&minhaLista);
				break;
			case 4: // remover determinado elemento
				// Implementem
				break;
			case 5: // mostrar lista
				if(estaVazia(&minhaLista)){
					printf("Lista vazia");
				} 
				else{
					mostrarLista(&minhaLista);
				}
				break;
			case 6: // abandonar o programa
				exit(0);
		}	


	}
}