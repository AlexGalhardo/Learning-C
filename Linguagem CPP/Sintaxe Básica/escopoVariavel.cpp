#include <iostream>

using namespace std;

int num_global = 12;

void foo(){
	int num = 10;
	static int num_static = 1;
	cout << "variavel local: " << num << endl;
	cout << "variavel global: "<< num_global << endl;
	num_static++;
	cout << "variavel estatica: " << num_static << endl;
}	

int main(){
	
	cout << num_global << endl;
	foo();
	foo();
	foo();
	foo();
	
	return 0;
}
