/* ---------- parte 1 ------------ */
#include <stdio.h>

int main(){
	char x[100];
	
	// stdin = standard input => entrada padrão => no caso do PC, geralmente é o teclado
	
	fgets(x, 100, stdin);
	printf("%s", x);
	
	freopen("Arquivo 1.txt", "r", stdin);
	fgets(x, 100, stdin);
	printf("%s", x);
	
	return 0;
}

/* ---------- parte 2 ------------ */

#include <stdio.h>

int main(){
	
	char x[100];
	
	FILE *file = fopen("Arquivo 1.txt", "r");
	
	fgets(x, 100, file);
	printf("%s\n", x);
	
	freopen("Arquivo 2.txt", "r", file);
	fgets(x, 100, file);
	printf("%s\n", x);
	
	return 0;
}
