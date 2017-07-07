#include <stdio.h>
#include <stdlib.h>

// (int *) malloc(sizeof(int)); --> é uma função que vai dizer para a memoria ram do computador, para alocar o tamanho de memoria desejado na variavel.
// nesse exemplo, temos uma função que pede a memoria ram para alocar o tamanho da variavel int, que no caso são 4 bytes
// importante dar o cast no inicio do malloc, porque ele vai retornar uma função void, por isso usamos o (int *)

int main(){
	
	int *p = (int *) malloc(sizeof(int)); // vai alocar 4 bytes na memoria ram do computador
	
	if(p == NULL){
		printf("Malloc não conseguiu alocar memoria na memoria ram!!!");
	}
	
	*p = 1000; // -> se não definirmos um valor para a memoria alocada, quando printarmos seu conteudo, ele vai retornar o lixo que tinha nesse memoria
	
	printf("%d", *p);
	
	return 0;
}
