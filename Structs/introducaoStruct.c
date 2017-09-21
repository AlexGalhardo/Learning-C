// fonte: https://www.youtube.com/watch?v=P1XGznGxsag&index=39&list=PLa75BYTPDNKZWYypgOFEsX3H2Mg-SzuLW
// INTRODUÇÃO A ESTRUTURAS
#include <stdio.h>

int main(){
	
	struct horario{
		int horas;
		int minutos;
		int segundos;
	};
	
	struct horario agora;
	agora.horas = 15;
	agora.minutos = 17;
	agora.segundos = 30;
	
	printf("%d: %d: %d", agora.horas, agora.minutos, agora.segundos);
	
	int vetor[5];
	
	
	return 0;
}
