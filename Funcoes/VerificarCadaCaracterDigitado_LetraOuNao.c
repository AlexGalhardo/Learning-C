// VERIFICAR CARACTERES ALFABETICOS
#include <stdio.h>

int main(){
	
	void alfabetico(char variavel);
	
	char nome[20];
	printf("Digite uma palavra: ");
	scanf("%s", nome);
	
	int i=0;
	while(nome[i] != '\0'){
		alfabetico(nome[i]);
		i++;
	}
	
	
	return 0;
}

void alfabetico(char variavel){
	
	if((variavel >= 'a' && variavel <= 'z') || (variavel >= 'A' && variavel <= 'Z')){
		printf("EH uma letra\n");
	}else{
		printf("NAO eh uma letra!\n");
	}
}
