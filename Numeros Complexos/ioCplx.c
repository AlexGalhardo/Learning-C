#include "complexo.h"

int menu(){
	int opcao;
	printf("1-Soma complexos x e y
			\n 2- Produto complexos x e y
			\nOpcao: ");
	scanf("%d", &opcao);
	return opcao;
}

void imprimeCplx(complexo a){
	printf("%.2f+%.2f\n", a.re, a.im);
}