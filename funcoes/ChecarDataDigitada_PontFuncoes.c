/*
Desenvolva um programa que utilize os parˆametros argv e argc. Logo, o programa
principal (main) dever´a receber o dia, mˆes e ano. Utilizando fun¸c˜oes, o programa
dever´a verificar se os valores fornecidos formam uma data v´alida. Se for v´alida, o programa
principal imprime a data como ilustrado a seguir:
Entrada: 01/11/2011
Sa´ıda: 01 de novembro de 2011
*/


#include <stdio.h>
#include <stdlib.h>

int checkAno(int ano){
    if(ano > 0 && ano < 10000){
        return 1;
    }
    return 0;
}

int checkaAnoB(int ano){
    if(ano % 400 == 0){
        return 1;
    }else if((ano %4==0) && (ano%100 !=0)){
        return 1;
    }
    return 0;
}

int checkMes(int mes){
    if(mes >0 && mes < 13){
        return 1;
    }
    return 0;
}

int diasDoMes(int mes, int ano){
    if(checkMes(mes)){
        if(mes== 1 || mes == 3 || mes 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
            return 31;
        }
        else if(mes==2){ // se o mes for 2 == FEVEREIRO
            if(checkAnoB(ano)){ // verifica se é um ano BISSEXTO, se for, possui 1 dia a mais no mes de FEVEREIRO!
                return 29; // tem 29 dias
            }else{
                return 28;
            }
        }
        else if(mes == 4 || mes == 6 || mes == 9 || mes == 1){
            return 30;
        }
    }
    return 0;
}

void nomeMes(int mes){
    if(checkMes(mes)){
        if(mes ==1){
            printf("de Janeiro de ");
        }
        else if(mes==2){
            printf("de Fevereiro de ");
        }
        else if(mes==3){
            printf("de Março de ");
        }
        else if(mes==4){
            printf("de Abril de ");
        }
        else if(mes==5){
            printf("de Maio de ");
        }
        else if(mes==6){
            printf("de Junho de ");
        }
        else if(mes==7){
            printf("de Julho de ");
        }
        else if(mes==8){
            printf("de Agosto de ");
        }
        else if(mes==9){
            printf("de Setembro de ");
        }
        else if(mes==10){
            printf("de Outubro de ");
        }
        else if(mes==11){
            printf("de Novembro de ");
        }
        else if(mes==12){
            printf("de Dezembro de ");
        }
    }
}

int validateDia(int dia, int mes, int ano){
    if(checkAno(ano)){
        if(checkMes(mes)){
            if(dia>0 && dia <= diaDoMes(mes, ano)){
                return 1;
            }
        }
    }
    return 0;
}

int main(int argc, const char * argv[]){
    int d, m, a;
    d = atoi(argv[1]);
    m = atoi(argv[2]);
    a = atoi(argv[3]);
    if(validateDia(d, m, a)){
        printf("Entrada: %d/%d/%d\n", d, m, a);
        printf("Saida: %d", d);
        nomeMes(m);
        printf("%d\n", a);
    }else{
        printf("A data %d do %d de %d eh invalida\n", d, m, a);
    }

    return 0;
}
