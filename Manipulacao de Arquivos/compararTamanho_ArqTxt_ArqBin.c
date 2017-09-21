/*
16.  Desenvolva um programa em C para manipula ̧c ̃ao de arquivo. O arquivo
”Lorem Ipsum
- 150 paragraphs - 14000 words - 94370 bytes”
deve ser baixado no link
1
.  Fa ̧ca
a leitura desse arquivo e o grave no formato bin ́ario.  Fa ̧ca uma an ́alise de tamanho do
arquivo bin ́ario gerado em rela ̧c ̃ao ao arquivo de texto.  Escreve as suas conclus ̃oes sobre
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 1600

int main(){

   char nameTxt[] = "Lorem ipsum.txt";
   char nameBin[] = "Lorem ipsum.bin";

   FILE *arqTxt = fopen(nameTxt, "r");
   FILE *arqBin = fopen(nameBin, "wb");

   if(arqTxt != NULL || arqBin != NULL){
        while(!feof(arqTxt)){
            char str[TAM];
            fgets(str, TAM, arqTxt);
            fwrite(str, sizeof(char), strlen(str), arqBin);
        }
   }
   else{
        printf("erro\n");
        return -1;
   }

    fclose(arqTxt);
    fclose(arqBin);

   return 0;
}
