#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char marca[30];
	int ano;
}carro;

typedef struct{
	char nome[10];
	float preco;
}fruta;

typedef union{
	carro c;
	fruta f;
}fruta_ou_carro;

int main(){

	fruta_ou_carro x;

	strcpy(x.c.marca, "FIAT");
	x.c.ano = 2010;
	printf("\nA) \nCarro: %s %d\nFruta: %s  %.2f", x.c.marca, x.c.ano, x.f.nome, x.f.preco);

	strcpy(x.f.nome, "BANANA");
	x.f.preco = 4.99;
	printf("\nB)\nCarro: %s %d\nFrutas: %s  %.2f", x.c.marca, x.c.ano, x.f.nome, x.f.preco);

	return 0;
}