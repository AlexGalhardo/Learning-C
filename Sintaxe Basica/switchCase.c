// bibliotecas dizem ao compilador, as funções que vão usar
#include <stdio.h>

int main(){
	
	int i;
	
	printf("Insira um numero inteiro de 1 a 5: \n");
	scanf("%d", &i);
	
	switch(i){
		case 1:
			printf("Primeiro\n");
			break;
		case 2:
			printf("Segundo\n");
			break;
		case 3:
			printf("Terceiro\n");
			break;
		case 4:
			printf("Quarto\n");
			break;
		case 5:
			printf("Quinto\n");
			break;
		default:
			printf("Nada!");
	}
	
	return 0;
}
