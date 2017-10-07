
#ifndef BATALHA_H_INCLUDED
    #define BATALHA_H_INCLUDED

#include <windows.h>


#define SIM 0
#define NAO 1
#define CIMA 72
#define BAIXO 80
#define DIREITA 77
#define ESQUERDA 75
#define ESC 27
#define POSICAO 15
#define ENTER 13

enum CORES{ //FUNDO_COR (default = PRETO)
    AZUL=9, BRANCO=15, VERDE=10, VERMELHO=12, ROSA=13, AMARELO=14, CINZA=8,
    AZUL_VERMELHO=28, AZUL_AMARELO=30, AZUL_ROSA=29, BRANCO_PRETO=240, BRANCO_AZUL=249,
    BRANCO_VERMELHO=252, ROSA_PRETO=192, CINZA_VERMELHO=140, VERMELHO_PRETO=192 };

typedef enum CORES COR_CONSOLE;

void cortexto (int COR){
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),COR);
}

void xplod(){
  Beep(60,20);  // 523 hertz (C5) for 500 milliseconds
  Beep(59,20);
  Beep(58,20);
  Beep(57,20);
  Beep(55,20);
  Beep(50,20);
  Beep(49,20);
  Beep(45,20);
}

/*
Pra fazer teste de todas as cores disponíveis use este código:

#include <windows.h>
#include <stdio.h>

int main(){
    int x;
for(x=0;x<256;x++){
cortexto(x);
printf("Codigo %3d\t",x);
x++;
cortexto(x);
printf("Codigo %3d\t",x);
x++;
cortexto(x);
printf("Codigo %3d\t",x);
x++;
cortexto(x);
printf("Codigo %3d\n",x);
}
getch();
return 0;
}

*/

void janela(int x, int y){   //Configurar janela e buffer
COORD outbuff;
outbuff.X = x;
outbuff.Y = y;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleScreenBufferSize(hConsole, outbuff);
Sleep(130);
SMALL_RECT windowSize = {0, 0, x-1, y-1};
SetConsoleWindowInfo(hConsole, TRUE, &windowSize);
}


void acerto(){
    int x;
for (x=0;x<1;x++){
        system("color 83");
        system("color 8f");
        system("color 8d");
        system("color 84");
        system("color 85");
        system("color 8e");
        system("color 87");
        system("color 88");
        system("color 89");
        system("color 8b");
        system("color 8a");
        system("color 81");
                    }
                    return;
                    }



#endif // BATALHA_H_INCLUDED
