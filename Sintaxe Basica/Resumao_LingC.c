// LINGUAGEM C - ALEX GALHARDO - 18/03/2017

/***** INTRODUÇÃO A LINGUAGEM C ****
 * C é uma linguagem de programação compilada de propósito geral, estruturada, imperativa, procedural, padronizada pela ISO, criada em 1972, por Dennis Ritchie, no AT&T Bell Labs, para desenvolver o sistema operacional Unix (que foi originalmente escrito em Assembly).
 * 
 * C é "case sensitive" ou seja, faz distinção entre minúsculas ou maiúsculas!
 * EM C é possível atribuir o mesmo valor para várias variáveis.

/*******************************************************
 * Vamos recapitular algumas coisas aqui:
 * 1 bit = 1 algorismo
 * 1 byte = 2^8 ou 256 algarismos
 * 2 byte = 2^(2*8) <=> 2^16 ou 65.535 algarismos
 * 3 byte = 2^(3*8) <=> 2^24 ou 2.147.483.647 algarismos
 * 4 byte = 2^(4*8) <=> 2^32 ou 4.294.967.295 algarismos...
 * 
 * Notação científica: 104E78 = 104^78 (cento e quatro elevado ao expoente 78).
 *                     10E102 = 10^102 (10 elevado ao expoente cento e dois).
 * ------------------------------------------------------------------------------------------------------
 * FUNÇÃO getchar() 
 * 
 * #include <stdio.h>

    int main(){
        char letra;
    }
    printf("Insira um caractere: ");
    letra = getchar();
    printf("Você digitou: '%c'", letra);
}
 * ------------------------------------------------------------------------------------------------------
 * Recebendo caracteres em C através das funçoes [FGETC e GETC]
 * Essas funções também servem para armazenar caracteres, porém são mais gerais que a getchar(), pois podem receber dados de outras fontes, além da padrão (o teclado - stdin).

    Seus usos são semelhantes ao getchar(), porém temos que dizer ao C por onde o programa deve receber as informações.
    No nosso caso, e pelo teclado, então fica: fgetc(stind) e getc(stdin)

    Por exemplo, um aplicativo em C que recebe duas letras e mostra na tela seria:
    
    #include <stdio.h>

    int main(){
        char letra1, letra2;

    printf("Insira um caractere: ");
    letra1 = getc(stdin);

    printf("Insira outro caractere: ");
    letra2 = getc(stdin);

    printf("Você digitou: '%c' e '%c'", letra1, letra2);
    }
 * 
 * 
 * ----------------------------------------------------------------------------------------------------------
 * VARIÁVEIS
 * -> Lembrando que nomes de váriaveis não pode começar com números, caracteres especiais ou palavras chaves reservadas da linguagem c.
 * -> podemos criar várias variaveis na mesma linha, desde que elas sejam do mesmo tipo e estejam separadas por vírgula (exemplo: int x, y, z;)
 * 
 * Tipos de váriaveis:
 * char => pode ser 1 character apenas representado por aspas simples EXEMPLO: 'Z', 'A'
 * ou uma string como um nome EXEMPLO: char nome[20] = "alex"; sempre representada por um vetor
 * 
 * LONG => O formato de escrita de um long na função printf é   %l 
 * SHORT => O formato de escrita de um SHORT na função printf é   %h
 * UNSIGNED => Formato não negativo, ou seja, os algarismos começam do 0
 * 
 * 
 * REAIS => O formato de escrita de um real na função prinft é %f
 * float peso = 72.90; ("real") = possui 6 dígitos de precisão = ocupa 4 bytes ou seja 2^32 algarismos
 * double numeroPI = 3.145678 = possui 10 digitos de precisão = ocupa 8 bytes ou seja 2^64 algarismos
 * long double piMaior = 3.145637864 = possui 10 digitos de precissão = ocupa 10 bytes ou seja 2^80
 * 
 * ->Toda operação matemática que envolva números inteiros e pelo menos 1 número real, todos os outros números inteiros, são automaticamente convertidos em número real para a realização da operação.
 * 
 * 
 * INTEIROS => O formato de escrita de um inteiro na função prinft é %d
 * int idade = 10; (inteiro) = não possui virgula = ocupa 2 bytes ou seja 2^ 16 algarismos(-32768 até 32767)
 * short int => inteiro = não possui virgula = ocupa 2 bytes ou seja 2^16 algarismos(-32768 até 32767)
 * long int => inteiro = não possui virgula = ocupa 4 bytes ou seja 2^32 algarismos(Max: 2.147.483.647)
 * unsigned int => inteiro = N possui virgula/ Ñ negativo = ocupa 2 bytes ou seja 2^16(de 0 até 65535)
 * unsigned short int = n possui virgula / Ñ negaivo = ocupa 2 bytes ou seja 2^16(de 0 até 65535)
 * unsigned long int = n possui virgula / Ñ negativo = ocupa 4 bytes ou seja 2^32(4.294.967.295)
 * 
 * char name[10] = "alex"; => lembrando que para salvarmos strings temos que indicar o tamanho dela entre chaves
 * char letter = 'z';   => lembrando que char com apenas 1 letra é com 1 aspas, e não 2
 * 
 *------------------------     COMENTÁRIOS NO NOSSO CÓDIGO     ----------------------------------------------
 * // COMENTÁRIOS DE 1 LINHA 
 * /* comentario
 * de 
 * varias 
 * linhas 
 * */
 /*
 
 
 ------------------------------ Funções PRINTF e SCANF  ---------------------------------------------
 printf("alguma coisa aqui dentro"); => vai imprimir algo na tela do usuário
 scanf("ler alguma coisa, algum tipo de input, seja do teclado, arquivo, etc...") => vai ler algum tipo de input
 
 
 ------------------------------- STRINGS  [ %s ] / FUNÇÃO get() / FUNÇÃO put()-----------------------------
 para pegar uma string é preciso ultilizar %s
 
 #include <stdio.h>
 int main(){
     char nome[20];
     nome = "alex";
     printf("Meu nome é %s", nome);
        
     return 0;
 }
    GETS
    Para usar a função gets(), é bem simples, basta passar uma string como argumento.
    A sintaxe é:
    => gets(nome_da_string);

    printf("Sobrenome: ");
    gets(sobrenome);
    
    PUTS    
    Essa função existe e é a puts() (de put string), e sua sintaxe é idêntica a da gets():
    puts( nome_da_string_a_ser_exibida);
    
 *-------------------------         OPERAÇÕES EM C    ---------------------------------------------------------
     ADIÇÃO 
        +  = adição
        
    EXEMPLO: 
    int main(){
        int x = 10; int y = 20;
        int sum = x + y;
        printf("%d", sum);
        return 0; // vai retornar 30
    }
    ----------------------------------------------------------------------------------------------
    SUBTRAÇÃO
          - = subtração
    EXEMPLO:
    int main(){
        float x = 4.5; float y = 2.5;
        less = x - y;
        printf("%f", less);
        return 0; // vai retornar 2.0
    }
    ----------------------------------------------------------------------------------------------
    DIVISÃO
        / = divisão
    EXEMPLO:
    int main(){
        int x = 10; int y = 5;
        division = x/y;
        printf("%d", division);
        return 0; // vai retornar 2
    }
    ---------------------------------------------------------------------------------------------- 
    MUTIPLICAÇÃO
        * = mutiplicação
    EXEMPLO:
    int main() {
        int x = 20; int y = 20;
        multi = x*y;
        printf("%d", multi);
        return 0; // vai retornar 400
    }
    ----------------------------------------------------------------------------------------------
    RESTO DIVISÃO
        % = resto de uma divisão
    EXEMPLO:
        int main(){
            int x = 20; int y = 6;
            resto = x%6;
            printf("%d", resto);
            return 0; // vai retornar 2 que é o resto da divisão
        }
    ----------------------------------------------------------------------------------------------    
    EXPOENTE
        pow(5, 2) = função de expoente = 5 elevado a 2 = 5^2
    EXEMPLO:
        int main(){
            int x = 5; int y = 2;
            power = pow(x, y);
            printf("%d", power);
            return 0;
        }
    ----------------------------------------------------------------------------------------------
    RAIZ QUADRADA
        sqrt(9) = função de raiz quadrada("square root") = raiz quadrada de 9 = 3
    EXEMPLO:
        int main(){
            int x = 9;
            raiz = sqrt(x);
            printf("%d", raiz);
            return 0;
        }
    ----------------------------------------------------------------------------------------------
    
 * ----------------------------    PRIMEIROS PROGRAMAS     ----------------------------------------
 ->sempre temos que adicionar bibliotecas no nosso código C
 -> as principais são:
 #include <stdio.h>
 #include <stdlib.h>
 */
