/*Desenvolva  um  programa  em  C  para  manipulacão  de  arquivo.   Os  arquivos
”rndIntMax.txt”
e
”rndIntMax.bin”
devem ser baixados no link.

.  Primeiramente faça a leitura do primeiro ar-
quivo e o grave no formato bin ́ario.  Em seguida, fa ̧ca a leitura do segundo arquivo e o
grave no formato bin ́ario, com outro nome.  Ent ̃ao, fa ̧ca a an ́alise de tamanho dos dois
arquivos bin ́arios gerados.  Compare esses tamanhos com o dos dois arquivos de texto.
Escreve as suas conclus ̃oes sobre essas an ́alises.
*/

#include <stdio.h>
#include <string.h>

#define TAM 1600

int main(){

    char nameTxt[] = "rndIntMax.txt";
    char nameBin[] = "rndIntMax.bin";

    FILE *arqTxt = fopen(nameTxt, "r");
    FILE *arqBin = fopen(nameBin, "wb");

    int value;
    if(arqTxt != NULL || arqBin != NULL){
        while(!feof(arqTxt)){
            int value;
            fscanf(arqTxt, "%d", &value);
            fwrite(&value, sizeof(int), 1, arqBin);
        }
    }else{
        printf("erro\n");
        return -1;
    }

    fclose(arqTxt);
    fclose(arqBin);

    return 0;
}
