/*
CALCULAR IMC DE UMA PESSOA

1 - digitar qntas pessoas vao ser cadastradas
2 - digitar uma ID e dizer os dados da pessoa: sexo nome imc (peso/altura^2)
3- caso  digitar -1, parar programa.
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 30

struct Pessoa{
	char nome[MAX];
	float altura;
	float peso;
	int id;
	char sexo;
	//float imc = peso / (altura * altura);
};

int main(){
	
	int qtd, i, j, op;
	scanf("%d", &qtd);

	struct Pessoa *pessoa[qtd];

	pessoa[qtd] = (struct Pessoa *) malloc(qtd * sizeof(struct Pessoa));

	for(i=0; i<qtd; i++){
		scanf("%s", pessoa[i]->nome);
		scanf("%f", &pessoa[i]->altura);
		scanf("%f", &pessoa[i]->peso);
		scanf("%d", &pessoa[i]->id);
		scanf("%c", &pessoa[i]->sexo);
	}

	do{
		scanf("%d", &op);
		for(j=0; j<qtd; j++){
			if(pessoa[j]->id == op){
				printf(" %c\t%s\t%1.2lf\n", pessoa[j]->sexo, pessoa[j]->nome, pessoa[j]->peso / (pessoa[j]->altura * pessoa[j]->altura));	
			}
		}
	}while(op != -1);

	return 0;
}