// nossa principal função na linguagem C é a int main() -> aqui dentro é onde nosso código é executado
// toda função termina com ()


// --------------------------------------------------------------------------------------------------------

// escrever um número e dizer qual é o próximo número
/*#include <stdio.h>
int main(){
    int x = 123;
    printf("O nosso numero eh %d e o proximo numero eh %d.", x, x+1);
    return 0;
}*/

// --------------------------------------------------------------------------------------------------------

//EXEMPLO 1
/*int main(){
    int x = 10;
    printf("%d", x);
    return 0; // vai printar o valor de x na tela, no caso 10
}*/

// --------------------------------------------------------------------------------------------------------

//Pulando linhas no nosso código EXEMPLO 2
/*#include <stdio.h>
#include <stdlib.h>
int main(){
    printf("C\n");
    printf(" is the greatest language\n");
    printf(" of all!");
}*/

// --------------------------------------------------------------------------------------------------------

//também podemos escrever o código acima em apenas 1 linha
/*#include <stdio.h>
int main(){
    printf("C\n is the greatest language\n of all!");
}*/

// --------------------------------------------------------------------------------------------------------

// escrever um código onde o caractere especial 2 aspas(") apareça no nosso printf
/*#include <stdio.h>
int main(){
    printf("Hoje está um dia \"LINDO\"!!!\n");
}*/


// --------------------------------------------------------------------------------------------------------//


// vamos escrever algo para o usuário digitar e dar o número ao quadrado
/*#include <stdio.h>
int main(){
    int number;
    printf("Por favor digite um numero: ");
    scanf("%d", &number);
    printf("O quadrado do numero digitado eh: %f", number*number);
    return 0;
}*/

// --------------------------------------------------------------------------------------------------------//

// agora, vamos calcular a área e o perimento de uma circuferência com 2 casas decimais
/*#include <stdio.h>
int main(){
    float pi = 3.14;
    float raio = 5.0;
    float area = pi * raio * raio;
    float perimetro = 2 * pi * raio;
    printf("A area da circuferencia eh %.2f e o perimetro da circuferencia eh %.2f.", area, perimetro);
}*/

// --------------------------------------------------------------------------------------------------------//

// vamos fazer alguns if dentro do nosso código C
/*#include <stdio.h>

int main(){
    int pera, banana, uva;
    pera = 2; 
    banana = 3; 
    uva = 5;
    printf("Joazinho foi a feira comprar algumas frutas!\n A banana custa 3 reais\n A uva custa 5 reais\n E as peras custam 2 reais.\n\n");
    int contPera, contBanana, contUva;
    contPera = 2;
    contBanana = 5;
    contUva = 5;
    printf("Joazinho comprou %d peras, %d bananas e %d uvas.\n\n", contPera, contBanana, contUva);
    printf("Sua mae lhe deu 50 reais para fazer as compras! O dinheiro de joaozinho vai dar para comprar?!\n\n");
    int totalGasto = ((pera*contPera) + (banana*contBanana) + (uva*contUva));
    if(totalGasto<50){
        printf("O dinheiro deu para pagar tudo!");
    }
    else {
        printf("O dinheiro não deu para pagar tudo!");
    }
}*/


// --------------------------------------------------------------------------------------------------------//


//Escreva um algoritmo que calcula o preço total de um produto, 
//tendo como entrada o preço unitário e a quantidade vendida.
/*#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
    float produto;
    int quantidade;
    printf("Por favor, digite o preço do produto: \n");
    produto = 4.5;
    //scanf("%f", &produto);
    printf("Por favor, digite a quantidade de produtos vendidas: \n");
    quantidade = 20;
    //scanf("%d", &quantidade);
    float sum = produto * quantidade;
    printf("O lucro das vendas desse produto eh R$ %.2f reais.", sum);
}*/


// --------------------------------------------------------------------------------------------------------//

/*Escreva um algoritmo para calcular o consumo médio de um 
automóvel (medido em km/l), dada a distância total percorrida e o 
volume de combustível consumido para percorre-la (em litros).*/

/*#include <stdio.h>
#include <stdlib.h>
int main(){
    float distancia, litros;
    distancia = 90.0;
    litros = 32.5;
    printf("A distancia total percorrida foi de %.2f, e o total de litros consumidos foi de %.2f litros.\n\n Ou seja, o consumo medio de km/l eh de %.2f km/litro!", distancia, litros, distancia/litros);
}*/


// --------------------------------------------------------------------------------------------------------//
/*Faça um algoritmo para cálculo do quadrado de um número, ou 
seja, o produto de um número por si mesmo.*/
/*#include <stdio.h>
#include <stdlib.h>
int main(){
    float number;
    number = 10;
    printf("O quadrado do numero %.2f eh de %.2f!", number, number*number);
}*/

// -------------------------------------------------------------------------------------------------------- //
/*Faça um algoritmo para o cálculo da função 2x + 3y^2 num domínio real.*/
/*#include <stdio.h>
#include <stdlib.h>
int main(){
    float x, y;
    x = 2;
    y = 3;
    int calculo = 2*x + 3*(y*y);
    printf("O resultado do calculo eh de %.2f", (float)calculo);
}*/
// --------------------------------------------------------------------------------------------------------//

// -------------- EXERCICIOS DE ESTRUTURA CONDICIONAL (IF, FOR, WHILE, SWITCH..) ------------
// no caso do C, eu nao tenho if else e nem preciso necessariamente ter o else no final da expressão
/*Elaborar um algoritmo que, dada a idade de um nadador, 
classificá-lo nas categorias: infantil A (5 - 7 anos), infantil 
B (8 -10 anos), juvenil A (11 - 13 anos), juvenil B (14 -17 
anos) e adulto (maiores que 18 anos).*/
/*
#include <stdio.h>
#include <stdlib.h>
int main(){
    int idade;
    idade = 20;
    //printf("Por favor, digite sua idade: ");
    //scanf("%d", &idade);
    if(idade >= 5 && idade <= 7){
        printf("A categoria de idade para %d anos eh : INFANTIL.\n", idade);
    }
    if (idade > 7 && idade <=10){
        printf("A categoria de idade para %d anos eh : INFANTIL B.\n", idade);
    }
    if (idade > 10 && idade <= 13){
        printf("A cateogoria de idade para %d anos eh : JUVENIL A.\n", idade);
    }
    if (idade >13 && idade <=17){
        printf("A categoria de idade para %d anos eh : JUVENIL B.\n", idade);
    }
    if (idade < 5){
        printf("Você nao pertence a nenhuma categoria!");
    } 
    if (idade > 17){
        printf("A categoria de idade para %d anos eh : ADULTO.\n", idade);
    }
}
*/


