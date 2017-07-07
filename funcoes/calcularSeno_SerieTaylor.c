/*
Seno

Utilizando uma série de Taylor , o seno de um ângulo pode ser calculado aproximação encontrada na imagem em anexo, sendo x um ângulo em radianos (no primeiro quadrante do círculo trigonométrico).

Faça um programa em C que leia o ângulo x (número real) e a quantidade de iterações que se deve fazer para encontrar o seno. Seu programa deverá ter duas funções recursivas: uma para calcular o fatorial de um número e a outra para calcular o valor do seno de x. Na saída, o resultado deverá ter 6 casas decimais
Exemplos de Entrada e Saída

Entrada:

0.785398 300

Saída:

0.707107
*/

#include <stdio.h>
#include <stdlib.h>

double fatorial(int termos)   //função que calcula fatorial(!)
{
   double aux;
   
   aux = termos;
   
   while(termos > 1){
      aux = aux * (termos - 1);
      termos--;
   }

   return (aux);
}


double power(double base, int expoente) //função potencia(x^y)
{
   double resultado;
   int i;

   resultado = 1;
   if(expoente == 0){
		return 1;
   }
   for(i = 0;i < expoente; i++){
   		resultado = resultado * base;
   }
   
   return (resultado);
}


double serie_seno(double angulo, int termos)
{
   int i;
   double resultado;
   resultado = 0;

   for(i = 0; i < termos ;i++){
      resultado += power(-1, i) * power(angulo, 2*i + 1) / fatorial(2*i + 1);
   }

   return resultado;
}

int main()
{
	double angulo;
	
	int termos;
	
	scanf("%lf %d", &angulo, &termos);
	
	double resultado = serie_seno(angulo, termos);
	
   	printf("%lf", resultado);
   	
   	return 0;
}
