// ordenar numeros de caracteres de acordo com 2 entradas e apresentar seus respectivos caracteres na tabela ASCI

#include <stdio.h>

int main(){
	int i,nmin, nmax, tmp;
	
	do{
		printf("Digite um numero entre 0 e 255: \n");
		scanf("%d", &nmin);
	}while(nmin<0 || nmin > 255);
	
	do{
		printf("Digite outro numero entre 0 e 255: \n");
		scanf("%d", &nmax);
	}while(nmax<0 || nmax > 255);
	
	
	if(nmin>nmax){
		tmp = nmin;
		nmin = nmax;
		nmax= tmp;
	}
	
	for(i=nmin; i<=nmax;i++){
		printf("%3d --> %c\n", i, (char) i);
	}
	
	return 0;
}