// --------------------------------------------------------------------------------------------------------
// fazer um código para dizer que dia da semana é de acordo com os números 1 e 7 (switch)

/*
#include <stdio.h>
#include <stdlib.h>
int main(){
    int dia = 1;
    printf("Por favor digite um numero de 1 a 7: \n");
    scanf("%d", &dia);
    int x = 1;
    while(x){
        if(dia < 1 && dia < 7){
            printf("Você digitou um numero invalido! Tente novamente")
            scanf("%d", &dia);
            if(dia >= 1 && dia <=7){
                x = 0;
            }
        }
    }
    switch(dia){
        case 1:
            printf("Hoje eh segunda-feira!\n");
            break;
        case 2:
            printf("Hoje é terça-feira!\n");
            break;
        case 3:
            printf("Hoje é quarta-feira!\n");
            break;
        case 4:
            printf("Hoje é quinta-feira!\n");
            break;
        case 5:
            printf("Hoje é sexta-feira!\n");
            break;
        case 6:
            printf("Hoje é sabado!\n");
            break;
        case 7:
            printf("Hoje eh domingo!\n");
            break;
        default:
            printf("Voce digitou um numero invalido!");
    }
}
*/

// --------------------------------------------------------------------------------------------------------//

/*Escreva um algoritmo que lê um valor em reais e calcula 
qual o menor número possível de notas de 100, 50, 10, 5 
e 1 em que o valor lido pode ser decomposto e escreva o 
valor lido e a relação de notas necessárias.  Ex. R$ 477,00 
-> 4 notas de 100,00, 1 nota de 50,00, 2 notas de 10,00, 
1 nota de 5,00 e 2 notas de 1,00*/
/*
#include <stdio.h>
#include <stdlib.h>
int main(){
    int reais;
    printf("--------   BEM VINDO AO BANCO USP ---------\n");
    printf("Por favor digite o valor que voce gostaria de sacar em reais: \n\n");
    printf("Por exemplo: Eu quero sacar R$989.00 reais!\n\n");
    reais = 989;
    //scanf("%f", &reais);
    int notas_100, notas_50, notas_20, notas_10, notas_5, notas_1; 
    int resto_100, resto_50, resto_20, resto_10, resto_5;
    notas_100 = reais / 100; // vai pegar 9 notas = 9 notas de 100 reais
    resto_100 = reais%100; // vai devolver o resto que eh 89
    notas_50 = resto_100 / 50; // vai pegar 89 dividir por 50 = 1 nota de 50
    resto_50 = resto_100% 50; // vai pegar 89 dividir por 50 e pegar o resto que é 39 reais
    notas_20 = resto_50/20; // vai pegar 39 reais que é o resto do 50 e dividir por 20 = 1 nota de 20
    resto_20 = resto_50%20; // vai pegar o resto que é (39%20) e retornar 19 reais
    notas_10 = resto_20/10; // vai pegar 19 reais que é o resto e dividir por 10 (19/10)= vai retornar 1 nota
    resto_10 = resto_20%10; // vai pegar o resto de 20 que é 19 reais, e pegar seu resto(19%10) que é 9 reais
    notas_5 = resto_10/5; // vai pegar 9 e dividir por 5 = vai retornar 1 nota de 5 reais
    resto_5 = resto_10%5; // vai pegar o resto de 9 reais e pegar seu resto % por 5 = vai retornar 4 reais
    notas_1 = resto_5/1; // vai pega o resto de 5 que é 4 reais e dividir por 1 = vai retornar 4 notas de 1 
    printf("Voce vai receber:\n %d notas de R$100.00 reais.\n %d notas de R$50.00 reais.\n %d notas de R$20.00 reais.\n %d notas de R$10.00 reais.\n %d notas de R$5.00 reais.\n E %d notas de R$1.00 real!",notas_100, notas_50, notas_20, notas_10, notas_5, notas_1);
}
*/

// --------------------------------------------------------------------------------------------------------//

/*Qualquer número natural de quatro algarismos pode ser dividido em duas dezenas formadas pelos seus dois primeiros e dois últimos dígitos. (1297 = 12 e 97; 5314 = 53 e 14). Escreva um algoritmo que lê um número inteiro n (de 4 algarismos) e verifica se a raiz quadrada de n é igual a soma das dezenas de n. 
Ex.: n = 9801, dezenas de n = 98 + 01, soma das dezenas 99, raiz quadrada de n = 99. Portanto a raiz quadrada de 9801 é igual a soma de suas dezenas. */
/***TERMINAR ESSE CÓDIGO
#include <stdio.h>
#include <stdlib.h>
int main(){
    int number;
    printf("Por favor digite um número de 4 algarismos: \n\n");
    printf("Digamos que eu escolhi 9801.\n");
    //scanf("%d", &number);
    number = 9801;
    int nub1 = number[0, 1];
    int nub2 = number[2, 3];
    printf("%d%d", nub1, nub2);
}
*/


// --------------------------------------------------------------------------------------------------------//
// escrever um código que pegue strings e imprima na tela
/*
#include <stdio.h>
#include <stdlib.h>
int main(){
    char nome[20] = "alex";
    char sobrenome[20] = "galhardo vieira";
    printf("Meu nome eh: %s %s \n", nome, sobrenome);
}
*/

// --------------------------------------------------------------------------------------------------------//
// FUNÇAO PUTS => como se fosse uma printf mais exclusiva para strings e pula um linha automaticamente
/*
#include <stdio.h>
#include <stdlib.h>
int main(){
    puts("Hello world!"); // é a mesma coisa que printf("Hello world!\n");
}
*/
// --------------------------------------------------------------------------------------------------------//

// quando eu crio uma scanf para pegar uma string eu não preciso usar & como nos numeros
/*
#include <stdio.h>
#include <stdlib.h>
int main(){
    char nome[20], sobrenome[20];
    printf("Por favor digite seu primeiro nome: ");
    scanf("%s", nome);
    printf("Por favor digite seu sobrenome: ");
    scanf("%s", sobrenome);
    printf("Seu nome completo é %s %s\n!", nome, sobrenome);
}
*/

// --------------------------------------------------------------------------------------------------------//

// vamos usar o GETS AGORA
/*
#include <stdio.h>
#include <stdlib.h>
int main(){
    char nome[20];
    printf("Por favor, digite seu nome completo: \n");
    gets(nome);
    printf("Seu nome completo é: %s", nome);
}
*/

// --------------------------------------------------------------------------------------------------------//

// vamos ciar uma função com laço infinito até o usuário apertar enter e mandar branco
/*
#include <stdio.h>
#include <stdlib.h>
int main(){
    char nome[50];
    while(1) {// laço infinito
        puts("Nome: ");
        gets(nome);
        if (nome[0]=='\0'){
            break;
        }
        else{
            printf("Nome introduzido: %s\n", nome);
        }
        
    }
}
*/

