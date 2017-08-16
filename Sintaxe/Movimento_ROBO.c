/*
Movimento de um robô

Você está programando a movimentação do novo robô que projetou e, no momento, está tentando fazer com que ele compreenda corretamente os comandos de "vire à direita" e "vire à esquerda". Para testá-lo, você irá fornecer à ele uma string contendo, no máximo, 200 comandos que poderão alternar entre 'D' (direita) e 'E' (esquerda), como mostram os exemplos abaixo:
Exemplos de Entrada

Entrada 1:

DDDDEEEEEDDEEE

Entrada 2:

DDDEEDEDEEEEEDEDDDEDDEDEDEDEDEDEEEDDDDDEDEEEEEEED

O robô estará inicialmente com a sua face voltada para o norte. Quando um comando 'D' for dado a ele, o robô virará para direita e ficará, então, com a face voltada para o leste. Caso mais um comando seja lido, ele virará novamente para direita, ficando, desta vez, com a face voltada para o sul. Assim, se um comando 'E' for lido, o robô virará na direção contrária e voltará sua face novamente para leste.
Seu programa deve ser capaz de informar para qual direção a face do robô deverá apontar após uma sequência de comandos (como as mostradas nos exemplos acima) e exibir, na saída padrão, qual é essa direção seguida por uma quebra de linha (\n). Tal como no exemplo abaixo:
Exemplos de saída

Saida 1:

Sul

Saida 2:

Leste

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX 200

int main(){
	char vet[MAX];
	int i, pos = 4, resto =0;
	scanf("%s", vet);
	
	for(i=0; i<strlen(vet); i++){
		if(vet[i]== 'D'){
			pos++;
		}
		if(vet[i] == 'E'){
			pos--;
		}
	}
	
	resto = abs(pos)%4;
	
	switch(resto){
		case 0:
			printf("Norte\n");
			break;
		case 1:
			if(pos<0){
				printf("Oeste\n");
			}
			else{
				printf("Leste\n");
			}
			break;
		
		case 2:
			if(pos<0){
				printf("Norte\n");
			}
			else{
				printf("Sul\n");
			}
			break;
		
		case 3:
			if(pos<0){
				printf("Leste\n");
			}
			else{
				printf("Oeste\n");
			}
			break;
	}
	
	return 0;
}
