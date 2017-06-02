#include <stdio.h> // bilioteca standar input/output
#include <stdbool.h> // biblioteca variaveis booleanas

// aula 59 ~ DE ALUNO PARA ALUNO
// https://www.youtube.com/watch?v=Rn0ExQbBx2g&list=PLa75BYTPDNKZWYypgOFEsX3H2Mg-SzuLW&index=59

// função definida globalmente
struct dicionario{
	char palavra[20];
	char definicao[50];
};

// receber 2 palavras e comprar se as duas palavras são iguais
// função para retornar valor boleana, com 2 entradas constantes, que não poderam ser mudadas dentro da função
bool compararStrings(const char palavra1[], const char palavra2[]){
	
	int i=0;
	while(palavra1[i] == palavra2[i] 
			&& palavra1[i] != '\0' 
			&& palavra2[i] != '\0'){
		++i;
	}
	
	if(palavra1[i] == '\0' && palavra2[i] == '\0'){
		return true;
	}else{
		return false;
	}	
}

int procurarStrings(const struct dicionario lingua[], const char procurar[],
					const int numDePalavras){
	
	bool compararStrings(const char palavra1[], const char palavra2[]);
	
	int i=0;
	while(i< numDePalavras){
		
		if(compararStrings(procurar, lingua[i].palavra)){
			return i;
		}else{
			return ++i;
		}
	}
	return -1;
}

int main(){
	
	int procurarStrings(const struct dicionario lingua[], const char procurar[],
					const int numDePalavras);
	const int NUMERODEDEFINICOES = 7; // quando declaramos uma variavel constante, geralmente deixamos tudo em MAIUSCULO
	char palavra[20]; // vetor da palavra que o usuario vai digitar
	int resultadoPesquisa;
	
	const struct dicionario portugues[7] = {{"pao", "comida de farinha"},
											{"mortadela", "comida de carne"},
											{"feijao", "comida brasileira"},
											{"tropero", "tipo de feijao"},
											{"queijo", "de minas"},
											{"macarronada", "tipico de vo"},
											{"pizza", "tipico da Italia"}};
	printf("Digite uma palavra: ");
	scanf("%s", palavra);
	
	resultadoPesquisa = procurarStrings(portugues, palavra, NUMERODEDEFINICOES);
	
	if(resultadoPesquisa != -1){
		printf("%s\n", portugues[resultadoPesquisa].definicao);
	}else{
		printf("Palavra nao encontrada.");
	}
	
	
	return 0;
}
