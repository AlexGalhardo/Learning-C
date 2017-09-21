// ESCREVER UM CÓDIGO QUE IMPRIMA OS ALGARISMOS EM ASCI EM ORDEM CRESCENTE 

#include <stdio.h>

int main(){
	int i, j, n;
	scanf("%d", &n);
	
	for(i=0;i<=n; i++){
		for(j=0; j<=0; j++){
			putchar('a' + i-1);
		}
		putchar('\n');
	}
	
	return 0;
}
