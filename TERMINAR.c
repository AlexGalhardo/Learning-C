#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 200

int verifica(char string[], char contrario[],int *total, int *erro){
    int i, j;

    for(i=0; i < *total; i++) {
        contrario[i] = string[j];
        j--;
    }

    for(i=0; i < *total; i++) {
        if(string[i] != contrario[i]){
            erro = 1;
        }
    }

    return erro;
}

void main() {

    char string[MAX], contrario[MAX];

    int total=0, i , j, erro = 0;

    scanf("%s",&string);

    total = strlen(string);
    j = total;
    total++;
    j--;

    verifica(char string[], char contrario[],int &total, int &erro);

    total--;



    if(erro == 1){
        printf("NAO");
    }
    else{
        printf("SIM");
    }

    return 0;
}
