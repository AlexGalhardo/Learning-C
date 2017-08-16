/*
Classificação dos jogos olímpicos
Disciplina: SSC0502 - Laboratório de Introdução a Computação I 
Prazo de Entrega: 06/07/2017 23:59:59 Aberto
A classificação do quadro de medalhas dos Jogos Olímpicos segue uma ordenação por etapas. A medalha de ouro tem maior valor, sendo as equipes posicionadas conforme suas medalhas de ouro, independente das outras medalhas conquistadas. Se dois países empatam em número de ouros, o desempate ́e realizado entre a quantidade de medalhas de prata entre os países empatados. Se o empate persiste no n ́umero de pratas, é considerado então o número de medalhas de bronze.
Por esta regra, o Brasil ficou apenas na 53º posição nos Jogos Olímpicos de Sydney, em 2000. Na ocasião o país conquistou 6 medalhas de prata e outras 6 de bronze, mas nenhum ouro. Ficaram à frente do Brasil países como Camarões, Colômbia e Moçambique, que conquistaram, cada um, apenas uma medalha de ouro durante os jogos.
Escreva um programa em C que leia de entrada o número de países N, em seguida seu programa deverá ler, para cada país, sua sigla (uma sequência de 3 “chars”. Exemplos: BRA,USA,GBR,GER), o número de medalhas de ouro, o número de medalhas de prata, e o número de medalhas de bronze. Em seguida imprima na tela o quadro de medalhas ordenado pela regra de classificação acima.

Exemplo de Entrada
4
BRA 3 4 5
USA 23 76 34
CHN 23 54 12
GER 10 20 23
Exemplo de Saída
USA 23 76 34
CHN 23 54 12
GER 10 20 23
BRA 3 4 5

Esconder Descrição 

Este exercício aceita os seguintes tipos de arquivos:
C  Baixar Casos de Teste

*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct{
	char nome[3];
	int ouro;
	int prata;
	int bronze;
}Medalhas;

void lerDados(Medalhas pais[], int qtd){

	int i;
	for(i=0; i<qtd; i++){
		scanf("%s", pais[i].nome);
		scanf("%d", &pais[i].ouro); 
		scanf("%d", &pais[i].prata);
		scanf("%d", &pais[i].bronze);
	}
}


void ordenarMedalhas(Medalhas pais[], int qtd){

	int i, j;
	Medalhas aux;
	for(i=0; i<qtd; i++){
		for(j=i+1; j<qtd; j++){
			if(pais[i].ouro <= pais[j].ouro){
				aux = pais[i];
				pais[i] = pais[j];
				pais[j] = aux;
			}
			if(pais[i].ouro <= pais[j].ouro && pais[i].prata <= pais[j].prata){
				aux = pais[i];
				pais[i] = pais[j];
				pais[j] = aux;
			}
			if(pais[i].ouro <= pais[j].ouro && pais[i].prata <= pais[j].prata && pais[i].bronze <= pais[j].bronze){
				aux = pais[i];
				pais[i] = pais[j];
				pais[j] = aux;
			}
		}
	}

}

void printarDados(Medalhas pais[], int qtd){

	int i;
	for(i=0; i<qtd; i++){
		printf("%s ", pais[i].nome);
		printf("%d ", pais[i].ouro);
		printf("%d ", pais[i].prata);
		printf("%d\n", pais[i].bronze);
	}
}

int main(){

	int qtd;
	scanf("%d", &qtd); // quantidade de paises

	Medalhas pais[qtd];

	lerDados(pais, qtd);
	ordenarMedalhas(pais, qtd);
	printarDados(pais, qtd);


	return 0;
}