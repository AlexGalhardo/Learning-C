#include "complexo.h"

int main(){

	int op;
	srand(time(NULL));
	
	op = menu();

	complexo x,y,z;

	x=iniciaCplx();
	y=iniciaCplx();

	imprimeCplx(x);
	imprimeCplx(y);

	switch(op){
		case 1:
			z=somaCplx(x,y);
			printf("x+y =");
			imprimeCplx(z);
			break;
		case 2:
			produtoCplx(&z, &x, &y);
			printf("x*y=");
			imprimeCplx(z);
			break;
		default: printf("\nERRO: Opcao invalida");
	}

	return 0;
}