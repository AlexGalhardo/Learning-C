// FUNÇÃO sizeof() --> nos dá quantos bytes a variavel ocupa na memoria
#include <stdio.h>
#include <stdlib.h>

struct x{
	int a;
	int b;
	int c;
};

int main(){
	
	int x; // 4 bytes na memoria ram 
	double y; // 8 bytes na memoria ram
	
	int vetor[10];
	
	struct x estrutura;
	
	printf("%li", sizeof(x)); // -> vai retornar 4
	printf("%li", sizeof(y)); // --> vai retornar 8
	printf("%li", sizeof(short)); // -> vai retornar 2
	printf("%li", sizeof(estrutura)); // -> vai retornar 12, porque temos 3 inteiros dentro da nossa estrutura	
	
	return 0;
}
