#include <stdio.h>
#include <stdlib.h>

// definindo uma enumeração

enum semana{Domingo, Segunda, Terça, Quarta, Quinta, Sexta, Sabado};

int main(){

	/* Uma enumeração pode ser vista como uma lista de 
	constantes, onde cada constante possui um nome significativo
	*/
	// declaração de uma variável enum

	enum semana s;
	// atribuindo um valor a variável
	s = Segunda; // 1
	printf("Valor = %d\n", s);


	// EXEMPLO 1
	enum semana s1, s2, s3;
	s1 = Segunda; // 1
	s2 = Terca; //2
	s3 = s1+s2;// 1+2

	printf("Domingo = %d\n", Domingo); //0
	printf("s1 == %d\n", s1);
	printf("s2 == %d\n", s2);
	printf("s3 == %d\n", s3);

	if(s3 == Quarta){
		printf("s3 igual a Quarta\n");
	}



	//EXEMPLO 2
	enum semana2 = {Domingo=1, Segunda, Terca, Quarta=7, Quinta, Sexta, Sabado};

	printf("Domingo = %d\n", Domingo); // 1
	printf("Segunda = %d\n", Segunda); // 2
	printf("Quarta = %d\n", Quarta); // 7

	return 0;
}