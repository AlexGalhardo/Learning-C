/*
Equação do Plano
Se você conhecer as coordenadas de três pontos do espaço, é possível encontrar a equação do plano que os contém, desde que os pontos não sejam colineares. A equação geral de um plano tem forma:

Ax + By + Cz + D = 0
onde (A,B,C) é a coordenada do vetor normal ao plano. Desenvolva um programa em C que leia 3 pontos do espaço não colineares e imprima os valores de A,B,C e D. A entrada terá 3 linhas, cada uma com 3 números reais correspondentes às coordenadas (x,y,z) de cada ponto. Imprima os valores reais com 2 casas após a vírgula.

Obs: Faça uma função que calcule os valores pedidos, passando-os como argumentos por referência. Faça também uma função que leia as coordenadas de um ponto.

Obs2: Como existem 2 vetores normais ao plano (de mesma direção e sentidos opostos) considere apenas aquele em que A é positivo. Se A for igual a 0, considere o que tem B positivo, e se A e B forem nulos, considere aquele em que C é positivo.

Exemplos de Entrada e Saída
Entrada:

3 4 5    
1 2 4
0 0 0
Saída:

6.00 -7.00 2.00 0.00
*/


#include <stdio.h>

void lerPontos(double vet[3]){
    scanf("%lf%lf%lf", &vet[0], &vet[1], &vet[2]);
}

void montaVetor(double vet1[3], double vet2[3], double vf[3]){
    for(int i=0 ; i<3 ; i++){
        vf[i] = vet1[i]-vet2[i];
    }
}

void calcNormal(double normal[3], double vAB[3], double vAC[3]){
    normal[0] = -1*((vAB[1]*vAC[2])-(vAC[1]*vAB[2]));
    normal[1] = -1*((vAB[2]*vAC[0])-(vAB[0]*vAC[2]));
    normal[2] = -1*((vAB[0]*vAC[1])-(vAB[1]*vAC[0]));
}

void calcD(double normal[3],double a[3],double *d){ // apresentando problemas no arredondamento no caso 5 do run.codes
    *d = -1*((a[0]*normal[0]) + (a[1]*normal[1]) + (a[2]*normal[2]));
}

int main(){
    double a[3], b[3], c[3], vAB[3], vAC[3];
    double normal[3], d;

    lerPontos(a);
    lerPontos(b);
    lerPontos(c);

    montaVetor(b, a, vAB);
    montaVetor(c, a, vAC);

    calcNormal(normal, vAB, vAC);

    calcD(normal, a, &d);
    
    for(int i=0; i<3 ; i++){
        if(normal[i] == -0.0){
            normal[i] = 0.0;
         }

    if(d == -0.0)
        d=0.0;
    }

    printf("%.2lf %.2lf %.2lf %.2lf", normal[0], normal[1], normal[2], d);


    return 0;
}
