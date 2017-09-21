// INTRODUÇÃO A ESTRUTURAS parte2
#include <stdio.h>

int main(){
	
	struct horario{
		int horas;
		int minutos;
		int segundos;
	};
	
	struct horario agora; // definir um nome para a estrutura
	agora.horas = 15;
	agora.minutos = 17;
	agora.segundos = 30;
	
	struct horario depois; // define um nome para a estrutura
	depois.horas = agora.horas +10;
	depois.minutos = agora.minutos +20;
	depois.segundos = agora.segundos-25;
	
	printf("%d / %d / %d \n", depois.horas, depois.minutos, depois.segundos);
	
	
	return 0;
}
