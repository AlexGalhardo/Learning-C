#include <stdio.h>
#include <stdlib.h>

int main(){

    char ch;
    int i;

    for(i=0; i<5; i++){
        printf("Digite o %do do caracter: \n");
        scanf("%c", &ch);
        setbuf(stdin, NULL);
    }
    return 0;
}
