/*
 * Este programa resolve o seguinte problema:
 * dado um inteiro positivo N (cujo último dígito não é zero), 
 * imprime-o na ordem inversa. 
 * Ex: se N=14806 então o programa imprime 60841.
 * O numero dado N deve ter no max 9 digitos.
 *
 * Tente entender por que o programa abaixo nao funciona 
 * quando N termina por zero.
 *
 */

#include <stdio.h>

int main()
{
  int N, 
      NovoNum, /* Novo numero correspondente ao inverso de N */
      i, /* para ir contando o total de digitos de N */
      digito; /* para armazenar cada digito de N */
       
  printf("Digite um numero inteiro positivo (com no max 9 digitos): ");
  scanf("%d", &N);
  printf("\n Numero dado = %d", N);

  NovoNum = 0; /* Inicializacao do novo numero */
  i = 0;

  while (N > 0){
    digito =  N % 10; /* resto da divisao de N por 10*/
    NovoNum = NovoNum * 10 + digito;
    i = i + 1;
    printf("\n Novo numero apos obter %d digitos  = %d", i, NovoNum); 
    N = N / 10; 
  }
  
  printf("\n Numero invertido = %d\n", NovoNum);
  printf("\n O numero dado tem %d digitos\n\n", i);
  
  return 0;
}


