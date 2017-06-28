#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 30

int main(){

	// função que conta
	char string[MAX];
	scanf("%s", string);

	int i, conta=0;
	for(i=0; string[i]!='\0'; i++){
		if(isalpha(string[i])){
			conta++;
		}
	}

	printf("A palavra %s tem %d algarismos alfabeticos!", string, conta);

	return 0;
}

