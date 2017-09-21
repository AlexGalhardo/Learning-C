// criando funções
#include <iostream>

using namespace std;

bool par(int num); // definir inscritura da função, caso ela fique abaixo da função main
void mensagem();

int main(){
	mensagem();
	
	int n;
	
	cout << "Digite um numero: ";
	cin >> n;
	
	if(par(n)){
		cout<< "O numero eh par!\n";
	}
	else{
		cout<<"O numero eh impar!";
	}
	
	return 0;
}

void mensagem(){
	cout << "Ola mundo!\n\n";
}

bool par(int num){
	if(num %2 ==0){
		return true;
	}else{
		return false;
	}
}
