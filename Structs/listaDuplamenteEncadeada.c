#include <stdio.h>
#include <stdlib.h>

// LISTA DUPLAMENTE ENCADEADA

/*
Lista Simplesmente Encadeada
➔
Cada elemento possui
◆
Espaço para armazenar informação
◆
Espaço para armazenar referência do local na 
memória do próximo elemento
◆
Espaço para armazenar referência do local na 
memória do elemento anterior

*/

// ESTRUTURA
struct Nodo {
	int info;
	struct Nodo *ant;
	struct Nodo *prox;
}no;


// LER VALORES ATÉ ENTRADA 0
void main(){
	struct Nodo *inicio = NULL, *tmp, *p;
	int v;

	while(1){
		printf("\nValor? ");
		scanf("%d", &v);

		if(v==0){
			break;
		}

		// cria um novo nodo para ser inserido na lista
		tmp = (struct Nodo*) malloc(sizeof(struct Nodo));

		tmp->info = v;
		tmp->prox = NULL;

		if(inicio == NULL){ // lista vazia
			inicio = tmp;
			tmp->ant = tmp->prox = NULL;
		}
		// SE TEM ELEMENTO, ADICIONAR EM ORDEM
		else{
			// p irá percorrer a lista
			p = inicio;
			while(p->prox != NULL && p->info !=v){
				p = p->prox;
			}
			if(p->info != v){
				p->prox = tmp;
				tmp -> ant = p;
			}
		}

		// mostrando a lista
		p = inicio;
		while(p != NULL){
			printf("%d\t", p->info);
			p = p->prox;
		}
		printf("\n");
	}
}



/* REFERÊNCIAS 
Referências
➔
http://www.cos.ufrj.br/~rfarias/cos121/aula_10.html
➔
http://www.cos.ufrj.br/~rfarias/cos121/aula_11.html
➔
https://www.ime.usp.br/~pf/algoritmos/aulas/lista
➔
https://www.cs.usfca.edu/~galles/visualization/java/visu
alization.html
*/
