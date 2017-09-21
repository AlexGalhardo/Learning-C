#include <stdio.h>
#include <stdlib.h>

// -------- SLIDE 2 - STRUCT ---- //

// ------- PILHAS ---- //

/*
Pilhas
➔
 Também conhecida como 
stack
➔
Estrutura de dados nas quais o último elemento inserido 
é o primeiro a ser retirado
◆
Só é permitido acesso a 1 único item por vez
●
O último que foi inserido

➔
Por seu tipo de acesso, é uma estrutura LIFO
◆
Last-In First-Out

Vamos ver um exemplo!
➔
https://www.cs.usfca.edu/~galles/visualization/StackArr
ay.html

*/

// --- Implementação de pilha com vetores -- //


struct Pilha{
	int topo; // posicao do elemento topo
	int capacidade;
	float *pElem; // elemento da pilha, no caso float
}

// criar pilha
void criarPilha(struct Pilha *p, int c){
	p->topo = -1;
	p->capacidade =c;
	p->pEleme = (float*) malloc(c * sizeof(float));
}

// PUSH - empilhar
void push(struct Pilha *p, float v){
	p->topo++;
	p->pElem [p->topo] = v;
}

// POP - Desempilhar
float pop (struct Pilha *p){
	float aux = p->pElem [p->topo];
	p->topo--;
	return aux;
}

// OBTER ELEMENTO DO TOPO
float retornaTopo(struct Pilha *p){
	return p->pElem [p->topo];
}

// CHECAR SE ESTÁ VÁZIA
int isEmpty(struct Pilha *p){
	if(p->topo==-1){
		return 1; // true
	}
	else{
		return 0; // false
	}
}

// CHECAR SE ESTÁ CHEIA
int isFull(struct Pilha *p){
	if(p->topo == p->capacidade -1){
		return 1;
	}
	else{
		return 0;
	}
}

//TESTANDO

int main(){

	struct Pilha minhaPilha;

	int capacidade, op;
	float valor;
	printf("\nCapacidade da pilha: ");
	scanf("%d", &capacidade);
	criarPilha(&minhaPilha, capacidade);

	while(1){ // loop infinito
		printf("\n 1 - empilhar (push)\n");
		printf("2 - desempilhar (POP) \n");
		printf("3 - Mostrar o topo \n");
		printf("4 - sair \n");
		printf("\nopcao? ");
		scanf("%d", &op);
	}

	switch(op){
		case 1: //push
			if(isFull(&minhaPilha)==1){
				printf("\nPILHA CHEIA!\n");
			}
			else{
				printf("\nVALOR? ");
				scanf("%f", &valor);
				push(&minhaPilha, valor);
			}
			break;
		case 2: //POP
			if(isEmpty(&minhaPilha)==1){
				printf("\nPILHA VAZIA! \n");
			}
			else{
				valor = pop(&minhapilha);
				printf("\n%.1f DESEMPILHADO!\n", valor);
			}
			break;
		case 3: // mostrar o topo
			if(isEmpty(&minhapilha)==1){
				printf("\n PILHA VAZIA! \n");
			}
			else{
				valor = retornatopo(&minhapilha);
				printf("\n TOPO: %.1f\n", valor);
			}
			break;
		case 4:
			exit(0);
		default:
			printf("\nOPCAO INVALIDA! \n");
	}
}
