#include<stdio.h>
#include<stdlib.h>
#include <time.h>

int quant;

struct jogador
{
	char nome[20];
	int M[6][6];
}cartelas[10];
//------------------------------------------------
void gerartipo1()
{
	FILE*file[quant];
    int i, j, x, y, cont=0,inicio, NumAleatorio;
    char nomecartela[quant][20];

    for(x=0;x<quant;x++)
	{
        sprintf(nomecartela[x],"cartela%d.txt", x+1);
        file[x] = fopen(nomecartela[x], "w");              //Cria os arquivos .txt
	}
 //------------------------------------------------
    srand((unsigned)time(NULL));
	for(y=0;y<quant;y++)
	{
		for(i=0;i<6;i++)											//Gera numeros aleatorios
    	{
        	inicio = i*10+1;
         	for(j=0;j<6;j++)
        	{
            	cartelas[y].M[i][j]=inicio + (rand()%10);
        	}
    	}
	}
//------------------------------------------------
	for(y=0; y<quant; y++)
	{
		for (i=0; i<6; i++)
		{
        	for(j=0; j<6; j++)
			{
            	for(x=0; x<j; x++)
				{
                	if(cartelas[y].M[i][j] ==cartelas[y].M[i][x])    //Compara os numeros da matriz / troca repetido por zero
                    	cartelas[y].M[i][x] = 0;
				}
            }
        }
    }
//-----------------------------------------------
    for(y=0; y<quant; y++)
    {
        cont = 0;
        for (i=0; i<6; i++)
        {
            for(j=0; j<6; j++)
            {
                if(cartelas[y].M[i][j] == 0)                           //Compara os numeros da matriz / incrementa contador
    			cont++;
            }
        }
//------------------------------------------------
        while (cont < 16)
        {
            for (i=0;i<6 && cont < 16; i++)
            {
                for(j=0; j<6 && cont < 16; j++)
                {
                    if (cartelas[y].M[i][j] != 0)            //Enquanto quantidade de zeros for menor que 16 / acrescenta zero
                    {
                        cartelas[y].M[i][j] = 0;
                        j = 6;
                        cont++;
                    }
                }
            }
        }
        while (cont > 16)
        {
            for (i=0;i<6 && cont > 16; i++)         //Enquanto quantidade de zeros for maior que 16 / acrescenta numeros aleatorios
            {
                inicio = i*10+1;
                NumAleatorio = inicio + (rand()%10);
                for(j=0; j<6 && cont > 16; j++)
                {
                    if((cartelas[y].M[i][j] != NumAleatorio) && (cartelas[y].M[i][j] != 0))
                    {
                        cartelas[y].M[i][j] = NumAleatorio;
                        cont--;
                        j = 6;
                    }
                }
            }
        }
    }
//-----------------------------------------------------
    for(y=0;y<quant;y++)
    {
        printf("\nCartela %d\n", y+1);
        for(i=0;i<6;i++)
        {
            printf("\n\n");
            fprintf(file[y],"\n\n");
            for(j=0;j<6;j++)
            {
                printf("%2d  ", cartelas[y].M[i][j]);
                fprintf(file[y],"%2d  ", cartelas[y].M[i][j]);
            }
        }
        fprintf(file[y],"\n\n");
        fclose(file[y]);
        printf("\n\n");
    }
}
//-------------------------------------------------------
void gerartipo2()
{
    int i, y, j, x, inicio, NumAleatorio;
    srand((unsigned)time(NULL));

	for(y=0;y<quant;y++)
    {
        printf("\nCartela %s", cartelas[y].nome);
		for(i=0;i<6;i++)
    	{
        	inicio = i*10+1;
         	 for(j=0;j<6;j++)
        	{
            	cartelas[y].M[i][j] = inicio + (rand()%10);
        	}
    	}
	}
//--------------------------------------------------------
	for(y=0;y<quant;y++)
	{
		for (i=0; i<6; i++)
		{
        	for(j=0; j<6; j++)
			{
            	for(x=0; x<j; x++)
				{
                	if(cartelas[y].M[i][j] == cartelas[y].M[i][x])    //Compara os numeros da matriz / troca repetido por zero
                    	cartelas[y].M[i][x] = 0;
            	}
        	}
    	}
	}
//-------------------------------------------------------
	for(y=0;y<quant;y++)
	{
		printf(" Cartela %d \n", y+1);
    	for(i=0;i<6;i++)
    	{
    		printf("\n\n");
         	 for(j=0;j<6;j++)
        	{
        		printf("%2d  ", cartelas[y].M[i][j]);
        	}
    	}
    	printf("\n\n\n\n\n");
	}
}
//-------------------------------------------------------
void mostrar()
{
    int y, i, j, x;
    for(y=0;y<quant;y++)
	{
		printf("Cartela do jogador %s\n",cartelas[y].nome);
    	for(i=0;i<6;i++)
    	{
    		printf("\n\n");
         	 for(j=0;j<6;j++)
        	{
        		printf("%2d  ", cartelas[y].M[i][j]);
        	}
    	}
    	printf("\n\n\n\n\n");
	}
}
//-------------------------------------------------------
void jogar()
{
    int i, y, j, x, k, contZero, NumAleatorio[60];
    srand((unsigned)time(NULL));

    for (x=0; x<60; x++)
    {
        NumAleatorio[x] = 1+rand()%60;
        for (k=0; k<x; k++)
        {
            if (NumAleatorio[x] == NumAleatorio[k])
            {
                NumAleatorio[x] = 1+rand()%60;
                k=0;
            }
        }
        _sleep(1000);                                                       // delay
        system("cls");                                                      // limpa tela
        printf("\n\tNumeros Sorteados: ");
        for (k=0; k<x; k++)                                                 // mostra numeros sorteados
        {
            printf("%d ", NumAleatorio[k]);
        }
        printf("\n\n\n\n");

        for (y=0; y<quant; y++) // percorre as cartelas
        {
            contZero = 0;
            for(i=0; i<6; i++)      // percorre os campos comparando os numeros batidos
            {
                for(j=0; j<6; j++)
                {
                    if (NumAleatorio[x] == cartelas[y].M[i][j])
                    {
                        cartelas[y].M[i][j] = 0;
                    }
                }
            }

            for(i=0; i<6; i++)      // percorre os campos contadando os zeros
            {
                for(j=0; j<6; j++)
                {
                    if (cartelas[y].M[i][j] == 0)
                    {
                        contZero++;
                    }
                }
            }
            if (contZero == 36) // Verifica o vencedor
            {
                mostrar();
                printf("\n\n\t\t VENCEDOR : %s \n\n", cartelas[y].nome);
                return;
            }
        }
        mostrar();
    }


}

