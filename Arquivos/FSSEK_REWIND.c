#include <stdio.h>
#include <stdlib.h>

int main(){

	/* Em geral, o acesso a um arquivo é quase sempre feito
	de modo sequencial.
	Porém, a linguagem C permite realizar operações de leitura e escrita
	randômica usando a função fseek() 
	*/

	/* definição 

		int fseek(FILE *fp, long numbytes, int origem)
	
	Parâmetros:
		fp: o ponteiro para o arquivo
		numbytes: é o total de bytes a ser pulado a partir de "origem"
		origem: a partir de onde os numbytes serão contados.

	Retorno: ZERO em caso de sucesso 
	*/
	
	/* Os valores possíveis para o parâmetro "origem" são definidos por
	constante na biblioteca stdio.h e são:

		SEEK_SET:
			valor: 0
			significado: inicio do arquivo

		SEEK_CUR:
			valor: 1
			significado: ponto atual do arquivo

		SEEK_END:
			valor: 2
			significado: fim do arquivo
	*/




	// EXEMPLO 1

		// CRIANDO UM ARQUIVO COM AS DEVIDAS ESTRUTURAS
		struct cadastro{
			char nome[20];
			char rua[20];
			int idade;
		}

		FILE *f = fopen("arquivo.txt", "wb"); // WRITE BINARIO

		if(f == NULL){
			printf("ERRO na abertura\n");
			exit(1);
		}

		struct cadastro cad[4] = {"Ricardo", "Rua 1", 31,
								  "Carlos", "Rua 2", 28, 
								  "Ana", "Rua 3", 45,
								  "Bianca", "Rua 4", 32	
								};

		fwrite(cad, sizeof(struct cadastro), 4, f); // ESCREVA NO ARQUIVO

		fclose(f);

		/* ------------------------------------------*/
		// CRIANDO PROGRAMA USANDO FSEEK
		struct cadastro{
			char nome[20];
			char rua[20];
			int idade;
		}

		FILE *f = fopen("arquivo.txt", "rb"); // READ BINARIO
		if(f == NULL){
			printf("ERRO na abetura\n");
			exit(1);
		}

		struct cadastro c;
		fseek(f, 2*sizeof(struct cadastro), SEEK_SET); /* EXPLICAÇÃO: Usando fseek() e definindo 2*sizeof(~),
														nós pulamos 2 posições na struct cadastro, OU SEJA, 
														agora estamos na terceira posição!!! 
														Nesse caso, irá imprimir os dados de c[2] ou seja
														da Ana! 
														*/
		fread(&c, sizeof(struct cadastro), 1, f);
		printf("%s\n%s\n%d\n", c.nome, c.rua, c.idade); /*Resultado: Ana
																     Rua 3
																     45
														*/

		/* FUNÇÃO REWIND 

		Outra opção de movimentação dentro do arquivo é simplesmente
		retornar para o seu inicio usando a função rewind() 
		
		Forma geral:

				void rewind(FILE *fp);

		*/

		// EXEMPLO REWIND
		fseek(f, 2*sizeof(struct cadastro), SEEK_SET);
		rewind(f); /*   EXPLICAÇÃO: nesse caso, na linha de cima nós informamos que queremos
						pular 2 posições do vetor, estamos na posição 2 agora! PORÉM, com o rewind
						abaixo, nós voltamos para a posição 0!
						*/

		fclose(f);

	return 0;
}
