/*
Pilha de Cartas

Utilizando uma implementação de Pilha, você deverá simular a criação de uma pilha de cartas e a retirada de cartas dessa pilha até a mão de um jogador ser preenchida, seguindo algumas condições.

Primeiramente, as cartas 8, 9, e 10 foram retiradas e, as cartas que possuem esses respectivos valores no baralho são: Valete (J), Dama (Q), e Rei (K).
A carta Ás (A) equivale ao valor 1. E a carta Coringa (C) não vale nada, e, portanto, não poderá estar presente na mão do jogador.

Todas as cartas são representadas por valores do tipo char, com os números correspondendo aos caracteres de seu algarismos, e as cartas especiais seguindo o que foi mencionado anteriormente.
Lembrem-se: valor decimal do caracter '0' na tabela ASC II: 48.

Seu programa deverá fazer o seguinte:
Ler o tamanho N da pilha.
Empilhar N cartas na pilha.
Retirar cartas da pilha até o jogador possuir 5 cartas na mão. Porém, se a carta for um Coringa (C), essa carta será descartada e uma nova dada ao jogador.
Imprimir as seguintes saídas:
Número de Coringas sacados pelo jogador:
"Coringas: %d\n"
Todas as cartas na mão do jogador, assim que ele terminar de sacar as cartas, na ordem do desempilhamento, e separadas por espaço:
"Cartas na mao:\n"
"%c "
E, ao final, após pular uma linha:
"\n"
Mostrar a soma dos valores das cartas na mão do jogador:
"Soma: %d\n"
Exemplos de Entrada e Saída

Entrada:

5
2
3
4
5
6

Saída:

Coringas: 0
Cartas na mao:
6 5 4 3 2 
Soma: 20

Entrada:

6
2
3
C
K
A
Q

Saída:

Coringas: 1
Cartas na mao:
Q A K 3 2 
Soma: 25
*/


#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int topo;
    int capacidade;
    char *cartas;

}PILHA;

/* função para criar PILHA */
/* sempre uso ponteiro de estruturas para selecionar o elemento correspondente dentro da estrutura */
void criarPilha(PILHA *ptr, int tam){
    ptr->topo=-1;
    ptr->capacidade=tam;
    ptr->cartas = (char*) malloc(tam * sizeof(char)); /* após receber o tamanho, aloco memoria para o ponteiro */
}

/* função para adicionar carta a pilha */
/* quando eu quero adicionar algo na pilha, eu incremento o topo, 
e chamo o ponteiro dentro da estrutura apontando para o topo, adicionando a carta que quero acrescentar */
void push(PILHA*ptr, char carta){
    ptr->topo++;
    ptr->cartas[ptr->topo]=carta;
}

/* função para retirar uma carta do baralho */
void pop(PILHA *ptr){
    ptr->topo--;
}


/* função para verificar se a pilha está vazia */
int isEmpty(PILHA*ptr){
    if(ptr->topo==-1){ // se o topo estiver -1, é sinal de que a pilha está vazia
        return 1;
    }
    else{
        return 0; // se não estiver, retorne false
    }
}

/* função para verificar se a pilha está cheia */
int isFull(PILHA *ptr){
    if(ptr->topo==ptr->capacidade-1){
        return 1; // está cheio, retorna 1
    }
    else{
        return 0; // senão, 0
    }
}

/* função que soma os valores das cartas correspondentes */
int somaCartas(PILHA *ptr){
    int soma=0, i, numero, cont=0;

    // usando um laço, para cada carta dentro da pilha
    for(i=ptr->topo; cont<5; i--, cont++){
        switch (ptr->cartas[i]){
        case 'A':
            numero = 1;
            break;
        case 'J':
            numero = 8;
            break;
        case 'Q':
            numero = 9;
            break;
        case 'K':
            numero = 10;
            break;
        default:
            numero = ptr->cartas[i] - 48;
            break;
        }
        soma += numero;
    }

    return soma;
}

void imprimeCartas(PILHA *ptr){
    int i, cont=0;

    for(i=ptr->topo; cont<5; i--, cont++){
        printf("%c ", ptr->cartas[i]);
    }
    printf("\n");
}


int main(){

    PILHA baralho; // struct de baralho

    int qnt, i, soma, cont_C = 0, cnt_cartas = 0;
    char carta;

    scanf("%d", &qnt);

    criarPilha(&baralho, qnt);

    // recebendo os dados das cartas pelo usuário
    for(i=0; i<qnt; i++){
        scanf(" %c", &carta);
        cnt_cartas++;

        if (isFull(&baralho)== 0){ // se a pilha não estiver cheia, adiciona a carta na pilha
            push(&baralho, carta);
        }

        if(carta=='C' && (isEmpty(&baralho))==0){
            pop(&baralho);
            cnt_cartas--; // se for coringa, eu vou retirar-lo (pop) e decrementar 1 na quantidade de cartas
            if (cnt_cartas<5){
                cont_C++;
            }
        }

    }

    soma = somaCartas(&baralho);

    printf("Coringas: %d\n", cont_C);
    printf("Cartas na mao:\n");
    imprimeCartas(&baralho);
    printf("Soma: %d", soma);

    return 0;
}