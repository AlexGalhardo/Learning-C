// fonte: https://www.youtube.com/watch?v=ahMgR8FoH-w&list=PLa75BYTPDNKZWYypgOFEsX3H2Mg-SzuLW&index=53
//Obter String do usuário
#include <stdio.h>

int main(){
	
	char linha[100];
	char caractere;
	int i =0;
	
	do{
		caractere = getchar();
		linha[i] = caractere;
		i++;
	}while(caractere != '\n');
	
	linha[i-1] = '\0';
	
	printf("%s\n", linha);
	
	/*
	char nome[20];
	char sobrenome[20];
	
	printf("Insira seu nome e sobrenome: \n");
	scanf("%s %s", &nome, &sobrenome);
	
	printf("%s %s", nome, sobrenome);
	*/
	
	
	return 0;
}
