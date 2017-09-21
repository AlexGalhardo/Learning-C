// classe conta
#include <iostream>

using namespace std;

class Conta{
public:
	int numero;
	double saldo;

	double depositar(double quantidade){
		if(quantidade > 0){
			saldo += quantidade;
		}
		return saldo;
	}

	double retirar(double quantidade){
		if(quantidade > 0 && saldo >= quantidade){
			saldo -= quantidade;
		}
		return saldo;
	}
};

int main(int argc, char *argv[]){
	
	Conta c;

	c.numero = 1;
	c.saldo = 100.70;

	cout << "Saldo: " << c.saldo << endl;

	c.depositar(100);
	cout << "Saldo depois do deposito: " << c.saldo << endl;
	// cout << "Saldo depois do deposito: " << c.depositar(100) << endl;


	c.retirar(50);
	cout << "Saldo depois de retirar: " << c.saldo << endl;
	cout << "Saldo depois de retirar: " << c.retirar(50) << endl;


	return 0;
}