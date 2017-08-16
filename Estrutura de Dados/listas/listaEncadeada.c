/*
Lista Encadeada
Disciplina: SSC0502 - Laboratório de Introdução a Computação I
Prazo de Entrega: 06/07/2017 23:59:59 Fechado
Lista Encadeada

Uma estrutura para organização de dados muito utilizada é a lista encadeada, composta por várias células (nós) em que cada nó tem um ponteiro para o nó seguinte, além de um ou mais valores.

Esse tipo de estrutura apresenta algumas vantagens em comparação a vetores, pois possibilita um uso mais eficiente de memória, além de operações de inserção e remoção mais simples.

Cada nó é representado por uma struct alocada dinamicamente, como no exemplo abaixo:

struct no{

struct no *proximo
//VALORES

};

A lista, por sua vez, também é representada por uma struct como a mostrada abaixo:

struct lista{

struct no *primeiro,
int elementos

};

O que você terá que fazer neste exercício é implementar a inserção ordenada em uma lista encadeada. Você terá que ler o nome e a idade de N pessoas e inserir de uma em uma na lista encadeada de maneira ordenada. Perceba que cada nó representará uma pessoa, com as variáveis de nome e idade. O critério para saber se um nó é menor que o outro é o valor da idade. A lista deverá estar ordenada de forma crescente. Caso o nó a ser inserido tenha idade igual a algum nó presente na lista, insira depois.

A entrada será composta por uma linha com um inteiro N, que é o número de pessoas a serem lidas, seguidas de N linhas, compostas por um inteiro representando a idade e uma string representando o nome.

Você deverá percorrer a lista do início ao fim e imprimir um nome por vez, que estarão ordenados pela idade.

Dica: Para inserir de maneira ordenada, percorra a lista enquanto o a idade do próximo nó for menor ou igual a idade do nó a ser inserido. Então insira o elemento rearranjando os ponteiros do nós anterior e do nó inserido. Caso o nó seja o último da lista, o ponteiro para o proximo nó deve valer NULL.

Obs: Armazene os nós em memória dinâmica, isto é, aloque memória para cada nó criado. Não se esqueça de desalocar a memória utilizada ao final do programa.
Exemplos de Entrada e Saída

Entrada:

4
32 Thiago Pereira Pinto
26 Vitor Costa Correia
29 Arthur Cavalcanti Souza
32 Sarah Goncalves Souza

Saída:

Vitor Costa Correia
Arthur Cavalcanti Souza
Thiago Pereira Pinto
Sarah Goncalves Souza

*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char*readName()
{
    char*nome= NULL;
    int cont=0;

    do
    {
        nome = (char*)realloc(nome,(cont+1)*sizeof(char));
        scanf("%c", &nome[cont]);
        cont++;
    }while(nome[cont-1]!='\n');

    nome[cont-1]='\0';

    return nome;
}

typedef struct
{
    int idade;
    char*nome;
}REGISTRO;

struct Node
{
    REGISTRO dados;
    struct Node *prox;
};

typedef struct
{
    struct Node *prim;
}listaEnc;

void criarLista(listaEnc *pLista)
{
    pLista->prim = NULL;

}

void inserirItemInicio(listaEnc*pLista, int age, char*name)
{
    struct Node*novo;
    novo = (struct Node*)malloc(sizeof(struct Node));

    novo->dados.idade = age;
    novo->dados.nome = (char*)realloc(novo->dados.nome, strlen(name)*sizeof(char));
    novo->dados.nome = name;

    novo-> prox = pLista->prim;
    pLista->prim=novo;
}


void removerItemInicio(listaEnc*pLista)
{
    struct Node*pAux = pLista->prim;
    pLista->prim = pLista->prim->prox;
    free(pAux);
}

//só de enfeite aqui
/*void inserirOrdem (listaEnc*pLista,int age, char*name)
{
    struct Node*novo;
    novo = (struct Node*)malloc(sizeof(struct Node));

    novo->dados.idade = age;
    novo->dados.nome = (char*)realloc(novo->dados.nome, strlen(name)*sizeof(char));
    novo->dados.nome = name;

    struct Node *pAnter, *pAtuali;
    pAnter = NULL;
    pAtuali = pLista->prim;
    while(pAtuali!=NULL && pAtuali->dados.idade<age)
    {
        pAnter = pAtuali;
        pAtuali = pAtuali->prox;

    }

    novo->prox = pAtuali-> prox;
    pAnter ->prox = novo;
}
*/

void ordenarLista (listaEnc*pLista)
{
    char tmp[50];
    int tmp2;
    struct Node*aux = pLista->prim;
    struct Node*t;

    while(aux!=NULL)
    {
        t=aux->prox;
        while(t!=NULL)
        {
            if(aux->dados.idade > t->dados.idade || (aux->dados.idade == t->dados.idade &&  strcmp(aux->dados.nome,t->dados.nome)<0))
            {
                strcpy(tmp,aux->dados.nome);
                strcpy(aux->dados.nome,t->dados.nome);
                strcpy(t->dados.nome, tmp);

                tmp2 = aux->dados.idade;
                aux->dados.idade = t->dados.idade;
                t->dados.idade = tmp2;

            }
            t = t->prox;
        }
        aux=aux->prox;
    }
}

int isEmpty(listaEnc*pLista)
{
    return (pLista->prim==NULL); //retona 1 se verdadeiro e 0 se falso;
}

void imprimirLista(listaEnc*pLista)
{
    struct Node*p;
    for (p=pLista->prim; p!=NULL; p=p->prox)
    {
        printf("%s\n",p->dados.nome);
    }
}

int main()
{

    char*nome;
    int idade, qnt, i;
    listaEnc myList;

    scanf("%d",&qnt);

    criarLista(&myList);

    for (i=0; i<qnt; i++)
    {
        scanf("%d ", &idade);
        nome = readName();
        inserirItemInicio(&myList, idade, nome);
    }

    ordenarLista(&myList);


    if (!isEmpty(&myList))
    {
        imprimirLista(&myList);
    }

    return 0;
}

