// pegar valores de i de 0 a 255 na tabela ASCI e imprimir seu respectivo caracter na tela!

#include <stdio.h>

int main(){
	
	int i, conta;
	char ch;
	
	for(i=0, conta=20; i<=255; i++){
		printf("%3d --> %c\n", i, (char) i);
		if(conta==20){
			do{
				printf("Pressione c ou C para continuar...");
				scanf(" %c", &ch);
			}while(ch != 'c' && ch != 'C');
			conta=1;
		}
	}
	
	return 0;
}
