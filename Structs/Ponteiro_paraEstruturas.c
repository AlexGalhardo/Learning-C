// fonte: https://www.youtube.com/watch?v=qvPh-QgQJmQ&list=PLa75BYTPDNKZWYypgOFEsX3H2Mg-SzuLW&index=63
// Ponteiro nas Estruturas!
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
	
	depois->hora = 40;
	depois->minutos = 60;
	depois->segundos = 50;
	
	printf("%d:%d:%d", agora.horas, agora.minutos, agora.segundos);
	
	getchar();
	
	return 0;
}
