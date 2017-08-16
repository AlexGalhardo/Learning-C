// fonte: https://www.youtube.com/watch?v=r_4gWu3AYwE&index=44&list=PLa75BYTPDNKZWYypgOFEsX3H2Mg-SzuLW
// Vetores de Estruturas
#include <stdio.h>
int main(){
	
	struct horario{
		int horas;
		int minutos;
		int segundos;
	};
	
	struct horario teste[5] = {{10, 20, 30}, 
								{40, 50, 60}, 
								{70, 80, 90}, 
								{100, 110, 120}, 
								{130, 140, 150}};
	/*
	teste[0].horas =10;
	teste[0].minutos = 20;
	teste[0].segundos = 30;
	*/
	int i;
	
	for(i=0; i<5; i++){
		printf("%d/%d/%d\n", teste[i].horas, teste[i].minutos, teste[i].segundos);
	}
	
	//printf("%d/%d/%d\n", teste[0].horas, teste[0].minutos, teste[0].segundos);	
	
	return 0;
}
