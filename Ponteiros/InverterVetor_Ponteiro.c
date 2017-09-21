/*
Desenvolva um programa que utilize uma fun¸c˜ao para inverter os elementos de
um vetor (com valores gerados usando a fun¸c˜ao do exerc´ıcio anterior) sem utilizar um
vetor auxiliar. Apenas o vetor fornecido `a fun¸c˜ao dever´a ser utilizado.
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX 100

void preencherVetor(int *vetor, int tamanho, int min, int max){
    int i;

    srand(time(NULL));
    for(i=0; i<tamanho; i++){
        vetor[i] = min +(rand() % (max-min+1));
    }
}

int inverter(int *vetor, int tamanho){
    int i, aux;
    for(i=0; i<tamanho/2; i++){
        aux = vetor[i];
        vetor[i] = vetor[tamanho-i-1];
        vetor[tamanho-i-1]= aux;
    }
    return 0;
}

void imprimirVetor(int *vetor, int tamanho){
    int i;
    for(i=0; i<tamanho; i++){
        printf("[%d] ", vetor[i]);
    }
}

int main(int argc, char **argv){
    int tamanho, min, max, vetor[MAX];

    printf("Digite o tamanho do seu vetor: \n");
    scanf("%d", &tamanho);
    
    printf("Digite o intervalo de valores no vetor: \n");
    scanf("%d %d", &min, &max);
    
    preencherVetor(vetor, tamanho, min, max);
    
    printf("Vetor original: \n");
    imprimirVetor(vetor, tamanho);
    
    inverter(vetor, tamanho);
    
    printf("\n Vetor invertido: ");
    imprimirVetor(vetor, tamanho);
    
    return 0;
}
