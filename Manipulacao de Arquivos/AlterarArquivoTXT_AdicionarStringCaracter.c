#include <stdio.h>
#include <stdlib.h>

int main(){
	
	FILE *file;
	file = fopen("string.txt", "a");
	
	if(file==NULL){
		printf("Arquivo nao pode ser aberto.\n");
		getchar();
		exit(1);
	}
	
	fprintf(file, "\nPrimeira linha\n");
	
	char frase[] = "\nSegunda linha";
	fputs(frase, file);
	
	char caractere = '3';
	fputc(caractere, file);
	
	fclose(file);
	
	return 0;
}
