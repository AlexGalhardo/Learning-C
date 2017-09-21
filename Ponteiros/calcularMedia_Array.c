#include <stdio.h>
#include <stdlib.h>

float media(int *vetor, int n, int tam){
    if(n<=0){
        return 0;
    }
    else{
        return vetor[n-1]/(float) tam + media(vetor, n-1, tam);
    }
}

int main(){

    int v[5] = {1, 2, 3, 4, 5};
    printf("Media = %f\n", media(v, 5, 5));
    return 0;
}
