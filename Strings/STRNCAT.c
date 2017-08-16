/*
strncat

Sintaxe:

strncat(string_destino, string_origem, tamanho);

Realiza a concatenação do conteúdo de uma variável a outra,
porém, deve ser especificado o tamanho a ser concatenado.
Ambas devem ser strings.

*/

#include <stdio.h>
#include <string.h>//necessário para strncat
#include <conio.h>
int main (void)
{
   char str1[20] = "Curso";
   char str2[17] = " de programacao C";
 
   strncat(str1, str2, 15);
   //concatena a string1 com 15 posições da string2
 
   printf("str1 = %s\n", str1);
   //Será exibido Curso de Programação
 
   getch();
   return 0;
}
