/*
Desenvolva um programa que primeiro utilize uma fun¸c˜ao para gerar um vetor
com tamanho definido pelo usu´ario e valores aleat´orios dentro de um intervalo [min, max]
determinado pelo usu´ario. Em seguida, uma outra fun¸c˜ao deve receber o vetor gerado, o
tamanho do vetor e dois n´umeros maior e menor. Retorne nas vari´aveis maior e menor
o menor e maior elemento do vetor. Dica1: menor e maior devem ser passados por
referˆencia. Dica2: use apenas uma estrutura de repeti¸c˜ao para achar o menor e maior
elemento
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define MAX 100

// -- FUNÇÃO PARA FAZER PREENCHER VETOR --
void preencherVetor(int *vetor, int tamanho, int min, int max){
    int i;

    srand(time(NULL));
    for(i=0; i<tamanho; i++){
        vetor[i] = min + (rand() % (max-min+1));
    }
}

void encontrarMaiorMenor(int *vetor, int tamanho, int *menor, int *maior){
    int i;

    for(i=0;i<tamanho; i++){
        if(vetor[i]< *menor){
            *menor = vetor[i];
        }
        if(vetor[i] > *maior){
            *maior = vetor[i];
        }
    }
}

void imprimirVetor(int *vetor, int tamanho){
    int i;
    for(i=0; i<tamanho; i++){
        printf("[%d] ", vetor[i]);
    }
}

int main(int argc, char *argv[]){
    int tamanho, maior, menor;
    int min, max, vetor[MAX];

    printf("Digite o tamanho do seu vetor: \n");
    scanf("%d", &tamanho);
    
    printf("Digite o intervalo de valores no vetor: \n");
    scanf("%d %d", &min, &max);
    
    preencherVetor(vetor, tamanho, min, max);
    
    maior = min;
    menor = max;
    
    encontrarMaiorMenor(vetor, tamanho, &menor, &maior);
    
    imprimirVetor(vetor, tamanho);
    
    printf("\n\n\nMaior = %d\n\nMenor = %d\n", maior, menor);

    return 0;
}
