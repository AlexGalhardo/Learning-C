#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int info;
	struct node *direita;
	struct node *esquerda;	
}NO;

arv* cria_arv(){
	arv* raiz = (arv*)malloc(sizeof(arv));
	if(raiz != NULL){
		*raiz = NULL;
	}
	return raiz;
}

void liberaNo(NO* no){
	if(no == NULL){
		return;
	}
	liberaNo(no->esquerda);
	liberaNo(no->direita);
	free(no);
	no = NULL;
}

void liberaArv(arv* raiz){
	if(raiz == NULL){
		return;
	}
	liberaNo(*raiz);
	free(raiz);
}

int vazia(arv *raiz){
	if(raiz == NULL){
		return 1;
	}
	if(*raiz == NULL){
		return 1;
	}
	return 0;
}

int altura(arv *raiz){
	if(raiz == NULL){
		return 0;
	}
	if(*raiz == NULL){
		return 0;
	}
	
	int alt_esq = altura(&((*raiz)->esq));
	int alt_dir = altura(&((*raiz)->dir));
	
	if(alt_esq > alt_dir){
		return (alt_esq+1);
	}
	else{
		return (alt_dir+1);
	}
}

int totalNo(arv *raiz){
	if(raiz == NULL){
		return 0;
	}
	if(*raiz == NULL){
		return 0;
	}
	int alt_esq = totalNo(&((*raiz)->esq));
	int alt_dir = totalNo(&((*raiz)->dir));
	
	return(alt_esq + alt_dir + 1);
}

void preOrdem(arv *raiz){
	if(raiz == NULL){
		return;
	}
	if(*raiz != NULL){
		printf("%d\n", (*raiz)->info);
		preOrdem(&((*raiz)->esq));
		preOrdem(&((*raiz)->dir));
	}
}

void emOrdem(arv *raiz){
	if(raiz == NULL){
		return;
	}
	if(*raiz != NULL){
		preOrdem(&((*raiz)->esq));
		printf("%d\n", (*raiz)->info);
		preOrdem(&((*raiz)->dir));
	}
}

void posOrdem(arv *raiz){
	if(raiz == NULL){
		return;
	}
	if(*raiz != NULL){
		preOrdem(&((*raiz)->esq));
		preOrdem(&((*raiz)->dir));
		printf("%d\n", (*raiz)->info);
	}
}

int insereArv(arv * raiz, int valor){
	if(raiz == NULL){
		return 0;
	}
	// cria o novo nó que será inserido na árvore
	NO *novo;
	novo = (NO*)malloc(sizeof(NO));
	if(novo == NULL){
		return 0;
	}
	novo->info = valor;
	novo->direita = NULL;
	novo->esquerda = NULL;
	
	if(*raiz == NULL){
		*raiz = novo;
	}
	else{
		NO *atual = *raiz;
		NO *ant = NULL;
		while(atual != NULL){
			ant = atual;
			if(valor == atual->info){
				free(novo);
				return 0;
			}
			
			if(valor > atual->info){
				atual = atual->direita;
			}
			else{
				atual = atual->esquerda;
			}
		}
		if(valor > ant->info){
			ant->direita = novo;
		}
		else{
			ant->esquerda = novo;
		}
	}
	return 1;
}

int removerNo(arv *raiz, int valor){
	if(raiz == NULL){
		return 0;
	}
	NO* ant = NULL;
	NO* atual = *raiz;
	while(atual != NULL){
		if(valor == atual->info){
			if(atual == *raiz){
				*raiz = remove_atual(atual);
			}
			else{
				if(ant->direita==atual){
					ant->direita = remove_atual(atual);
				}
				else{
					ant->esquerda = remove_atual(atual);
				}
			}
			return 1;
		}
		ant = atual;
		if(valor >atual->info){
			atual = atual->direita;
		}
		else{
			atual = atual->esquerda;
		}
	}
}

NO* remove_atual(NO* atual){
	NO *no1, *no2;
	if(atual->esquerda == NULL){
		no2 = atual->direita;
		free(atual);
		return no2;
	}
	no1 = atual;
	no2 = atual->esquerda;
	while(no2->direita != NULL){
		no1 = no2;
		no2 = no2->direita;
	}

	if(no1 != atual){
		no1->direita = no2->esquerda;
		no2->esquerda = atual->esquerda;
	}
	no2->direita = atual->direita;
	free(atual);

	return no2;
}

int consultaArv(arv *raiz, int valor){
	if(raiz == NULL){
		return 0;
	}
	NO *atual = *raiz;
	while(atual != NULL){
		if(valor == atual->info){
			return 1;
		}
		if(valor > atual->info){
			atual = atual->direita;
		}
		else{
			atual = atual->esquerda;
		}
	}
	return 0;
}

int main(){
	
	arv *raiz = cria_arv();
	liberaArv(raiz);
	
	return 0;
}
