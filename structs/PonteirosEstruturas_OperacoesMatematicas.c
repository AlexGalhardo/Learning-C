// fonte : https://www.youtube.com/watch?v=pQYP-kgLf3k&list=PLa75BYTPDNKZWYypgOFEsX3H2Mg-SzuLW&index=64
// Ponteiro nas Estruturas, operações matematicas!
#include <stdio.h>

int main(){
	
	struct horario{
		int horas;
		int minutos;
		int segundos;
	};
	
	struct horario agora, *depois;
	depois = &agora;
	
	/*
	(*depois).horas= 20;
	(*depois).minutos = 30;
	(*depois).segundos = 40;
	*/
	
	depois->horas = 40;
	depois->minutos = 60;
	depois->segundos = 50;
	
	int somatorio = 100;
	
	struct horario antes;
	antes.horas = somatorio + depois->horas;
	antes.minutos = somatorio + depois->minutos;
	antes.segundos = somatorio + depois->segundos;
	
	printf("%d:%d:%d", antes.horas, antes.minutos, antes.segundos);
	
	getchar();
	
	return 0;
}
