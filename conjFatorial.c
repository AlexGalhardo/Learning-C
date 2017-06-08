/*
Conjunto de Fatorial em Intervalo
Desenvolva um programa em C que calcule o fatorial de um conjunto de números consecutivos e os retorne através do retorno de um ponteiro para inteiro (vetor de inteiros). Deverão ser lidos do teclado o primeiro número (n0) que começará a sequência do fatorial e a quantidade de números impressos (size). Qualquer vetor utilizado durante o programa deverá ser alocado dinamicamente. Sugestão desenvolva uma função com a seguinte assinatura: int* getConjuntoFatorial(int n0, int size).

Exemplos de Entrada e Saída
Entrada:

3 5
Saída:

6 24 120 720 5040

*/

#include <stdio.h>
#include <stdlib.h>

void getConjuntoFatorial(int *vet, int n, int tam){
    
    int fat, i, j;
    
    for (j = 1; j <= tam; j++){
        fat = 1;
        for (i = n; i > 0; i--){
            fat *= i;
        }
        *(vet + j - 1) = fat;
        n++;
    }
}

int main()
{
    int n, tam, i;
    
    int *vet;
    
    scanf("%d %d", &n, &tam);
    
    vet = (int *) malloc(tam * sizeof(int));
    
    getConjuntoFatorial(vet, n, tam);

    for (i = 0; i < tam; i++){
        printf("%d ", vet[i]);
    }
    return 0;
}
