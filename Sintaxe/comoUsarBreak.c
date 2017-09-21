// COMO USAR BREAK
#include <stdio.h>

int main(){
	
	int i;
	// verificar os numeros entre 1 e 20 que são divisiveis por 3 e 9 ao mesmo tempo!
	for(i=1; i<=100; i++){
		if(i%3 == 0 && i%9==0){
			printf("O numero %d EH divisivel por 3 e 9!\n\n", i);
			break; // vai parar quando encontrar o primeiro numero divisel por 9!
		}else{
			printf("O numero %d NAO eh divisivel por 3 e 9!\n\n", i);
		}
	}
	
	getchar();
	
	return 0;
}
