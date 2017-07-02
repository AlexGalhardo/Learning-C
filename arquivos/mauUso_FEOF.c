#include <stdlib.h>


int main(){

	/* Um mau uso muito comum da função "feof()"
	é usar a função para terminar um loop. */

	// ERRADO
	while(!feof(F)){
		fscanf(F, "%d", &n);
		printf("%d\n", n);
	} /* Nesse caso, o ultimo resultado vai ser imprimido 2x */

	fclose(F);

	// CORRETO

	int i, n;

	FILE *F = fopen("teste.txt", "r");

	if(F == NULL){
		printf("ERRO de abertura\n");
		exit(1);
	}

	while(1){
		fscanf(F, "%d", &n); // leia um dado no arquivo F e armazene na variavel n
		if(feof(F)){ // se chegou no final do arquivo, pare loop
			break;
		}
		printf("%d\n", n);
	}
	fclose(F);	

	return 0;
}