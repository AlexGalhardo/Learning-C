#include <stdio.h>
#include <stdlib.h>

int main(){
    char strings[5][100];
    int i;
    for (i=0; i < 5; i++){
        printf("Digite uma string: ");
        scanf("%s",strings[i]);
    }
    for (i=0; i < 5; i++)
        printf("%s\n",strings[i]);
}
