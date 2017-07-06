/*Desenvolva um programa em C que leia uma frase e escreve em um arquivo de texto.
Ap ́os a escrita no arquivo, o programa deve ler o conte ́udo do arquivo e exibi-lo na tela
*/


#include <stdio.h>
#include <stdlib.h>

int main(){

    char frase[100];
    FILE *arq = fopen("frase.txt", "w+");

    if(arq== NULL){
        printf("\nERRO na abertura do arquivo!");
        exit(1);
    }

    printf("Digite uma frase: \n");
    fgets(frase, 100, stdin); // pega frase do usuário

    fprint(arq, "%s", frase); // imprime a frase do usuário dentro do arquivo chamado arq

    char frase2[100]; // vetor que será guardado a frase

    rewind(arq); // volta o selecionador para o inicio do arquivo

    fgets(frase2, 100, arq); // função pega string, (coloque no vetor frase2), tamanho do vetor, entrada do input(arq)

    printf("A frase digitada eh: \n %s", frase); //

    fclose(arq);

    return 0;
}