// --------------------------------------------------------------------------------------------------------//
// SLIDE 3 - EXERCICIO 3
/*Qualquer número natural de quatro algarismos pode ser 
dividido em duas dezenas formadas pelos seus dois 
primeiros e dois últimos dígitos. (1297 = 12 e 97; 5314 = 
53 e 14). Escreva um algoritmo que lê um número inteiro 
n 
(de 4 algarismos) e verifica se a raiz quadrada de n é 
igual a soma das dezenas de 
n
. 
Ex.: n = 9801, dezenas de n = 98 + 01, soma das 
dezenas 99, raiz quadrada de n = 99. Portanto a raiz 
quadrada de 9801 é igual a soma de suas dezenas. */
/*
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
    int x, soma, primeiros, ultimos;
    float raizNumero;
    printf("Por favor digite um numero inteiro de 4 algarismos: \n\n");
    //scanf("%d", &x);
    printf("Digamos que o numero seja 9801. \n\n");
    x = 9801;
    raizNumero = sqrt(x);
    primeiros = x/100;
    ultimos = x%100;
    soma = primeiros + ultimos;
    printf("Os dois primeiros numeros sao %d e os dois ultimos sao %d!\n\n", primeiros, ultimos);
    if(soma != raizNumero){
        printf("A soma dos dois primeiros e dos dois ultimos algarismos eh %.2f, e a raiz do numero fornecido eh %.2f, assim, a soma dos 2 numeros nao eh igual a raiz do numero fornecido!\n\n", soma, raizNumero);
    }
    if(soma == raizNumero){
        printf("A soma dos dois primeiros e dos dois ultimos algarismos eh %.2d, e a raiz do numero fornecido eh %.2f, assim, a soma dos 2 numeros EH igual a raiz do numero fornecido!\n\n", soma, raizNumero);
    }
    
}
*/

// --------------------------------------------------------------------------------------------------------//

// vamos escrever uma função que pede o estado civil da pessoa sem os parenteses depois do IF
/*
#include <stdio.h>
#include <stdlib.h>
int main(){
    char estadoCivil; // ***lembrando que char é sempre 1 letra e com aspas simples***
    printf("Digite seu estado civil atual: \n\n");
    estadoCivil = getchar();
    if(estadoCivil == 'S' || estadoCivil == 's')
        printf("Solteiro");
    else 
        if(estadoCivil == 'C' || estadoCivil == 'c')
            printf("Casado.\n");
        else
            if(estadoCivil == 'D' || estadoCivil == 'd')
                printf("Divorcidado.\n");
            else
                if(estadoCivil == 'V' || estadoCivil == 'v')
                    printf("Viúvo.\n");
                else
                    printf("Estado civil invalido.\n");
    
}
*/
// --------------------------------------------------------------------------------------------------------//

// vamos escrever uma função que pede para pessoa escrever um dos nomes 
/*
#include <stdio.h>
#include <stdlib.h>
int main(){
    char nome[20];
    printf("Por favor digite um dos nomes abaixos, para escolher seu vilão: \n 1-Batman\n2-Homem Aranha\n3-Logan.\n\n");
    scanf("%s", nome);
    if(nome == "Batman" || nome == "batman"){
        printf("O seu vilão é o Coringa! HAHAHA\n");
    }
    if(nome == "Homem Aranha" || nome == "homem aranha"){
        printf("O seu vilão é o VENOM! HAHAHAHA.\n");
    }
    if(nome == "Logan" || nome == "logan"){
        printf("O seu vilão é seu proprio veneno! :c.\n");
    }
    printf("%s", nome);
}
*/

// --------------------------------------------------------------------------------------------------------//

// vamos escrever um código que calcula a taxa selic com uma renda de 12% ao ano, ou 1% ao mês, durante 10 anos.
/*
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
    int total_anos, total_meses;
    float capital_inicial, renda_mensal, renda_anual;
    printf("Por favor digite o total de dinheiro que você vai investir: \n\n");
    scanf("%f", &capital_inicial); // digamos que ele começe com 1000 reais
    //capital_inicial = 1000;
    printf("Por favor, digite quantos meses você quer que seu dinheiro inicial renda: \n\n");
    scanf("%d", &total_meses); // digamos 36 meses = 3 anos
    //total_meses = 36;
    printf("Por favor, digite quantos anos você quer que seu dinheiro renda: \n\n");
    scanf("%d", &total_anos); // digamos 10 anos
    //total_anos = 10;
    renda_mensal = capital_inicial * (pow(1.01, total_meses));
    renda_anual = capital_inicial * (pow(1.12, total_anos));
    printf("Durante %d meses, o seu montante será de %.2f!\n\n", total_meses, renda_mensal);
    printf("Durante %d anos, o seu montante será de %.2f!\n\n", total_anos, renda_anual);
    
}
*/

// ----------------------------------------------------------------------------------------------------

//** ---------------------------------- LISTA DE EXERCÍCIOS 1 ------------------------------------**

/*1.
(F ́acil)
Determine os resultados l ́ogicos das express ̃oes mencionadas, assinalando se s ̃ao
verdadeiras (V) ou falsas (F). Considere para as respostas os seguintes valores:
X= 1,
A= 3,
B= 5,
C= 8 e
D= 7.
#include <stdio.h>
#include <stdlib.h>
int main(){
    int A, B, C, D, X;
    A = 3;
    B= 5;
    C=8;
    D = 7;
    X=1;
    // -------------------------      EXERCICIO A  ------------------------------------------- //
    printf("--  Exercicio da Primeira Lista - ICC - 1 Semestre \n\n");
    printf("Considere os numeros: \nA=3\nB=5\nC=8\nD=7\nX=1\n\n");
    printf("Exericio (a): [ X >= 2?  ]?\n");
    if(X>=2){
        printf("Verdade!\n");
    } else {
        printf("Falso!\n");
    }
    // -------------------------      EXERCICIO B  ------------------------------------------- //
    printf("-------------------------------\n");
    printf("Exericio (b): ![ X > 3?  ]?\n");
    if(!(X>3)){
        printf("Verdade!\n");
    } else {
        printf("Falso!\n");
    }
    // -------------------------      EXERCICIO C  ------------------------------------------- //
    printf("-------------------------------\n");
    printf("Exericio (c): [ X<1 && !(B >= D) ]?\n");
    if((X<1) && !(B >= D)){
        printf("Verdade!\n");
    }else {
        printf("Falso!\n");
    }
    // -------------------------      EXERCICIO D  ------------------------------------------- //
    printf("-------------------------------\n");
    printf("Exericio (d): [ D<0 || C >5 ]?\n");
    if(D<0 || C >5){
        printf("Verdade!\n");
    }else {
        printf("Falso!\n");
    }
    // -------------------------      EXERCICIO E  ------------------------------------------- //
    printf("-------------------------------\n");
    printf("Exericio (e): [ D<0 OU C>5  ] ? \n\n");
    if(D<0 || C>5){
        printf("Verdade!\n");
    }else {
        printf("Falso!\n");
    }
    // -------------------------      EXERCICIO F  ------------------------------------------- //
    printf("-------------------------------\n");
    printf("Exericio (f): [ !D<0 AND C>5 ] ? \n\n");
    if(!(D<0) && (C>5)){
        printf("Verdade!\n");
    }else {
        printf("Falso!\n");
    }
    // -------------------------      EXERCICIO G  ------------------------------------------- //
    printf("--------------------------------\n");
    printf("Exericio (g): [  !(D>3) || !(B<7)] ?\n\n");
    if(!(D>3) || !(B<7)){
        printf("Verdade!\n");
    }else {
        printf("Falso!\n");
    }
    // -------------------------      EXERCICIO H ------------------------------------------- //
    printf("------------------------------------\n");
    printf("Exericio (h): [ !(X>3) OU (C<7) ] \n\n?");
    if(!(X>3) || (C<7)){
        printf("Verdade!\n");
    }else {
        printf("Falso!\n");
    }
    // -------------------------      EXERCICIO I ------------------------------------------- //
    printf("------------------------------------\n");
    printf("Exericio (i): [ A.B AND !C>B ] ? \n\n");
    if((A>B) || !(C>B)){
        printf("Verdade!\n");
    }else {
        printf("Falso!\n");
    }
    // -------------------------      EXERCICIO J ------------------------------------------- //
    printf("-------------------------------------\n");
    printf("Exericio (j): [ A>B || C>B  ] ?\n\n");
    if(A>B || C>B){
        printf("Verdade!\n");
    }else {
        printf("Falso!\n");
    }
    return 0;
}
*/


