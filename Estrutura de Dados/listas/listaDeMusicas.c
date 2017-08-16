/*
Lista de Músicas
Disciplina: SSC0502 - Laboratório de Introdução a Computação I
Prazo de Entrega: 06/07/2017 23:59:59 Fechado
Lista de Músicas

Com seus recém-adquiridos conhecimentos de programação e listas, você deseja começar a criar um aplicativo em que o usuário possa criar uma playlist com suas músicas favoritas: o USPotify.
Como todo projeto precisa começar em algum ponto, você planeja começar criando uma lista ligada em que cada nó conterá as seguintes informações:
Nome da música (máximo de 50 caracteres)
Nome do artista/banda (máximo de 50 caracteres)
Gênero musical(máximo de 20 caracteres)
*Não haverá espaços entre os caracteres e seu programa deverá diferenciar maiúsculas de minúsculas (ou seja, não precisa tratar nenhuma exceção em relação a isso)

Usando uma implementação de lista ligada semelhante à vista em sala (com a inserção dos elementos novos no início da lista), seu programa deverá ler diversos comandos de entrada, até que o comando de número 5 seja inserido, que indica saída.
Os 4 comandos que seu programa fará serão:
1:

Inserir um nó de música como primeiro elemento da lista.
2:

Imprimir a linha: printf("\nMusicas na sua lista:\n\n");
E mostrar todas as músicas da lista.
3:

Receber um nome de artista como entrada, imprimir a seguinte linha:
printf("\nMusicas do artista %s\n\n", artista);
E exibir todas as músicas da lista daquele artista.
4:

Receber um gênero de música como entrada, imprimir a seguinte linha:
printf("\nMusicas do genero %s\n\n", genero);
E exibir todas as músicas da lista daquele gênero.

As impressões deverão seguir a seguinte formatação:

printf("Nome: %s\n", nome);
printf("Artista: %s\n", artista);
printf("Genero: %s\n", genero);

Caso a lista esteja vazia e algum comando para imprimir a lista seja pedido, seu programa deverá imprimir a seguinte mensagem:
printf("Lista vazia");
Exemplos de Entrada e Saída

Entrada:

1
FearOfTheDark
IronMaiden
HeavyMetal
2
5

Saída:

Musicas na sua lista:

Nome: TheTrooper
Artista: IronMaiden
Genero: HeavyMetal

Entrada:

1
TheTrooper
IronMaiden
HeavyMetal
1
SweatingBullets
Megadeth
ThrashMetal
1
DreamOfMirrors
IronMaiden
HeavyMetal
3
IronMaiden
4
ThrashMetal
5

Saída:

Musicas do artista IronMaiden

Nome: DreamOfMirrors
Artista: IronMaiden
Genero: HeavyMetal
Nome: TheTrooper
Artista: IronMaiden
Genero: HeavyMetal

Musicas do genero ThrashMetal

Nome: SweatingBullets
Artista: Megadeth
Genero: ThrashMetal
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

char*alocarMemoria(int tam)
{
    char*palavra;
    palavra = (char*)malloc(tam*sizeof(char));

    return palavra;

}

typedef struct
{
    char*nomeMusica,*nomeArtista,*genero;

}REGMUSICA;


struct Node
{
    REGMUSICA dados;
    struct Node *prox;
};

typedef struct
{
    struct Node *prim;
}listaSimplesEnc;


void criarLista(listaSimplesEnc *pLista)
{
    pLista->prim = NULL;

}

void inserirItemInicio(listaSimplesEnc*pLista, char*musica, char*cantor, char*genero)
{
    struct Node*novo;
    novo = (struct Node*)malloc(sizeof(struct Node));

    novo->dados.nomeMusica = alocarMemoria(strlen(musica));
    novo->dados.nomeArtista = alocarMemoria(strlen(cantor));
    novo->dados.genero = alocarMemoria(strlen(genero));


    strcpy(novo->dados.nomeMusica,musica);
    strcpy(novo->dados.nomeArtista,cantor);
    strcpy(novo->dados.genero,genero);

    novo-> prox = pLista->prim;
    pLista->prim=novo;
}

void removerItemInicio(listaSimplesEnc*pLista)
{
    struct Node*pAux = pLista->prim;
    pLista->prim = pLista->prim->prox;
    free(pAux);
}

int isEmpty(listaSimplesEnc*pLista)
{
    return (pLista->prim==NULL); //retona 1 se verdadeiro e 0 se falso;
}

void imprimirLista(listaSimplesEnc*pLista)
{
    struct Node*p;
    for (p=pLista->prim; p!=NULL; p=p->prox)
    {
        printf("Nome: %s\n", p->dados.nomeMusica);
        printf("Artista: %s\n", p->dados.nomeArtista);
        printf("Genero: %s\n", p->dados.genero);
    }
}

void pesquisarArtista (listaSimplesEnc*pLista, char*artista)
{
    struct Node*p;
    for (p=pLista->prim; p!=NULL; p=p->prox)
    {
        if (strcmp(p->dados.nomeArtista,artista)==0)
        {
            printf("Nome: %s\n", p->dados.nomeMusica);
            printf("Artista: %s\n", p->dados.nomeArtista);
            printf("Genero: %s\n", p->dados.genero);
        }
    }
}

void pesquisarGenero (listaSimplesEnc*pLista, char*genero)
{
    struct Node*p;
    for (p=pLista->prim; p!=NULL; p=p->prox)
    {
        if (strcmp(p->dados.genero,genero)==0)
        {
            printf("Nome: %s\n", p->dados.nomeMusica);
            printf("Artista: %s\n", p->dados.nomeArtista);
            printf("Genero: %s\n", p->dados.genero);
        }
    }
}



int main()
{
    listaSimplesEnc myList;

    char*musica=NULL, *artista=NULL, *genero=NULL;
    int opcao;

    criarLista(&myList);

    do
    {
        scanf("%d ",&opcao);
        switch (opcao)
        {
        case 1:

            musica = readName();
            artista = readName();
            genero = readName();

            inserirItemInicio(&myList, musica, artista, genero);
            break;

        case 2:
            if(!isEmpty(&myList)) //se for falso(zero)
            {
                printf("\nMusicas na sua lista:\n\n");
                imprimirLista(&myList);
            }
            else
            {
                printf("Lista vazia");
            }
            break;

        case 3:
            scanf("%s", artista);
            printf("\nMusicas do artista %s\n\n", artista);
            pesquisarArtista(&myList, artista);
            break;

        case 4:
            scanf("%s", genero);
            printf("\nMusicas do genero %s\n\n", genero);
            pesquisarGenero(&myList, genero);
            break;
        }


    }while(opcao!=5);


    return 0;
}
