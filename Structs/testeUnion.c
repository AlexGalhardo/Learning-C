#include <stdio.h>
#include <stdlib.h>

union real_ou_inteiro{
	double r;
	int i;
};

	
int main(){

		union real_ou_inteiro num;

		num.r = 2.5;

		printf("\nA) r = %.2f i = %d", num.r, num.i);
		num.i = 1000;

		printf("\nB) r=%.2f i=%d", num.r, num.i);
		num.r = -34.25;

		printf("\nC r=%.2f i=%d", num.r, num.i);
		num.i = -1;

		printf("\nD) r=%.2f i=%d", num.r, num.i);


		printf("\n\n");
		return 0;
}