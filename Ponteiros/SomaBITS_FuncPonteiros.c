/*
Desenvolva um programa para testar uma fun¸c˜ao com prot´otipo void somabit(int
b1, int b2, int *vaium, int *soma);. A fun¸c˜ao recebe trˆes bits (inteiros 0 ou 1) b1, b2
e *vaium. A fun¸c˜ao retorna um bit soma que armazena o resultado da soma dos trˆes
primeiros e o bit ”vai-um” em *vaium.
*/

#include <stdio.h>


void somabit(int b1, int b2, int *vaium, int *soma){

    *soma = (b1+b2+ *vaium) % 2;
    
    if(b1+b2+ *vaium <2){
        *vaium=0;
    }
    
    else{
        *vaium=1;
    }
}



int main(){
    int b1=0, b2=0, vaium=1, soma; // valores para teste
    
    printf("\n\nb1=%d\n b2=%d\n v1= %d\n +_____", b1, b2, vaium);
    
    somabit(b1, b2, &vaium, &soma);
    
    printf("\n\n S = %d\n v1= %d\n", soma, vaium);

    return 0;
}
