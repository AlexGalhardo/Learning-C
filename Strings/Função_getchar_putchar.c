#include <stdio.h>

int main(){
	
	//char x[10];
	
	//x[0] = getchar();
	/*
	int i = 0;
	
	while((x[i] = getchar()) != '\n' && i<8){
		i++;
	}
	x[i++] = '\0';
	
	printf("%s", x);
	*/
	int j = 0;
	char y;
	
	while((y=getchar()) != '\n'){
		putchar(y);
	}
	
	return 0;
}
