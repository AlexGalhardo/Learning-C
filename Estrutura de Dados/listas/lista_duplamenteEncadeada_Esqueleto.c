#include <stdlib.h>

typedef struct no {
	int valor;
	struct no *anterior;
	struct no *posterior;
}NO;

typedef struct lista_duplamente_encadeada //struct para organizaзгo dos nуs em forma de lista duplamente encadeada
{
	int qtd_elementos;
	NO *comeco;
	NO *fim;
}LDE;

NO *criar_no(int valor){		// funзгo para criar nу
	NO *no = (NO*)malloc(sizeof(NO));

	no->valor = valor;

	return no;
}

LDE *criar_lista(){			//funзгo para criar lista
	LDE *lista = (LDE*)calloc(1, sizeof(LDE)); //alocaзгo dinвmica para uma lista
	return lista;				   //retorna lista (funзгo do tipo LDE)
}

void inserir_no_comeco(LDE *lista, int valor){	//funзгo para inserir nу no comeзo de uma lista
	NO *no = criar_no(valor);		//chama funзгo criar_no();
	lista->qtd_elementos++;			//incrementa o nъmero de elementos na lista

	if (lista->comeco == NULL)		//condicional para saber se a lista estб vazia
	{
		lista->comeco = no;		
		lista->fim = no;
		
		no->anterior = NULL;
		no->posterior = NULL;
		
		return;
	}					//para todos os outros casos

	NO *aux = lista->comeco;		//cria variбvel aux que armazena o endereзo do primeiro nу
	lista->comeco = no;			//variбvel 'comeзo' da lista aponta pro novo nу
	no->posterior = aux;			//a variбvel 'posterir' do primeiro nу aponta pro novo nу
	no->anterior = NULL;			//variбvel 'anterior' do primeiro nу aponta pra NULL
}

void destruir_no(NO **no){			//destrуi o nу
	free(*no);
	
	*no = NULL;
}

void remover_no_comeco(LDE *lista){		//organizaзгo do nу para remover ele da lista:
	if (lista->comeco == NULL)		//verifica se a lista estб vazia e para a funзгo
	{
		return;
	}
	
	if (lista->qtd_elementos == 1)		//caso a lista sу tenha 1 elemento:
	{					//destrуi o primeiro nу e aponta
		destruir_no(&(lista->comeco));	//comeзo e fim da lista como NULL;
		
		lista->comeco = NULL;
		lista->fim = NULL;
		
		lista->qtd_elementos--;		//decrementa o nъmero de elementos da lista
		
		return;
	}	
						//Caso tenha mais de 1 elemento:						
	NO *aux = lista->comeco;		//cria vetor auxiliar, armazenando o vetor "comeзo" do primeiro elemento
	lista->comeco = aux->posterior;		//comeзo da lista aponta pro segundo elemento
	lista->comeco->anterior = NULL;		//valor do "anterior" do segundo elemento aponta pra NULL;
	destruir_no(&aux);			//destrуi o primeiro elemento
}

int main(){

	
	return 0;
}
