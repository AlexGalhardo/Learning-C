#include <stdio.h>
#include <stdlib.h>

void calcular(int *vetor, int n, float *m, float *dp){

    int i;
    *m = 0.0;
    for(i=0; i<n; i++){
        *m = *m + vetor[i];
    }
    *m = *m/n;
    *dp = 0.0;
    for(i=0; i<n; i++){
        *dp = *dp + pow(vetor[i] - *m, 2);
    }
    *dp = sqrt(*dp/(n-1));
}

int main(){

    int v[5] = {1, 2, 3, 4, 5};
    float media, desvio;
    calcular(v, 5, &media, &desvio);
    printf("%f\n%f\n", media, desvio);
    return 0;
}
