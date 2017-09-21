/*
Leitura de Arquivo de Texto - Letra de Música
Faça um programa em C que leia duas palavras (palavra1 e palavra2) em seguida leia um arquivo, chamado QuePaiseEste.txt, contendo uma letra de música. Faça uma busca nesse arquivo procurando as palavras palavra1 e palavra2. Para cada vez que encontrar a palavra conte sua ocorrência. No final do processamento do arquivo imprima a palavra1 e na tela quantas vezes a palavra1 aparece no texto, imprima também a palavra2 e quantas vezes a palavra2 aparece no texto.

Dica: use a seguinte linha para a impressão printf("%s %d %s %d\n", palavra1, nOcorrencia1, palavra2, nOcorrencia2);

Entrada e Saída:
Entrada:

pais morte (arquivo de texto QuePaiseEste.txt)
Saída:

pais 11 morte 1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30

int main(){

	char palavra1[MAX], palavra2[MAX];
	scanf("%s %s", palavra1, palavra2);

	FILE *arq;

	arq = fopen("QuePaiseEste.txt", "r");

	if(arq == NULL){
		printf("ERRO na abertura!\n");
		exit(1);
	}

	int nOcorrencia1=0, nOcorrencia2=0;

	// strings testes
	char teste1[MAX];

	do{
		fscanf(arq, "%s", teste1);

		int p1 = strcmp(teste1, palavra1);
		int p2 = strcmp(teste1, palavra2);

		if(p1 == 0){ // palavra 1 é iguail
			nOcorrencia1++;
		}
		else if(p2 == 0){ // palavra 2 e igual
			nOcorrencia2++;
		}

	}while(!feof(arq));

	printf("%s %d %s %d\n", palavra1, nOcorrencia1, palavra2, nOcorrencia2);

	fclose(arq);

	return 0;
}