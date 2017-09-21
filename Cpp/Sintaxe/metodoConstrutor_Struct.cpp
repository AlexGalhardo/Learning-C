#include <iostream>

using namespace std;

struct Pessoa{
private:
	int idade;
	int numero_sorte;

public:
	Pessoa(int idade, int num_sorte){
		this->idade = idade;
		this->numero_sorte = num_sorte;
	}
	void setIdade(int idade){
		this->idade = idade;
	}
	int getIdade(){
		return this->idade;
	}
};

int main(int argc, char *argv[]){

	Pessoa p(20, 30);
	Pessoa p2(20, 10);

	//p.setIdade(20);

	cout << p.getIdade() << endl;

	return 0;	
}