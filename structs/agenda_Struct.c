/*
Disciplina: SSC0502 - Laboratório de Introdução a Computação I
Prazo de Entrega: 26/06/2017 23:55:55 Aberto

Implemente uma agenda com data, hora e atividade a ser realizada, em que data contém, dia, mês e ano e hora contém hora, minuto e segundo. Será passado a quantidade de atividades sequido da data da hora e da ativadade. As entradas e saídas deverão ser exibidas de acordo com o exemplo a seguir:
Exemplo de Entrada

3
23
06
2015
23
59
59
Finaliza  entrega  no run.codes
04
07
2015
00
00
01
Inicio  das  Ferias ....=D
13
07
2015
08
15
00
Inicio  da  Recuperacao

Exemplo de Saída

23/06/2015  - 23:59:59
Finaliza  entrega  no run.codes
04/07/2015  - 00:00:01
Inicio  das  Ferias ....=D
13/07/2015  - 08:15:00
Inicio  da  Recuperacao
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 200

struct datas{
	int dia;
	int mes;
	int ano;
	int horas;
	int minutos;
	int segundos;
	char frase[MAX];
};

int main(){

	int qtd;
	
	scanf("%d", &qtd);

	struct datas *vetor[qtd]; // criar um vetor de estruturas de acordo com a quantidade que o usuario oferecer

	vetor[qtd] = (struct datas*) malloc(sizeof(struct datas));

	// ENTRADAS
	int i;
	for(i=0; i<qtd; i++){
		scanf("%d", &vetor[i]->dia);
		scanf("%d", &vetor[i]->mes);
		scanf("%d", &vetor[i]->ano);
		scanf("%d", &vetor[i]->horas);
		scanf("%d", &vetor[i]->minutos);
		scanf("%d", &vetor[i]->segundos);
		scanf("%s", vetor[i]->frase);
	}

	// SAIDAS
	int j;
	for(j=0; j<qtd; j++){
		printf("%d/%d/%d  - %d:%d:%d\n%s", vetor[i]->dia, vetor[i]->mes, vetor[i]->ano,
									   vetor[i]->horas, vetor[i]->minutos, vetor[i]->segundos, vetor[i]->frase);
	}


	free(vetor);
	
	return 0;
}
