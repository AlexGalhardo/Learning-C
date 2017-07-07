/*
12. (M´edio) Fa¸ca um programa que simule o sistema de um mercado. Determine um conjunto
de produtos que ter´a no seu mercado e estabele¸ca dois vetores, um de pre¸co e
um de quantidade no estoque, que contenham as informa¸c˜oes dos produtos. Crie uma
vari´avel que represente o dinheiro no caixa com um valor inicial que desejar. Leia um
inteiro na fun¸c˜ao principal que corresponde `a a¸c˜ao que se deseja fazer (1 - adicionar
ao estoque, em caso de compra de um fornecedor, e 2 - retirar do estoque, em caso de
venda a um cliente). Fa¸ca uma fun¸c˜ao que implemente cada um desses casos. Ambas
as fun¸c˜oes devem receber os vetores de pre¸co e quantidade, assim como o dinheiro no
caixa, atrav´es de passagem por referˆencia. Elas tamb´em devem imprimir um menu com
os produtos, cada produto representado por um n´umero. Depois que for lido o inteiro
do produto escolhido, ser´a lido a quantidade comprada ou vendida. Caso seja a fun¸c˜ao
da op¸c˜ao 1, esse valor ser´a adicionado `a quantidade no estoque e o dinheiro em caixa
ser´a decrementado de acordo com o pre¸co do produto e a quantidade comprada. Caso
seja a op¸c˜ao 2, a quantidade no estoque ser´a diminu´ıda, mas o dinheiro no caixa ser´a
incrementado.
Exemplo de menu:
Escolha o produto desejado:
(1) - Arroz
(2) - Feij˜ao
(3) - Biscoito
(4) - Molho de tomate
*/


#include <stdio.h>
#define PRODUTOS 5
#define DINHEIRO_INICIAL 200

void imprimirMenu(){
    printf("Escolha o produto: \n");
    printf("[0] -- ARROZ\n");
    printf("[1] -- FEIJAO\n");
    printf("[2] -- BISCOITO\n");
    printf("[3] -- MACARRAO\n");
    printf("[4] -- PIPOCA\n");
}


void compra(int *quantidade, double *preco, double *dinheiro){
    int op, quantidadeComprada;

    imprimirMenu();

    scanf("%d", &op);

    if(op <0 || op >= PRODUTOS){
        printf("Opcao Invalida\n");
        return;
    }

    printf("Digite a quantidade comprada: \n");
    scanf("%d", &quantidadeComprada);

    if(quantidadeComprada * preco[op] > *dinheiro){
        printf("Nao ha dinheiro suficiente para realizar essa operacao!\n");
        return;
    }

    *dinheiro -= quantidadeComprada * preco[op];
    quantidade[op] += quantidadeComprada;
}

void venda(int *quantidade, double *preco, double *dinheiro){
    int op, quantidadeVendida;

    imprimirMenu();

    scanf("%d", &op);

    if(op <0 || op >= PRODUTOS){
        printf("Opcao Invalida\n");
        return;
    }

    printf("Digite a quantidade vendida: \n");
    scanf("%d", &quantidadeVendida);

    if(quantidadeVendida < quantidade[op]){
        printf("Nao ha produto em estoque suficiente para realizar essa operacao\n");
        return;
    }
    *dinheiro += quantidadeVendida * preco[op];
    quantidade[op] -= quantidadeVendida;
}

void imprimirProdutos(int *quantidade, double *preco){
    int i=0;

    for(i=0; i < PRODUTOS; i++){
        if(i==0){
            printf("Arroz: ");
        }
        else if(i==1){
            printf("Feijao: ");
        }
        else if(i==1){
            printf("Biscoito: ");
        }
        else if(i==1){
            printf("Macarrao: ");
        }
        else if(i==1){
            printf("Pipoca: ");
        }
        printf("Quantidade em estoque: %d, ", quantidade[i]);
        printf("Preco do produto: %.2f\n", preco[i]);
    }
}


int main(int argc, char * argv[]){
    double dinheiro = DINHEIRO_INICIAL;
    int op;
    int quantidade[PRODUTOS] = {10, 40, 3, 12, 15};
    double preco[PRODUTOS] = {8.00, 12.00, 4.00, 6.50, 2.00};

    printf("Digite 1 para adicionar ao estoque e 2 para retirar do estoque: \n");
    scanf("%d", &op);

    if(op ==1){
        compra(quantidade, preco, &dinheiro);
    }
    else if(op ==2){
        venda(quantidade, preco, &dinheiro);
    }
    else{
        printf("Opcao invalida\n");
    }

    return 0;
}
