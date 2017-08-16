/*
Questão 2 (4.0 Pontos): Pilha de Livros
Utilizando uma implementação de Pilha, você deverá simular a criação de uma pilha de livros, a inserção e a retirada de livros dessa pilha
Você deverá primeiramente ler o tamanho da pilha e criar a pilha. Em seguida, você deve ler comandos do usuário até que ele digite o valor 0, que irá fazer com que o programa termine
Os comandos possíveis (inteiros) são:
1 - Adicionar Livro na pilha
2 - Remover Livro da pilha
3 - Mostrar Livro no topo da pilha

Cada livro contém:
Nome do livro (no máximo 50 caracteres)
Nome do autor (no máximo 50 caracteres)
Número de Páginas (inteiro)

Nenhum nome conterá espaço

Para imprimir os dados de um livro, assim como para a inserção, a ordem deverá ser a mesma apresentada acima
Para a impressão dos livros, use a formatação:
"Nome: %s\n"
"Autor: %s\n"
"Nro Paginas: %d\n\n"

Caso a pilha esteja cheia ao adicionar um livro, apenas imprima:
"Pilha cheia\n\n"

Caso a pilha esteja vazia ao tentar remover ou ler os dados de um livro, apenas imprima:
"Pilha vazia\n\n"

Exemplos de Entrada e Saída
Entrada:

4
1
OPistoleiro
StephenKing
120
3
0
Saída:

Nome: OPistoleiro
Autor: StephenKing
Nro Paginas: 120
Entrada:

3
1
AFundacao
IsaacAsimov
210
2
3
0
Saída:

Nome: AFundacao
Autor: IsaacAsimov
Nro Paginas: 210

Pilha vazia
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 30


typedef struct{
    char nome[MAX];
    char autor[MAX];
    int paginas;
}LIVRO;

typedef struct{
    int topo;
    int tamanho;
    LIVRO *dados;
}PILHA;


void criarPilha(PILHA *ptr, int tamanho){
    ptr->topo= -1;
    ptr->tamanho = tamanho;
    ptr->dados = (LIVRO *) malloc(sizeof(LIVRO));
}

int isEmpty(PILHA *ptr){
    if(ptr->topo == -1){
        return 1;
    }
    else{
        return 0;
    }
}

PILHA livros;

void pop(PILHA *ptr){
    if(isEmpty(&livros) != 1){ // se não estiver vazia
        ptr->topo--;
        printf("Nome: %s\n", ptr->dados[ptr->topo].nome);
        printf("Autor: %s\n", ptr->dados[ptr->topo].autor);
        printf("Nro Paginas: %d\n\n", ptr->dados[ptr->topo].paginas);
    }
    else{
        printf("Pilha vazia\n\n");
    }
}


void push(PILHA *ptr, char *nome, char *autor, int paginas){

    ptr->topo++;
    strcpy(ptr->dados[ptr->topo].nome, nome); /* nos dados da minha PILHA, no index ptr->topo, do tipo .nome, eu vou concatenar name */
    strcpy(ptr->dados[ptr->topo].autor, autor); /* no mesmo estilo, nos dados da pilha, no index ptr->topo, do tipo .idade, vou dar o valor de age */
    ptr->dados[ptr->topo].paginas = paginas;
}

int isFull(PILHA *ptr){

    if(ptr->topo == ptr->tamanho-1){
        return 1;
    }
    else{
        return 0;
    }
}

void mostrarLivro(PILHA *ptr){
    printf("Nome: %s\n", ptr->dados[ptr->topo].nome);
    printf("Autor: %s\n", ptr->dados[ptr->topo].autor);
    printf("Nro Paginas: %d\n\n", ptr->dados[ptr->topo].paginas);
}

int main(){

    PILHA livro;

    int tamanho;

    scanf("%d", &tamanho); // tamanho da pilha

    criarPilha(&livro, tamanho);

    int op;

    char nome[MAX], autor[MAX];
    int paginas;

    do{
        scanf("%d", &op); // pega primeira opção, e sucessivamente
        switch(op){
            case 1: // adicionar livro na pilha
                scanf("%s %s %d", nome, autor, &paginas); // dados do livro
                push(&livro, nome, autor, paginas);
                break;
            case 2: // remover livro
                pop(&livro);
                mostrarLivro(&livro);
                break;
            case 3: // mostrar livro
                mostrarLivro(&livro);
                break;
            default:
                continue;
        }
    }while(op != 0);

    return 0;
}
