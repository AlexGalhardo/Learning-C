/*
 * Este programa le uma sequencia de n numeros inteiros,
 * para um dado n, e determina quantos deles sao pares
 * e quantos sao impares.
*/

#include <stdio.h>  
#include <stdlib.h>  

int main(){
    int
       n,                         /* total de numeros que devem ser lidos */
       par,                       /* conta os numeros pares */
       impar,                     /* conta os  numeros impares */
       cont,                      /* conta os numeros `a medida que sao lidos */
       num;                       /* cada um dos numeros que serao lidos */

    printf("Entre com o valor de n (total de inteiros a serem fornecidos): ");
    scanf("%d", &n);
  
    par = 0;
    impar = 0;
    cont = 0;
    while (cont < n) 
       {
          printf("Digite o %d o. numero: ", cont+1);
          scanf("%d", &num);
          if (num % 2 == 0) par = par + 1;
          else impar = impar + 1;
          cont = cont + 1;
        }

    printf("Foram dados  %d numero(s) par(es) e %d impar(es).\n",
           par, impar);

    return 0;
}
