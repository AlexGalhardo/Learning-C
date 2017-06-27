#include <stdio.h>
#include <stdlib.h>

struct PAIS{
	char nome[3];
	int ouro;
	int prata;
	int bronze;
};

int main(){

	int qtd, i, j;

	scanf("%d", &qtd); // QUANTIDADE DE PAISES

	struct PAIS *pais[qtd];
	pais[qtd] = (struct PAIS *) malloc(qtd * sizeof(struct PAIS));


	// RECEBENDO OS DADOS
	for(i=0; i<qtd; i++){
		scanf("%s %d %d %d", pais[i]->nome, pais[i]->ouro, pais[i]->prata, pais[i]->bronze);
	}

	int aux;

	// ORDENANDO OS DADOS
	for(j=0; j<qtd; j++){
		if(pais[j]->ouro > pais[j+1]->ouro){ 
			aux = pais[j];
			pais[j] = pais[j+1];
			pais[j+1] = aux;
		}
		else if(pais[j]->ouro == pais[j+1]->ouro){
			if(pais[j]->prata > pais[j+1]->prata){
				aux = pais[j];
				pais[j] = pais[j+1];
				pais[j+1] = aux;
			}
		}
		else if(pais[j]->ouro == pais[j+1]->ouro && pais[j]->prata == pais[j+1]->prata){
			if(pais[j]->bronze > pais[j+1]->bronze){
				aux = pais[j];
				pais[j] = pais[j+1];
				pais[j+1] = aux;
			}
		}
	}

	// IMPRIMINDO OS DADOS
	for(i=0; i<qtd; i++){
		printf("%s ", pais[i]->nome);
		printf("%d ", pais[i]->ouro);
		printf("%d ", pais[i]->prata);
		printf("%d", pais[i]->bronze);
		printf("\n");
	}

	return 0;
}