// ------------------------------ EXERCICIO 2 ------------------------------------------------
/*(F́acil)
Desenvolva um algoritmo que leia um n ́umero inteiro positivo, calcule e escreva*/
/*
#include <stdio.h>
#include <stdlib.h>
int main(){
    int number, quadrado, cubo;
    printf("------ EXERCICIO 2 DA LISTA ------- \n\n");
    printf("Por favor, digite um numero inteiro: \n\n");
    //scanf("%d", &number);
    number = 20;
    printf("Agora vamos te dar o quadrado e o cubo do numero digitado!\n\n");
    quadrado = number * number;
    cubo = number * number * number;
    printf("O quadrado do numero %d eh: %d;\n\nE o cubo do numero %d eh: %d!", number, quadrado, number, cubo);
    return 0;
}
*/

// ---------------------------     EXERCICIO 3 ----------------------------------------------------
/*
3.(F́acil)
Desenvolva um algoritmo que leia um n ́umero, representando uma temperatura
na escala Celsius, calcule e escreva.
(a)  Seu correspondente em Farenheit:
F= (9*C)/5 + 32

(b)  Seu correspondente em Kelvin (
K= C+ 273)
*/
/*
#include <stdio.h>
#include <stdlib.h>
int main(){
    float C, F, K;
    printf("----- EXERCICIO 3 DA LISTA ----\n\n");
    printf("Por favor digite um valor real em celsius que voce deseja converter: \n\n");
    printf("Por exemplo 40.\n");
    C = 40;
    //scanf("%f", &C);
    printf("Agora iremos converter de Celsius para Kelvin e Farenheit!\n\n");
    F = (9*C)/5 + 32;
    K = C + 273;
    printf("De acordo com o numero digitado, convertendo %.2f Celsius, temos:\n\nFarenheit = %.2f\nKelvin = %.2f.", C, F, K);
    return 0;
}
*/


// ------------------------------- EXERCICIO 4 --------------------------------------------------
/*
4.
(F́acil)Desenvolva um algoritmo que leia um n ́umero, representando um ˆangulo qul-quer entre 0oe 360o, calcule e escreva seu correspondente em radianos (rad= π·angle/180).
*/
/*
#include <stdio.h>
#include <stdlib.h>
int main(){
    float angulo, radianos;
    printf("----- EXERCICIO 4 DA LISTA ------\n\n");
    printf("Por favor digite um numero real que represente um angulo de 0 a 360: \n\n");
    angulo = 180;
    //scanf("%f", &angulo);
    radianos = (3.14 * angulo)/180;
    printf("Segundo o valor fornecido %0.2f, temos que o valor em radianos eh: \n\nRadianos = %.2f!", angulo, radianos);
    return 0;
}
*/

// ---------------------------------- EXERCICIO 5 -----------------------------------------------------
/*
5.(F́acil) Desenvolva  um  algoritmo  que  leia  a  altura  (metros)  e  a  massa  (kg)  de  umapessoa, calcule e escreva o Indice de Massa Corporal (IMC). ==> (IMC=massa/altura2). */
/*
#include <stdio.h>
#include <stdlib.h>
int main(){
    float IMC, altura, massa;
    printf("---- EXERCICIO 5 DA LISTA ---- \n\n");
    printf("Por favor, digite a sua altura em metros: \n\n");
    altura = 1.70;
    printf("Digamos que a altura seja 1.70m\n\n");
    //scanf("%f", altura);
    printf("Por favor, adora digite a sua massa em KG: \n\n");
    massa = 70.0;
    printf("Digamos que a massa seja 70kg.\n\n");
    //scanf("%f", &massa);
    printf("Agora vamos calcular o seu Indice de Massa Corporal (IMC)...\n\n");
    IMC = (massa / (altura * altura));
    printf("Com %0.2f metros de altura e %.2f kilos de massa, o seu IMC eh\n\nIMC = %.2f", altura, massa, IMC);
    return 0;
}
*/

// --------------------------------   EXERCICIO 6 ----------------------------------------------------------
/*6.
(Medio)Desenvolva um algoritmo que receba como entrada dois valores inteiros e armazene nas varíaveis a e b , depois troque os valores de a com b e escreva-os na tela*/
/*
#include <stdio.h>
#include <stdlib.h>
int main(){
    int a, b, inicial_a, inicial_b;
    printf("---- EXERCICIO 6 DA LISTA ----\n\n");
    printf("Por favor digite um numero inteiro para a variavel A: \n\n");
    a = 20;
    printf("Digamos que \"a\" seja 20.\n\n");
    //scanf("%d", &a);
    printf("Por favor, agora digite outro numero inteiro para a variavel B: \n\n");
    b = 30;
    printf("Digamos que \"b\" seja 30.\n\n");
    //scanf("%d", &b);
    // eu criei mais 2 variaveis para armazenar os valores iniciais dados
    inicial_a = a;
    inicial_b = b;
    a = inicial_b;
    b = inicial_a;
    printf("Dado os dados: \n A = %d e \n B= %d,\n\n Trocando os valores das variaveis temos:\n\n A= %d\nB=%d", inicial_a, inicial_b, a, b);
    return 0;
}

*/

// ------------------------------------- EXERCÍCIO 7 ------------------------------------------------------
/*7.(F́acil )Desenvolva um algoritmo que leia uma quantidade em horas, minutos, segundos
  e escreva a quantidade total de segundos equivalente. */
/*
#include <stdio.h>
#include <stdlib.h>
int main(){
    int horas, minutos, segundos, converter_horas, converter_minutos, soma_total;
    printf("---- EXERCICIO 7 DA LISTA ---- \n\n");
    printf("Por favor digite quantas horas voce quer converter para segundos: \n\n");
    scanf("%d", &horas);
    printf("Por favor, agora digite quantos minutos voce quer converter para segundos: \n\n");
    scanf("%d", &minutos);
    printf("Por favor, agora digite os segundos restantes: \n\n");
    scanf("%d", &segundos);
    converter_horas = horas * 3600;
    converter_minutos = minutos * 60;
    soma_total = converter_horas + converter_minutos + segundos;
    printf("Segundo os dados informados: \n\n %d Horas,\n%d Minutos e\n%d Segundos, \n\n Temos o total de: \n %d Segundos!", horas, minutos, segundos, soma_total);
    return 0;
}
*/

