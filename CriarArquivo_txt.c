#include <stdio.h>

int main(){
	
	FILE *file;
	file = fopen("teste.txt", "w"); // R -> READ // W -> WRITE
	fprintf(file, "Pao com mortadela.");
	fclose(file);
	
	return 0;
}
