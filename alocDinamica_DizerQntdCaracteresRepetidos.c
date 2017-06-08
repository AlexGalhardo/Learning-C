#include <stdio.h>
#define MAX 30


/* EXEMPLO

araraquara a
5

*/

int ocorrencias(char palavra[], char letra, int i) {
	if (palavra[i] == '\0'){
    return 0;
  }
	return (letra == palavra[i]) + ocorrencias(palavra, letra, i + 1);
}

int main() {
	char palavra[MAX];
	char letra;
	scanf("%s %c", palavra, &letra);
	printf("%d", ocorrencias(palavra, letra, 0));
}
