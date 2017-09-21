/*Desenvolva um programa em C que abra 2 arquivos de texto j ́a existentes e mostre as
palavras que est ̃ao presentes em ambos os arquivos.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int main(){

    char filename1[MAX], filename2[MAX], palavra[MAX], conteudo[MAX];

    FILE *arq1, *arq2;

    printf("Digite o nome do arquivo 1: \n");
    scanf("%s", filename1);
    if((arq1==fopen(filename1, "r"))==NULL){
        printf("\nERRO na abertura do arquivo.\n");
        exit(1);
    }

    printf("Digite o nome do arquivo 2: \n");
    scanf("%s", filename2);
    if((arq2==fopen(filename2, "r"))==NULL){
        printf("\nErro na abertura do arquivo.\n");
        exit(1);
    }

    while(!feof(arq1)){ // enquanto não chegar no final do arq1, continue o laço
        fscanf(arq1, "%s", palavra); // pegando primeira palavra que será comparada
        while(!feof(arq2)){ // enquanto não chegar no final do arq2, continue o laço
            fscanf(arq2, "%s", conteudo); // pega palavra para ser comparada com a primeira
            if(strcmp(palavra, conteudo)==0){ // usando strcmp, compare as 2 palavras para ver se são iguais
                printf("A palavra %s esta nos dois arquivos!", palavra);
            }
        }
        // não se esquecer que após comparar a primeira palavra do arq1, voltar para o inicio do arquivo2 novamente!!!
        rewind(arq2); // voltar selecionador para o inicio do arquivo2
    }

    fclose(arq1);
    fclose(arq2);

    return 0;
}
