// material extra de resumo : https://www.dropbox.com/sh/z06ijjcd0rbl9vk/8Rmw4j7mTc

// Limpeza de buffer | Limpar o buffer | O que é o buffer
#include <stdio.h>

int main(){
	
	void limparBuffer(void);
	char a, b, c;
	
	a = getchar();
	//fflush(stdin);
	//setbuf(stdin, NULL);
	limparBuffer();
	b = getchar();
	//fflush(stdin);
	//setbuf(stdin, NULL);
	limparBuffer();
	c = getchar();
	//fflush(stdin);
	//setbuf(stdin, NULL);
	limparBuffer();
	
	printf("%c\n", a);
	printf("%c\n", b);
	printf("%c\n", c);
	
	return 0;
}

void limparBuffer(){
	char c;
	while((c = getchar())!= '\n' && c != EOF){
		
	}
}
