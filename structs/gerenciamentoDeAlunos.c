/*
Gerenciamento de estudantes
Disciplina: SSC0502 - Laboratório de Introdução a Computação I
Prazo de Entrega: 06/07/2017 23:59:59 Aberto
Desenvolva um algorítmo capaz de gerenciar registros de alunos de uma universidade. Cada registro é composto por quatro campos: identificador, nome, curso e idade. Seu programa deve ser capaz de:

Ler n registros até que o usuário forneça -1
Ler n operações até que o usuário forneça -1
Permitir que um aluno seja consultado por meio de seu identificador e que seu registro seja impresso caso esta operação seja selecionada (operação 1)
Permitir a consulta de todos os alunos de um determinado curso e impressão de seus registros (operação 2)
Permitir que todos os registros armazenados sejam impressos (operação 3)
Exemplos de entrada
9297384
Fulano da Silva
Ciencias da Computacao
20
8237381
Fulano da Silva Segundo
Ciencias da Computacao
22
9787485
Fulano da Silva Terceiro
Sistemas de Informacao
20
6578309
Fulano da Silva Diferentoso
Arquitetura e Urbanismo
23
-1
1
9297384
2
Ciencias da Computacao
3
-1
Exemplo de Saída
Nome: Fulano da Silva
Curso: Ciencias da Computacao
N USP: 9297384
Idade: 20

Nome: Fulano da Silva
Curso: Ciencias da Computacao
N USP: 9297384
Idade: 20

Nome: Fulano da Silva Segundo
Curso: Ciencias da Computacao
N USP: 8237381
Idade: 22

Nome: Fulano da Silva
Curso: Ciencias da Computacao
N USP: 9297384
Idade: 20

Nome: Fulano da Silva Segundo
Curso: Ciencias da Computacao
N USP: 8237381
Idade: 22

Nome: Fulano da Silva Terceiro
Curso: Sistemas de Informacao
N USP: 9787485
Idade: 20

Nome: Fulano da Silva Diferentoso
Curso: Arquitetura e Urbanismo
N USP: 6578309
Idade: 23
Note que cada registro é separado por dois pulos de linha e que o -1 é utilizado para indicar o fim da entrada de registros e, também de operações. Caso o aluno buscado não seja encontrado, seu programa deverá imprimir "Aluno nao cadastrado", seguido por uma quebra de linha
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    int id;
    int idade;
    char nome[50];
    char curso[50];
}REGISTRO;

registro *criar(int *cont){

    registro *vet;
    vet = (registro *) malloc(1*sizeof(registro));
    int i=0;
    while(1){
        scanf("%d", &vet[i].id);
        if(vet[i].id==-1){
            break;
        }
        scanf(" %[^\n]", vet[i].nome);
        scanf(" %[^\n]", vet[i].curso);
        scanf(" %d", &vet[i].idade);
        i++;
        vet = (registro *) realloc(vet, (i+1)*sizeof(registro));
        *cont=i;
    }
    return vet;
}

void func(registro *vet, int cont){
    int op, id, i;
    char curso[50];
    scanf(" %d", &op);
    while(op!=-1){
        if(op==1){
            scanf(" %d", &id);
            for(i=0; i<cont; i++){
                if(id==vet[i].id){
                    printf("\nNome: %s\n", vet[i].nome);
                    printf("Curso: %s\n", vet[i].curso);
                    printf("N USP: %d\n", vet[i].id);
                    printf("IDADE: %d\n", vet[i].idade);
                }
            }
        }
        else if(op==2){
            scanf(" %[^\n]", curso);
            for(i=0; i<cont; i++){
                if(strcmp(curso, vet[i].curso)==0){
                    printf("\nNome: %s\n", vet[i].nome);
                    printf("Curso: %s\n", vet[i].curso);
                    printf("N USP: %d\n", vet[i].id);
                    printf("IDADE: %d\n", vet[i].idade);
                }
            }
        }
        else if(op==3){
            for(i=0; i<cont; i++){
                    printf("\nNome: %s\n", vet[i].nome);
                    printf("Curso: %s\n", vet[i].curso);
                    printf("N USP: %d\n", vet[i].id);
                    printf("IDADE: %d\n", vet[i].idade);
            }
        }
        scanf("%d", &op);
    }
    printf("\n");
}

int main(){

    int cont;

    registro *vet;
    vet = criar(&cont);
    func(vet, cont);
    return 0;
}
