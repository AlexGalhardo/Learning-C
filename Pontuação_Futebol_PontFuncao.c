/*
Faça um programa que calcule a pontuação de dois times ap´os uma partida de
futebol. Na fun¸c˜ao principal leia dois n´umeros inteiros que correspondem ao n´umero de
pontos dos dois times antes do jogo. Depois leia dois inteiros que representam o n´umero
de gols que cada time fez na partida. Vocˆe dever´a fazer uma fun¸c˜ao separada que receba
os pontos dos dois times por referˆencia e os atualize de acordo com o resultado. Em caso
de vit´oria s˜ao somados 3 pontos, em caso de empate ´e somado um ponto, e em caso de
derrota, nenhum ponto ´e somado.
*/

#include <stdio.h>

void atualizarPontos(int *pontos1, int *pontos2, int gols1, int gols2){
    if(gols1==gols2){
        (*pontos1)++;
        (*pontos2)++;
    }
    else if(gols1>gols2){
        (*pontos1)+=3;
    }else{
        (*pontos2)+=3;
    }
}

int main(int argc, char * argv[]){
    int pontos1, pontos2;
    int gols1, gols2;

    printf("Digite os pontos dos dois times antes da partida: \n");
    scanf("%d%d", &pontos1, &pontos2);

    printf("Digite a quantidade de gols de cada time: \n");
    scanf("%d %d", &gols1, &gols2);

    atualizarPontos(&pontos1, &pontos2, gols1, gols2);

    printf("Pontos do time 1: %d\n", pontos1);
    printf("Pontos do time 2: %d\n", pontos2);

    return 0;

}
