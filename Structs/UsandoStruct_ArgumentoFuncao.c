// fonte: https://www.youtube.com/watch?v=9ycgQb8dGUg&list=PLa75BYTPDNKZWYypgOFEsX3H2Mg-SzuLW&index=42
// RECEBER ESTRUTURAS A UMA FUNÇÃO
#include <stdio.h>

struct horario{
		int horas;
		int minutos;
		int segundos;
	};

int main(){
	
	struct horario teste(struct horario x);
	
	struct horario agora;
	agora.horas = 10;
	agora.minutos = 42;
	agora.segundos = 58;
	
	struct horario proxima;
	proxima = teste(proxima);
	
	printf("%d / %d / %d \n", proxima.horas, proxima.minutos, proxima.segundos);
	
	return 0;
}

struct horario teste(struct horario x){	
	x.horas = 100;
	x.minutos = 100;
	x.segundos = 100;
	return x;
}
