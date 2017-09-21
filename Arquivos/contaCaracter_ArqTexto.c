/*
Leitura de Arquivo de Texto - Conta Caracteres

Faça um programa em C que leia um arquivo de texto, chamado texto.txt. Esse programa deverá armazenar as letras presentes nesse arquivo e sua frequência. Para isso defina um registro contendo uma letra e a quantidade de ocorrência dessa letra (freq). Segue abaixo a struct a ser usada.

struct freqLetra{
char letra;
int freq;
};

Após processar todo o texto o seu programa deverá imprimir na tela cada um dos 26 caracteres possíveis (letras de 'a' a 'z' minúsculas) com a sua frequência que aparecem no texto seguido de um '\n'. Durante o processamento faça a conversão dos caracteres para minúsculo usando a função tolower(letra), da biblioteca ctype.h.

OBS: código para impressão na tela: printf("%c = %d\n", cLetra[i].letra, cLetra[i].freq); OBS: exemplo de uso da função tolower: char letraMinuscula = tolower(letra);
Exemplo de Entrada e Saída:

Entrada:

(arquivo de texto chamado texto.txt)

Saída:

a = 745
b = 66
c = 217
d = 230
e = 659
f = 57
g = 43
h = 75
i = 348
j = 29
k = 2
l = 156
m = 207
n = 263
o = 581
p = 120
q = 62
r = 378
s = 313
t = 217
u = 266
v = 88
w = 3
x = 5
y = 3
z = 34

*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


typedef struct{
    char letra;
    int qnt;
}REGLETRA;


int main(){

    int posicao, valorLetra, i;
    REGLETRA *vet = NULL;
    char letter;

    FILE*arq = fopen("texto.txt","r");
    if(arq==NULL){
        exit(0);
    }

    vet = (REGLETRA*) malloc(26 * sizeof(REGLETRA));

    do{
       fscanf(arq,"%c", &letter);
       letter = tolower(letter); /* biblioteca ctype.h */

       if (letter >='a' && letter <= 'z'){
           valorLetra = letter; // o inteiro valorLetra recebe a posição de letter na TABELA ASCI
           posicao = valorLetra - 97; // 97 é o valor de 'a' na tabela ASCI. se for 'a' dará zero para a posicao.
           vet[posicao].letra = letter;
           vet[posicao].qnt++;
       }

    }while(!feof(arq)); // faça esse loop, enquanto n chegar no fim do arquivo, adicionado o caracter e a qtd repetida dentro do vetor de structs

    for(i=0; i<26; i++){
        if (vet[i].qnt == 0){
            if (vet[i-1].qnt != 0){
                vet[i].letra = vet[i-1].letra +1;
            }
            else if (vet[i+1].qnt != 0){
                vet[i].letra = vet[i+1].letra -1;
            }
        }
        printf("%c = %d\n", vet[i].letra, vet[i].qnt);
    }

    fclose(arq); // sempre fechar arquivo, depois de usá-los

    return 0;
}
