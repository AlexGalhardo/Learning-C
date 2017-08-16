// fonte: https://www.youtube.com/watch?v=oZo3Dxs3tcg&index=43&list=PLa75BYTPDNKZWYypgOFEsX3H2Mg-SzuLW
// INICIALIZANDO ESTRUTURAS
#include <stdio.h>

int main(){
	
	struct horario{
		int horas;
		int minutos;
		int segundos;
	}agora = {.segundos=10, .minutos=20, .horas=30};
	

	printf("%d / %d/ %d \n", agora.horas, agora.minutos, agora.segundos);
	
	return 0;
}
