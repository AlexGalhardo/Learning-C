#include <stdio.h>

int main(){
	
	int x = 16;
	int y = 3;
	
	float resultado = x/y; // vai retornar resultado inteiro sem o casting
	
	float resultado2 = (float)x/y; // vai retornar resultado inteiro sem o casting

	printf("Sem casting  -->  %.2f", resultado);
	printf("\n\nCom casting  -->  %.2f", resultado2);
	
	return 0;
}
