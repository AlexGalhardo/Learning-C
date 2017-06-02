// fonte : https://www.youtube.com/watch?v=hP6aSmO6nAk&index=20&list=PLa75BYTPDNKZWYypgOFEsX3H2Mg-SzuLW
// OPERADOR CONDICIONAL ? : 
#include <stdio.h>

int main(){
	
	int num1 = 100;
	int num2 = 20;
	
	int resposta;
	
	num1 < num2 ? printf("sim\n") : printf("nao\n");
	
	num1 < num2 ? resposta = 10 : resposta = -10;
	
	printf("%d\n", resposta);
	
	// REVISÃO TIPOS DE DADOS
	bool variavelBool = true; // 0 ou 1
	printf("%i\n", variavelBool);
	
	char caracter = 'a';
	printf("%c\n", caracter);
	
	float variavelFloat = 10.1;
	printf("%f\n", variavelFloat);
	
	double variavelDouble = 10.10; // tem uma precisao maior do que a FLOAT --> DOUBLE > FLOAT
	printf("%lf\n", variavelDouble);
	
	long int intao = 1561654987;
	printf("%d\n", intao);
	
	const int constante = 4164987; // variavel que seu valor não pode ser mudado
	printf("%d\n", constante);
	
	return 0;
}