// ------------------------------------- EXERCICIO 8 -------------------------------------------------------
/*8.(F́acil) Desenvolva um algoritmo que leia uma velocidade em m/s, converta para km/h e escreva na tela.*/
/*
#include <stdio.h>
#include <stdlib.h>
int main(){
    printf("---- EXECICIO 8 DA LISTA ----\n\n");
    float velocidade, km_hora;
    printf("Por favor, digite a velocidade em \"Metros\"/por segundo que voce gostaria de converter para KM/hora: \n\n");
    velocidade = 30;
    printf("Digamos que o usuario tenha digitado 30.\n\n");
    //scanf("%f", &velocidade);
    km_hora = velocidade * 3.6;
    printf("Convertendo o valor de velocidade dado: %.2f metros/segundo para KM/h temos:\n\n %.2f KM/hora!", velocidade, km_hora);
    return 0;
}
*/
// --------------------------------------- EXERCICIO 9 ------------------------------------------------------
// SOMEONE HELP ME HERE PLEASE :C
/*9.(Dif́ıcil) Desenvolva um algoritmo que leia a data de nascimento (dd/mm/aaaa) de uma
pessoa e a data atual, calcule e escreva a idade da pessoa. */
/*
#include <stdio.h>
#include <stdlib.h>
int main(){
    printf("---- EXERCICIO 9 DA LISTA ---- \n\n");
    int ano, mes, dia, ano_atual;
    printf("Por favor, digite o ano em que voce nasceu: \n\n");
    scanf("%d", &ano);
    printf("Por favor, agora digite o numero correspondente ao mes em que voce nasceu: \n\n");
    scanf("%d", &mes);
    printf("Por favor, agora digite o dia em que voce nasceu: \n\n");
    scanf("%d", &dia);
    ano_atual = 2017;
    dif_ano = ano_atual - ano;
    dif
}
*/
// ------------------------------------ EXERCICIO 10 --------------------------------------------------------
/*
10.(Ḿedio)
Desenvolva  um  algoritmo  que  leia  as  coordenadas  de  dois  pontos:
P1(x1, y1) e P2(x2, y2) e calcule a distancia entre esses dois pontos. A equação é dada a seguir:
distancia = sqrt((x2-x1)**2)+(y2-y1)**2); 
*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
    printf("---- EXERCICIO 10 DA LISTA ---- \n\n");
    float x1, x2, y1, y2, distancia;
    printf("Vamos começar pegando as coordenadas do primeiro ponto: P1. \n\n");
    printf("Por favor, digite a coordenada x1 do ponto P1: \n");
    scanf("%f", &x1);
    printf("Por favor, agora digite a coordenada y1 do ponto P1: \n\n");
    scanf("%f", &y1);
    printf("Agora vamos pegar as coordenadas do segundo ponto: P2. \n\n");
    printf("Por favor, digite a coordenada x2 do ponto P2: \n");
    scanf("%f", &x2);
    printf("Por favor, agora digite a coordenada y2 do ponto P2: \n\n");
    scanf("%f", &y2);
    // pego as coordenadas, vamos fazer a conta da distancia entre os pontos
    distancia = sqrt(((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1)));
    printf("Pegando os pontos:\nP1(%.2f, %.2f) e \n P2(%.2f, %.2f) \n temos a distancia entre esses dois pontos de %.2f!", x1, y1, x2, y2, distancia); 
    return 0;
}
*/

// ------------------------------------------- EXERCICIO 11 -----------------------------------------------
/*11.
(M ́edio)
Desenvolva um algoritmo que leia dois ńumeros, calcule e escreva.
(a)  A ḿedia arit ́etica (mediaA =(a+b)/2).
(b)  A ḿedia geometrica(media G=√a·b).
(c)  A media harmonica (mediaH  = 2/((1/a)+(1/b))
*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
    printf("---- EXERCICIO 11 DA LISTA ---- \n\n");
    float harmonica, a, b, aritmetica, geometrica;
    printf("Vamos calcular 3 medias diferentes! \n\n");
    printf("Por favor, digite um valor inteiro para a letra A: \n\n");
    a = 25.0;
    printf("Digamos que A seja 10. \n\n");
    //scanf("%d", &a);
    printf("Por favor, digite outro valor inteiro para a letra B: \n\n");
    b=30.0;
    printf("Digamos que B seja 20. \n\n");
    //scanf("%d", &b);
    aritmetica = (a+b)/2;
    geometrica = sqrt(a*b);
    harmonica = 2/((1/a) + (1/b));
    printf("Sendo os valores de a e b:\n A = %.2f\nB = %.2f\n temos as medias: \n Aritmetica = %.2f\nGeometrica = %.2f \n Harmonica = %.2f. \n", a, b, aritmetica, geometrica, harmonica);
    return 0;
}
*/

// -----------------------------------------EXERCICIO 12 ------------------------------------------------
/*
12.
(F́acilQuais variaveis a seguir são permitidos pelo compilador C? Faça o teste com as variaveis a seguir:
x1• (PERTMITIDA)
1s• (NAO PERMITIDA)
ijk (PERMITIDA)
5•  (NAO)
Ac5• (PERMITIDA)
I3E• (PERMITIDA)
teste• (PERMITIDA)
if• (NÃO)
3 (NÃO)
kg• (NÃO)
.R• (NÃO)
var inteira• (NÃO)
&n• (NÃO)
#a2• (NÃO)
nao-pertence• (NÃO)
preço• (PERMITIDA)
c̃ao•(NÃO)
ńumero•(PERMITIDA)
ab() (NÃO)
/* (NÃO)
*/
// -----------------------------------------EXERCICIO 13 ------------------------------------------------
/*
13.
(F́acil)
Descubra  o  que  o  programa  FazAlgo  faz  e  descreva  abaixo.   Os  nomes  das
varíaveis do programa foram alterados afim de dificultar o exerc ́ıcio.

Programa FazAlgo ()
I n i c i o
Real :  a ;
Real :  r e s u l t 1 ;
Real :  r e s u l t 2 ;
Real : VALORCONST;
VALORCONST = 3 ,1415;
Escreva ( ”Entre com um numero  p o s i t i v o :  ” ) ;
Leia ( a ) ;
r e s u l t 1 = 2∗VALORCONST∗a ;
r e s u l t 2 = VALORCONST∗a∗a ;
Escreva ( ” Resultado  1:  ” ,  r e s u l t 1 ) ;
Escreva ( ” Resultado  2:  ” ,  r e s u l t 2 ) ;
Fim .
*/
/*
#include <stdio.h>
#include <stdlib.h>
int main(){
    printf("---- EXERCICIO 13 DA LISTA ----\n\n");
    printf("O algoritmo nos fornece o calculo da area e do comprimento de uma circuferencia!\n\n");
    printf("A variavel real \"A\" equivale ao raio de um circulo. \n\n");
    printf("A variavel real \"resultado 1\" equivale ao comprimento da circuferencia!\n\n");
    printf("E a variavel real \"resultado 2\" equivale a area de um circulo!\n");
    return 0;
    
}
*/

// -----------------------------------------EXERCICIO 14 ------------------------------------------------
/*
14.
(F́acil)Descubra  o  que  o  programa  FazAlgo2  faz  e  descreva  abaixo.   Os  nomes  das vari ́aveis do programa foram alterados afim de dificultar o exerc ́ıcio
Programa FazAlgo2 ()
I n i c i o
Real :  k ;
Real :  l ;
Real : m;
Real :  r1 ;
Real :  r2 ;
Escreva ( ”Entre com  t r e s  numeros  r e a i s  (k ,  l , m)  e com (k !=  0) :  ” ) ;
Leia (k) ;
Leia ( l ) ;
Leia (m) ;
d = l∗l−4∗k∗m;
r1 = (−l+Raiz (d) ) /(2∗k);
r2 = (−l−Raiz (d) ) /(2∗k);
Escreva (” Resultado  1:  ” ,  r1 ) ;
Escreva ( ” Resultado  2:  ” ,  r2 ) ;
Fim .
*/
/*
#include <stdio.h>
#include <stdlib.h>
int main(){
    printf("---- EXERCICIO 14 DA LISTA ---- \n\n");
    printf("O algoritmo nos fornece a resolucao de uma formula de baskara a partir de 3 variaveis de input!\n\n");
    printf("As variaveis k, l, m equivalem aos coeficientes A, B, e C da nossa equacao de segundo grau!\n\n");
    printf("As variaveis reais r1 e r2 equivalem:\n r1= o valor de X quando usamos o \"+\" da equacao antes da raiz.\nr2= o valor de X quando usamos o \"-\" da equacao antes da raiz.\n\n");
    return 0;
}
*/


