/*Desenvolva um programa em C que abra o arquivo criado anteriormente e imprima as
informações dos carros que custem mais de R$20.000,00.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 5


typedef struct {
    char modelo[15];
    char cor[10];
    float preco;
}CARRO;


void le(FILE *arq, CARRO *vet){
    rewind(arq);
    fread(vet, sizeof(CARRO), TAM, arq);
}


void impressao(CARRO *vet){
    int i;
    for(i=0; i<TAM; i++){
        if(vet[i].preco>20000){
            printf("Carro %d\nModelo: %s\nCor: %s\nPreço: %f\n", i+1, vet[i].modelo, vet[i].cor, vet[i].preco);
        }
    }
}

int main(){

    FILE *arq;
    CARRO vetor[TAM];
    char filename[100];

    printf("Digite o nome do arquivo: \n");
    scanf("%s", filename);

    if((arq=fopen(filename, "rb"))==NULL){
        printf("\nErro na abertura do arquivo.\n");
        exit(1);
    }

    le(arq, vetor);
    impressao(vetor);

    fclose(arq);

    return 0;
}
