#include <stdio.h>
#include <stdlib.h>

union tipoU{
	short int x;
	unsigned char c;
};

struct tipoS{
	short int x;
	unsigned char c;
};

int main(){
	

	/* STRUCT vs UNION
	union: espaço para armazenar APENAS o maior elemento - 
	memória compartilhada
	*/

	union tipoU v;
	v.x = 5;
	v.c = 'a';

	printf("x == %d\n", v.x); // 16 bytes
	printf("c == %c\n", v.c); // 8 bytes

	/* 
	->NO CASO DO STRUCT, OCUPA 16+8 = 24 BYTES DE MEMÓRIA!
	->NO CASO DO UNION, OCUPA O MAIOR, OU SEJA, 16>8 = 16 BYTES DE MEMÓRIA!
	*/

	/* Um dos usos mais comum de união é unir
	um tipo básico a um array de tipos menores. 
	*/

	union tipoU p;
	p.x = 1545; // 00000110 00001001
	printf("x = %d\n", v.x);
	// 00000110 -> 9
	printf("c[0] = %d\n", v.c[0]);
	// 00001001 -> 6
	printf("c[1] = %d\n", v.c[1]);
	return 0;
}