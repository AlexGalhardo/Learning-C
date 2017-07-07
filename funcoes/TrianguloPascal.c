#include <stdio.h>

int fatorial(int n);
int coeficiente(int n, int k);

int main(void)
{
	int n, k, n2, opcao;
	int numero;
	printf("Tartaglia 0.2\n\n");
	printf("O que você quer ver: \n");
	printf("\t1 -> Triângulo de Pascal até uma linha \"n\"\n");
	printf("\t2 -> Linha \"n\" do Triângulo\n\n");
	printf("\t0 -> Sair\n\n");

	while(opcao != 0){
		printf("Opção: ");
		scanf("%d",&opcao);
		if((opcao > 2) || (opcao < 0)){
			printf("%d não é opção\n",opcao);
			continue;
		}
		switch(opcao){
			case 1:	/* Triângulo de Pascal até uma linha "n" */
				printf("linha: ");
				scanf("%d",&n2);
				printf("\n");
				for(n=0;n<=n2;n++){
					for(k=0;k<=n;k++){
						printf("%d ",coeficiente(n,k));
					}
				printf("\n");
				}
				printf("\n");
			break;
			case 2:	/* Linha "n" do Triângulo */
				printf("linha: ");
				scanf("%d",&n);
				printf("\n");
				for(k=0;k<=n;k++){
					printf("%d ",coeficiente(n,k));
				}
				printf("\n\n");
			break;
			default:
				printf("Saindo...\n");
				printf("\a");
			break;
		}
	}
	return(0);
}

/* calcula o fatorial de um numero natural */
int fatorial(int n)
{
	int fat;
	int i;
	fat = 1;
	for(i=1;i<=n;i++) fat *= i;
	return(fat);
}

/* calcula o coeficiente binominal de 'n' sobre 'k' */
int coeficiente(int n, int k)
{
	int coef;
	coef = fatorial(n) / (fatorial(n-k) * fatorial(k));
	return(coef);
}
