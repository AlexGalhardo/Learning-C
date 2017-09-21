#include <stdio.h>
#include <stdlib.h>

/*
S = 2 + ... + (1 + n^2/n)
*/
float serieS(int n){
    if(n>0){
        return (1+n*n)/(float)n + serieS(n-1);
    }
    else{
        return 0;
    }
}

int main(){

    printf("S = %f\n", seriesS(5));

    return 0;
}
