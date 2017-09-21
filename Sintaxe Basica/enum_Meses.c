#include <stdio.h>
#include <stdlib.h>

enum meses{jan=1, fev, mar, abr, mai, jun, jul, ago, set, out, nov, dez};


int main(){
	
	enum meses mes;
	//int mes;
	
	printf("Digite o numero do mes: ");
	scanf("%d", &mes);
	
	exibeMeses(mes);
	printf("\n\n");
	exibeMeses(mes+1);
	
	return 0;
}

void exibeMeses(enum meses m){
	if((m>=jan) && (m<=dez)){
		switch(m){
			case jan:
				printf("%d - Janeiro", m);
			break;
			case fev:
				printf("%d - Fevereiro", m);
			break;
			case mar:
				printf("%d - Março", m);
			break;
			case abr:
				printf("%d - Abril", m);
			break;
			case mai:
				printf("%d - Maio", m);
			break;
			case jun:
				printf("%d - Jun", m);
			break;
			case jul:
				printf("%d - Julho", m);
			break;
			case ago:
				printf("%d - Agosto", m);
			break;
			case set:
				printf("%d - Setembro", m);
			break;
			case out:
				printf("%d - Outubro", m);
			break;
			case nov:
				printf("%d - Novembro", m);
			break;
			case dez:
				printf("%d - Dezembro", m);
			break;
		}
	}
	else{
		printf("Numero invalido!");
	}
	return 0;	
}
