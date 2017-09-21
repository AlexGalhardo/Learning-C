/*
Leitura de Arquivo de Binário - Procura Registro
Faça um programa em C que leia o conteúdo de um arquivo binário, chamado "dados-alunos.bin". A primeira informação guardada nesse arquivo é a quantidade de registros (size). As informações restantes guardadas nesse arquivo são um conjunto registro. Durante a leitura do arquivo armazene o conteúdo em vetor de registro de tamanho size (struct descrita abaixo). O seu programa deverá ler também o número de matrícula de um aluno do terminal. Em seguida, faça uma busca pelo vetor de registro pelo aluno que possui esse número de matrícula e então imprima o conteúdo do registro contendo o nome, idade, sexo e matrícula.

struct aluno{
char nome[40];
int idade;
char sexo;
int matricula;
};

OBS: Sugestão use o printf abaixo para imprimir os campos do aluno:
printf("Nome: %s\n", a.nome);
printf("Idade: %d\n", a.idade);
printf("Sexo: %c\n", a.sexo);
printf("Matricula: %d\n", a.matricula);

Exemplo de Entrada e Saída:
Entrada:

(arquivo binário chamado "dados-alunos.bin")
8290
Saída:

Nome: Viviane Souza
Idade: 39
Sexo: f
Matricula: 8290

Esconder Descrição

Arquivos:
dados-alunos.bin

Este exercício aceita os seguintes tipos de arquivos:
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[50];
    int idade;
    char sexo;
    float salario;
}REGFUNC;

int main(){

    FILE*arq = fopen("dados-funcionario.bin", "rb");

    REGFUNC func;

    int total=0, tot_Hom=0, tot_Mul=0;

    float mediaTotal, mediaHom, mediaMul, somaTotal=0, somaH=0, somaM=0;

    if (arq== NULL){
        exit(0);
    }

    while (fread(&func, sizeof(REGFUNC), 1, arq)){
        if (func.sexo=='m'){
            tot_Hom++;
            somaH += func.salario;
        }
        else{
            tot_Mul++;
            somaM += func.salario;
        }

        somaTotal += func.salario;
        total++;
    }

    mediaTotal = somaTotal/total;
    mediaHom = somaH/tot_Hom;
    mediaMul = somaM/tot_Mul;

    printf("%d %d %d %.2f %.2f %.2f", total, tot_Hom, tot_Mul, mediaTotal, mediaHom, mediaMul);

    fclose(arq);

    return 0;
}
