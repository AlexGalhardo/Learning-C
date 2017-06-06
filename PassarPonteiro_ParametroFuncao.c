#include <stdio.h>
#include <stdlib.h>

int main(){
	
	void testeVariavel(int x);
	void testePonteiro(int *pX);
	int teste = 1;
	int *pTeste = &teste;
	
	//testeVariavel(teste);
	testePonteiro(pTeste);
	
	printf("%d\n", teste);
	
	getchar();
	
	return 0;
}

void testeVariavel(int x){
	++x;
	printf("%d\n", x);
}

void testePonteiro(int *pX){
	++*pX;
}
