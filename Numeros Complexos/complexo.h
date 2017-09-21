#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN -1000
#define MAX 1000
#define precisao 100.0
#define Aleatorio(MIN, MAX) ( (MIN+rand()%(MAX-MIN+1) )/precisao)

typedef struct{
	float re;
	float im;
} complexo;

int menu();
complexo iniciaCplx();
void imprimeCplx(complexo);
complexo somaCplx(complexo, complexo);
void produtoCplx(complexo *, complexo*, complexo *);