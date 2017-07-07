// TABELA ASCI2 COMPLETA: http://www.thortech.ind.br/img/products/505d181f53.pdf
/* EXPLICAÇÃO
char codigo = 'A';

variavel codigo é um caractere A.

Se você usar: printf ("%c", codigo);

Ele vai imprimir 'A'

Mas, se você usar: printf ("%d", codigo);

Ele vai imprimir o valor numérico de 'A', o codigo ascii.


Agora, dado um inteiro, se você quiser saber qual é seu caractere ascii correspondente é só fazer:

main(){

   int i;
   char c;

   i='109';
   c=i;

   printf("%c",c);

}


*/

/*
Simulado P2 - 2) Encriptando palavras

Neste exercício você deverá receber uma letra e uma palavra (com no máximo 30 caracteres) como entrada.
A palavra conterá apenas letras minúsculas, e a letra fornecida também será minúscula.
Você deverá fazer uma função que fará o seguinte algoritmo sobre a palavra:
Para cada vez que a letra lida for encontrada na palavra, a letra deverá ser substituída pelo valor decimal em ASC 2 da letra somado ao índice da letra na palavra.
A nova letra deverá estar no intervalo de 'a' e 'z'.
Para essa função, deverá ser passada, por referência, uma variável que armazenará a quantidade de letras que foram trocadas pelo algoritmo.
Por fim, seu programa deverá imprimir a quantidade de trocas, a nova palavra e a palavra original, todos separados por quebra de linha.

Exemplo:
Entrada:
a
banana
Saída:
Numero de trocas: 3
Nova palavra: bbndnf
Palavra original: banana

*/

// letra a para letra z --> 141 a 172 na tavela ASC2 
// indice == index

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30

void converter(char *vogal, char palavra[MAX], int *contador, char new[MAX]){
	int i, asci;
	char letra;
	
	/*
	for(j=0; j < strlen(palavra); j++){
		*new[j] = palavra[j];
	}
	new[j] = '\0';
	*/
	
	
	for(i=0; i < strlen(palavra); i++){
		if(palavra[i] == *vogal){
			asci = palavra[i]; // pegar valor ASCI2 do respectivo index da palavra original
			letra = asci; // transformar ASCI2 em caracter
			new[i] = letra + i; 
			*contador+=1;
		}
	}
	
}

int main(){
	char palavra[MAX], new[MAX];
	char vogal;
	int contador, j;
	contador = 0;
	
	scanf("%c", &vogal);
	scanf("%s", palavra);
	
	// colocando em minusculo
	/*
	vogal = tolower(vogal);
	for(i=0; i != '\0'; i++){
		palavra[i] = tolower(palavra[i]);
	}
	*/
	
	// copiando palavra original no vetor da nova palavra
	for(j=0; j < strlen(palavra); j++){
		new[j] = palavra[j];
	}
	
	converter(&vogal, palavra, &contador, new);
	
	printf("Numero de trocas: %d", contador);
	printf("\nNova palavra: %s", new);
	printf("\nPalavra original: %s", palavra);
	
	return 0;
}
