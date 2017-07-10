#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inverte(char *,char *);
void consoante(char *);

int main(void){
    char dest[100],ori[100];
    printf("Digite a string (em letras minusculas, por favor): ");
    scanf("%s",ori);
    consoante(ori);
    inverte(ori,dest);
    printf("Resultado: %s\n",dest);
    return 0;
}


void inverte(char *origem, char *destino ){
    int i,j;
    for(i=0,j=(strlen(origem)-1);origem[i];i++,j--)
        destino[i]=origem[j];
    destino[i]='\0';
}

void consoante(char *str){
    int i=0;
    while(str[i]){
        switch(str[i]){
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                i++;
                continue;
            default:
                str[i]='#';
        }
    i++;
    }
}
