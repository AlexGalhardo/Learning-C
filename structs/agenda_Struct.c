/*
Agenda
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

#define MAX 100

struct DATA{
	int dia;
	int mes;
	int ano;
};


struct HORA{
	int hora;
	int minuto;
	int segundo;
};

void lerDados1(){
	scanf("%d", &finaliza.dia);
	scanf("%d", &finaliza.mes);
	scanf("%d", &finaliza.ano);
	scanf("%d", &finaliza.hora);
	scanf("%d", &finaliza.minuto);
	scanf("%d", &finaliza.segundo);
	scanf("%s", &frase1);
	
}

void lerDados2(){

	scanf("%d", &finaliza.dia);
	scanf("%d", &finaliza.mes);
	scanf("%d", &finaliza.ano);
	scanf("%d", &finaliza.hora);
	scanf("%d", &finaliza.minuto);
	scanf("%d", &finaliza.segundo);
	scanf("%s", &frase1);
	scanf("%d", &ferias.dia);
	scanf("%d", &ferias.mes);
	scanf("%d", &ferias.ano);
	scanf("%d", &ferias.hora);
	scanf("%d", &ferias.minuto);
	scanf("%d", &ferias.segundo);
	scanf("%s", &frase2);
}

void lerDados3(){

	scanf("%d", &finaliza.dia);
	scanf("%d", &finaliza.mes);
	scanf("%d", &finaliza.ano);
	scanf("%d", &finaliza.hora);
	scanf("%d", &finaliza.minuto);
	scanf("%d", &finaliza.segundo);
	scanf("%s", frase1);
	scanf("%d", &ferias.dia);
	scanf("%d", &ferias.mes);
	scanf("%d", &ferias.ano);
	scanf("%d", &ferias.hora);
	scanf("%d", &ferias.minuto);
	scanf("%d", &ferias.segundo);
	scanf("%s", frase2);
	scanf("%d", &rec.dia);
	scanf("%d", &rec.mes);
	scanf("%d", &rec.ano);
	scanf("%d", &rec.hora);
	scanf("%d", &rec.minuto);
	scanf("%d", &rec.segundo);
	scanf("%s", frase3);
}


int main(){

	int qtd; // quantidade de atividades. entre 1 e 3

	char frase1[MAX], frase2[MAX], frase3[MAX];

	struct DATA finaliza;
	struct DATA ferias;
	struct DATA rec;

	struct HORA finaliza;
	struct HORA ferias;
	struct DATA rec;

	scanf("%d", &qtd);
	if(qtd<1 || qtd>3){
		scanf("%d", &qtd);
	}

	if(qtd==1){
		lerDados1();
	}
	else if(qtd==2){
		lerDados2();
	}
	else if(qtd==3){
		lerDados3();
	}

	
	return 0;
}