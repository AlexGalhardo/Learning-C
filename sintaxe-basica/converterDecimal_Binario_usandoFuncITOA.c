// FUNÇÃO QUE CONVERTE UM NÚMERO DECIMAL EM BINÁRIO USANDO A FUNÇÃO ITOA() DA BIBLIOTECA CONIO.H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(int argc, char* argv[]){
	
 	int a;
 	
 	char b[10];
 	
	printf("Digite um numero decimal: ");
 	scanf("%d",&a);
 	
	itoa(a,b,2); //Converte para base 2
	
	printf("nO numero %d em binario e: %s",a,b);
	
	getch();
	
 	return 0;
}

// -- outra modo de se fazer, encontrado no google -- //
#include <stdio.h>
#include <stdlib.h>
  
int main() {
	
 	int numero; // Número de entrada
 	int r; // Resultado do deslocamento
 	int i; // Contador
  
	scanf("%d", &numero);
  
 	// Utiliza um número de 8 bits como base para a conversão.
 	for(i = 7; i >= 0; i--) {
    	r = numero >> i;
         
    // Por meio do "e" lógico ele compara se o valor 
    // na posição mais à direita é 1 ou 0 
    // e imprime na tela até reproduzir o número binário.
    	if(r & 1) {
        	printf("1");
    	} else {
        	printf("0");
    	}
	}
  
 	printf("\n");
  
 return 0;
}
