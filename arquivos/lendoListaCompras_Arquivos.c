#include <stdio.h>
#include <stdlib.h>

int main(){

    char prod[30];
    float qtd, valor, total = 0.0;

    FILE *f = fopen("compras.txt", "r");
    if(f == NULL){
        printf("ERRO na abertura");
        exit(1);
    }

    while(!feof(f)){
        fscanf(f, "%s %f %f", prod, &qtd, &valor);
        total += qtd * valor;
    }

    printf("Total = %f\n", total);

    return 0;
}
