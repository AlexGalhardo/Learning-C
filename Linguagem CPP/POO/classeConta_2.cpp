#include <iostream>

using namespace std;

class Conta
{
public:
	int numero;
	double saldo;

	double depositar(double quantidade)
	{
		if(quantidade > 0)
			saldo += quantidade;
		return saldo;
	}

	double retirar(double quantidade)
	{
		if(quantidade > 0 && saldo >= quantidade)
			saldo -= quantidade;
		return saldo;
	}
};

int main(int argc, char *argv[])
{
	Conta c;
	Conta* pc = &c;
	
	pc->numero = 1;
	pc->saldo = 200;

	cout << "Saldo: " << c.saldo << endl;
	cout << "Saldo depois do deposito: " << pc->depositar(100) << endl;
	cout << "Saldo depois do saque: " << pc->retirar(50) << endl;
	return 0;
}