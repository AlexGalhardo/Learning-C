// fonte: https://www.youtube.com/watch?v=7pWQWqGnVso&list=PLa75BYTPDNKZWYypgOFEsX3H2Mg-SzuLW&index=47
// INTRODUÇÃO STRINGS / VETORES DE CARACTERES
#include <stdio.h>
#include <string.h>

int main(){
	
	void concatenarStrings(char string1[], int t1, char string2[], int t2, char string3[]);
	
	char palavra1[] = {'p','a', 'o', ' '}; // quando eu defino todos os elementos dentro do vetor, eu não preciso definir qual é o tamanho dele
	char palavra2[] = {'m', 'o', 'r', 't', 'a', 'd', 'e', 'l', 'a'};
	char novaPalavra[13]; // quando eu defino um vetor, e não indico quais são seus elementos, eu preciso definir qual sera o tamanho desse vetor
	
	concatenarStrings(palavra1, 4, palavra2, 9, novaPalavra);
	
	int i;
	for(i=0; i<13; i++){
		printf("%c", novaPalavra[i]);
	}
	printf("\n");
	
	return 0;
}

void concatenarStrings(char string1[], int t1, char string2[], int t2, char string3[]){
	
	int i, j;
	
	for(i=0; i<t1; i++){
		string3[i] = string1[i];
	}
	
	// pegar o tamanho da string1 que é [4] +j para concatenar a segunda palavra na primeira
	for(j=0; j<t2; j++){
		string3[t1+j] = string2[j];
	}
	
}
