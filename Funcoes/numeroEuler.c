#include <stdio.h>
#include <stdlib.h>

int main(){

    int N = 100000;
    int i, j;
    float f, E = 1.0;
    for(i=1; i<=N; i++){
        f = 1;
        for(j=1; j<=i; j++){
            f = f * j;
        }
        E = E + 1.0/f;
    }
    printf("E = %f\n", E);

    return 0;
}
