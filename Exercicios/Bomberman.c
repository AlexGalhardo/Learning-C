/*
Bomberman é um personagem que vive em uma matriz MxN. Cada célula pode conter uma bomba ou não ter nada. Uma bomba pode ser plantada em qualquer posição da matriz, mas ela só explode após 3 segundos. Quando uma bomba é detonada, além de destruir a célula em que estava, ela também destrói suas quatro células vizinhas, ou seja, se a bomba estiver na posição (i,j), as células vizinhas destruídas são (i,j±1) e (i±1,j). Se a posição vizinha conter uma outra bomba, a bomba vizinha não é detonada, apenas destruída, ou seja, não há explosões em cadeia.

Bomberman é imune a bombas e pode se mover livremente pela matriz. A seguir estão as ações que ele realiza:

1 - Ele planta bombas em algumas posições iniciais da matriz;
2 - Após um segundo, ele não faz nada;
3 - Após um segundo, ele coloca bombas em todas as posições da matriz que estão vazias, enchendo a matriz inteira de bombas;
4 - Após um segundo, Bomberman observa as explosões das bombas plantadas 3 segundos antes.
5 - Os passos 3 e 4 são repetidos infinitamente
Obs: Nos passos 1 e 3, as bombas são sempre plantadas simultaneamente, portanto elas serão todas detonadas ao mesmo tempo 3 segundos mais tarde.

O que seu programa deverá fazer é, dada uma matriz inicial com bombas plantadas (Passo 1), determine o estado da matriz após T segundos.

Formato da Entrada
A primeira linha da entrada contém 3 inteiros, respectivamente M,N e T. Depois haverão outras M linhas com N caracteres, que representam as posições da matriz inicial. O caracter '.' representa uma célula vazia e '0'(zero) representa uma posição que contém uma bomba.

Obs2: Seu programa deve ter uma função separada que recebe a matriz de entrada como parâmetro e a modifica.

Obs3: 0 < M,N < 200

Exemplos de Entrada e Saída
Entrada:

6 7 3
.......
...0...
....0..
.......
00.....
00.....
Saída:

000.000
00...00
000...0
..00.00
...0000
...0000
Passo a Passo do exemplo
Estado inicial (t=0):

.......
...0...
....0..
.......
00.....
00.....
Bomberman não faz nada em t=1

.......
...0...
....0..
.......
00.....
00.....
Em t=2, Bomberman planta bombas em todas as células que estavam vazias

0000000
0000000
0000000
0000000
0000000
0000000
Todas as bombas plantadas 3 segundos atrás (t=0), foram detonadas

000.000
00...00
000...0
..00.00
...0000
...0000
*/



#include<stdio.h>

void leMat(int m,int n,char mat[m][n],int tB[m][n])
{
	int a,b;
	for(a=0;a<m;a++)
	{
		for(b=0;b<n;b++)
		{
			scanf(" %c",&mat[a][b]);
			
		}
	}
	for(a=0;a<m;a++)
	{
		for(b=0;b<n;b++)
		{
			if(mat[a][b]=='0')
			{
				tB[a][b]=3;
				
			}
			else
			{
				
				tB[a][b]=-1;
			}
			
		}
	}
	
}


void explode(int l,int c,int m,int n, char mat[m][n], int tB[m][n])
{
	mat[l][c]='.';
	tB[l][c]=-1;
	if(c+1<n)
	{
		mat[l][c+1]='.';
		if(tB[l][c+1]!=1)
		{
			tB[l][c+1]=-1;
		}
	}
	if(c-1>=0)
	{
		mat[l][c-1]='.';
		if(tB[l][c-1]!=1)
		{
			tB[l][c-1]=-1;
		}
	}
	if(l+1<m)
	{
		mat[l+1][c]='.';
		if(tB[l+1][c]!=1)
		{
			tB[l+1][c]=-1;
		}
	}
	if(l-1>=0)
	{
		mat[l-1][c]='.';
		if(tB[l-1][c]!=1)
		{
			tB[l-1][c]=-1;
		}
	}
}
void preBomba(int m,int n, char mat[m][n], int tB[m][n])
{
	int a,b;
	for(a=0;a<m;a++)
	{
		for(b=0;b<n;b++)
		{
			if(mat[a][b]!='0')
			{
				mat[a][b]='0';
				tB[a][b]=3;
			}
		}
	}
}
void diminuiSec(int m,int n, char mat[m][n], int tB[m][n])
{
	int a,b;
	for(a=0;a<m;a++)
	{
		for(b=0;b<n;b++)
		{
				tB[a][b]--;
				if(tB[a][b]==0)
				{
					explode(a,b,m,n,mat,tB);
				}
		}
	}
	
	
	
}
void passaSegundos(int m,int n, int t, char mat[m][n], int tB[m][n])
{
	int a,preenche=2;
	for(a=1;a<=t;a++)
	{
		diminuiSec(m,n,mat,tB);
		if(a==preenche)
		{
			preenche+=2;
			preBomba(m,n,mat,tB);
		}
		
		
		
	}
}

int main()
{
	int m,n,t;
	scanf("%d%d%d",&m,&n,&t);
	int tempoB[m][n];
	char mat[m][n];
	leMat(m,n,mat,tempoB);
	int a,b;
	
	passaSegundos(m,n,t,mat,tempoB);
	
	for(a=0;a<m;a++)
	{
		for(b=0;b<n;b++)
		{
			printf("%c",mat[a][b]);
		}
		printf("\n");
	}
	return 0;
}
