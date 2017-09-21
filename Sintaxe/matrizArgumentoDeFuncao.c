// fonte : https://www.youtube.com/watch?v=t3wDtXpu8ig&index=37&list=PLa75BYTPDNKZWYypgOFEsX3H2Mg-SzuLW
// funções que recebem matrizes como argumento
#include <stdio.h>

int main(){
	
	void funcaoPrint(int x[3][3]);
	
	int matriz[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	
	int i, j;
	
	funcaoPrint(matriz); // quando eu chamar uma função de matriz, eu não preciso especificar as dimensões dela, apenas o nome!
	
	return 0;
}

void funcaoPrint(int x[3][3]){
	
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			printf("%d", matriz[i][j]);
		}
		printf("\n");
	}
}
