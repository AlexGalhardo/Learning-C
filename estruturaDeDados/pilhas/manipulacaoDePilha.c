/*
Manipulação de Pilha

Implemente uma estrutura de pilha usando vetor contendo as operações de inserção (push) e remoção (pop) na pilha. O seu programa principal deverá ler inicialmente o tamanho máximo da sua estrutura pilha (n). Em seguida, será lido um caractere seguido de um valor inteiro, tantas vezes, quantas foram o tamanho de n. Apenas dois caracteres são permitidos 'i' indicando inserção e 'r' indicando remoção. Ao se ler o caractere 'i' o valor inteiro seguinte deverá ser inserido na pilha. Ao se ler o caractere 'r' (o valor posterior poderá ser qualquer valor inteiro não será usado eu estou usando o valor 0) se removerá o valor do topo da pilha. A saída do programa deverá ser os valores presentes na pilha impressos na ordem em que se retira os elementos da pilha.

OBS: sugestão de leitura das informações de operação e valor: scanf(" %c %d", &op, &valor);
Exemplos de Entrada e Saída

Entrada:

7 
i 6 i 3 r 0 r 0 i 2 i 1 i 9

Saída:

9 1 2

Entrada:

5
i 3 r 0 i 6 i 2 i 9

Saída:

9 2 6

*/


#include <stdio.h>
#include <stdlib.h>


typedef struct{
    int topo; 
    int capacidade;
    int *valor; //vetor de valores
}PILHA;

void criarPilha(PILHA*ptr, int tam){
    ptr->topo = -1; // toda vez que crio uma pilha, eu tenho que definir o topo dela para -1
    ptr->capacidade = tam; // o tamanho da pilha recebe o dado que o usuario digitou
    ptr->valor = (int *) malloc(tam *sizeof(int)); // e para o vetor, eu tenho que alocar memoria *NÃO SE ESQUECER*
}

void push(PILHA *ptr, int valor){
    ptr->topo++; // toda vez que dou um push na pilha, eu tenho que incrementar o topo dela
    ptr->valor[ptr->topo]=valor; // o vetor valor, recebe o INDEX = ponteiro->topo
}

void pop(PILHA*ptr){
    ptr->topo--;
}

int isEmpty(PILHA*ptr){
    if(ptr->topo==-1){
        return 1; //true
    }
    else{
        return 0; //false
    }
}

// verifica se a função está cheia. COMO?
// se o ponteiro apotando para o TOPO for igual a capacidade-1 (por causa do index 0), retorna 1, SENÃO, 0
int isFull(PILHA*ptr){

    if(ptr->topo == ptr->capacidade-1){
        return 1;
    }
    else{
        return 0;
    }
}

void imprimirPilha (PILHA *ptr){

    int i;
    for(i=ptr->topo; i>-1; i--){ // no caso da pilha, a gente sempre imprime do MAIOR INDEX[TAM] para o MENOR[-1]
        printf("%d ",ptr->valor[i]);
    }
}

int main(){

    int tam, i = 0, valor;
    char opcao;
    PILHA myPilha;

    scanf("%d",&tam);
    criarPilha(&myPilha, tam);

    while(i<tam){
        scanf(" %c %d", &opcao, &valor);
        if(opcao =='i'){
            if(isFull(&myPilha) != 1){
                push(&myPilha, valor);
            }
        }
        else{
           if(isEmpty(&myPilha) != 1){ // se a opcao nao for i, "tem que ser r de retirar", AND, pilha não está vazia, retire o valor digitado 
               pop(&myPilha);
           }
        }
        i++;
    }

    imprimirPilha(&myPilha);

    return 0;
}
