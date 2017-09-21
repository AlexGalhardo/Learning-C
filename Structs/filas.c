#include <stdio.h>
#include <stdlib.h>


/*
Filas
➔
 Também conhecida como 
queue
➔
Estrutura de dados nas quais o elemento inserido há mais 
tempo é o primeiro a ser retirado
◆
Só é permitido acesso a 1 único item por vez
●
O mais antigo
Filas
➔
Por seu tipo de acesso, é uma estrutura FIFO
◆
First-In First-Out


Filas
➔
Adiciona-se elementos no fim da fila (
tail
)
➔
Remove-se elementos no início dela (
head


Duas operações essenciais ocorrem numa fila
◆
Inserção, também conhecido como 
enqueue
◆
Remoção, também conhecido como 
dequeue



Enqueue
◆
Insere um elemento no fim da fila
◆
Aumenta o tamanho da pilha
◆
Atualiza qual elemento é o último



Dequeue
◆
Remove o elemento no início da fila
◆
Reduz o tamanho da fila
◆
Atualiza qual elemento é o início
)


Existem duas maneiras de implementar uma fila
◆
Vetores
◆
Lista Ligada
➔
Vamos ver agora a implementação em Vetor
Vamos ver um exemplo!
➔
https://www.cs.usfca.edu/~galles/visualization/QueueAr
ray.html
*/

// IMPLEMENTAÇÃO DE PILHAS COM VETORES

//STRUCT FILA

struct Fila{
	int capacidade;
	float *dados;
	int primeiro;
	int ultimo;
	int nItens;
}

//CRIAR FILA
void criarFila(struct Fila *f, int c){
	f->capacidade = c;
	f->dados = (float*) malloc(f->capacidade *sizeof(float));
	f->primeiro =0;
	f->ultimo = -1;
	f->nItens=0;
}

//INSERIR -ENQUEUE
void enqueue(struct Fila *f, int v){
	if(f->ultimo == f->capacidade -1){
		f->ultimo= -1;
	}

	f->ultimo++;
	f->dados[f->ultimo] = v; // incrementa ultimo e insere
	f->nItens++; // mais um item inserido
}


// REMOVER -DEQUEUE
int dequeue(struct Fila *f){ // pega o item do começo da fila

	int temp = f->dados[f->primeiro++]; // pega o valor e incrementa o primeiro
	if(f->primeiro == f->capacidade){
		f->primeiro =0;
	}

	f->nItems--; // um item retirado
	return tempo;
}

// ESTÁ VAZIA?
int isEmpty(struct Fila *f){ // true se estiver vazia
	return (f->nItens==0);
}

// ESTÁ CHEIA?
int isFull(struct Fila *f){ // True se estiver cheia
	return(f->nItens == f->capacidade);
}

//MOSTRAR FILA
void mostrarFila(struct Fila *f){
	int cont, i;
	for(cont=0, i=f->primeiro; cont<f->nItens; cont++){
		printf("%.2f\t", f->dados[i++]);
		if(i== f->capacidade){
			i=0;
		}
	}
	printf("\n\n");
}

// TESTANDO
void main(){
	int opcao, capa;
	float valor;
	struct Fila umaFila;

	//cria a fila
	printf("\nCapacidade da fila?");
	scanf("%d", &capa);
	criarFila(&umaFila, capa);

	// apresenta menu
	while(1){
		printf("\n1 - Inserir elemento \n2 - remover\n 3-Mostrar Fila\n 0-sair\n\nOpcao?");
		scanf("%d", &opcao);

		switch(opcao){
			case 0:
				exit(0);

			case 1: // insere elemento
				if(isFull(&umaFila)){
					printf("\nFila Cheia!!!\n\n");
				}
				else{
					printf("\nValor do elemento a ser inserido");
					scanf("%f", &valor);
					inserir(&umaFila, valor);
				}	
				break;
			case 2: // remove elemento
				if(isEmpty(&umaFila)){
					printf("\nFila VAZIA!!!\n\n");
				}
				else{
					valor = remover(&umaFila);
					printf("\nlf removido com sucesso\n", valor);
				}
				break;
			case 3: // mostrar fila
				if(isEmpty(&umaFila)){
					printf("\nFila vazia!!!\n\n");
				}
				else{
					printf("\nConteudo da fila => ");
					mostrarFila(&umaFila);
				}
				break;
			default:
				printf("\nOpcao invalida\n\n");
		}	
	}
}

// Referencias
/*
Referências
1.
https://www.cs.usfca.edu/~galles/visualization/Algorithms.html
2.
http://www.cos.ufrj.br/~rfarias/cos121/pilhas.html
3.
https://www.vivaolinux.com.br/script/Pilha-usando-lista-encadeada
4.
http://www.cos.ufrj.br/~rfarias/cos121/filas.html

*/
