#include <stdio.h>
// %p --> retorna endereço de memoria em valor hexadecimal
int main(){
	
	int vetor[3] = {1, 2, 3};
	
	/*
	Observa-se que a cada posição que pulanos no vetor, aumenta 4 bits no endereço de memória
	*/

	/*
	int *ponteiro = &vetor[0];
	printf("%d\n", ponteiro);
	
	//*ponteiro = &vetor[2];
	++ponteiro;
	printf("%d\n", ponteiro);
	
	//*ponteiro = &vetor[2];
	++ponteiro;
	printf("%d\n", ponteiro);
	*/
	
	int *ponteiro = vetor;
	
	*(ponteiro + 1) = 10; // adicionaod 1 posição(começamos no vetor[0]), definimos o vetor[0+1] como valor 10
	printf("%i\n", vetor[1]);
	
	getchar();
	return 0;
}
