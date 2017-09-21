/*
Imprimindo chars como inteiros
Você deverá ler vários caracteres de entrada, até encontrar o caractere 'x'. Em casos de '\n', você deverá ignorar este caractere (não adicioná-lo ao vetor) e continuar a leitura.
Ao terminar a leitura, ordene o vetor em ordem crescente.
Ao final, você deverá imprimir seu vetor de caracteres como um vetor de inteiros, pulando uma linha após cada número impresso.
Lembre-se: um inteiro possui 4 bytes, enquanto um caractere possui 1 byte. Ou seja, 4 caracteres formam 1 inteiro.

Exemplo:
Entrada:
abcdefghijklmnopqrstx
Saída:
1684234849
1751606885
1818978921
1886350957
1953722993

Entrada:
programaremcx
Saída:
1701011809
1869442407
1920103024

*/



#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define OK(x) (printf("OK ate %d\n",(x)))

void ordena(char *vet)
{
    int i, len;
    char temp;
    len = strlen(vet);
    for(i=0; i<len-1;i++)
    {
        if(vet[i]>vet[i+1])
        {
            temp = vet[i];
            vet[i] = vet[i+1];
            vet[i+1] = temp;
            i=-1;
        }
    }
}

/*
void charemint(char *vet)
{
    int i, j, len, temp=0;
    len = strlen(vet);
    for(i=0; i<len;i++)
    {
        temp += (int)vet[i] ;
        if((i+1)%4==0)
        {

            printf("%d\n",temp);
            temp = 0;
        }
    }
    if((i+1)%4!=0)
    {
        printf("%d\n",temp);
    }
*/

void charemint(char *vet)
{
    int *z,i=0, len;
    len = strlen(vet);
    while(i<len-2)
    {
        z = (int *)(vet+i);
        printf("%d\n",z[0]);
        i+=4;
    }
}

int main()
{
    int count = 1;
    char *frase, c;
    frase = (char *)calloc(1,sizeof(char));
    do
    {
        scanf("%c",&c);
        if(c!='\n')
        {
            frase[count-1] = c;
            frase = (char *)realloc(frase,sizeof(char)*(++count));
        }
    }while(c!='x');
    frase[count]='\0';
//    printf("0\n%s\n0\n",frase);
    ordena(frase);
    charemint(frase);
//    printf("0\n%s\n0\n",frase);
    free(frase);
    return 0;
}

