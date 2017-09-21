// fonte: https://www.youtube.com/watch?v=Bi6wmPEbO3Y&index=33&list=PLa75BYTPDNKZWYypgOFEsX3H2Mg-SzuLW
// FORMATAÇÃO DE OUTPUT

#include <stdio.h>

int main(){
	
	int intVar = 99999;
	int intVar2 = 10;
	double doubleVar = 100.14159;
	
	// formatação variaveis inteiras
	printf("Variavel inteira (%%d) = %d\n", intVar); // mesma coisa que o %i
	printf("Variavel inteira (%%i) = %i\n", intVar); // usado para mostrar o numero original como inteiro
	printf("Variavel inteira (%%x) = %x\n", intVar); // NA BASE X, converte o numero na base HEXADECIMAL
	printf("Variavel inteira (%%o) = %o\n", intVar); // NA BASE O, converte o numero na base octonal
	printf("\n");
	
	
	// formatacao variaveis float double
	printf("Variavel double (%%f) = %.2f\n", doubleVar);
	printf("Variavel double (%%e) = %e\n", doubleVar); // notacao cientifica
	printf("Variavel double (%%g) = %g\n", doubleVar); // precisao decente menor
	printf("Variavel double (%%g) = %a\n", doubleVar); // notacao cientifica usando virgula
	printf("\n");
	
	return 0;
}