// -----------------------------------------EXERCICIO 15 ------------------------------------------------
/*
15.
(F́acil)
Desenvolva um algoritmo que leia 3 ńumeros inteiros,  os quais representam o
primeiro termo, o   ́ultimo termo e a soma dos termos de uma progress ̃ao arim ́etica, e
em seguida calcule o ńumero de termos nessa PA.*/
/*
#include <stdio.h>
#include <stdlib.h>
int main(){
    printf("---- EXERCICIOS 15 DA LISTA ----- \n\n");
    int soma, primeiro, ultimo, n_termos;
    printf("Por favor, digite o primeiro termo de uma progressao aritmetica: \n\n");
    scanf("%d", &primeiro);
    printf("Por favor, digite o ultimo termo de uma progressao aritmetica: \n\n");
    scanf("%d", &ultimo);
    printf("Por favor, digite a soma total da progressao aritmetica: \n\n");
    scanf("%d", &soma);
    n_termos = (soma*2)/(primeiro+ultimo);
    printf("O numero de termos dessa progressao aritmetica eh: %d!.\n\n", n_termos);
    return 0;
}
*/

// --------------------------------------EXERCICIO 16 -------------------------------------------------------
/*
16.
(Ḿedio)
Desenvolva um algoritmo que leia dois n ́umeros que representam as dimens ̃oes
(em  metros)  de  uma  sala.   O  ch̃ao  dessa  sala  ser ́a  revestido  de  azulejos  de  dimens ̃oes
1x1m, podendo ser brancos ou pretos.  Considerando que os azulejos s ̃ao dispostos assim
como em um tabuleiro de xadrez, ou seja, adjacentes apenas `a azulejos da outra cor, e
que o n ́umero total de azulejos  ́e par, calcule o n ́umero de azulejos pretos necess ́arios.
*/
/*
#include <stdio.h>
#include <stdlib.h>
int main(){
    printf("---- EXERCICIO 16 ---- \n\n");
    int largura, comprimento, area, prova_real;
    printf("Por favor, digite pelo menos um numero inteiro par nas proximas perguntas.\n\n");
    printf("Por favor, digite a largura da sala: \n\n");
    scanf("%d", &largura);
    printf("Por favor, agora digite o comprimento da sala: \n\n");
    scanf("%d", &comprimento);
    area = largura * comprimento;
    prova_real = area % 2;
    if(prova_real != 0){
        while(area % 2 !=0){
            printf("Por favor, digite pelo menos um numero inteiro par nas proximas perguntas.\n\n");
            printf("Por favor, digite a largura da sala: \n\n");
            scanf("%d", &largura);
            printf("Por favor, agora digite o comprimento da sala: \n\n");
            scanf("%d", &comprimento);
        }
    }
    // falta conferir como eu vou calcular qntos azulejos pretos tem nessa sala.
    return 0;
}
*/

