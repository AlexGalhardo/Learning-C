#include "complexo.h"

complexo iniciaCplx(){
	complexo a;
	a.re = Aleatorio(MIN, MAX);
	a.im = Aleatorio(MIN, MAX);
	imprimeCplx(a);
	return a;
}

complexo somaCplx(complexo a, complexo b){
	complexo c;
	c.re = a.re + b.re;
	c.im = a.im + b.im;
	return c;
}

void produtoCplx(complexo *z, complexo *a, complexo *b){
	z->re = (a->re)*(b->re) - (a->im)*(b->im);
	z->im = (b->re)*(a->im) + (a->re)*(b->im);
}