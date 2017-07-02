#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* STRUCT DENTRO DE STRUCT */

struct endereco{
	char rua[50];
	int numero;
};

struct pessoa{
	char nome[50];
	int idade;
	struct endereco ender;
};

int main(){

	struct pessoa p;
	p.idade = 31;
	p.ender.numero = 101;

	gets(p.nome);
	scanf("%d", &p.idade);
	gets(p.ender.rua);
	scanf("%d", &p.ender.numero);


	return 0;
}