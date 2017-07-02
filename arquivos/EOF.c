/* EOF = END OF FILE */

#include <stdio.h>
#include <stdlib.h>

int main(){

	FILE *f;
	f = fopen("arquivo.txt", "r");

	if(f == NULL){
		printf("ERRO\n");
		exit(1);
	}

	char c = fgetc(f);
	while( c!= EOF){
		printf("%c", c);
		c = fgetc(f);
	}

	printf("\nFIM\n");

	fclose(f);

	/* Porém, quando maniuplando dados binários, um valor inteiro
	igual ao valor da constante EOF pode ser lido

	Para evitar este tipo de situação, a linguagem C inclui a função feof()

	int feof(FILE *fp)

	Essa função retorna um valor inteiro igual a ZERO se ainda não tiver atingido
	o final do arquivo
	*/
	

	return 0;
}