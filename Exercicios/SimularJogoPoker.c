/*
Poker
Em um jogo de poker é utilizado um baralho de 52 cartas, divididos em 4 naipes: Copas, Espadas, Ouros e Paus. Cada naipe tem 13 cartas: 2,3,4,5,6,7,8,9,10, valete(J), dama(Q), rei(K) e ás(A). Cada jogador tem 5 cartas na mão. As possíveis 9 combinações que podem determinar o vencedor estão listadas abaixo, começando da combinação que vale menos até a que vale mais:

Par: Duas cartas com valor igual
Dois Pares: Dois pares de cartas com valores iguais
Trinca: Três cartas com o mesmo valor
Straight: 5 cartas em sequência de naipes diferentes
Flush: 5 cartas do mesmo naipe que não estão em sequência
Full House: Uma trinca e um par
Quadra: Quatro cartas com valor igual
Straight Flush: 5 cartas em sequência do mesmo naipe
Royal Straight Flush: 5 cartas em sequência do mesmo naipe de 10 a A
Obs: Uma sequência não pode ser formada por algumas das últimas cartas e algumas das primeiras, ou seja, o 2 só pode formar sequência com 3,4,5 e 6, assim como o A só pode estar em uma sequência de 10 a A.

A entrada terá um número N que corresponde a quantas partidas foram jogadas. Seu programa terá que calcular o número de vitórias de cada jogador, assim como o número de empates. Um empate acontece quando os dois jogadores tiverem feito a mesma combinação. Caso nenhum dos dois tenha feito nenhuma combinação, o vencedor será aquele que tiver a carta mais alta. Caso a carta mais alta dos dois tenham valor igual, considere um empate.

Dica: Faça um vetor de naipes e um de valores para cada jogador, além de uma função de leitura que os preencha. (não é obrigatório)

Dica2: Faça vetores contadores, que incrementam uma posição de acordo com o valor da carta, pode ajudar na checagem de combinações. (não é obrigatorio)

Obs2: Faça uma função separada na qual o jogo acontece, e passe as variáveis vitoria1,empate e vitoria2 por referência (isso é obrigatório)

Formato de Entrada e Saída
A saída será composta de 3 números inteiros, respectivamente o número de vitórias do jogador 1, o número de empates e o número de vitórias do jogador 2.

A entrada será composta por um número inteiro N na primeira linha que dirá quantas partidas foram jogadas. Cada partida terá uma entrada de duas linhas com 5 cartas cada uma, a primeira linha representa a mão do primeiro jogador e a segunda linha a mão do jogador 2. Como são N partidas, haverá 2N linhas com 5 cartas cada. As cartas serão compostas por um caracter que representa o naipe, e o valor da carta. As letras de cada naipe são: C para Copas, E para Espadas, O para Ouros e P para Paus.

Obs: Se a leitura estiver funcionando no seu computador mas não no run.codes, tente colocar um fgetc(stdin); após ler a linha inteira (caso esteja lendo caracter por caracter).

Exemplos de Entrada e Saída
Entrada:

1
O3 CA O4 E10 P3
PJ PQ P10 PA P4
Saída:

0 0 1
Entrada:

2
O3 CA O4 E10 P3
OJ PQ P10 C10 P4
P2 O4 P7 C10 CQ
OJ PK P10 C8 P4
Saída:

0 1 1


*/



#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void ordena(char *n,int *c)
{
    int i=0,t=0;
    char lt='0';
    for(i=0;i<4;i++)
    {
        if(c[i]>c[i+1])
        {
            t = c[i];
            c[i] = c[i+1];
            c[i+1] = t;
            lt = n[i];
            n[i] = n[i+1];
            n[i+1] = lt;
            i=-1;
        }
    }
}

