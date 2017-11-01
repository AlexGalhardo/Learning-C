#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
	
	cout << "quantidade de argumentos: " << argc << endl;
	cout << "\nArgumentos passados: " << endl;

	for(int i=0; i<argc; i++){
		cout << argv[i] << endl;
	}

	return 0;
}