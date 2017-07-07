
/* 
 * arquivo: acha_n.c
 * -----------------
 * Este programa determina o menor inteiro n tal que 
 * a soma 1 + ... + n seja maior que 1000.
 */

#include <stdio.h>

int main()
{
  int n, soma;

  soma = 0; 
  n = 0;

  while (soma <= 1000) {
    n = n + 1;
    soma = soma + n;
    printf("a soma de 1 ate' %d e' %d  \n", n, soma);
  }

  printf("o menor inteiro n tal que  1 + ...+ n > 1000 e' %d\n", n);	
  return 0;
}
