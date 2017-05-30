/*
Você, um jovem universitário mochileiro espacial, está viajando pelo sistema solar. Você está com fome e, como todo bom universitário, só tem dinheiro para comer no bandejão.
Portanto, seria muito útil você saber quanto tempo sua viagem até cada um dos planetas durará em termos dos dias de cada planeta, já que cada um tem uma rotação diferente. Assim, você poderia traçar a melhor rota para pegar um bandejão ainda aberto, seja na Terra, em Júpiter, em Vênus ou em Mercúrio (nos outros planetas você sabe que terá picadinho).
Para tanto, você fará um programa que receberá um inteiro contendo o total de segundos gasto na viagem e uma string contendo o nome do planeta de destino.
Então, seu programa deverá calcular quantos dias, horas, minutos e segundos são equivalentes à passagem desse tempo em segundos no planeta destino. Como um bom estudante, você fará uma função que receberá como referência todos esses parâmetros, e, calculado o resultado, irá imprimi-lo na main do seu programa.

Vamos arredondar o dia terrestre para 24 horas (você sabe que ele dura 23 horas e 56 minutos, mas os terráqueos gostam de simplificar).
O dia em Vênus equivale a 243 dias terrestres.
O dia em Mercúrio equivale a 58 dias e 16 horas terrestes.
O dia em Júpiter equivale a 9 horas e 56 minutos terrestres (Cuidado, esse vai ser um pouco mais difícil calcular!).
Obs: Todos os nomes de planetas serão fornecidos sem acentos e com a primeira letra maiúscula. Saída desejada:

%d segundos no planeta %s equivalem a:\n
%d dias, %d horas, %d minutos e %d segundos\n
Exemplo:
Entrada:
36181 Terra
Saída:
36181 segundos no planeta Terra equivalem a:
0 dias, 8 horas, 51 minutos e 1 segundos

Entrada:
36181 Jupiter
Saida:
36181 segundos no planeta Jupiter equivalem a:
1 dias, 0 horas, 7 minutos e 1 segundos

*/


#include <stdio.h>
#include <stdlib.h>

#define MAX 30

// Versão 2.0

void venus(int totalSegundos, int *dias, int *horas, int *minutos, int *segundos){
    *dias = totalSegundos / 20995200;
    *horas = (totalSegundos%20995200) / 3600;
    *minutos = (totalSegundos%3600) / 60;
    *segundos = (totalSegundos%3600)%60;
}

void jupiter(int totalSegundos, int *dias, int *horas, int *minutos, int *segundos){
    *dias = totalSegundos / 35760;
    *horas = (totalSegundos%35760) / 3600;
    *minutos = ((totalSegundos%35760) / 60;
    *segundos = (totalSegundos%3600)%60;
}

void mercurio(int totalSegundos, int *dias, int *horas, int *minutos, int *segundos){
    *dias = totalSegundos / 5068800;
    *horas = (totalSegundos%5068800)/3600;
    *minutos = (totalSegundos%3600) / 60;
    *segundos = (totalSegundos%3600)%60;
}

void terra(int totalSegundos, int *dias, int *horas, int *minutos, int *segundos){
    *dias = totalSegundos / 86400;
    *horas = (totalSegundos%86400)/3600;
    *minutos = (totalSegundos%3600) / 60;
    *segundos = (totalSegundos%3600)%60;
}

/*
O dia em Vênus equivale a 243 dias terrestres.= 20995200 segundos/ DIA TERRESTRE
O dia em Mercúrio equivale a 58 dias e 16 horas terrestes. 86400*58dias + 16*3600 = 5011200+57600= 5068800 segundos/DIA TERRESTRE
O dia em Júpiter equivale a 9 horas e 56 minutos terrestres = 1 DIA EM JUPITER = 32400 + 3360= 35760 segundos/DIA TERRESTRE
*/

int main(){
	int dias, horas, minutos, totalSegundos, segundos;
	char planeta[MAX];

	scanf("%d %s", &totalSegundos, planeta);

	if(*planeta == 'M'){
        mercurio(totalSegundos, &dias, &horas, &minutos, &segundos);
	}
	else if(*planeta == 'V'){
        venus(totalSegundos, &dias, &horas, &minutos, &segundos);
	}
	else if(*planeta == 'J'){
        jupiter(totalSegundos, &dias, &horas, &minutos, &segundos);
	}
	else if(*planeta == 'T'){
        terra(totalSegundos, &dias, &horas, &minutos, &segundos);
	}

    /* TESTE
    dias = totalSegundos / 5068800;
    horas = (totalSegundos%5068800) / 3600;
    minutos = (totalSegundos%3600) / 60;
    segundos = (totalSegundos%3600)%60;
    */

	printf("%d segundos no planeta %s equivalem a: \n", totalSegundos, planeta);
	printf("%d dias, %d horas, %d minutos e %d segundos", dias, horas, minutos, segundos);

	return 0;
}
