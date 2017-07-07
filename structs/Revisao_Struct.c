//fonte: https://www.youtube.com/watch?v=jsMxEWCGpmk&list=PLa75BYTPDNKZWYypgOFEsX3H2Mg-SzuLW&index=45
// REVISÃO STRUCTS
#include <stdio.h>

struct horario{
	int hora;
	int minuto;
	int segundo;
};

int main(){
	
	void receberHorarios(struct horario lista[5]);
	void printHorarios(struct horario lista[5]);
	struct horario listaHorarios[5];
	
	receberHorarios(listaHorarios);
	printHorarios(listaHorarios);
	
	return 0;
}

void receberHorarios(struct horario lista[5]){
	int i;
	
	for(i=0; i<5; i++){
		printf("Digite o %d horario(HH:mm:ss): ", i+1);
		scanf("%d:%d:%d",&lista[i].hora,&lista[i].minuto,&lista[i].segundo);
		printf("\n");
	}
}

void printHorarios(struct horario lista[5]){
	
	int i;
	for(i=0; i<5; i++){
		printf("O %d horario eh = %d:%d:%d \n", i+1,
								lista[i].hora,
								lista[i].minuto,
								lista[i].segundo);
	}
	
}
