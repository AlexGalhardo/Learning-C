#include <stdio.h>

struct lista{
	int valor;
	struct lista *proximo;
}; // definição da nossa lista 

struct lista *procurarValor(struct lista *pLista, int valor){
		
	while(pLista != (struct lista *)0){ // enquanto o valor apontado não for nulo, execute o laço
		if(pLista->valor == valor){ // se o valor apontado for igual o valor digitado pelo usuario, retorne esse valor
			return(pLista);
		}else{
			pLista = pLista->proximo; // senão, continue procurando proximos valores nas proximas structs
		}
	}
	return(struct lista *) 0; // caso nada seja encontrado, retorne 0
	
}

int main(){
	
	struct lista *procurarValor(struct lista *pLista, int valor); // definir nossa função de procurar valor na struct
	struct lista m1, m2, m3; // criando nossas 3 listas 
	struct lista *resultado, *gancho = &m1;
	
	m1.valor = 5; // valor de m1 
	m2.valor = 10; // valor de m2
	m3.valor = 15; // valor de m3
	
	m1.proximo = &m2; // m1.proximo aponta para a lista m2
	m2.proximo = &m3; // m2.proximo aponta para a lista m3
	m3.proximo = 0; // m3.proximo aponta para 0
	
	int valor;
	
	printf("Digite valor da pesquisa: \n");
	scanf("%d", &valor);
	
	resultado = procurarValor(gancho, valor); // variavel inteira resultado recebe o valor retornado pela função
	
	if(resultado == (struct lista*)0){ // verificar o valor da variavel resultado
		printf("Valor nao encontrado.\n");
	}else{
		printf("Valor %d encontrado.\n", resultado->valor);
	}
	
	return 0;
}
