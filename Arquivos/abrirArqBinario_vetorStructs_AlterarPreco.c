/*
Desenvolva  um  programa  em  C  que  abra  o  arquivo  criado  anteriormente  e  permite  a
altera ̧c ̃ao dos pre ̧cos dos carros.
*/

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
    fwrite(vet, sizeof(CARRO), TAM, arq);
}


void le(FILE *arq, CARRO *vet){
    rewind(arq);
    fread(vet, sizeof(CARRO), TAM, arq);
}


void impressao(CARRO *vet){
    int i;
    for(i=0; i<TAM; i++){
        printf("Carro %d\nModelo: %s\nCor: %s\nPreço: %f\n", i+1, vet[i].modelo, vet[i].cor, vet[i].preco);
    }
}

int main(){

    FILE *arq;
    CARRO vet[TAM];
    char filename[100], modelo[15], cor[10];
    float preco;
    int opcao, i, nao=0;

    printf("Digite o nome do arquivo: \n");
    scanf("%s", filename);
    // verifica se o arquivo existe
    if((arq=fopen(filename, "rb"))==NULL){
        printf("\nErro na abertura do arquivo.\n");
        exit(1);
    }

    le(arq, vet);
    printf("Deseja procurar carro por:\n1-Modelo\n2-Cor\n3-Preco\n");
    scanf("%d", &opcao);

    switch(opcao){
        case 1:
            printf("Digite o modelo do carro: ");
            scanf("%s", modelo);
            //procura carro com o modelo digitado
            for(i=0; i<TAM; i++){
                if(strcmp(modelo, vet[i].modelo)==0){
                    printf("Carro %d\nModelo: %s\nCor: %s\nPreço: %f\n", i+1, vet[i].modelo, vet[i].cor, vet[i].preco);
                    printf("Digite o novo preco: ");
                    scanf("%f", &vet[i].preco);
                }
                else{
                    nao++;
                }
            }
        if(nao==TAM){
            printf("Modelo de carro nao cadastrado!!\n");
        }

        case 2:
            printf("Digite a cor do carro: ");
            scanf("%s", cor);
            // procura carro com a cor digitado
            for(i=0; i<TAM; i++){
                if(strcmp(cor, vet[i].cor)==0){
                    printf("Carro %d\nModelo: %s\nCor: %s\nPreço: %f\n", i+1, vet[i].modelo, vet[i].cor, vet[i].preco);
                    printf("Digite o novo preco: \n");
                    scanf("%f", &vet[i].preco);
                }
                else{
                    nao++;
                }
            }
        if(nao==TAM){
            printf("Cor de carro nao cadastrado!!\n");
        }
        case 3:
            printf("Digite o preco do carro: \n");
            scanf("%f", &preco);
            // precocura carro com o preço digitado
            for(i=0; i< TAM; i++){
                if(preco == vet[i].preco){
                    printf("Carro %d\nModelo: %s\nCor: %s\nPreço: %f\n", i+1, vet[i].modelo, vet[i].cor, vet[i].preco);
                    printf("Digite o novo preco: \n");
                    scanf("%f", &vet[i].preco);
                }
                else{
                    nao++;
                }
            }
        if(nao==TAM){
            printf("Preco de carro nao cadastrado!!\n");
        }
    }

    if(nao!=TAM){
        armazena(arq, vet);
        printf("Carros com atualizacao!\n");
        impressao(vet);
    }

    fclose(arq);

    return 0;
}
