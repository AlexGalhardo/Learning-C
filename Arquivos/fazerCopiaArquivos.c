/*Desenvolva um programa em C que crie uma c ́opia de um arquivo.  Para isso solicite ao
usu ́ario dois nomes de arquivos, sendo o primeiro o arquivo de origem e o segundo o de
destino. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // não se esquecer da biblioteca string.h para usar as funções necessárias

#define MAX 100

int main(){

    FILE *arq1, *arq2;

    char filename1[MAX], filename2[MAX], conteudo[100];

    // digite o nome do primeiro arquivo, e verifique se ele existe
    printf("Digite o nome do arquivo de origem : \n");
    scanf("%s", filename1);
    if((arq1==fopen(filename1, "r"))==NULL){ // LER OS DADOS == "r"
        printf("\nERRO na abertura do arquivo 1!");
        exit(1);
    }

    // digite o nome do arquivo 2, e verifique se ele existe
    printf("Digite o nome do arquivo de destino: \n");
    scanf("%s", filename2);
    if((fopen(filename2, "w+"))==NULL){ // ESCREVER DENTRO DO ARQUIVO = "w"
        printf("\nERRO na abertura do arquivo!\n");
        exit(1);
    }

    // enquanto não chegar ao final do arquivo1, armazene as strings no vetor conteudo, de tamanho 100, de entrada arq1
    while(!feof(arq1)){
        fgets(conteudo, 100, arq1);
        fprintf(arq2, "%s", conteudo); // ESCREVA NO ARQUIVO 2, as strings %s, do vetor CONTEUDO
    }

    // se tudo der certo, vai ser digitado essa frase
    printf("Arquivo copiado com sucesso!!!");

    // sempre fechar os arquivos depois de utilizá-los
    fclose(arq1);
    fclose(arq2);

    return 0;
}
