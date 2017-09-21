#include <stdio.h>
#include <stdlib.h>

// sempre tentar deixar as variaveis define com letra MAIUSCULA
#define PI 3.14
#define DOIS_PI 2*PI
#define AREA_CIRCULO(raio) raio * raio * PI // --> MACRO

int main(){
	
	printf("%.2f\n", PI);
	printf("%.2f\n", DOIS_PI);
	printf("%.2f\n", AREA_CIRCULO(10));
	
	getchar();
	return 0;
}
