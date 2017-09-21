/*
Você deverá simular a IA de um jogador escolhendo qual o melhor ataque contra determinado oponente. Para isso, é preciso saber qual a relação entre os diversos tipos existentes no jogo, qual o dano e o tipo de cada ataque do jogador, e o tipo do inimigo.
As relações entre tipos são dadas por uma matriz MxM, na qual M é a quantidade de tipos existentes no jogo, e será fornecida ao usuário no início do programa. Cada elemento dessa matriz é um float que indica por qual valor o ataque de um tipo (linha) deve ser multiplicado quando usado em outro tipo (coluna).
Cada ataque possui duas informações: a primeira é seu poder de ataque (inteiro), e a segunda seu tipo (índice do tipo na tabela).
Você deverá ler os dados de cada ataque até encontrar o valor -1 na leitura do primeiro atributo*, totalizando N ataques.
Por fim, a última entrada é o tipo do inimigo. Esse é o tipo no qual o ataque será usado!
Seu objetivo é descobrir qual o melhor ataque a ser usado no inimigo do tipo fornecido como entrada e, então imprimir a seguinte mensagem:
"O melhor ataque possui indice X e dano Y\n", sendo X o índice (de 0 a N) do ataque, e Y o dano dado por tal ataque (imprima apenas as 2 primeiras casas decimais do dano).
*Não leia o segundo atributo caso encontre -1.
Exemplo:
Entrada:
3
1 2 1
2 1 0.5
1 1 2
2 0
2 1
2 2
-1
2
Saída:
O melhor ataque possui indice 2 e dano 4.00
*/

#include <stdio.h>
#include <stdlib.h>

int main (){

  int M,i,j,a,inimigo,indice;
  float **matriz,**atk=NULL,dano=0;

  scanf ("%d",&M);

  matriz = (float **)malloc(M*sizeof(float*));
  if(matriz == NULL){
  printf("Espaco insuficiente para alocar\n");
  exit(1);
  
  return 0;
 }



for (i=0;i<M;i++){
  matriz[i] = (float *)malloc(M*sizeof(float));
  
  if(matriz[i] == NULL){
    printf("Espaco insuficiente para alocar\n");
    exit(1);
  }
  
  for (j=0;j<M;j++){
    scanf ("%f",&matriz[i][j]);
   }
}


for (i=0;;i++){
  atk = (float **)realloc(atk, (i+1)*sizeof(float*));
  
  if(atk == NULL){
    printf("Espaco insuficiente para alocar\n");
    exit(1);
  }
  
  atk[i] = (float *)malloc(3*sizeof(float));
  
  if(atk[i] == NULL){
    printf("Espaco insuficiente para alocar\n");
    exit(1);
  }
  
  scanf ("%f",&atk[i][0]);

  if (atk[i][0]==-1){
    break;
  }
  
  scanf ("%f",&atk[i][1]);
  a=i;
}

scanf ("%d",&inimigo);

for (i=0;i<=a;i++){
  atk[i][2]=(float) atk[i][0]*matriz[(int)atk[i][1]][inimigo];
}

for (i=0;i<=a;i++){
  if (atk[i][2]>dano){
    dano = atk[i][2];
    indice = (int) atk[i][1];
   }
}

  printf ("O melhor ataque possui indice %d e dano %.2f",indice,dano);
  return 0;
}

