/*Desenvolva  um  programa  em  C,  em  seguida,  crie  uma  estrutura  carro  com  os  dados:
modelo, cor, pre ̧co.  Declarar um vetor com 5 elementos do tipo carro.  Armazenar esse
vetor em um arquivo de dados bin ́arios.*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 5

typedef struct {
    char modelo[15];
    char cor[10];
    float preco;
}CARRO;

void armazena(FILE *arq, CARRO *vet){
    rewind(arq);
    fwrite(vet, sizeof(CARRO), TAM, arq); // sempre definir o tipo de acordo com struct
}

void le(FILE *arq, CARRO *vet){
    rewind(arq);
    fread(vet, sizeof(CARRO), TAM, arq);
}

void leitura(CARRO *vet){

    int i;
    for(i=0; i<TAM; i++){
        printf("Carro %d\nModelo: ", i+1);
        scanf("%s", vet[i].modelo);
        printf("Cor: ");
        scanf("%s", vet[i].cor);
        printf("Preco: ");
        scanf("%f", &vet[i].preco);
        printf("\n");
    }
}

void impressao(CARRO *vet){

    int i;
    for(i=0; i<TAM; i++){
        printf("Carro %d\nModelo: %s\nCor: %s\nPreço: %f\n", i+1, vet[i].modelo, vet[i].cor, vet[i].preco);
    }
}

int main(){

    FILE *arq;
    CARRO vetor[TAM], vetor2[TAM];
    char filename[100];

    printf("Digite o nome do arquivo: \n");
    scanf("%s", filename);

    if((arq=fopen(filename, "wb+"))==NULL){
        printf("\nErro na abertura do arquivo.\n");
        exit(1);
    }

    leitura(vetor); // ler dados da struct
    armazena(arq, vetor); // armazenar vetor de structs dentro do arquivo binário
    le(arq, vetor2); // le os dados do arquivos em binario e armazene no veto2
    impressao(vetor2); // imprima os dados que estão no vetor de structs vetor2

    fclose(arq); // sempre fechar arquivo, após o uso dele

    return 0;
}
