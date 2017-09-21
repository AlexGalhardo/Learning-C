/*
Desenvolva um programa que leia a quantidade total de segundos e converta
para Horas, Minutos e Segundos. Imprima o resultado da convers˜ao no formato
HH:MM:SS. Para isso, utilize a fun¸c˜ao com prot´otipo void converteHora(int total
segundos, int *hora, int *min, int *seg).
*/

#include <stdio.h>

void converterHora(int totalsegundos, int *hora, int *min, int*seg){
    int horas_seg = 3600;
    *hora = (totalsegundos / horas_seg);
    *min = (totalsegundos - (horas_seg * *hora)) / 60;
    *seg = (totalsegundos - (horas_seg * *hora) - (*min * 60));
}

int main(){
    int tempo, horas, minutos, segundos;
    printf("Entre com o numero de segundos totais: \n");
    scanf("%d", &tempo);
    converterHora(tempo, &horas, &minutos, &segundos);
    printf("%dH:%dM:%dS \n", horas, minutos, segundos);

    return 0;
}
