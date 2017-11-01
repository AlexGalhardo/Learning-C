// ordenando carros -> bubble sort
#include <iostream>
#include <string.h>


#define MAX 10

using namespace std;

class Carro
{
public:
	char nome[100];
	char cor[20];
	char placa[20];
	double preco;
};

// ordenação utilizando o algoritmo bubble sort
void ordena(Carro carros[], int tam)
{
	Carro aux;

	for(int i = tam; i >= 0; i--)
	{
		for(int j = 1; j <= i; j++)
		{
			if(strcmp(carros[j - 1].nome, carros[j].nome) == 1)
			{
				aux = carros[j - 1];
				carros[j - 1] = carros[j];
				carros[j] = aux;
			}
		}
	}
}

int main(int argc, char *argv[])
{
	Carro carros[MAX];
	int i = 0;

	while(true)
	{
		char resp;
		cout << "Digite o nome do carro: ";
		cin >> carros[i].nome;
		cout << "Digite o preco: ";
		cin >> carros[i].preco;
		cout << "Voce deseja continuar? <S>SIM ou <N>NAO: ";
		cin >> resp;
		if(resp != 'S')
			break;
		cout << endl;
		i++;
	}

	cout << endl;
	cout << "Exibindo todos os carros...\n\n";

	for(int j = 0; j <= i; j++)
	{
		cout << "Nome do carro: " << carros[j].nome << endl;;
		cout << "Preco: R$" << carros[j].preco << "\n\n";
	}

	ordena(carros, i);

	cout << "Exibindo os carros ordenados pelo nome...\n\n";

	for(int j = 0; j <= i; j++)
	{
		cout << "Nome do carro: " << carros[j].nome << endl;;
		cout << "Preco: R$" << carros[j].preco << "\n\n";
	}
	return 0;
}