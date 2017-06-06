#include <stdio.h>

int main(){
	
	char x[100];
	
	//FILE *file = fopen
	
	fgets(x, 100, stdin);
	printf("%s", x);
	
	freopen("Arquivo 1.txt", "r", stdin);
	fgets(x, 100, stdin);
	printf("%s", x);
	
	return 0;
}
