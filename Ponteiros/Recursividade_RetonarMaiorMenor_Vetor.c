#include <stdio.h>
#include <stdlib.h>

/* implementação de "procurar()" omitida */

void procurar(int vetor[], int tamanho, int * maior, int * menor) {
    if (tamanho == 1) { /* caso base */
        *maior = *menor = vetor[0];
    } else { /* passo indutivo */
        procurar(vetor + 1, tamanho - 1, maior, menor);
        if (vetor[0] > * maior) * maior = vetor[0];
        if (vetor[0] < * menor) * menor = vetor[0];
    }
}

int main() {
    int tamanho, i, maior, menor;
    int *vetor;

    scanf("%d", &tamanho);
    
    vetor = malloc(tamanho * sizeof(int));
    
    if(vetor == NULL){
        printf("Não consegui alocar o vetor\n");
        return 1;
    }

    for(i = 0; i < tamanho; i++) {
        scanf("%d", &vetor[i]);
	}

    procurar(vetor, tamanho, &maior, &menor);
    printf("%d %d", maior, menor);

    return 0;
}
