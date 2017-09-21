/*
Questão 3 (4.0 Pontos): Software Centro de Maternidade
O Centro de Maternidade da cidade de São Carlos necessita de um software para extrair informações sobre bases de dados de bebês. Esse centro de maternidade dispõe de duas bases de dados de bebês: uma mais antiga que se encontra disponível em formato binário (arquivo "dados-bebes.bin") e outra base mais nova em formato de texto (arquivo "dados-bebes.txt"). Desenvolva um programa em C que leia esses dois arquivos e guarde as informações em um vetor de registro. O registro que você deverá utilizar é dado abaixo e contém as seguintes informações: dia, mês e ano do nascimento do bebe, sexo, altura, peso e nome do bebe.

struct bebe{
int dia;
int mes;
int ano;
char sexo;
float altura;
float peso;
char nome[50];
};

Após a leitura dos dados de ambos os arquivos, baseados nos dados do vetor de registro, calcule: a quantidade total de bebês homens, a média da altura dos homens, a média do peso dos homens, a quantidade total de bebês mulheres, a média da altura das mulheres, a média do peso das mulheres. Em seguida, imprima essas informações na tela.

Dica, utilize os comandos abaixo para impressão dessas informações na tela.

printf("Dados dos Bebes Homens: \n");
printf("Total: %d\n", totalM);
printf("Media da Altura: %.2f metros\n", mediaAlturaM);
printf("Media do Peso: %.2f kg\n", mediaPesoM);

printf("Dados dos Bebes Mulheres: \n");
printf("Total: %d\n", totalF);
printf("Media da Altura: %.2f metros\n", mediaAlturaF);
printf("Media do Peso: %.2f kg\n", mediaPesoF);

Para facilitar as coisas sabe-se que cada arquivo contém um total de 6 registros totalizando 12 registros. Dessa forma, pode-se alocar o vetor de registro estaticamente para guardar as informações. Lembre-se que o modo de leitura do arquivos de texto é "r" e que o modo de leitura de arquivos binários é "rb".

Exemplo de Entrada e Saída
Entradas:

(arquivo binário chamado "dados-bebes.bin")
(arquivo de texto chamado  "dados-bebes.txt")
Saída:

Dados dos Bebes Homens:
Total: 5
Media da Altura: 0.53 metros
Media do Peso: 3.32 kg

Dados dos Bebes Mulheres:
Total: 7
Media da Altura: 0.49 metros
Media do Peso: 3.17 kg

*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


typedef struct{
    int dia;
    int mes;
    int ano;
    char sexo;
    float altura;
    float peso;
    char nome[50];
}BEBE;


int main(){

    FILE *arqTxt, *arqBin;

    /* verificação */
    arqTxt = fopen("dados-bebes.txt", "r"); // ler primeiro arquivo TEXTO
    if(arqTxt == NULL){
        printf("\nERRO NA ABERTURA!\n");
        exit(1);
    }

    arqBin = fopen("dados-bebes.bin", "rb"); // ler segundo arquivo BINARIO
    if(arqBin == NULL){
        printf("\nERRO NA ABERTURA!\n");
        exit(1);
    }

    int qtdMulher=0, qtdHomem=0;
    float totAlturaMasc=0, totAlturaFem=0;
    float totPesoMasc=0, totPesoFem=0;
    float mediaPesoMasc=0, mediaPesoFem=0;
    float mediaAlturaMasc=0, mediaAlturaFem=0;



    BEBE bbT[12]; // estrutura de registro


    int j = 0; // POSIÇÃO DO VETOR

    /* ARQUIVO TEXTO */
    do{
        fscanf(arqTxt, "%d %d %d %c %f %f %s", &bbT[j].dia, &bbT[j].mes, &bbT[j].ano, &bbT[j].sexo, &bbT[j].altura, &bbT[j].peso, bbT[j].nome);


        if(tolower(bbT[j].sexo) == 'f'){ // se for mulher, incremente
            qtdMulher++;
            totPesoFem += bbT[j].peso;
            totAlturaFem += bbT[j].altura;
        }
        else{
            qtdHomem++; // senão, incremente homem
            totPesoMasc += bbT[j].peso;
            totAlturaMasc += bbT[j].altura;
        }

        j++;
        if(j==6){
            break;
        }
    }while(!feof(arqTxt));



    /* ARQUIVO BINARIO */
    do{
        fread(bbT, sizeof(BEBE), 1, arqBin); // leia o arquivo binario, de sizeof BEBE, 1, e armazene na struct bbT no index j=6
    }while(!feof(arqBin));

    int i;
    for(i=6; i<12; i++){
        if(tolower(bbT[i].sexo) == 'f'){ // se for mulher, incremente
            qtdMulher++;
            totPesoFem += bbT[i].peso;
            totAlturaFem += bbT[i].altura;
        }
        else{
            qtdHomem++; // senão, incremente homem
            totPesoMasc += bbT[i].peso;
            totAlturaMasc += bbT[i].altura;
        }
    }

    mediaPesoMasc = totPesoMasc / 2;
    mediaAlturaFem = totAlturaFem / 2;

    printf("Dados dos Bebes Homens: \n");
    printf("Total: %d\n", qtdHomem);
    printf("Media da Altura: %.2f metros\n", mediaAlturaMasc);
    printf("Media do Peso: %.2f kg\n", mediaPesoMasc);
    printf("\n\n");
    printf("Dados dos Bebes Mulheres: \n");
    printf("Total: %d\n", qtdMulher);
    printf("Media da Altura: %.2f metros\n", mediaAlturaFem);
    printf("Media do Peso: %.2f kg\n", mediaPesoFem);

    fclose(arqTxt);
    fclose(arqBin);

    return 0;
}
