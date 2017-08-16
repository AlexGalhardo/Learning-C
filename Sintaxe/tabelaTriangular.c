/* 
 * arquivo: tabela_triang.c
 * ------------------------
 * Este programa imprime uma tabela triangular como a sguinte:
 *   0 
 *   0  1 
 *   0  1  2 
 *   0  1  2  3 
 *   0  1  2  3  4 
 *   0  1  2  3  4  5 
 *   0  1  2  3  4  5  6 
 *   0  1  2  3  4  5  6  7 
 *   0  1  2  3  4  5  6  7  8 
 *   0  1  2  3  4  5  6  7  8  9 
 *   0  1  2  3  4  5  6  7  8  9 10 
 */

#include <stdio.h>

int main()
{
    int i, j;

    printf("Tabela triangular\n");

    for (i = 0; i <= 10; i++) {
	for (j = 0; j <= i; j++)
	    printf("%2d ", j);
	printf("\n");
    }
    return 0;
}
