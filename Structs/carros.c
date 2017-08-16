/*
Registro de carros
Disciplina: SSC0502 - Laboratório de Introdução a Computação I
Prazo de Entrega: 06/07/2017 23:59:59 Aberto

Criar uma estrutura para carros com as seguintes informações: id, fabricante, modelo, ano, cor, preço. Em seguida, crie as seguintes funções:
1. Ler os dados de um carro.
2. Buscar um determinado carro por meio de seu ID e imprimir seus dados (operação 1)
3. Modificar o fabricante para "GM" caso o registro seja Chevrolet (operação 2)
4. Imprimir os dados de todos os carros (operação 3)

Os campos fabricante, modelo e cor não terão mais de 20 caracteres. O primeiro valor a ser fornecido, será o da quantidade de carros a ser cadastrada e, em seguida, os dados de cada um. A entrada e saída do seu programa devem ser de acordo com os exemplos abaixo:
Exemplo de entrada

2
123
Chevrolet
Passat
Preto
2004
20000
456
Toyota
Corolla
Preto
2003
30000
1
123
2
3
1
456
0

Note que a operação zero deverá finalizar o programa.
Exemplo de saída

Fab: Chevrolet
Mod: Passat
Cor: Preto
Ano: 2004
Pre: 20000

Fab: GM
Mod: Passat
Cor: Preto
Ano: 2004
Pre: 20000

Fab: Toyota
Mod: Corolla
Cor: Preto
Ano: 2003
Pre: 30000

Fab: Toyota
Mod: Corolla
Cor: Preto
Ano: 2003
Pre: 30000

*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 30

struct CARRO{
	int id;
	char fabricante[MAX];
	char modelo[MAX];
	int ano;
	char cor[MAX];
	int preco;
};

int main(){

	int qtd, i;
	scanf("%d", &qtd);

	struct CARRO *carros[qtd];

	*carros[qtd] = (struct CARRO *) malloc(qtd * sizeof(struct CARRO));


	for(i=0; i<qtd; i++){
		scanf("%d", &carros[i]->id);
		scanf("%s", carros[i]->fabricante);
		scanf("%s", carros[i]->modelo);
		scanf("%s", carros[i]->cor);
		scanf("%d", &carros[i]->ano);
		scanf("%d", &carros[i]->preco);
	}

	int op, ID, j;

do{
	scanf("%d", &op);
	if(op==1){
		scanf("%d", &ID);
		for(j=0; j<qtd; j++){
			if(carros[j]->id == ID){
				printf("Fab: %s", carros[j]->fabricante);
				printf("Mod: %s", carros[j]->modelo);
				printf("Cor: %s", carros[j]->cor);
				printf("Ano: %d", carros[j]->ano);
				printf("Pre: %d", carros[j]->preco);
			}
		}
	}
	else if(op==2){
		for(j=0; j<qtd; j++){
			if(*carros[j]->fabricante == "Chevrolet"){
				*carros[j]->fabricante = "GM";
			}
		}
	}
	else if(op==3){
		for(j=0; j<qtd; j++){
			printf("Fab: %s", carros[j]->fabricante);
			printf("Mod: %s", carros[j]->modelo);
			printf("Cor: %s", carros[j]->cor);
			printf("Ano: %d", carros[j]->ano);
			printf("Pre: %d", carros[j]->preco);
		}
	}

}while(op!=0);

	return 0;
}