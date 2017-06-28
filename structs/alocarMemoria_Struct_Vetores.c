// EXEMPLO 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX         (100)
#define QTD_CARROS  (5)


struct CARRO {
    int id;
    char fabricante[MAX];
    char modelo[MAX];
    int ano;
    char cor[MAX];
    int preco;
};

typedef struct CARRO carro_t;


void carro_preencher( carro_t * c, int id, char * fab, char * mod, int ano, char * cor, int preco )
{
    c->id = id;
    strncpy( c->fabricante, fab, MAX );
    strncpy( c->modelo, mod, MAX );
    c->ano = ano;
    strncpy( c->cor, cor, MAX );
    c->preco = preco;
}


int main( int argc, char * argv[] )
{
    /* Cria array de carros */
    carro_t * carros = calloc( QTD_CARROS, sizeof(carro_t) );

    /* Preenche os dados de cada Carro na array */
    carro_preencher( &carros[0], 1000, "Volkswagen", "Kombi", 1980, "Branco", 1000 );
    carro_preencher( &carros[1], 2000, "Chevrolet", "Camaro", 2017, "Amarelo", 80000 );
    carro_preencher( &carros[2], 3000,"Fiat",  "Uno", 2005, "Cinza", 5000 );
    carro_preencher( &carros[3], 4000,"Ford", "Fiesta", 2001, "Vermelho", 10500 );
    carro_preencher( &carros[4], 5000,"Toyota", "Corolla", 2017, "Prata", 70000 );

    /* Libera array de carros */
    free(carros);

    return 0;
}



// ------------  EXEMPLO 2 -----------------


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define QTD_CARROS  (5)


struct CARRO {
    int id;
    char * fabricante;
    char * modelo;
    int ano;
    char * cor;
    int preco;
};


typedef struct CARRO carro_t;


carro_t * carro_construir(  int id, char * fab, char * mod, int ano, char * cor, int preco )
{
    carro_t * c = calloc( 1, sizeof(carro_t) );

    c->id = id;
    c->fabricante = strdup(fab);
    c->modelo = strdup(mod);
    c->ano = ano;
    c->cor = strdup(cor);
    c->preco = preco;

    return c;
}


void carro_destruir( carro_t * c )
{
    free(c->fabricante);
    free(c->modelo);
    free(c->cor);
    free(c);
}


int main( int argc, char * argv[] )
{
    int i = 0;
    carro_t * carros[ QTD_CARROS ]; /* Array de carros */

    /* Constroi um Carro para cada elemento da array... */
    carros[0] = carro_construir( 1000, "Volkswagen", "Kombi", 1980, "Branco", 1000 );
    carros[1] = carro_construir( 2000, "Chevrolet", "Camaro", 2017, "Amarelo", 80000 );
    carros[2] = carro_construir( 3000, "Fiat",  "Uno", 2005, "Cinza", 5000 );
    carros[3] = carro_construir( 4000, "Ford", "Fiesta", 2001, "Vermelho", 10500 );
    carros[4] = carro_construir( 5000, "Toyota", "Corolla", 2017, "Prata", 70000 );

    /* Destroi cada Carro contido na array */
    for( i = 0; i < QTD_CARROS; i++ )
        carro_destruir( carros[i] );

    return 0;
}
