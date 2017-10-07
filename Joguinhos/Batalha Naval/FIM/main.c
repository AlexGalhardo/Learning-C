// Batalha Naval Basico
// Por Felipe Rodrigues e Rodrigo Oliveira
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include "batalha.h" //Com Macros para facilitar o entendimento do código e outros

#define W 176
#define I 176

/*Legenda:
1 Casa  = S = Submarino = 1
2 Casas = E = Encouraçado = 2
3 Casas = C = Cruzador = 3
4 Casas = H = Hidro Avião = 4
5 5asas = P = Porta Aviao = 2
*/


void player1();
void rank();
void player2();
int main();


char mapa[16][26]={              //Mapa que aparecerá pro jogador
                   {W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W},
                   {W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W},
                   {W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W},
                   {W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W},
                   {W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W},
                   {W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W},
                   {W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W},
                   {W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W},
                   {W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W},
                   {W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W},
                   {W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W},
                   {W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W},
                   {W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W},
                   {W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W},
                   {W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W},
                   {W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W}},

mapa2[16][26]={              //Mapa que aparecerá pro jogador2
                   {W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W},
                   {W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W},
                   {W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W},
                   {W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W},
                   {W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W},
                   {W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W},
                   {W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W},
                   {W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W},
                   {W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W},
                   {W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W},
                   {W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W},
                   {W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W},
                   {W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W},
                   {W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W},
                   {W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W},
                   {W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W}};

int  mapareveal[16][26]={                  //Mapa Revelado
                   {0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 1, 0, 0, 0, 0, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 3, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 4, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 0, 0, 0, 0, 0, 4, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}},

