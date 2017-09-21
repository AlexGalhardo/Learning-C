/*5.  Desenvolva  um  programa  em  C  que  armazene  e  leia  um  vetor  de  5  inteiros  no  modo
arquivo binário*/

#include <stdio.h>
#include <stdlib.h>

void armazena(FILE *arq, int *vet){
    rewind(arq); // coloque selecionador no inicio do arquivo
    // fwrite -> serve para escrever dentro de arquivos binários
    fwrite(vet, sizeof(int), 5, arq);  // escrever dados do vetor, do tipo sizeof(int), com 5 componentes, no arquivo arq
}

void le(FILE *arq, int *vet){
    rewind(arq);
    // fread -> serve para ler dados dentro de arquivos binários
    fread(vet, sizeof(int), 5, arq); // mesma sintaxe do fwrite, so que com fread
}

void leitura(int *vet){ // função que le os inteiros do vetor
    int i;

    printf("Digite os valores do vetor\n");
    for(i=0; i<5; i++){
        scanf("%d", &vet[i]);
    }
}

void impressao(int *vet){

    int i;

    printf("O vetor lido eh\n");
    for(i=0; i<5; i++){
        printf("%d", vet[i]);
    }
}

int main(){

    FILE *arq;
    int vetor[5];
    char filename[100];

    printf("Digite o nome do arquivo: \n");
    scanf("%s", filename);

    if((arq=fopen(filename, "wb+"))==NULL){
        printf("\nERRO na abertura do arquivo.\n");
        exit(1);
    }

    leitura(vetor); // ler dados do vetor
    armazena(arq, vetor); // armazenar dados do vetor dentro do arquivo binário
    le(arq, vetor); // ler os dados do arquivo binario, e guarde dentro do vetor
    impressao(vetor); // imprimir dados que estão dentro do vetor

    // não se esquecer de fechar arquivo
    fclose(arq);

    return 0;
}
