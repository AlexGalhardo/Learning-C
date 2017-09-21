/* 
 * arquivo: 
 * ------------------
 * Este programa lê uma data (day, month, year) e um inteiro NumDias.
 * Ele determina qual é a data correspondente ao dia seguinte da data fornecida, 
 * e determina também qual é a  data depois de decorrer NumDias (em relaçao à data dada).
 */

#include <stdio.h>
#include <stdlib.h>


/*******   Prototipos das funcoes  ***********************/

int EhBissexto(int ano);
/* devolve 1 se ano é bissexto; 0 em caso contrario */

int NumDiasMes(int mes, int ano);
/* devolve o numero de dias do mes do ano correspondente */
/* Valores possiveis: 31, 30, 29 ou 28                   */

void DataSeguinte(int *dia, int *mes, int *ano);
/* Veja os parâmetros:são apontadores  <==========================Veja  */
/* calcula a data correspondente ao dia seguinte da data dada: */

/************************************************************/

int main()
{
    int day, month, year, NumDias, i;

    printf("Forneca uma data que existe (dia mes ano):\n");
    scanf("%d %d %d", &day, &month, &year);
    printf("Data dada:  %2d /%2d /%4d\n", day, month, year);

    printf("Nao e´ feita verificacao se a data dada é correta\n");
    printf
	("Se a data dada é incorreta, a resposta certamente será incorreta.\n");

    DataSeguinte(&day, &month, &year);	/* chamada da funcao DataSeguinte <====== Veja  */
                                        /* Veja como foi feita a chamada:   */
                                        /* foram passados os endereços das  */
                                        /* variáveis  day, month e year.    */                 
         
    printf("Dia seguinte: %2d /%2d /%4d\n", day, month, year);

    printf
	("Forneca o numero de dias a serem computados a partir da data dada:\n");
    scanf("%d", &NumDias);
    printf("Numero de dias depois da data dada: %d\n", NumDias);

    for (i = 1; i < NumDias; i++)
	DataSeguinte(&day, &month, &year); /* chamada da funcao DataSeguinte */

    printf("Nova data: %2d /%2d /%4d\n", day, month, year);

    system("PAUSE");
    return 0;
}

/********** Funcoes ***********************/

int EhBissexto(int ano)
{
  return ((ano % 4 == 0) && (ano % 100 != 0))
             || (ano % 400 == 0);
}

/******/

int NumDiasMes(int mes, int ano)
{
    if (mes < 1 || mes > 12)
	printf("Tem erro: mes inexistente!\n");
    else
	switch (mes) {
	case 2:
	    if (EhBissexto(ano))
		return 29;
	    else
		return 28;
	case 4:
	case 6:
	case 9:
	case 11:
	    return 30;
	default:
	    return 31;
	}
}


/******/

void DataSeguinte(int *dia, int *mes, int *ano)
{
    int NumeroDeDiasDoMes;

    NumeroDeDiasDoMes = NumDiasMes(*mes, *ano); /* Veja: passagem de valor */

    if (*dia == NumeroDeDiasDoMes) {  /* é o ultimo dia do mes */

	*dia = 1;		/* dia seguinte */

	if (*mes == 12)
	    *ano = *ano + 1;	/* unico caso em que muda o ano; senao o ano fica inalterado */

	*mes = (*mes + 1) % 12;	/* se estiver em dezembro o mes seguinte é janeiro; */
                        	/* senao, é sempre o *mes +1                        */
    } else
	*dia = *dia + 1;	/* se não é final do mes, muda o dia, mas o mes e o ano ficam inalterados */

}
