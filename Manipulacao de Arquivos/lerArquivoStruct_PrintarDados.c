/*
Leitura Arquivo Texto - Estatística
Disciplina: SSC0502 - Laboratório de Introdução a Computação I 
Prazo de Entrega: 07/07/2017 23:55:55 Aberto
Leitura Arquivo Texto - Estatística
Faça um programa em C que leia o arquivo de texto chamado dados.txt e guarde o seu conteúdo em um registro (struct). Esse arquivo contém o primeiro nome de uma pessoa, o seu sexo e por último a idade. O seu programa deverá ler esse arquivo, calcular e então imprimir quantos registros tem no total, a quantidade de homens, a quantidade de mulheres, a média de idade total, a média de idade dos homens e por fim, a média de idade das mulheres. Use duas casas decimais para imprimir as médias de idade.

Exemplos de Entrada e Saída
Entrada

(arquivo de texto dados.txt)
Saída:

15 7 8 27.07 26.86 27.25
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 30
#define max 10


typedef struct{
	char nome[MAX];
	char sexo;
	int idade;
}PESSOA;

int main(){
	
	FILE *arq;

	arq = fopen("dados.txt", "r"); // abrir arquivo

	if(arq == NULL){
		printf("Erro na abertura do arquivo!\n");
		exit(1);
	}

	// vetor de struturas
	PESSOA pessoa[max]; 
	
	int i=0, registros=0, qtdHomem=0, qtdMulher=0;
	int homemIdade=0, mulherIdade=0, totalIdade=0;

	do{
		fscanf(arq, "%s %c %d", pessoa[i].nome, 
								&pessoa[i].sexo, 
								&pessoa[i].idade);

		// se for homem
		if(pessoa[i].sexo == 'm'){
			qtdHomem++;
			homemIdade += pessoa[i].idade;
			registros++; // total de pessoas
			totalIdade += pessoa[i].idade;
		}
		// se for mulher
		else if(pessoa[i].sexo == 'f'){
			qtdMulher++;
			mulherIdade += pessoa[i].idade;
			registros++; // total de pessoas
			totalIdade += pessoa[i].idade;
		}
		
		i++; // incrementa vetor
		
	}while(!feof(arq)); // enquanto nao chegar no fim do arquivo, continue

	float mediaHomem, mediaMulher, mediaTotal;

	mediaHomem = (float) homemIdade / qtdHomem;
	mediaMulher = (float) mulherIdade / qtdMulher;
	mediaTotal = (float) totalIdade / registros;


	printf("%d %d %d %.2f %.2f %.2f", registros, 
									  qtdHomem, 
									  qtdMulher, 
									  mediaTotal, 
									  mediaHomem, 
									  mediaMulher);
	
	return 0;
}
