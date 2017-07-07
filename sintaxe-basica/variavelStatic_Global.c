// TIPOS DE VARIAVEIS
#include <stdio.h>

//VARIAVEL GLOBAL
int variavelGlobal = 2;

int main(){
	
	void teste(void);
	
	printf("Variavel Global:  %d\n\n\n", variavelGlobal);
	teste();
	teste();
	teste();
	
	return 0;
}

void teste(void){
	int variavelLocal = 2;
	variavelLocal *=2;
	
	// variavel que a cada vez que eu chamo a função, a variavel muda!
	static int variEstatica =2;
	variEstatica*=2;
	
	// variavel global se comporta como uma variavel estatica
	variavelGlobal *=2;
	
	printf("Variavel Local: %d\n", variavelLocal);
	printf("Variavel Estatica: %d\n", variEstatica);
	printf("Variavel Global: %d\n", variavelGlobal);
}
