/*
Particionamento de string

Você deverá implementar um programa capaz de particionar uma frase (a partir dos espaços) e montar um array de strings com as palavras que a compõe.
O usuário poderá solicitar duas operações:

    Imprimir as palavras
    Imprimir as palavras em ordem alfabética

As entradas e saídas serão fornecidas como nos exemplos abaixo:
Exemplos de Entrada

Entrada 1

Eu queria estar jogando Zelda agora
1

Entrada 2

Eu tambem queria estar jogando Nier Automata
2

Exemplos de Saída

Saída 1

Eu
queria
estar
jogando
Zelda
agora

Saída 2

automata
estar
eu
jogando
nier
queria
tambem

Note que, para realizar a ordenação, você converter as letras de todas as palavras para minúsculas. Somente para ordenar!
Seu programa deverá conter obrigatoriamente as seguintes funções:

    Uma para particionar a frase
    Uma para printar as palavras
    Uma para ordenar as palavras 
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PAL 200
#define MAX_CARAC 100


int particionarFrase (char frase[], char particao[MAX_PAL][MAX_CARAC])
{
    int i=0, p=0,c=0, len;

    len = strlen(frase);

    for (i=0; i<len-1; i++)
    {
        if (frase[i]!=' ')
        {
            particao[p][c]=frase[i];
            c++; //contador de caracteres
        }
        else
        {
            p++; //contador de palavras
            c=0;
        }


    }
    return p;
}

void ordenarFrase (char particao[MAX_PAL][MAX_CARAC], int tam)
{
    int i,j;
    char aux[MAX_CARAC];

    //letras minusculas
    for (i=0; i<=tam; i++)
    {
        for (j=0; particao[i][j]!=' '; j++)
        {
            particao[i][j] = tolower(particao[i][j]);
        }
    }

    //ordena??o das palavras
    for (i=0; i<=tam; i++)
    {
        for (j=i+1; j<=tam; j++)
        {
            if (strcmp(particao[i],particao[j])>0)
            {
                strcpy(aux,particao[i]);
                strcpy(particao[i],particao[j]);
                strcpy(particao[j],aux);
            }
        }
    }
}



void printarFrase (char particao[MAX_PAL][MAX_CARAC], int tam)
{
    int i=0;
    for(i=0; i<=tam; i++)
    {
        printf("%s\n",particao[i]);
    }
}


int main()
{
    char frase[MAX_CARAC], particao[MAX_PAL][MAX_CARAC];
    int opcao, tam;

    fgets(frase, MAX_CARAC, stdin);

    scanf(" %d", &opcao);

    tam = particionarFrase(frase, particao);

    if (opcao==2)
    {
        ordenarFrase(particao, tam);
    }

    printarFrase(particao, tam);

    return 0;
}
