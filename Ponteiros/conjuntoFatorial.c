/*
Conjunto de Fatorial em Intervalo
Desenvolva um programa em C que calcule o fatorial de um conjunto de números consecutivos e os retorne através do retorno de um ponteiro para inteiro (vetor de inteiros). Deverão ser lidos do teclado o primeiro número (n0) que começará a sequência do fatorial e a quantidade de números impressos (size). Qualquer vetor utilizado durante o programa deverá ser alocado dinamicamente. Sugestão desenvolva uma função com a seguinte assinatura: int* getConjuntoFatorial(int n0, int size).

Exemplos de Entrada e Saída
Entrada:

3 5
Saída:

6 24 120 720 5040
*/

// começar imprimindo fatorial de 3, e ir imprimindo até o fatorial de 3+tamanho-1

#include <stdio.h>
#include <stdlib.h>

int getConjuntoFatorial(int *num, int *size);

int main(){

    int num;
    int size;

    scanf("%d %d", &num, &size);

    // alocando memoria para o vetor dos resultados fatoriais
    int fatoriais[size];
    int *p = &fatoriais;
    p = (int *) malloc(size * sizeof(int));

    getConjuntoFatorial(&num, &size, p);

    return 0;
}


int getConjuntoFatorial(int *num, int *size, int *p){

    int aux = *num; // auxiliar estatico igual ao num = 3
    int i = 0;

    if(*num == 1){
        return 1;
    }
	else if(num){
        return *p[i] = *num * getConjuntoFatorial(*num-1, *size);
	}
	printf("%d", *p[i]); // printar posição i na tela
	i++; // acrescentar posição no vetor
	*num++; // aumentar em 1 o valor de num
}

