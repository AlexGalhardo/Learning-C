#include <stdio.h>
#include <stdlib.h>
// a -> alterar arquivo
// r -> ler arquivo
// w -> write arquivo
int main(){
	
	FILE *file;
	file = fopen("numeros.txt", "r"); // a -> alterar arquivo
	
	if(file == NULL){
		printf("Arquivo nao pode ser aberto!");
		return 0;
	}
	
	int x, y, z;
	
	fscanf(file, "%d %d %d", &x, &y, &z);
	
	printf("%d %d %d\n", x, y, z);
	
	fclose(file);
	
	return 0;
}
