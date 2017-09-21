#include <stdio.h>
#include <stdlib.h>

int main(){
	
	enum dia {dom, seg, ter, qua, qui, sex, sab};
	enum mes {jan=1, fev, mar, abr, mai, jun, jul, ago, set, out, nov, dez};
	enum fruta {pera=8, maca, uva=4, banana};
	
	enum dia diaSemana;
	enum mes mesAtual;
	enum fruta f1;
	enum {cenoura=2, beterraba, batata} veg1, veg2;
	enum fruta f2;
	
	for(diaSemana=dom; diaSemana <= sab; diaSemana++){
		printf("%d  ", diaSemana);
	}
	printf("\n\n\n");
	
	for(mesAtual=jan; mesAtual<=dez; mesAtual++){
		printf("%d  ", mesAtual);
	}
	printf("\n\n\n");
	
	f1=pera; f2=uva;
	printf("%d  %d  %d  %d\n\n\n", f1, f1+1, f2, f2+1);
	
	veg2=batata;
	for(veg1=cenoura; veg1 <=veg2; veg1++){
		printf("%d  ", veg1);
	}
	
	return 0;
}
