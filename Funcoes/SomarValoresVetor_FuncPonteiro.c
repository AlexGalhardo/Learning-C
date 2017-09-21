#include <stdio.h>

int somarVetor(int vetor[], const int n){
	
	int soma = 0;
	int *ponteiro;
	int *const finalVetor = vetor +n; // vai apontar para o ultimo membro do meu vetor

	// nesse for, é importante ressaltar que estamos comparando o endereço de memória
	for(ponteiro = vetor; ponteiro < finalVetor; ponteiro++){
		soma += *ponteiro;
	}
	
	return soma;
}


int main(){
	
	int somarVetor(int vetor[], const int n);
	int vetor[10] = {5,5, 5, 5, 5, 5, 5, 5, 10, 10};
	
	printf("A soma dos membros do vetor = %d", somarVetor(vetor, 10));
	
	return 0;
}
