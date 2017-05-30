// imprimir uma string de caracteres ao contrario

// importante ressaltar a função PUTCHAR() para imprimir cada caracter solto dentro do vetor

#include <stdio.h>

int main(){
	char s[100];
	char *ptr =s;
	
	printf("Introduza uma string: \n");
	scanf("%s", s);
	
	if(*ptr == '\0'){
		return; 
	}
	
	while(*ptr != '\0'){
		putchar(*ptr++);
		//imprimir string ao contrário 
	}
	
	
	ptr--; // por causa do char '\0' 
	
	printf("\n\n");
	
	while(ptr>=s){
		putchar(*ptr--);
	}
	return 0;
}


