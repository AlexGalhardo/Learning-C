/*
 * Sabe-se que um número da forma n^3 (n ao cubo) é igual `a  soma de n ímpares
 * consecutivos.
 * Exemplo: 1^3= 1, 2^3= 3+5, 3^3= 7+9+11,  4^3= 13+15+17+19,...
 * Dado m, determine os ímpares consecutivos cuja soma é igual a n^3,
 * para n assumindo valores de 1 a m
 */

#include <stdio.h>

int main() {
  int n, m, i, inicio, soma;

  printf("Digite o valor de m: ");
  scanf("%d", &m);

  for (n = 1; n <= m; n++) {
    /* Trecho para procurar o inicio (primeiro impar) de uma sequencia */
    /* de n impares consecutivos cuja soma e ' igual a n ^3            */ 
    soma = 0;
    for (inicio = 1; soma != n * n * n; inicio = inicio + 2) {
      soma = 0;
      for (i = 0; i < n; i++)
	soma = soma + (inicio + 2*i);  /* a partir de "inicio" vamos considerando os n-1 impares consecutivos */
                                       /* somando inicio + 2 ,  inicio + 4,  inicio + 6, etc...  */
      /* Em "soma" temos a soma dos n impares  a partir de "inicio" */                                          
      /* Precisamos testar se tal "soma" e ´ igual a n ao cubo ---  */    
      /* isto e´ testado no "for" mais externo                      */
    }
    inicio = inicio - 2;

  /** aqui sabemos que "inicio" e ´ o primeiro impar da sequencia procurada **/ 

    printf("%d*%d*%d = %d", n, n, n, inicio);
    for (i = 1; i < n; i++)
      printf("+ %d", inicio + 2*i);
    printf("\n");    
  }

  return 0;
}
