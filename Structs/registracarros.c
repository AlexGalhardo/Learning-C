#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30

struct CARRO{
	int id;
	char fabricante[MAX];
	char modelo[MAX];
	int ano;
	char cor[MAX];
	int preco;
};

void opONE(struct CARRO carros[], int ids[], int qtd){ // IMPRIMIR DADOS DO CARROS, DE ACORDO COM SUA ID

	int j, i=0;
	for(j=0; j<qtd; j++){
		if(carros[j].id == ids[i]){
			printf("Fab: %s\n", carros[j].fabricante);
			printf("Mod: %s\n", carros[j].modelo);
			printf("Cor: %s\n", carros[j].cor);
			printf("Ano: %d\n", carros[j].ano);
			printf("Pre: %d\n", carros[j].preco);
			i++;
		}
	}
}

void opTWO(struct CARRO carros[], int qtd){ // MUDAR FABRICANTE PARA GM, SE FOR CHEVROLET

	int j;
	for(j=0; j<qtd; j++){
		if(strcmp(carros[j].fabricante, "Chevrolet") == 0){
			strcpy(carros[j].fabricante,"GM");
		}
	}
}

void opTHREE(struct CARRO carros[], int qtd){ // IMPRIMIR TODOS OS REGISTROS

	int j;
	for(j=0; j<qtd; j++){
		printf("Fab: %s\n", carros[j].fabricante);
		printf("Mod: %s\n", carros[j].modelo);
		printf("Cor: %s\n", carros[j].cor);
		printf("Ano: %d\n", carros[j].ano);
		printf("Pre: %d", carros[j].preco);
	}
}


int main(){

	int qtd, i;

	scanf("%d", &qtd);

	struct CARRO *carros = malloc(qtd * sizeof(struct CARRO));


	// RECEBENDO DADOS DOS CARROS
	for(i=0; i<qtd; i++){
		scanf("%d", &carros[i].id);
		scanf("%s", carros[i].fabricante);
		scanf("%s", carros[i].modelo);
		scanf("%s", carros[i].cor);
		scanf("%d", &carros[i].ano);
		scanf("%d", &carros[i].preco);
	}

	int options[MAX], ids[MAX], p=0, option;

	// ARMAZENANDO OPÇÕES E IDS
	do{
		scanf("%d", &option);
		options[p]=option;

		if(options[p] == 1){
			scanf("%d", &ids[p]);
		}
		p++;

	}while(option != 0);

	// CHAMANDO AS FUNÇÕES E PRINTANDO RESULTADOS
	int a;
	for(a=0; a<qtd; a++){
		if(options[a]== 1){
			opONE(carros, ids, qtd);
			printf("\n\n");
		}
		else if(options[a]== 2){
			opTWO(carros, qtd);
			printf("\n\n");
		}
		else if(options[a]== 3){
			opTHREE(carros, qtd);
			printf("\n\n");
		}
	}

	free(carros);

	return 0;
}