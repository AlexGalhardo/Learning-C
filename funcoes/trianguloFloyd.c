#include <stdio.h>
#include <stdlib.h>

int main(){

    int n, j, c=0, i;
    scanf("%d", &n);

    for(i=1; i<=n; i++){
        for(j=1; j<=i; j++){
            c++;
            printf("%d ", c);
        }
        printf("\n");
    }


    return 0;
}
