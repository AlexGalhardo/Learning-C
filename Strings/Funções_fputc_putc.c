// Funções fputc e putc
#include <stdio.h>

int main(){
	
	char x[] = "coxinha";
	
	FILE *file = fopen("Arquivo 1.txt", "w");
	
	//putc('c', stdout); // -> escrever caractere no console // saida padrão
	//putc(x[0], file); // -> escrever a posição 0 do vetor x no arquivo
	
	int i=0, j=0;
	
	
	// imprimir todos os caracteres do vetor x[]
	while(x[i] != '\0'){
		putc(x[i], stdout);
		i++; 
	}
	
	// escrever todos os caracteres do vetor x[] no Arquivo 1.txt
	while(x[j] != '\0'){
		putc(x[j], file);
		j++;
	}
	
	return 0;
}
