#include <stdio.h>
#include <stdlib.h>

main(){
    int n;
    double x;
    char s[] ="10 5.8";
    //converte a string para um inteiro e um double
    sscanf(s,"%d %lf", &n, &x);
    printf("n = %d\nx= %f\n", n, x);
    return 0;
}