//-------------------------------------------------------
int main()
{
	int continuar=1,tipo, i=0;
	do
	{
		printf("--------------------------------------------\n");
		printf(" ---------####-------------------------------\n");
		printf("  --------#---#-------------------------------\n");
		printf("   -------#---#---#---#----#----###-----###----\n");
		printf("    ------#-##----#---##---#---#-------#---#----\n");
		printf("     -----#---#---#---#-#--#---#--##---#---#-----\n");
		printf("      ----#---#---#---#--#-#---#---#---#---#------\n");
		printf("       ---####----#---#---##----###-----###--------\n");
		printf("        --------------------------------------------\n\n\n");

		printf("\tMENU\n\n(1)Instrucoes\n(2)Jogar\n(3)Sair\n\n");
		scanf("%d", &continuar);
		switch (continuar)
		{
			case 1:
				printf("\n\tExistem dois tipos de bingo:\n\n\tTIPO 1. O participante escolhe com qual cartela deseja jogar.\n\n\tTIPO 2. O participante recebe uma cartela gerada aleatoriamente\n");
				printf("\n\tO vencedor sera aquele que primeiro completar o bingo, isto e, todos\n\tos numeros de sua cartela forem sorteados. Se houver empate, vence o\n\tparticipante que recebeu primeiro a cartela.\n\n\n\n");
				break;

			case 2:
                printf("\nInforme tipo de jogo\n");
                scanf("%d", &tipo);
                do
                {
                    printf("\nInforme quantidade de jogadores\n");
                    scanf("%d", &quant);
                    if (quant<=1)
                        printf("\n\n\tQUANTIDADE INVALIDA!!\n");
                }while(quant<2);
                if (tipo==1)
                {
                    gerartipo1();
                    for (i=0; i<quant; i++)
                    {
                        printf("\n\nInforme o nome do jogador que ira utilizar a cartela %d:\n", i+1);
                        fflush(stdin);
                        gets(cartelas[i].nome);
                    }
                    jogar();
                }
                else if (tipo==2)
                {
                    for (i=0; i<quant; i++)
                    {
                        printf("\nInforme o nome do jogador %d\n", i+1);
                        fflush(stdin);
                        gets(cartelas[i].nome);
                    }
                    gerartipo2();
                    jogar();
                }
                break;

			case 3:
				printf("\tObrigado por utilizar nosso programa! Ate mais!\n\n");
				return 0;
				break;

			default:
			printf("\tValor invalido!\n\n\n\n");
		}
		system("pause");
        system("cls");
	}while(continuar!=3);
	system("pause");
	return 0;
}
