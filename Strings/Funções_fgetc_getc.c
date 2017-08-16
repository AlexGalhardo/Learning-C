// Funções fgetc e getc
/* ---------- PARTE 1 -------- */
// usando função para imprimir o que o usuario digitar no teclado

#include <stdio.h>

int main(){
	
	char x[100];
	
	int i = 0;
	
	while((x[i] = fgetc(stdin))!= '\n'){
		i++;
	}
	x[++i] = '\0';
	
	printf("%s", x);
	
	return 0;
}


/* ---------- PARTE 2 -------- */
// usando função para imprimir o que esta escrito dentro de um arquivo.txt

// Funções fgetc e getc

#include <stdio.h>

int main(){
	
	char x[100];
	
	FILE *file = fopen("Arquivo 1.txt", "r");
	
	int i = 0;
	
	while((x[i] = fgetc(file))!= EOF){ // EOF -> END OF FILE
		i++;
	}
	x[i] = '\0';
	
	printf("%s", x);
	
	return 0;
}
