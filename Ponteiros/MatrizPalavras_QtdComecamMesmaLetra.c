/*
Faça um programa que leia uma quantidade N de palavras, sendo que N ´e
fornecido pelo usu´ario. Elas devem ser salvas em uma matriz de modo que cada linha
represente uma palavra. Fa¸ca uma fun¸c˜ao que receba como parˆametro um n´umero
inteiro, a matriz lida e um vetor de inteiros, todos passados por referˆencia. O que a
fun¸c˜ao dever´a fazer ´e salvar no vetor os n´umeros das linhas em que a primeira letra da
palavra ´e igual `a ´ultima. O n´umero inteiro passado como referˆencia ser´a um contador
que dir´a o tamanho desse vetor, ou seja, a quantidade de palavras em que a primeira e
a ´ultima letra s˜ao iguais.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

void lerPalavras(char palavras[][MAX], int n){
    int i;

    for(i=0; i<n; i++){
        scanf("%s", palavras[i]);
    }
}

void acharPalavras(char palavras[][MAX], int n, int posicoes[MAX], int *contador){
    int i, len;

    for(i=0; i<n; i++){
        len = strlen(palavras[i]);
        if(tolower(palavras[i][0]) == tolower(palavras[i][len-1])){
            posicoes[(*contador)++] = i;
        }
    }
}

void imprimirPalavras(char palavras[MAX][MAX], int posicoes[MAX], int contador){
    int i, soma=0;

    printf("\n\nPalavras encontradas: \n");
    for(i=0; i < contador; i++){
        printf("%s\n", palavras[posicoes[i]]);
        soma++;
    }
    printf("\n\nTotal de Palavras\n");
    printf("%d", soma);
}


int main(int argc, char * argv[]){
    int n, posicoes[MAX], contador = 0;
    char palavras[MAX][MAX];

    printf("Digite o numero de palavras a serem lidas: \n");
    scanf("%d", &n);

    lerPalavras(palavras, n);
    acharPalavras(palavras, n, posicoes, &contador);
    imprimirPalavras(palavras, posicoes, contador);

    return 0;
}
