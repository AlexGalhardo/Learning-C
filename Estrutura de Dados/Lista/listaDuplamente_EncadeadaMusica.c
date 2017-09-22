/*
Lista Duplamente Encadeada de Músicas

Com seus recém-adquiridos conhecimentos de programação e listas, você começou a criar o USPotify (ver exercício Lista de Músicas).
Como todo projeto precisa começar em algum ponto, você planeja começar criando uma lista duplamente ligada em que cada nó conterá as seguintes informações:
Nome da música (máximo de 50 caracteres)
Nome do artista/banda (máximo de 50 caracteres)
Gênero musical(máximo de 20 caracteres)
*Não haverá espaços entre os caracteres e seu programa deverá diferenciar maiúsculas de minúsculas (ou seja, não precisa tratar nenhuma exceção em relação a isso)

Usando uma implementação de lista duplamente ligada semelhante à vista em sala (com a inserção dos elementos novos no início da lista), seu programa deverá ler diversos comandos de entrada, até que o comando de número 3 seja inserido, que indica saída.
Os 2 comandos que seu programa fará serão:
1:

Inserir um nó de música como primeiro elemento da lista.
2:

Receber um nome de música como entrada, e buscar essa música na lista.
Se a música estiver na lista, imprimir a seguinte linha:
printf("Musica:\n");
E mostrar as informações da música.
Em seguida, se existir uma música depois dessa na lista, imprimir:
printf("Proxima musica:\n");
Seguida pelos dados da música ou, se não existir, imprimir:
printf("Ultima musica da lista\n");
Por fim, se existir uma música anterior a essa na lista, imprimir:
printf("Musica anterior:\n");
Seguida pelos dados da música ou, se não existir, imprimir:
printf("Primeira musica da lista\n");
Caso a música não exista na lista, imprima somente essa linha:
printf("Musica nao esta na lista\n");

As impressões deverão seguir a seguinte formatação:

printf("Nome: %s\n", nome);
printf("Artista: %s\n", artista);
printf("Genero: %s\n", genero);

Caso a lista esteja vazia e seja pedido para buscar uma música, seu programa deverá imprimir a seguinte mensagem:
printf("Lista vazia");
Exemplos de Entrada e Saída

Entrada:

1
TheTrooper
IronMaiden
HeavyMetal
2
TheTrooper
3

Saída:

Musica:
Nome: TheTrooper
Artista: IronMaiden
Genero: HeavyMetal
Ultima musica da lista
Primeira musica da lista

Entrada:

1
TheTrooper
IronMaiden
HeavyMetal
1
SweatingBullets
Megadeth
ThrashMetal
1
DreamOfMirrors
IronMaiden
HeavyMetal
2
TheTrooper
3

Saída:

Musica:
Nome: TheTrooper
Artista: IronMaiden
Genero: HeavyMetal
Ultima musica da lista
Musica anterior:
Nome: SweatingBullets
Artista: Megadeth
Genero: ThrashMetal

*/



#include <stdlib.h>

typedef struct no //struct para o nу
{
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


