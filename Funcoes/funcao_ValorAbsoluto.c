// fonte: https://www.youtube.com/watch?v=x17zyAd5WLM&list=PLa75BYTPDNKZWYypgOFEsX3H2Mg-SzuLW&index=34
// FUNÇÕES QUE CHAMAM OUTRAS FUNÇÕES
#include <stdio.h>

int main(){
	
	float somaDeDigitos(float num1, float num2);
	float valorAbsoluto(float x);
	float a, b, soma;
	
	printf("Digite 2 numeros: ");
	scanf("%f", &a);
	scanf("%f", &b);
	
	soma = somaDeDigitos(a, b);
	
	printf("A soma dos digitos eh: %.2f", soma);
	
	return 0;
}

float somaDeDigitos(float num1, float num2){
	
	float valorAbsoluto(float x);
	
	if(num1 < 0){
		num1 = valorAbsoluto(num1);
	}
	if(num2<0){
		num2 = valorAbsoluto(num2);
	}
	
	return num1 + num2;
}


float valorAbsoluto(float x){	
	return x * -1;
}
