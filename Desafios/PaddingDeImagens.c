/*
Padding de Imagens
Você irá implementar um algoritmo muito utilizado em Processamento de Imagens: Padding (uma adição de bordas).
Esse procedimento é um pré-processamento da imagem que adiciona uma borda ao redor da imagem original com pixels de valor 0.
Pode-se criar uma borda de qualquer tamanho. Por exemplo, em uma borda de tamanho 2, adicionamos, para cada pixel na extremidade da imagem, 2 pixels na direção da extremidade.
O programa receberá as seguintes entradas:
Largura da imagem.
Altura da imagem.
Largura*Altura pixels da imagem, que são inteiros variando de 0 a 255.
O tamanho da borda.
Como saída o programa deverá exibir a imagem com o padding, e, após pular uma linha, a imagem original.

Exemplo:
Entrada:
3
3
1 1 1
2 2 2
3 3 3
2
Saída:
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 1 1 1 0 0
0 0 2 2 2 0 0
0 0 3 3 3 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0

1 1 1
2 2 2
3 3 3

Entrada:
2
3
1 1
2 2
3 3
1

Saída:
0 0 0 0
0 1 1 0
0 2 2 0
0 3 3 0
0 0 0 0

1 1
2 2
3 3

*/



#include <stdlib.h>
#include <stdio.h>
#define OK(x) (printf("OK ate %d\n",(x)))

void fill_mat(int **vetor, int lin, int col)
{
    int i, j;
    for(i=0;i<lin;i++)
    {
        for(j=0;j<col;j++)
        {
            scanf("%d",&vetor[i][j]);
        }
    }
}

void cria_mat(int ***vetor, int lin, int col)
{
    int i;
    vetor[0] = (int **)calloc(lin,sizeof(int *));
    for(i=0;i<lin;i++)
    {
        vetor[0][i] = (int *)calloc(col, sizeof(int));
    }
}

void padd_mat(int **vetor, int lin, int col, int pad)
{
    int i, j;
    for(i=0;i<lin+pad*2;i++)
    {
        for(j=0;j<col+pad*2;j++)
        {
            if(i<pad || i>pad+lin-1 || j<pad || j>pad+col-1)
            {
                printf("0 ");
            }
            else
            {
                printf("%d ",vetor[i-pad][j-pad]);
            }
        }
        printf("\n");
    }

}

void print_mat(int **vetor, int lin, int col)
{
    int i, j;
    for(i=0; i<lin; i++)
    {
        for(j=0;j<col;j++)
        {
            printf("%d ", vetor[i][j]);
        }
        printf("\n");
    }
}

void libera_mat(int ***vetor, int lin)
{
    int i;
    for(i=0;i<lin;i++)
    {
        free(vetor[0][i]);
    }
    free(vetor[0]);
}

int main()
{
    int **mat, pad, l, c;
    do
    {
        scanf("%d",&c);
        scanf("%d",&l);
    }while(l<1 || c<1);
    cria_mat(&mat, l, c);
//    OK(1);
    fill_mat(mat, l, c);
//    OK(2);
    do
    {
        scanf("%d",&pad);
    }while(pad<1);
    padd_mat(mat, l, c, pad);
    printf("\n");
//    OK(3);
    print_mat(mat,l, c);
//    OK(4);
    libera_mat(&mat,l);
//    OK(5);
    return 0;
}


