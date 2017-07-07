// fonte: https://www.youtube.com/watch?v=nipW-60w9KY&index=18&list=PLa75BYTPDNKZWYypgOFEsX3H2Mg-SzuLW
#include <stdio.h>

int main(){
	
	int numero, cifra;
	
	printf("Dgite um numero inteiro: \n");
	scanf("%d", &numero);
	
	if(numero >=0){
		do{
			cifra = numero % 10;
			printf("%d", cifra);
			numero /= 10;
		}while(numero != 0);
		printf("\n");
	}
	else if(numero<1){
		numero = numero * -1;
		
		printf("-");
		
		do{
			cifra = numero %10;
			printf("%d", cifra);
			numero /= 10;
		}while(numero !=0);
		printf("-");
	}
	
	return 0;
}
