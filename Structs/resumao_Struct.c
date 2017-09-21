#include <stdio.h>
#include <string.h>
#define MAX 30

int main(){

	struct ALUNO {
		char numUSP[10];
		char nome[MAX];
		char sexo;
		float renda;
	};

	// para declarar uma struct
	struct ALUNO alex;

	// parar criar uma instancia de si mesmo, deve ser ponteiro.

	struct CARRO{
		char modelo[30];
		float litros;
		struct CARRO *ford; // correto
		struct CARRO ford; // ERRO
	};

	// criando struct tipo registro em C
	struct PESSOA{
		char nome[30];
		float peso;
		int cpf;
	}pessoa1, pessoa2;
	
	//iniciar um elemento de uma variavel
	strcpy(pessoa1.nome, "Alex");
	strycpy(pessoa1.peso, 60);
	strcpy(pessoa1.cpf, 123123123);

	strcpy(pessoa2.nome, "Joao");
	strycpy(pessoa2.peso, 70);
	strycpy(pessoa2.cpf, 345345);

	// como iniciar um elemento de uma variável do tipo struct
	// exemplo 1
	typedef struct{
		float re;
		float im;
	}complexo;

	complexo a[2][2] = {
		{{1, 2}, {2,3}}, // primeira linha
		{{3, 4}, {5, 6}} // segunda linha
	};

	// exemplo 2
	struct fruta{
		char nome[20];
		char caloria;
	};

	struct fruta banana = {"banana", 100}, maca ={0};	

	// ---------- ESTRUTURA DENTRO DE ESTRUTURA   ---------- //
	// criando corpo da estrutura
	struct tipo_endereco{
		char rua[50];
		int numero;
		char bairro[20];
		char cidade[30];
		char sigla_estado[3];
		char CEP[10];
	};

	// criando outro corpo de estruta com uma estrutura dentro
	struct ficha_pessoal{
		char nome[50];
		long int telefone;
		struct tipo_endereco endereco;
	};

	typedef struct{
		int dia, mes, ano;
	}REGDATA;
	typedef struct{
		char nome[20];
		REGDATA nasc, contrato;
		float salario;
	}REGF;

	REGF dados[100];

	dados[0].nasc.dia = 1;
	dados[0].nasc.mes = 12;
	dados[0].nasc.ano = 1970;

	dados[0].contrato.dia = 5;
	dados[0].contrato.mes = 8;
	dados[0].contrato.ano = 2001;

	// -------- VETOR DE REGISTROS --------- //
	typedef struct{
		char numUSP[10];
		char nome[30];
		char sexo;		
		float renda;
	}ALUNO; // definindo aqui embaixo o nome da estrutura

	ALUNO aluno[42]; // definindo um tipo de estrutura do tipo ALUNO chamada aluno

	// editando os dados do aluno na posição 0 do vetor
	aluno[0].numUSP = "123123";
	aluno[0].nome = "alex";
	aluno[0].sexo = 'm';
	aluno[0].renda = 2000;

	// editando os dados do aluno na posição 10 do vetor
	aluno[10].numUSP = "456456";
	aluno[10].nome = "marcia";
	aluno[10].sexo = 'f';
	aluno[10].renda = 2500;


	// --------- ESTRUTURAS E FUNÇÕES ------ //
	typedef struct{
		char nome[20];
		int idade;
	}REG;

	REG dados;

	void ler(REG dados) // definidir que é estrutura na definição da função
	/*
	int main(){
		ler(dados); // apenas o nome da estrutura
		return 0;
	}
	*/

	// ponteiros para estruturas
	typedef struct{
		char nome[20];
		int idade;
	}EXAMPLE;

	EXAMPLE dados;

	void ler(EXAMPLE *dados){
		dados->nome = "alex";
		dados->idade = 20;
	};

	/*
	int main(){
		ler(&dados);
		return 0;
	}
	*/


	// -------------- UNION ----------------
	/*
	Union
 	é um tipo de dados composto cujos 
	membros compartilham o mesmo espaço de 
	armazenamento.
	■
	A quantidade de armazenamento ocupada será 
	tão grande quanto o maior membro da 
	union
	■
	Logo, union economiza espaço de armazenamento.

	*/
	// EXAMPLE  1

	/*
	#include <stdio.h>
	#include <stdlib.h>

	union real_ou_inteiro{
		double r;
		int i;
	};

	
	int main(){

		union real_ou_inteiro num;

		num.r = 2.5;

		printf("\nA) r = %.2f i = %d", num.r, num.i);
		num.i = 1000;

		printf("\nB) r=%.2f i=%d", num.r, num.i);
		num.r = -34.25;

		printf("\nC r=%.2f i=%d", num.r, num.i);
		num.i = -1;

		printf("\nD) r=%.2f i=%d", num.r, num.1);
	}
	*/

	// EXAMPLE 2

	/*
	#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char marca[30];
	int ano;
}carro;

typedef struct{
	char nome[10];
	float preco;
}fruta;

typedef union{
	carro c;
	fruta f;
}fruta_ou_carro;

int main(){

	fruta_ou_carro x;

	strcpy(x.c.marca, "FIAT");
	x.c.ano = 2010;
	printf("\nA) \nCarro: %s %d\nFruta: %s  %.2f", x.c.marca, x.c.ano, x.f.nome, x.f.preco);

	strcpy(x.f.nome, "BANANA");
	x.f.preco = 4.99;
	printf("\nB)\nCarro: %s %d\nFrutas: %s  %.2f", x.c.marca, x.c.ano, x.f.nome, x.f.preco);

	return 0;
}
	*/

	return 0;
}















