#include <stdio.h>

#define MAIOR(x,y) x > y ? x : y
#define E_MINUSCULO(char) char >='a' && char <='z'

int main(){
	
	char x = 'G';
	
	if(E_MINUSCULO(x)){
		printf("SIM");
	}else{
		printf("NAO");
	}
	
	printf("\n\n%d", MAIOR(100, 50));
	
	return 0;
}
