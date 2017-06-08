/*
Sequência de Padovan
A sequência de Padovan é uma sequência de números naturais que formam lados de triângulos equiláteros em espiral, como na imagem em anexo. A sequência P(n) é definida pelos valores iniciais:

P(0) = P(1) = p(2) = 1
e pela a seguinte relação recursiva:

P(n) = P(n - 2) + P(n - 3) se n > 2
Alguns valores da sequência são: 1, 1, 1, 2, 2, 3, 4, 5, 7, 9, 12, 16, 21, 28...

Faça um programa com uma função recursiva que receba um número N e retorne o N-ésimo termo da sequência de Padovan.

Obs: Observe que o N-ésimo termo de P é P(N-1).

Exemplos de Entrada e Saída
Entrada:

6
Saída:

3
Entrada:

14
Saída:

28
*/

#include <stdio.h>
#include <stdlib.h>

int pad(int *vet, int n, int cont){
    if (cont == 0 && n <= 3){
        return 1;
    }
    else{
        if (cont <= 2){
            *(vet + cont) = 1;
            return pad(vet, n, cont + 1);
        }
        else{
            *(vet + cont) = *(vet + cont - 2) + *(vet + cont - 3);
            if (cont != n - 1){
                return pad(vet, n, cont + 1);
            }
            else{
                return *(vet + cont);
            }
        }
    }
}

int main()
{
    int n, num, cont = 0;
    int *vet;
    scanf("%d", &n);
    vet = (int *)malloc(n * sizeof(int));
    num = pad(vet, n, cont);
    printf("%d", num);
    return 0;
}
