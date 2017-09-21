#include <iostream>
#define PI 3.14

using namespace std;

int main(){
	cout << "Hello world!" << endl;
	
	int idade =20;
	cout << idade << endl;
	
	// calcular area de um circulo
	float raio = 1.0;
	float area;
	area = raio * raio * PI;
	cout << area << endl;	
	
	int ano;
	cout << "Imprime ano de nascimento: " << endl;
	cin>> ano;
	
	cout << "Voce tem " << 2017 - ano << " anos!" << endl;
	
	return 0;
}
