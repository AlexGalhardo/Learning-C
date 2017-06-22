/*
Registro de carros
Disciplina: SSC0502 - Laboratório de Introdução a Computação I
Prazo de Entrega: 26/06/2017 23:55:55 Aberto

Criar uma estrutura para carros com as seguintes informações: id, fabricante, modelo, ano, cor, preço. Em seguida, crie as seguintes funções:
1. Ler os dados de um carro.
2. Buscar um determinado carro por meio de seu ID e imprimir seus dados (operação 1)
3. Imprimir os dados de todos os carros (operação 2)
4. Modificar o fabricante para "GM" caso o registro seja Chevrolet (operação 3)

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

note que cada registro encontra-se separado por duas quebras de linha e que o id do carro não deve ser impresso em nenhuma das operações.
*/

#include <stdio.h>
#include <stdlib.h>


#define MAX 20


struct CARRO{
	int id;
	char fabricante[MAX];
	char modelo[MAX];
	int ano;
	char cor[MAX];
	int preco;
};

void lerDados(CARRO carros[i]){
	scanf("%d", &carros[i].id);
	scanf("%s", carros[i].fabricante);
	scanf("%s", carros[i].modelo);
	scanf("%s", carros[i].cor);
	scanf("%d", &carros[i].ano);
	scanf("%d", &carros[i].preco);
}

int buscarID(CARRO carros[i], int *index, int ID, int qtd){ // OPERACAO 1

	int k;
	for(k=0; k<qtd; k++){
		if(carros[k].id == ID){
			*index = k; // index recebe posicao do carro
		}
	}

	return *index;
}

void imprimirDados(CARRO carros[i], int qtd){ // OPERACAO 2

	int p;
	for(p=0; p<qtd; p++){
		printf("Fab: ", carros[p].fabricante);
		printf("Mod: ", carros[p].modelo);
		printf("Cor: ", carros[p].cor);
		printf("Ano: ", carros[p].ano);
		printf("Pre: ", carros[p].preco);
	}
}

void mudarFabricante(CARRO carros[*index]){ // OPERACAO 3
	carros[*index].fabricante = "GM";
}


int main(){
	
	int qtd; // quantida de carros a ser cadastrada

	scanf("%d", &qtd);

	struct CARRO carros[qtd]; // criar um vetor de estruturas do tipo CARRO com a quantidade selecionada pelo usuario

	int i =0;
	while(i<qtd){
		lerDados(carros[i]);
		i++;
	}

	int option, ID;

	int j;
	do{
		scanf("%d", &option);
		if(option == 1){
			scanf("%d", &ID);
			int *index; // que posicão o carro se encontra?
			buscarID(carros[i], &index, ID, qtd); // buscar ID do carro
			// que posição do vetor de carros, essa ID se encontra?
			imprimirDados(carros[index]); // ler dados do carro
		}
		else if(option == 2){
			for(j=0; j<qtd; j++){
				imprimirDados(carros[j], qtd); // imprimir dados de todos os carros
			}
		}
		else if(option == 3){
			if(carros[i].fabricante == "Chevrolet"){
				buscarID(carros[i], &index, ID, qtd); // retorna a posição do carro no vetor de carros
				mudarFabricante(carros[&index]); // muda o fabricante do carro na posição index 
			}
		}

	}while(option !=0);


	return 0;
}