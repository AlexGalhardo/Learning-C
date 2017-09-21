/* Desenvolva um programa em C leia uma palavra digitada, abra um arquivo de texto j ́a
existente e verifique se a palavra est ́a contida no arquivo. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main(){

    char palavra[MAX], filename[MAX];
    FILE *arq;

    int cont = 0;

    printf("Digite o nome do arquivo: \n"); // pegando nome do arquivo a ser lido do usuário
    scanf("%s", filename); // salva no vetor filename

    if((arq==fopen(filename, "r"))==NULL){ // se não existir um arquivo texto com nome digitado pelo usuário, pare programa
        printf("ERRO na abertura do arquivo!\n");
        exit(1);
    }

    printf("Digite uma palavra: \n"); // pegando palavra do usuário que será comparada
    scanf("%s", palavra); // guarde palavra no vetor palavra

    while(!feof(arq)){ // enquanto não chegar no fim do arquivo, continue o laço
        char strLido[MAX];
        fscanf(arq, "%s", strLido);
        if(strcmp(strLido, palavra)==0){ // pegando função da biblioteca string.h -> se strLido do arquivo for igual palavra digitado, incremente o contador
            cont++;
        }
    }

    return 0;
}
