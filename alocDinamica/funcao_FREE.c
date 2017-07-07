#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int *p = (int *) malloc(sizeof(int));
	
	*p = 1000;
	
	printf("%d", *p);
	
	free(p); // a função free, libera a alocação de memoria feita
	// ou seja, após usar aquela alocação de memoria e a função free é chamada
	// aquela alocação não existe mais, PORÉM, o resultado que colocamos naquela alocação
	// continua lá, como lixo de memoria
	
	return 0;
}
