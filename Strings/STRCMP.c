/*
strcmp

Sintaxe:

variável do tipo inteiro = strcmp(string1, string2);

Compara o conteúdo de duas strings;

Possíveis valores de retorno:

0: conteúdo das strings são iguais

< 0: conteúdo da string1 é menor do que string2

> 0: conteúdo da string1 é maior do que string2

*/
#include <stdio.h>
#include <string.h>//necessário para strcmp
#include <conio.h>
int main (void)
{
  char str1[3] = "abc";
  char str2[3] = "abd";
  int retorno;
 
  retorno = strcmp(str1, str2);
  printf("retorno = %d\n", retorno);
  //mostra o retorno da função strcmp
 
  getch();
  return 0;
}
