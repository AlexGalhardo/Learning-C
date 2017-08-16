/*
Auto Corretor

Faça um programa que leia N palavras que corresponde a um dicionário. Logo após, leia uma palavra-chave que foi digitada com algum erro. Compare com as palavras do dicionário e imprima todas aquelas que se aproximam da palavra-chave.

Considere que as possíveis palavras tenham sempre o mesmo número de letras da palavra-chave e considere como sendo próximas aquelas em que mais de 70% das letras são iguais.

Obs: O dicionário estará em ordem alfabética e a sua saída, caso haja mais de uma palavra, também tem que estar em ordem alfabética.

Obs2: Caso nenhuma palavra parecida seja encontrada, não imprima nada na saída.
Exemplos de Entrada e Saída

Entrada:

10
Ave
Bolo
Casa
Escola
Fazenda
Gato
Hino
Rolo
Solo
Zebra
Xolo

Saída:

Bolo
Rolo
Solo

Entrada:

5
Aríete
Gato
Pássaro
Roedor
Zoológico
Zoolegifo

Saída:

Zoológico

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define QTD 200 // quantida de linhas dentro do dicionario
#define MAX 30 // quantidade de caracteres por palavra

int main(){
	int n, i, j, cont, k, tamanho;
	j= 0;
	k = 0;
	cont = 0;
	
	// definindo nossos vetores
	char palavras[QTD][MAX];
	char parecidas[QTD][MAX];
	char errada[MAX];
	
	scanf("%d", &n);
	
	// adicionando palavras no nosso dicionario
	for(i=0; i<n; i++){
		scanf("%s", palavras[i]);
	}
	
	// palavra digitada por último, que vai ser a errada
	scanf("%s", errada);
	
	// verificar o tamanho da palavra errada
	tamanho = strlen(errada);
	
	// comparando nossas palavras do dicionario com a palavra errada
	for(j=0; j<n; j++){
		if(tamanho == strlen(palavras[j])){
			for(i=0; i<tamanho; i++){
				if(errada[i] == palavras[j][i]){
					cont++;
				}
			}
			if(cont>=tamanho*0.70){
				strcpy(parecidas[k], palavras[j]);
				k++;
			}
			cont=0;
		}
	}
	
	for(j=0; j<k; j++){
		printf("%s\n", parecidas[j]);
	}
	
	return 0;
	
}