// -------------------------- EXEMPLO DE FUNÇÃO PARA VER SE É NUMERO PRIMO OU NÃO ---------------------
/*
#include <stdio.h>
#include <stdlib.h>
int primo(int n){
    int c, i;
    i=2;
    c=1;
    while((i<n) && (c)){
        if(n%i == 0){
            c=0;
            printf("%d", c);
        }else{ 
            i = i+1;
        }
    return 0;
}
//int primo(int);
int main(){
    int n;
    printf("Por favor digite um numero: "); 
    printf("Digamos que o numero seja 7.\n\n");
    n = 7;
    //scanf(“%d”,&n);
    if(primo(n)){
        printf("%d eh primo", n);
    }else{ 
        printf("%d nao eh primo", n);
    }
    return 0;
}
*/
// ------------------------------------------- EXERCICIO 1 - LABORATORIO --------------------------------
/*1. (F´acil) Desenvolva um algoritmo capaz de identificar um triˆanglo retˆangulo com base
nas medidas inteiras de seus lados, que ser˜ao fornecidas pelo usu´ario. Caso os lados
fornecidos sejam os de um triˆangulo retˆangulo, o seu programa dever´a imprimir na tela
’SIM’ e, caso contr´ario, ’NAO’.*/
/*
#include <stdio.h>
#include <stdlib.h>
int main(){
    int lado_1, lado_2, lado_3, hipotenusa, conta;
    printf("Usaremos o teorema de pitágoras para resolver o problema!\n\n");
    printf("Por favor digite o primeiro cateto do triangulo: \n\n");
    //printf("Digamos que o primeiro cateto seja seja 2.\n\n");
    //lado_1 = 3;
    scanf("%d", &lado_1);
    printf("Por favor digite o segundo cateto do triangulo: \n\n");
    //printf("Digamos que o segundo cateto seja 3.\n\n");
    //lado_2 = 4;
    scanf("%d", &lado_2);
    printf("Por favor digite o o maior lado do triangulo: \n\n");
    //printf("Digamos que o terceiro cateto seja 5.\n\n");
    //lado_3 = 5;
    scanf("%d", &lado_3);
    conta = (lado_1*lado_1)+(lado_2*lado_2);
    hipotenusa = lado_3*lado_3;
    if(conta == hipotenusa){
        printf("O triangulo é retangulo!\n\n");
    }else{
        printf("O triangulo nao eh retangulo!\n\n");
    }
    return 0;
}
*/
// ----------------------------- EXERCICIO 4 - LABORATORIO --------------------------------------------------
/*
4. (Dif´ıcil) Vocˆe est´a em uma partida de rpg com seus amigos e decide atacar uma unidade
inimiga, mas n˜ao sem antes analisar a situa¸c˜ao. Sabe-se que cada unidade possui trˆes
atributos: hp, ataque e defesa. Al´em disso, existem trˆes tipos de arma: machado, espada
e lan¸ca. Ambas s˜ao capazes de infringir o mesmo dano, contudo, existe a seguinte rela¸c˜ao
entre elas:
Arma Vantagem
Machado Lan¸ca
Espada Machado
Lan¸ca Espada
Dessa forma, se uma unidade equipada com machado for atacada por outra equipada
com espada, ela tomar´a o dobro de dano que tomaria normalmente. Da mesma forma,
se atacar algu´em equipado com lan¸ca, dar´a o dobro do dano normal. N˜ao h´a nenhum
modificador de dano quando as armas forem iguais.
O dano ´e calculado da seguinte maneira: dano = ataque*mod - defesa
Page 2
Onde mod ´e o modificador de dano que dever´a ser atribu´ıdo tendo como base a tabela
de rela¸c˜oes mostrada anteriormente.
Desenvolva um algoritmo capaz de calcular a hp restante que a sua unidade e o inimigo
ter˜ao ap´os o combate, para que, ent˜ao, vocˆe possa decidir se ir´a ou n˜ao atac´a-lo. O
programa dever´a receber como entrada: o equipamento (’M’, ’E’ ou ’L’) e os valores de
hp, ataque e defesa (todos inteiros, nesta ordem), tanto para a sua unidade, quanto para
unidade inimiga.
Por fim, vocˆe ir´a atacar somente se a sua hp final for maior do que a hp final do inimigo.
Exemplo de entrada Exemplo de saida
’M’ 60 15 50 e ’L’ 40 5 10 Far´a o ataque
OBS: caso o valor do dano seja menor que zero, vocˆe dever´a considerar que ele ser´a
igual a zero.*/
/*
#include <stdio.h>
#include <stdlib.h>
int main(){
    printf("--- Vamos jogar Dungeon And Dragons! ---\n\n");
    int hp_personagem, hp_inimigo, def_personagem, def_inimigo, ataque, weapon_personagem, weapon_inimigo, mod = 1;
    char machado, espada, lança;
    // PRIMEIRO VAMOS SELECIONAR O ATAQUE PADRAO DO JOGO
    printf("Por favor, selecione um ataque padrão para o jogo entre 1 e 5. \n\n");
    printf("Digamos que o ataque padrao do jogo seja 5.\n\n");
    ataque = 5;
    //scanf("%d",&ataque);
    
    // AGORA VAMOS PEGAR OS ATRIBUTOS DO PERSONAGEM
    printf("Por favor, selecione uma das armas abaixo para seu PERSONAGEM: \n");
    printf("---Machado[M]---\n");
    printf("---Espada[E]---\n");
    printf("---Lança[L]---\n");
    printf("Digamos que a arma escolhida seja Espada.\n\n");
    weapon_personagem = 'E';
    //scanf("%c", &weapon_personagem); // WEAPON DO USUARIO É ESPADA 'E'
    printf("Por favor, digite a vida do seu personagem de 50 a 100: \n\n");
    printf("Digamos que a vida do usuario seja 100.\n\n"); // 100 de HP usuario
    hp_personagem =100;
    //scanf("%d", &hp_personagem);
    printf("Por favor, selecione um defesa entre 5 e 20. \n\n");
    printf("Digamos que a defesa do personagem seja 2.");
    def_personafem = 2;   //=> DEFESA DO PERSONAGEM IGUAL A 20
    //scanf("%d", &def_personagem);
    
    
    //AGORA VAMOS PEGAR OS ATRIBUTOS DO INIMIGO
    printf("Por favor, selecione uma das armas abaixo para o INIMIGO: \n");
    printf("---Machado[M]---\n");
    printf("---Espada[E]---\n");
    printf("---Lança[L]---\n");
    printf("Digamos que a arma escolhida para o inimigo seja machado. \n\n");
    weapon_inimigo = 'M';
    //scanf("%c", &weapon_inimigo); // DIGAMOS QUE ESCOLHA 'M' para weapon do INIMIGO
    printf("Por favor, digite a vida do inimigo de 50 a 100: \n\n");
    printf("Digamos que a vida do inimigo seja 50.\n\n");
    hp_inimigo = 50;
    //scanf("%d", &hp_inimigo);
    printf("Por favor, selecione uma defesa de 5 a 20 para o inimigo.\n");
    printf("Digamos que a defesa do inimigo seja 1.\n");
    def_inimigo = 1;  // => DEFESA DO INIMIGO IGUAL A 5
    //scanf("%d", &def_inimigo);
    
    
    // VERIFICAR A VIDA DO PERSONAGEM
    if(hp_personagem < 50 && hp_personagem > 100){
        while(hp_personagem < 50 && hp_personagem > 100){
            printf("Por favor, escolha uma vida entre 50 e 100.\n");
            scanf("%d", &hp);
        }
    }
    
    // VERIFICAR VIDA DO INIMIGO
    if(hp_inimigo < 50 && hp_inimigo > 100){
        while(hp_inimigo < 50 && hp_inimigo > 100){
            printf("Por favor, escolha uma vida entre 50 e 100.\n");
            scanf("%d", &hp_inimigo);
        }
    }
    
    // Mostrando os atributos escolhidos entre o personagem e o inimigo
    printf("Mostrando os atributos do personagem e do inimigo.\n");
    // VAMOS FAZER O COMBATE AGORA
    printf("A arma escolhida do usuario é: %c.\n", weapon_personagem);
    printf("A HP escolhida do usuario é: %d.\n", hp_personagem);
    printf("O ataque da arma padrao é 5.\n");
    printf("A defesa escolhida do usuario é: %d.\n", def_personagem);
    // ATRIBUTOS DO INIMIGO
    printf("A arma escolhida do inimigo é: %c.\n", weapon_inimigo);
    printf("A HP escolhida do inimigo é: %d.\n", hp_inimigo);
    printf("O ataque da arma padrao é 5.\n");
    printf("A defesa escolhida do usuario é: %d.\n", def_inimigo);
    //
    if(weapon_personagem == 'E' && weapon_inimigo == 'M'){ // ESPADA X MACHADO
        ataq_personagem = ataq_personagem * ataq_personagem;
    }else if(weapon_personagem == 'E' && weapon_inimigo == 'L'){ // ESPADA X LANÇA
        
    }else if(weapon_personagem == 'E' && weapon_inimigo == 'E'){ // ESPADA x ESPADA
        
    }else if(weapon_personagem == 'M' && weapon_inimigo == 'L'){ // MACHADO X LANÇA
        
    }else if(weapon_personagem == 'M' && weapon_inimigo == 'E'){ // MACHADO X ESPADA
        
    }else if(weapon_personagem == 'M' && weapon_inimigo == 'M'){ // MACHADO X MACHADO
        
    }else if(weapon_personagem == 'M' && weapon_inimigo == 'L'){ // LANÇA X MACHADO
        
    }else if(weapon_personagem == 'M' && weapon_inimigo == 'L'){ // LANÇA X ESPADA
        
    }else if(weapon_personagem == 'M' && weapon_inimigo == 'L'){  // LANÇA X LANÇA
        
    }
    
    
    
    return 0;
}
*/
// ----------------- LABORATORIO - EXERCICIO 4 -----------------------------------------------------------
/*
#include <stdio.h>
#include <stdlib.h>
int main(){
    printf("---- EXERCICIO 4 - LABORATORIO ----\n\n");
    int usu_hp, usu_atq, usu_def, ini_hp, ini_atq, ini_def;
    char weapon, weapon_inimigo, weapon_usuario;
    
    printf("Por favor, escolha uma arma para o personagem: [M] Machado / [E] Espada / [L] Lanca.\n\n");
    printf("Digamos que seja Espada.\n\n");
    weapon_usuario = 'e';
    //scanf("%c", &weapon_usuario);
    while(weapon_usuario != 'm' || weapon_usuario != 'e' || weapon_usuario != 'l'){
        printf("Voce escolheu uma arma invalida! Por favor escolha novamente.");
        scanf("%c", &weapon);
    }   
    // atributos do personagem
    printf("Por favor, digite o HP, o ATAQUE e a DEFESA do personagem: \n\n");
    printf("Digamos que seja 50 40 30.\n\n");
    usu_hp = 50; usu_atq = 40; usu_def = 30;
    //scanf("%d %d %d\n\n", &usu_hp, &usu_atq, &usu_def);
    
    // atributos do inimigo
    printf("Por favor, escolha uma arma para o inimigo: [M] Machado / [E] Espada / [L] Lanca.\n\n");
    printf("Digamos que seja Machado.\n\n");
    weapon_usuario = 'm';
    //scanf("%c", &weapon_inimigo);
    printf("Por favor, digite o HP, o ATAQUE e a DEFESA do personagem: \n\n");
    printf("Digamos que seja 40 30 20.\n\n");
    ini_hp = 40; ini_atq = 30; ini_def = 20;
    //scanf("%d %d %d\n\n", &ini_hp, &ini_atq, &ini_def);
    
    // atacando o inimigo
    if(usu_hp > ini_hp){
        printf("Voce atacara.\n");
    }else if(usu_hp == ini_hp){
        printf("Ira dar empate.\n");
    }else{
        printf("Voce nao atacara.\n");
    }
    return 0;
}
*/
