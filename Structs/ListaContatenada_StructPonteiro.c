#include <stdio.h>

int main(){
	
	struct lista{
		int valor;
		struct lista *proximo;
	};
	
	struct lista m1, m2, m3;
	struct lista *gancho = &m1;
	
	m1.valor = 10;
	m1.valor = 20;
	m3.valor = 30;
	
	m1.proximo = &m2;
	m2.proximo = &m3;
	m3.proximo = (struct lista *)0;
	
	while(gancho != (struct lista *)0){
		printf("%d\n", gancho->valor);
		gancho = gancho->proximo;
	}
	
	getchar();
	return 0;
}
