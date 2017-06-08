// FUNÇÃO QUE CONVERTE UM NÚMERO DECIMAL EM BINÁRIO USANDO A FUNÇÃO ITOA() DA BIBLIOTECA CONIO.H

#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

int main(int argc, char* argv[]){
	
 	int a;
 	
 	char b[10];
 	
	printf("Digite um numero decimal: ");
 	scanf("%d",&a);
 	
	itoa(a,b,2); //Converte para base 2
	
	printf("nO numero %d em binario e: %s",a,b);
	
	getch();
	
 	return 0;
}