void calc_placar(int *res,char *n1,int *c1,char *n2,int *c2)
{
    int i=0, p1=0, p2=0;
//conta pares
    while(i<4)
    {
        if(c1[i]==c1[i+1])
        {
            p1+=100;
        }
        if(c2[i]==c2[i+1])
        {
            p2+=100;
        }
        i++;
    }
    i=0;
//conta trincas
    while(i<3)
    {
        if(c1[i]==c1[i+1]&&c1[i+1]==c1[i+2])
        {
            p1+=100;
        }
        if(c2[i]==c2[i+1]&&c2[i+1]==c2[i+2])
        {
            p2+=100;
        }
        i++;
    }
    i=0;
//conta Full House
    if(p1==400)
    {
        p1+=2000;
    }
    if(p2==400)
    {
        p2+=2000;
    }
//conta straight
    if(c1[0]+1==c1[1]&&c1[1]+1==c1[2]&&c1[2]+1==c1[3]&&c1[3]+1==c1[4])
    {
        p1+=400;
    }
    if(c2[0]+1==c2[1]&&c2[1]+1==c2[2]&&c2[2]+1==c2[3]&&c2[3]+1==c2[4])
    {
        p2+=400;
    }
//conta Flush
    if(n1[0]==n1[1]&&n1[1]==n1[2]&&n1[2]==n1[3]&&n1[3]==n1[4])
    {
        if(c1[0]+1==c1[1]&&c1[1]+1==c1[2]&&c1[2]+1==c1[3]&&c1[3]+1==c1[4])
        {
            if(c1[0]==10)
            {
                p1+=100000;
            }
            p1+=10000;
        }
        p1+=1000;
    }
    if(n2[0]==n2[1]&&n2[1]==n2[2]&&n2[2]==n2[3]&&n2[3]==n2[4])
    {
        if(c2[0]+1==c2[1]&&c2[1]+1==c2[2]&&c2[2]+1==c2[3]&&c2[3]+1==c2[4])
        {
            if(c2[0]==10)
            {
                p2+=100000;
            }
            p2+=10000;
        }
        p2+=1000;
    }
//conta quadra
    while(i<2)
    {
        if(c1[i]==c1[i+1]&&c1[i+1]==c1[i+2]&&c1[i+2]==c1[i+3])
        {
            p1+=3000;
        }
        if(c2[i]==c2[i+1]&&c2[i+1]==c2[i+2]&&c2[i+2]==c2[i+3])
        {
            p2+=3000;
        }
        i++;
    }

//conta nada
    if(p1==0)
    {
        p1+=c1[4];
    }
    if(p2==0)
    {
        p2+=c2[4];
    }
//altera placar
    if(p1>p2)
    {
        res[0]++;
    }
    else if(p2>p1)
    {
        res[2]++;
    }
    else if (p2==p1)
    {
        res[1]++;
    }
}

void conv_inp(char *entrada,char *naipe,int *numero)
{
    *naipe = entrada[0];
    if(entrada[1]=='1')
    {
        *numero = 10;
    }
    else if(entrada[1]>'/' && entrada[1] <':')
    {
        *numero = entrada[1]-'0';
    }
    else if(entrada[1]=='J')
    {
        *numero = 11;
    }
    else if(entrada[1]=='Q')
    {
        *numero = 12;
    }
    else if(entrada[1]=='K')
    {
        *numero = 13;
    }
    else if(entrada[1]=='A')
    {
        *numero = 14;
    }
}

int main()
{
    int part, res[3]={0,0,0}, i=0, j=0, c1[5],c2[5];
    char s[3], n1[5],n2[5];
    do
    {
        scanf("%d", &part);
    }while(part<1);
    while(i<part)
    {
        while(j<5)
        {
            scanf(" %s",s);
            conv_inp(s,&n1[j],&c1[j]);
            j++;
        }
        j=0;
        while(j<5)
        {
            scanf(" %s",s);
            conv_inp(s,&n2[j],&c2[j]);
            j++;
        }
        j=0;
        ordena(n1,c1);
        ordena(n2,c2);
        calc_placar(res,n1,c1,n2,c2);
/*      printf("\n%c%d %c%d %c%d %c%d %c%d\n",n1[0],c1[0],n1[1],c1[1],n1[2],c1[2],n1[3],c1[3],n1[4],c1[4]);
        printf("%c%d %c%d %c%d %c%d %c%d\n",n2[0],c2[0],n2[1],c2[1],n2[2],c2[2],n2[3],c2[3],n2[4],c2[4]);
        printf("%d %d %d\n\n",res[0],res[1],res[2]);
*/      i++;
    }
    printf("%d %d %d",res[0],res[1],res[2]);
    return 0;
}
