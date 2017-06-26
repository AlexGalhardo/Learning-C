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
};

int main(){

	int qtd;

	struct datas *primeiro;
	struct datas *segundo;
	struct datas *terceiro;

	
	primeiro = (struct datas *) malloc(sizeof(struct datas));
	segundo = (struct datas *) malloc(sizeof(struct datas));
	terceiro = (struct datas *) malloc(sizeof(struct datas));
	

	scanf("%d", &qtd);
	char frase1[MAX], frase2[MAX], frase3[MAX];

	if(qtd == 1){
		scanf("%d", &primeiro->dia);
		scanf("%d", &primeiro->mes);
		scanf("%d", &primeiro->ano);
		scanf("%d", &primeiro->horas);
		scanf("%d", &primeiro->minutos);
		scanf("%d", &primeiro->segundos);
		scanf("%s", frase1);
		/*
		printf("%d/%d/%d  - %d:%d:%d\n", primeiro->dia, primeiro->mes, primeiro->ano,
									   primeiro->horas, primeiro->minutos, primeiro->segundos);
		printf("%s", frase1);
		*/
	}
	else if(qtd == 2){
		scanf("%d", &primeiro->dia);
		scanf("%d", &primeiro->mes);
		scanf("%d", &primeiro->ano);
		scanf("%d", &primeiro->horas);
		scanf("%d", &primeiro->minutos);
		scanf("%d", &primeiro->segundos);
		scanf("%s", frase1);
		scanf("%d", &segundo->dia);
		scanf("%d", &segundo->mes);
		scanf("%d", &segundo->ano);
		scanf("%d", &segundo->horas);
		scanf("%d", &segundo->minutos);
		scanf("%d", &segundo->segundos);
		scanf("%s", frase2);
		/*
		printf("%d/%d/%d  - %d:%d:%d\n", primeiro->dia, primeiro->mes, primeiro->ano,
									   primeiro->horas, primeiro->minutos, primeiro->segundos);
		printf("%s\n", frase1);
		printf("%d/%d/%d  - %d:%d:%d\n", segundo->dia, segundo->mes, segundo->ano,
									     segundo->horas, segundo->minutos, segundo->segundos);
		printf("\n%s", frase2);
		*/
	}
	else if(qtd == 3){
		scanf("%d", &primeiro->dia);
		scanf("%d", &primeiro->mes);
		scanf("%d", &primeiro->ano);
		scanf("%d", &primeiro->horas);
		scanf("%d", &primeiro->minutos);
		scanf("%d", &primeiro->segundos);
		scanf("%s", frase1);
		scanf("%d", &segundo->dia);
		scanf("%d", &segundo->mes);
		scanf("%d", &segundo->ano);
		scanf("%d", &segundo->horas);
		scanf("%d", &segundo->minutos);
		scanf("%d", &segundo->segundos);
		scanf("%s", frase2);
		scanf("%d", &terceiro->dia);
		scanf("%d", &terceiro->mes);
		scanf("%d", &terceiro->ano);
		scanf("%d", &terceiro->horas);
		scanf("%d", &terceiro->minutos);
		scanf("%d", &terceiro->segundos);
		scanf("%s", frase3);
		/*
		printf("%d/%d/%d  - %d:%d:%d\n", primeiro->dia, primeiro->mes, primeiro->ano,
									   primeiro->horas, primeiro->minutos, primeiro->segundos);
		scanf("%s\n", frase1);
		printf("%d/%d/%d  - %d:%d:%d\n", segundo->dia, segundo->mes, segundo->ano,
									     segundo->horas, segundo->minutos, segundo->segundos);
		scanf("\n%s", frase2);
		printf("%d/%d/%d  - %d:%d:%d\n", terceiro->dia, terceiro->mes, terceiro->ano,
									     terceiro->horas, terceiro->minutos, terceiro->segundos);
		printf("%s", frase3);
		*/
	}

	if(qtd==1){
		printf("%d/%d/%d  - %d:%d:%d\n", primeiro->dia, primeiro->mes, primeiro->ano,
									   primeiro->horas, primeiro->minutos, primeiro->segundos);
		puts(frase1);
	}
	else if(qtd ==2){
		printf("%d/%d/%d  - %d:%d:%d\n", primeiro->dia, primeiro->mes, primeiro->ano,
									   primeiro->horas, primeiro->minutos, primeiro->segundos);
		puts(frase1);
		printf("%d/%d/%d  - %d:%d:%d\n", segundo->dia, segundo->mes, segundo->ano,
									     segundo->horas, segundo->minutos, segundo->segundos);
		puts(frase2);
	}
	else if(qtd==3){
		printf("%d/%d/%d  - %d:%d:%d\n", primeiro->dia, primeiro->mes, primeiro->ano,
									   primeiro->horas, primeiro->minutos, primeiro->segundos);
		puts(frase1);
		printf("%d/%d/%d  - %d:%d:%d\n", segundo->dia, segundo->mes, segundo->ano,
									     segundo->horas, segundo->minutos, segundo->segundos);
		puts(frase2);
		printf("%d/%d/%d  - %d:%d:%d\n", terceiro->dia, terceiro->mes, terceiro->ano,
									     terceiro->horas, terceiro->minutos, terceiro->segundos);
		puts(frase3);
	}

	
	return 0;
}
