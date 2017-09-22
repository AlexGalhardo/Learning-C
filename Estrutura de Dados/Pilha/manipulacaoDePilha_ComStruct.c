/*
Manipulação de Pilha com Struct

Adapte a estrutura pilha do exercício "Manipulação de Pilha" para agora ao invés de apenas inserir números inteiros insira informações sobre um registro de aluno. O aluno deverá ser criado usando struct e deverá ter os campos, nome, idade e sexo. As operações de inserção (push) e remoção (pop) na pilha deverão ser adaptadas para esse registro. O seu programa principal deverá ler inicialmente o tamanho máximo da sua estrutura pilha (n). Em seguida, será lido um caractere (indicando uma operação) seguido de um nome, seguido de idade e sexo, tantas vezes, quantas foram o tamanho de n. Apenas dois caracteres indicando operação são permitidos 'i' indicando inserção e 'r' indicando remoção. Ao se ler o caractere 'i' os campos do aluno lidos em seguida deverá ser inserido na pilha. Ao se ler o caractere 'r' (os três campos posteriores não serão usados e poderão ser quaisquer informação eu estou usando 0 0 0) se removerá o valor do topo da pilha. A saída do programa deverá ser os valores presentes na pilha impressos na ordem em que se retira os elementos da pilha.

OBS: sugestão de leitura das informações: scanf(" %c %s %d %c", &op, nome, &idade, &sexo);

OBS: sugestão de impressão das informações : printf("%s %d %c\t", var.nome, var.idade, var.sexo);
Exemplos de Entrada e Saída

Entrada:

3
i jesimar 28 m i vivian 24 f i antonio 23 m

Saída:

antonio 23 m    vivian 24 f jesimar 28 m    

Entrada:

4
i tiago 20 m i janaina 18 f r 0 0 0 i suzana 31 f

Saída:

suzana 31 f    tiago 20 m  

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    char nome[30];
    char sexo;
    int idade;
}REGISTRO;



typedef struct{
    int topo, capacidade;
    REGISTRO *dados;
}PILHA;



void criarPilha(PILHA*ptr, int tam){
    ptr->topo = -1;
    ptr->capacidade = tam;
    ptr->dados = (REGISTRO *) malloc(tam *sizeof(REGISTRO));
}



void push(PILHA*ptr, char *name, int age, char sex){
    ptr->topo++;
    strcpy(ptr->dados[ptr->topo].nome, name); /* nos dados da minha PILHA, no index ptr->topo, do tipo .nome, eu vou concatenar name */
    ptr->dados[ptr->topo].idade = age; /* no mesmo estilo, nos dados da pilha, no index ptr->topo, do tipo .idade, vou dar o valor de age */
    ptr->dados[ptr->topo].sexo = sex; /* nos dados da pilha, no index ptr->topo, do tipo .sexo, eu vou dar o valor de sex */
}

/* função para retirar um item da pilha */
void pop(PILHA*ptr){
    ptr->topo--;
}

/* verificar se está vazia */
int isEmpty(PILHA *ptr){
    if(ptr->topo==-1){
        return 1;
    }
    else{
        return 0;
    }
}

/* verificar se está cheia */
int isFull (PILHA*ptr){
    if(ptr->topo == ptr->capacidade-1){
        return 1;
    }
    else{
        return 0;
    }
}


/* imprimir dados da pilha */
void imprimirPilha (PILHA*ptr){
    int i;
    for(i=ptr->topo; i>-1; i--){
        printf("%s %d %c\t", ptr->dados[i].nome, ptr->dados[i].idade, ptr->dados[i].sexo);
    }
}


int main(){

    int tam, i=0, idade;

    char opcao, nome[30], sexo;
    PILHA myPilha;

    scanf("%d",&tam);
    criarPilha(&myPilha,tam);

    while(i<tam)
    {
        scanf(" %c %s %d %c", &opcao, nome, &idade, &sexo);

        if(opcao=='i'){
            if(isFull(&myPilha) != 1){ // se a PILHA não estiver cheia, adicione os dados no seu struct pessoa
                push(&myPilha,nome,idade,sexo);
            }
        } // caso a opção for 'r'
        else {
           if(isEmpty(&myPilha) != 1){ // se for opção retirar, e a pilha não estiver vazia, retire um valor da pilha
               pop(&myPilha);
           }
        }

        i++;
    }

    imprimirPilha(&myPilha);

    return 0;
}