mapareveal2[16][26]={                  //Mapa Revelado 2
                   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 0, 0, 0, 0},
                   {0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 3, 0, 0, 0, 0, 2, 0, 0, 0, 0, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 3, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {4, 4, 4, 4, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 0, 0, 0, 4},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4},
                   {0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4},
                   {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

//Globais
char opt;
int linha_atual=0, coluna_atual=0,tiros,jacomecou=NAO, tecla,pontos=0,linha,coluna,
    linha_atual2=0, coluna_atual2=0,tiros2,pontos2=0,perde=0,doisp=NAO,

//Pontuações Player 1
    cont_sub=0, af_sub=0,cont_enc=0, af_enc=0, cont_cruz=0,
    af_cruz=0, cont_hidro=0, af_hidro=0, cont_pa=0, af_pa=0,

//Pontuações Player 2
    cont_sub2=0, af_sub2=0,cont_enc2=0, af_enc2=0, cont_cruz2=0,
    af_cruz2=0, cont_hidro2=0, af_hidro2=0, cont_pa2=0, af_pa2=0;


float tempo;

void reset(){ //Reseta o mapa,os tiros, a posição,etc
for (linha=0;linha<16;linha++)
              for(coluna=0;coluna<26;coluna++) mapa[linha][coluna]=W;
              linha_atual=0, coluna_atual=0;
              jacomecou=NAO;
for (linha=0;linha<16;linha++)
              for(coluna=0;coluna<26;coluna++) mapa2[linha][coluna]=W;
              linha_atual2=0, coluna_atual2=0;

    cont_sub=0, af_sub=0,cont_enc=0, af_enc=0, cont_cruz=0,
    af_cruz=0, cont_hidro=0, af_hidro=0, cont_pa=0, af_pa=0,

    cont_sub2=0, af_sub2=0,cont_enc2=0, af_enc2=0, cont_cruz2=0,
    af_cruz2=0, cont_hidro2=0, af_hidro2=0, cont_pa2=0, af_pa2=0;

return;
}

int start(){
    system("color a && title Batalha Naval");

for(;;){
    system("cls");

    puts("\n\n\n\n\n\n\n\n\n");
  cortexto(BRANCO);
  puts("      ____________________________________________________________________");
  puts("     |  ****************************************************************  |");
  puts("     |  ************************* BATALHA NAVAL ************************  |");
  puts("     |  **************************************************** Ver: 4.0 **  |");
  puts("     |                          [1] 1 Jogador                             |");
  puts("     |                          [2] 2 Jogadores                           |");
printf("     |                          [3] Instru%c%ces                            |\n",135,228);
printf("     |                          [4] Cr%cditos                              |\n",130);
printf("     |                          [5] Hist%crico                             |\n",224);
  puts("     |                          [6] Sair                                  |");
  puts("     |____________________________________________________________________|");
opt=getch();
system("cls");
    if(opt=='1' && jacomecou==SIM && doisp==NAO) return SIM; // Se ele já começou o jogo, Retorna pro game
    switch(opt){
            case '1':
            doisp=NAO;
                for(;;){
                    system("cls");
                    puts("\n\n\n\n\n\n\n\n\n\n");
                puts("      ____________________________________________________________________");
                puts("     |  ****************************************************************  |");
                puts("     |  ************************* BATALHA NAVAL ************************  |");
                puts("     |  **************************************************** Ver: 4.0 **  |");
              printf("     |                          [1] F%ccil                                 |\n",160);
              printf("     |                          [2] M%cdio                                 |\n",130);
              printf("     |                          [3] Dif%ccil                               |\n",161);
                puts("     |                          [4] Hardcore                              |");
                puts("     |____________________________________________________________________|");
                opt=getch();
                if (opt=='1') {tiros=125; reset(); jacomecou=SIM; break;}
                    else if (opt=='2') {tiros=100; reset(); jacomecou=SIM; break;}
                        else if (opt=='3') {tiros=75; reset(); jacomecou=SIM; break;}
                            else if (opt=='4') {tiros=50; reset(); jacomecou=SIM; break;}
            }
            system("cls");
            return SIM;

            case '4':
            puts("\n\n\n\n\n\n\n");
                  puts("       __________________________________________________________________");
                  puts("      |                                                                  |");
                printf("      |       Trabalho de L%cgica de Programa%c%co Feito por:               |\n",162,135,198);
                  puts("      |                                                                  |");
                  puts("      |  Felipe Rodrigues                       Rodrigo Oliveira         |");
                printf("      |      C%cdigo                           Sintaxe e Estrutura        |\n",162);
                  puts("      |    9695-6489                               9702-3427             |");
                  puts("      |                                                                  |");
                  puts("      |                          Agradecimentos:                         |");
                  puts("      |         Thalison Pelegrini ---------- Professor                  |");
                printf("      |        Inform%ctica Noturno --------- Apoio Moral lol             |\n",160);
                  puts("      |__________________________________________________________________|");
                puts("\n\n\n\n\n\n\n\n\n\n\t\tPressione qualquer tecla para voltar ao Menu");
                getch();
                system("cls");
                break;

            case '3':
                puts("\n\n\n       _________________________________________________________________");
                puts("      | **************************************************************  |");
              printf("      | **************************Instru%c%ces**************************  |\n",135,228);
                puts("      | **************************************************************  |");
                puts("      |                                                                 |");
              printf("      |     Batalha naval consiste em afundar todas as embarca%c%ces      |\n",135,228);
                puts("      |                     presentes no tabuleiro.                     |");
                puts("      |                                                                 |");
                puts("      |            O contador no canto superior da tela                 |");
                puts("      | mostra sempre a quantidade de tentativas restantes ao jogador.  |");
                puts("      |                                                                 |");
                puts("      |   O jogador tem um numero determinado de tentativas (tiros)     |");
                puts("      |   que varia de acordo com o grau de dificuldade escolhido.      |");
                puts("      |                                                                 |");
                puts("      |                                                                 |");
                puts("      |                                                                 |");
                puts("      |                                                                 |");
              printf("      |                                                                 |\n");
                puts("      |                                                                 |");
                puts("      | TECLAS DO JOGO                                                  |");
              printf("      | SETAS DO TECLADO -> Movimentar Mira                             |\n");
                puts("      | ENTER -> Selecionar / Atirar                                    |");
                puts("      | ESC -> Voltar ao Menu                                           |");
                puts("      |_________________________________________________________________|");
                puts("\n\n\n\t\tPressione qualquer Tecla para voltar ao Menu...");
                getch();
                system("cls");
                break;
            case '6':
                exit (SIM);
            case '2':
            if(doisp!=SIM){
                reset();
                tiros=100;
                tiros2=100;}
            doisp=SIM;
            system("color 81");
                player1();
            case '5':
            rank();
            default:
                continue;
           }//endsw
}//endfor

return NAO; //Se retornar 1, tem algum erro
} // endfunção

void rank(){
    system("cls");
    cortexto(BRANCO);
    FILE * arquivo=fopen("btnh.fer","a+"); //apontar a var pro arquivo; e abre o arquivo. Obs.: ".fer" = Felipe E Rodrigo s2 *-*
    char nome[100],c;
  puts(" ____________________________________________________________________");
  puts("|  ****************************************************************  |");
  puts("|  ************************* BATALHA NAVAL ************************  |");
  puts("|  **************************************************** Ver: 4.0 **  |");
if(opt!='5'){
printf("\n    Digite seu Nome:  ");
gets(nome);
//adicionar no arquivo...
if (doisp==SIM) fprintf(arquivo,"Modo: Dois Jogadores\n");
else fprintf(arquivo,"Modo: Um Jogador\n");
fprintf(arquivo,"Nome: %s\n",nome);
fprintf(arquivo,"Acertos: %d\n",pontos);
fprintf(arquivo,"Tempo:  %.2f Min.\n",(tempo/CLOCKS_PER_SEC)/60);
fprintf(arquivo,"-------------------\n");
fclose(arquivo);
}
for(;;){
system("cls");
    puts(" ____________________________________________________________________");
    puts("|  ****************************************************************  |");
    puts("|  ************************* BATALHA NAVAL ************************  |");
    puts("|  **************************************************** Ver: 4.0 **  |");
    puts("|                       Historico de Jogadores\n\n");

arquivo=fopen("btnh.fer","r");//n sei pq mas tive que reabrir como somente leitura pra fazer esse scan
while(!feof(arquivo)){//enquanto não atingir o final do arquivo
c=getc(arquivo);//captura cada caractere
printf("%c",c);// e imprime ele
}//endwhile
fclose(arquivo);
puts("\n\nPressione ENTER para voltar ao menu");
tecla=getch();
    system("cls");
    if (tecla==ENTER) main();

}//endfor
}//endfunc

void ganhou(){ //quando, QUANDO o jogador ganhar
system("cls");
system("color e");
    tempo=clock();
    for(;;){
    printf("                                \n");
    printf("\t\t     ____________________       \n");
    printf("\t\t   /|                    |\\    \n");
    printf("\t\t /  |                    | \\   \n");
    printf("\t\t |  |                    |  |   \n");
    printf("\t\t  \\ |                    | /   \n");
    printf("\t\t   \\|                    |/    \n"); // Graphics.h??? coisa de LOSER
    printf("\t\t    |                    |      \n");
    printf("\t\t     \\                  /      \n");
    printf("\t\t      \\                /       \n");
    printf("\t\t       \\              /        \n");
    printf("\t\t        |            |          \n");
    printf("\t\t         |          |           \n");
    printf("\t\t          |        |            \n");
    printf("\t\t           |      |             \n");
    printf("\t\t           |      |             \n");
    printf("\t\t      _____|      |_____        \n");
    if(perde==2)printf("\t\t     |     PLAYER 1     |       \n");
    if(perde==1)printf("\t\t     |     PLAYER 2     |       \n");
    else printf("\t\t     |                  |       \n");
    printf("\t\t     |   VOCE VENCEU!!  |       \n");
    printf("\t\t     | Tempo: %2.2f min. |       \n",(tempo/CLOCKS_PER_SEC)/60);
    printf("\t\t      ------------------        \n");
    puts("\nPressione ENTER...");
    tecla=getch();
    system("cls");
    reset();
    if (tecla==ENTER) rank();
    }
return;
}

void perdeu(){ //Quando o jogador perder (mais provável)
system("cls");
system("color 0F");
tempo=clock();
for(;;){
    printf("\n\n\t\t %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   \n",I,I,I,I,I,I,I,I,I,I,I,I,I,I,I,I,I,I,178,178);
    printf("\t\t %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   \n",I,I,I,I,I,I,I,I,I,I,I,I,I,I,I,I,I,I,178,178);
    printf("\t\t %c%c%c%c%cVOCE%c%c%c%c%c%c%c%c%c%c%c       \n",I,I,I,I,I,I,I,I,I,I,I,I,I,I,178,178);
    printf("\t\t %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   \n",I,I,I,I,I,I,I,I,I,I,I,I,I,I,I,I,I,I,178,178);
    printf("\t\t %c%c%c%c%c%c%c%cPERDEU%c%c%c%c%c%c       \n",I,I,I,I,I,I,I,I,I,I,I,I,178,178);
    printf("\t\t %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   \n",I,I,I,I,I,I,I,I,I,I,I,I,I,I,I,I,I,I,178,178);
    printf("\t\t %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   \n",I,I,I,I,I,I,I,I,I,I,I,I,I,I,I,I,I,I,178,178);
    printf("\t\t %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   \n",I,I,I,I,I,I,I,I,I,I,I,I,I,I,I,I,I,I,178,178);
    printf("\t\t %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   \n",I,I,I,I,I,I,I,I,I,I,I,I,I,I,I,I,I,I,178,178);
    printf("\t\t                   %c%c   \n",178,178);
    printf("\t\t                   %c%c   \n",178,178);
    printf("\t\t                   %c%c   \n",178,178);
    printf("\t\t                   %c%c   \n",178,178);
    printf("\t\t                   %c%c   \n",178,178);
    printf("\t\t                 ~~%c%c~~ \n",178,178);
    printf("\t\t               ~~~~%c%c~~~~\n",178,178);
      puts("\t\t                 ~~~~~~");
    printf("Pressione ENTER...");
    tecla=getch();
    system("cls");
    reset();
    if (tecla==ENTER) rank();
    }
}

void impmapa(){ //Função pra tela fixa
system("cls");
int linha,coluna;
puts("*******************************************************************************");
puts("******************************** BATALHA NAVAL ********************************");
puts("****************************************************************** Ver: 4.0 ***");
if(doisp==SIM)puts("                                    PLAYER 1");
printf(" Mapa:                                                 ");
if(tiros<15){cortexto(140); printf("  Tiros Restantes: %d\n\n",tiros); cortexto(129);}
else printf("   Tiros Restantes: %d\n\n",tiros);
              cortexto(137);
              for (linha=0;linha<16;linha++){
                  printf("\t\t\t   ");//manter no meio do prog
              for(coluna=0;coluna<26;coluna++) {
                  if ((linha == linha_atual)&&(coluna == coluna_atual)&&(tecla!=ENTER)){cortexto(156); printf("%c",POSICAO); cortexto(137);}
                    else printf("%c",mapa[linha][coluna]);
              }
                  printf("\n");
        } // fim for
cortexto(129);
//DEBUG
///printf("\nlinha_atual=%d  coluna_atual=%d tecla=%d pontos=%d \n",linha_atual,coluna_atual,tecla,pontos);


         return;
}//fim void

void impmapa2(){ //Função pra tela fixa
system("cls");
int linha,coluna;
puts("*******************************************************************************");
puts("******************************** BATALHA NAVAL ********************************");
puts("****************************************************************** Ver: 4.0 ***");
puts("                                    PLAYER 2");
printf(" Mapa:                                                 ");
if(tiros<15){cortexto(140); printf("   Tiros Restantes: %d\n\n",tiros2); cortexto(129);}
else printf("   Tiros Restantes: %d\n\n",tiros2);
              for (linha=0;linha<16;linha++){
                  printf("\t\t\t   ");//manter no meio do prog
              for(coluna=0;coluna<26;coluna++) {
                  if ((linha == linha_atual2)&&(coluna == coluna_atual2)&&(tecla!=ENTER)) {cortexto(128); printf("%c",POSICAO); cortexto(129);}
                    else printf("%c",mapa2[linha][coluna]);
              }
                  printf("\n");
        } // fim for

//DEBUG
//printf("\nlinha_atual2=%d  coluna_atual2=%d tecla=%d pontos2=%d \n",linha_atual2,coluna_atual2,tecla,pontos2);


         return;
}//fim void

void player1(){

for(;;){
for(;;){

        impmapa(); //Funçao Imprime o Mapa

        printf("\n Movimentos:\n"); // Imprime as direcoes
        printf("     %c          \t\t\t%c Submarino:     %d/1 |\tAfundou: %d/3 \n",30,4,cont_sub,af_sub);
        printf("   %c %c %c        \t\t\t%c Encoura%cado:   %d/2 |\tAfundou: %d/2 \n",17,197,16,16,135,cont_enc,af_enc);
        printf("     %c          \t\t\t%c Cruzador:      %d/3 |\tAfundou: %d/3 \n"  ,31,205,cont_cruz,af_cruz);
        printf("                 \t\t\t%c Hidro Avi%co:   %d/4 |\tAfundou: %d/4 \n",254,198,cont_hidro,af_hidro);
        printf("ENTER=Atirar\t  ESC=Menu   \t\t%c Porta Avi%co:   %d/5 |\tAfundou: %d/2 \n",17,198,cont_pa,af_pa);
        printf ("\n");
        tecla=getch();

system("cls");

              //Definindo As Direcionais
        if (tecla==CIMA) linha_atual--;
            else if (tecla==BAIXO) linha_atual++;
                else if (tecla==DIREITA) coluna_atual++;
                    else if (tecla==ESQUERDA) coluna_atual--;
                        else if (tecla==ENTER) {tiros--; break;}
                            else if (tecla==ESC) main();


//se atingir o limite do mapa (matriz) volta para a anterior
if(linha_atual<0)linha_atual++;
    else if(linha_atual>15)linha_atual--;
if(coluna_atual<0) coluna_atual++;
    else if (coluna_atual>25)coluna_atual--;

}


system("cls");

//Tem jeito (muito) mais simples de montar esse IF, mas pra evitar bugs, preferí assim
//O jeito mais simples é colocar: se(diferente de escondido){ja acertou}
if (mapa[linha_atual][coluna_atual]==4   || mapa[linha_atual][coluna_atual]==16 || mapa[linha_atual][coluna_atual]==205 ||
    mapa[linha_atual][coluna_atual]==254 || mapa[linha_atual][coluna_atual]==17 || mapa[linha_atual][coluna_atual]==126){
                                                 tiros++;
                                                 impmapa();
                                                 printf("J%c acertou essa %crea!",160,160);
                                                 getch();
                                                 }


//Esses Tambem tem como melhorar
                        else if(mapareveal[linha_atual][coluna_atual]==1){
                                                        mapa[linha_atual][coluna_atual]=4;
                                                        cont_sub++;
                                                        impmapa();
                                                        pontos++;
                                                        puts("Acertou um Submarino!");
                                                        acerto();
                                                        if (cont_sub==1){
                                                            cont_sub=0;
                                                            af_sub++;}
                                                        //chama a funçao colrida
                                                        if (af_sub==3)printf ("\nVoce afundou todos os submarinos!!!");
                                                        getch();//pausa

                                                    }

                        else if (mapareveal[linha_atual][coluna_atual]==2){
                                                        mapa[linha_atual][coluna_atual]=16;
                                                        cont_enc++;
                                                        impmapa();
                                                        pontos++;
                                                        puts("Acertou um Encouracado (2 casas)!");
                                                        acerto();
                                                        if (cont_enc==2)
                                                        {cont_enc=0;
                                                        af_enc++;}
                                                        if (af_enc==2)printf ("\nVoce afundou todos os Encouracados!!!");
                                                        getch();
                                                        }


                        else if (mapareveal[linha_atual][coluna_atual]==3){
                                                        mapa[linha_atual][coluna_atual]=205;
                                                        cont_cruz++;
														impmapa();
														pontos++;
                                                        puts("Acertou um Cruzador (3 casas)!");
                                                        acerto();
                                                        if (cont_cruz==3){
														cont_cruz=0;
                                                        af_cruz++;}
                                                        if (af_cruz==3) printf ("\nVoce afundou todos os Cruzadores!!!");
                                                        getch();

                                                        }


                        else if (mapareveal[linha_atual][coluna_atual]==4){
                                                        mapa[linha_atual][coluna_atual]=254;
                                                        cont_hidro++;
                                                        impmapa();
                                                        pontos++;
                                                        printf("Acertou um Hidro Avi%co (4 casas)!",198);
                                                        acerto();
                                                        if (cont_hidro==4){
                                                            cont_hidro=0;
                                                            af_hidro++;}
                                                        if (af_hidro==4) printf ("\nVoce afundou todos os Hidro Avioes");
                                                        getch();

                                                        }


                        else if (mapareveal[linha_atual][coluna_atual]==5){
                                                        mapa[linha_atual][coluna_atual]=17;
                                                        cont_pa++;
                                                        impmapa();
                                                        pontos++;
                                                        printf("Acertou um Porta Avi%ces (5 casas)!",228);
                                                        acerto();
                                                        if (cont_pa==5)
                                                        {cont_pa=0;
                                                        af_pa++;}
                                                        if (af_pa==2) printf ("\nVoce afundou todos os Porta Avioes");
                                                        getch();
                                                        }

                        else if (mapareveal[linha_atual][coluna_atual] == 0){
                                                        mapa[linha_atual][coluna_atual]=126;
                                                        impmapa();
                                                        printf("Acertou na %cgua...",160);
                                                        getch();
                        }

            if(pontos2==44 || tiros2<=0){perde=1; ganhou();}
            player2();
}//endfor
}

void player2(){

for(;;){
for(;;){
        impmapa2(); //Funçao Imprime o Mapa

        printf("\n Movimentos:\n"); // Imprime as direcoes
        printf("     %c          \t\t\t%c Submarino:     %d/1 |\tAfundou: %d/3 \n",30,4,cont_sub2,af_sub2);
        printf("   %c %c %c        \t\t\t%c Encoura%cado:   %d/2 |\tAfundou: %d/2 \n",17,197,16,16,135,cont_enc2,af_enc2);
        printf("     %c          \t\t\t%c Cruzador:      %d/3 |\tAfundou: %d/3 \n"  ,31,205,cont_cruz2,af_cruz2);
        printf("                 \t\t\t%c Hidro Avi%co:   %d/4 |\tAfundou: %d/4 \n",254,198,cont_hidro2,af_hidro2);
        printf("ENTER=Atirar\t  ESC=Menu   \t\t%c Porta Avi%co:   %d/5 |\tAfundou: %d/2 \n",17,198,cont_pa2,af_pa2);
        printf ("\n");
        tecla=getch();

system("cls");

              //Definindo As Direcionais
        if (tecla==CIMA) linha_atual2--;
            else if (tecla==BAIXO) linha_atual2++;
                else if (tecla==DIREITA) coluna_atual2++;
                    else if (tecla==ESQUERDA) coluna_atual2--;
                        else if (tecla==ENTER) {tiros2--; break;}
                            else if (tecla==ESC) main();


//se atingir o limite do mapa (matriz) volta para a anterior
if(linha_atual2<0)linha_atual2++;
    else if(linha_atual2>15)linha_atual2--;
if(coluna_atual2<0) coluna_atual2++;
    else if (coluna_atual2>25)coluna_atual2--;

}


system("cls");

//Tem jeito (muito) mais simples de montar esse IF, mas pra evitar bugs, preferí assim
//O jeito mais simples é colocar: se(diferente de escondido){ja acertou}
if (mapa2[linha_atual2][coluna_atual2]==4   || mapa2[linha_atual2][coluna_atual2]==16 || mapa2[linha_atual2][coluna_atual2]==205 ||
    mapa2[linha_atual2][coluna_atual2]==254 || mapa2[linha_atual2][coluna_atual2]==17 || mapa2[linha_atual2][coluna_atual2]==126){
                                                 tiros2++;
                                                 impmapa2();
                                                 printf("J%c acertou essa %crea!",160,160);
                                                 getch();
                                                 }


//Esses Tambem tem como melhorar
                        else if(mapareveal2[linha_atual2][coluna_atual2]==1){
                                                        mapa2[linha_atual][coluna_atual]=4;
                                                        cont_sub2++;
                                                        impmapa2();
                                                        pontos2++;
                                                        puts("Acertou um Submarino!");
                                                        acerto();//chama a funçao colrida
                                                        if (cont_sub2==1){
                                                            cont_sub2=0;
                                                            af_sub2++;}
                                                        //chama a funçao colrida
                                                        if (af_sub2==3)printf ("\nVoce afundou todos os submarinos!!!");
                                                        getch();//pausa
                                                    }
                        else if (mapareveal2[linha_atual2][coluna_atual2]==2){
                                                        mapa2[linha_atual2][coluna_atual2]=16;
                                                        cont_enc2++;
                                                        impmapa2();
                                                        pontos2++;
                                                        printf("Acertou um Encoura%cado (2 casas)!",135);
                                                        acerto();
                                                        if (cont_enc2==2){
                                                            cont_enc2=0;
                                                            af_enc2++;}
                                                        if (af_enc2==2)printf ("\nVoce afundou todos os Encouracados!!!");
                                                        getch();
                        }
                        else if (mapareveal2[linha_atual2][coluna_atual2]==3){
                                                        mapa2[linha_atual2][coluna_atual2]=205;
                                                        cont_cruz2++;
                                                        impmapa2();
                                                        pontos++;
                                                        puts("Acertou um Cruzador (3 casas)!");
                                                        acerto();
                                                        if (cont_cruz2==3){
														cont_cruz2=0;
                                                        af_cruz2++;}
                                                        if (af_cruz2==3) printf ("\nVoce afundou todos os Cruzadores!!!");
                                                        getch();
                        }
                        else if (mapareveal2[linha_atual2][coluna_atual2]==4){
                                                        mapa2[linha_atual2][coluna_atual2]=254;
                                                        cont_hidro2++;
                                                        impmapa2();
                                                        pontos2++;
                                                        printf("Acertou um Hidro Avi%co (4 casas)!",198);
                                                        acerto();
                                                        if (cont_hidro2==4){
                                                            cont_hidro2=0;
                                                            af_hidro2++;}
                                                        if (af_hidro2==4) printf ("\nVoce afundou todos os Hidro Avioes");
                                                        getch();
                        }
                        else if (mapareveal2[linha_atual2][coluna_atual2]==5){
                                                        mapa2[linha_atual2][coluna_atual2]=17;
                                                        cont_pa2++;
                                                        impmapa2();
                                                        pontos2++;
                                                        printf("Acertou um Porta Avi%ces (5 casas)!",228);
                                                        if (cont_pa2==5)
                                                        {cont_pa2=0;
                                                        af_pa2++;}
                                                        if (af_pa2==2) printf ("\nVoce afundou todos os Porta Avioes");
                                                        acerto();
                                                        getch();
                        }
                        else if (mapareveal2[linha_atual2][coluna_atual2] == 0){
                                                        mapa2[linha_atual2][coluna_atual2]=126;
                                                        impmapa2();
                                                        printf("Acertou na %cgua...",160);
                                                        getch();
                        }

            if(pontos2==44 || tiros2<=0){perde=2; ganhou();}
            player1();
}//endfor

}

int main(void){
    janela(80,33);//Regular a janela
start(); // chama a função de inicio do game
system("color 81");
for(;;){
for(;;){
        impmapa(); //Funçao Imprime o Mapa

       printf("\n Movimentos:\n"); // Imprime as direcoes
        printf("     %c          \t\t\t%c Submarino:     %d/1 |\tAfundou: %d/3 \n",30,4,cont_sub,af_sub);
        printf("   %c %c %c        \t\t\t%c Encoura%cado:   %d/2 |\tAfundou: %d/2 \n",17,197,16,16,135,cont_enc,af_enc);
        printf("     %c          \t\t\t%c Cruzador:      %d/3 |\tAfundou: %d/3 \n"  ,31,205,cont_cruz,af_cruz);
        printf("                 \t\t\t%c Hidro Avi%co:   %d/4 |\tAfundou: %d/4 \n",254,198,cont_hidro,af_hidro);
        printf("ENTER=Atirar\t  ESC=Menu   \t\t%c Porta Avi%co:   %d/5 |\tAfundou: %d/2 \n",17,198,cont_pa,af_pa);
        printf ("\n");
        tecla=getch();

system("cls");

              //Definindo As Direcionais
        if (tecla==CIMA) linha_atual--;
            else if (tecla==BAIXO) linha_atual++;
                else if (tecla==DIREITA) coluna_atual++;
                    else if (tecla==ESQUERDA) coluna_atual--;
                        else if (tecla==ENTER) {tiros--; break;}
                            else if (tecla==ESC) main();

//se atingir o limite do mapa (matriz) volta para a anterior
if(linha_atual<0)linha_atual++;
    else if(linha_atual>15)linha_atual--;
if(coluna_atual<0) coluna_atual++;
    else if (coluna_atual>25)coluna_atual--;

}


system("cls");

//Tem jeito (muito) mais simples de montar esse IF, mas pra evitar bugs, preferí assim
//O jeito mais simples é colocar: se(diferente de escondido){ja acertou}
if (mapa[linha_atual][coluna_atual]==4   || mapa[linha_atual][coluna_atual]==16 || mapa[linha_atual][coluna_atual]==205 ||
    mapa[linha_atual][coluna_atual]==254 || mapa[linha_atual][coluna_atual]==17 || mapa[linha_atual][coluna_atual]==126){
                                                 tiros++;
                                                 impmapa();
                                                 printf("J%c acertou essa %crea!",160,160);
                                                 getch();
                                                 }


//Esses Tambem tem como melhorar
                        else if(mapareveal[linha_atual][coluna_atual]==1){
                                                        mapa[linha_atual][coluna_atual]=4;
                                                        cont_sub++;
                                                        impmapa();
                                                        pontos++;
                                                        puts("Acertou um Submarino!");
                                                        acerto();
                                                        if (cont_sub==1){
                                                            cont_sub=0;
                                                            af_sub++;}
                                                        //chama a funçao colrida
                                                        if (af_sub==3)printf ("\nVoce afundou todos os submarinos!!!");
                                                        getch();//pausa

                                                    }

                        else if (mapareveal[linha_atual][coluna_atual]==2){
                                                        mapa[linha_atual][coluna_atual]=16;
                                                        cont_enc++;
                                                        impmapa();
                                                        pontos++;
                                                        puts("Acertou um Encouracado (2 casas)!");
                                                        acerto();
                                                        if (cont_enc==2)
                                                        {cont_enc=0;
                                                        af_enc++;}
                                                        if (af_enc==2)printf ("\nVoce afundou todos os Encouracados!!!");
                                                        getch();
                                                        }


                        else if (mapareveal[linha_atual][coluna_atual]==3){
                                                        mapa[linha_atual][coluna_atual]=205;
                                                        cont_cruz++;
														impmapa();
														pontos++;
                                                        puts("Acertou um Cruzador (3 casas)!");
                                                        acerto();
                                                        if (cont_cruz==3){
														cont_cruz=0;
                                                        af_cruz++;}
                                                        if (af_cruz==3) printf ("\nVoce afundou todos os Cruzadores!!!");
                                                        getch();

                                                        }


                        else if (mapareveal[linha_atual][coluna_atual]==4){
                                                        mapa[linha_atual][coluna_atual]=254;
                                                        cont_hidro++;
                                                        impmapa();
                                                        pontos++;
                                                        printf("Acertou um Hidro Avi%co (4 casas)!",198);
                                                        acerto();
                                                        if (cont_hidro==4){
                                                            cont_hidro=0;
                                                            af_hidro++;}
                                                        if (af_hidro==4) printf ("\nVoce afundou todos os Hidro Avioes");
                                                        getch();

                                                        }


                        else if (mapareveal[linha_atual][coluna_atual]==5){
                                                        mapa[linha_atual][coluna_atual]=17;
                                                        cont_pa++;
                                                        impmapa();
                                                        pontos++;
                                                        printf("Acertou um Porta Avi%ces (5 casas)!",228);
                                                        acerto();
                                                        if (cont_pa==5)
                                                        {cont_pa=0;
                                                        af_pa++;}
                                                        if (af_pa==2) printf ("\nVoce afundou todos os Porta Avioes");
                                                        getch();
                                                        }

                        else if (mapareveal[linha_atual][coluna_atual] == 0){
                                                        mapa[linha_atual][coluna_atual]=126;
                                                        impmapa();
                                                        printf("Acertou na %cgua...",160);
                                                        getch();
                        }

            if(pontos==44)ganhou();
            if(tiros<=0)perdeu();
}//endfor

return 0;
}
