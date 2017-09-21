/*Desenvolva um programa em C que leia n ́umeros inteiros de um arquivo chamado ”nu-
meros.txt”.
`
A medida que vai lendo,  ele deve escrever em um arquivo chamado ”im-
pares.txt” os n ́umeros  ́ımpares e em um arquivo ”pares.txt” os que s ̃ao pares.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *arq, *par, *impar;

    int num;

    arq = fopen("numeros.txt", "r");
    if((arq = fopen("numeros.txt", "r"))== NULL){
        printf("\nERRO na abertura do arquivo!\n");
        exit(1);
    }
    if((arq = fopen("par.txt", "w+"))==NULL){
        printf("\nERRO na abertura do arquivo PAR!");
        exit(1);
    }
    if((arq==fopen("impar.txt", "w+"))==NULL){
        printf("\nERRO na abertura do arquivo IMPAR!");
        exit(1);
    }

    // enquanto não chegar no fim do arquivo ARQ, continue o laço
    while(!feof(arq)){
        fscanf(arq, "%d", &num); // FSCANF -> PONTEIRO DO ARQUIVO -> TIPO DE DADO -> QUE VARIAVEL ARMAZENAR AQUELE DADO
        if(num%2==0){ // SE FOR PAR
            fprintf(par, "%d", num); // FPRINTF --> PONTEIRO DO ARQUIVO ONDE SERÁ PRINTADO -> TIPO DE DADO -> QUE VARIAVEL ESTÁ ARMAZENADO O DADO
        }
        else{
            fprintf(impar, "%d", num);
        }
    }

    printf("\nOs numeros pares foram separados dos impares!!");

    fclose(arq);
    fclose(par);
    fclose(impar);

    return 0;
}
