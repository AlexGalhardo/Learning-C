#include <iostream>
#include <string>
//#include "classe.h"
using namespace std;

class ALUNO{
public:
	ALUNO(string name, int idade, int hum, int cie, int port, int mat, int red){
		NAME = name;
		IDADE = idade;
		HUMANAS = hum;
		CIENCIAS = cie;
		PORTUGUES = port;
		MATEMATICA = mat;
		REDACAO = red;
		Computacao = 0;
		Sociologia = 0;
		Medicina = 0;
	}
	
	void getNotaHumanas(){
		cout << "\nA nota de humanas do aluno eh " << HUMANAS << endl;
	}
	void getNotaCiencias(){
		cout <<"\nA nota de ciencias do aluno eh " << CIENCIAS << endl;
	}
	void getNotaMatematica(){
		cout << "\nA nota de matematica do aluno eh " << MATEMATICA << endl;
	}
	void getNotaPortugues(){
		cout << "\nA nota de portugues do aluno eh" << PORTUGUES << endl;
	}
	void getNotaRedacao(){
		cout << "\nA nota de redacao do aluno eh " << REDACAO << endl;
	}
	
	void getComputacao(){
		int mat = 4 * this->MATEMATICA;
		int ciencias = 2 * this->CIENCIAS;
		int redacao = 2 * this->REDACAO;
		Computacao = (HUMANAS + ciencias + mat + redacao + PORTUGUES) / 10;
		cout << "\n    A media de nota de computacao do aluno eh --> " << Computacao;
	}

	void getSociologia(){
		Sociologia = ((4*HUMANAS) + CIENCIAS + (3*PORTUGUES) + (2*REDACAO) + MATEMATICA) / 11;
		cout << "\n    A media de nota de sociologia do aluno eh --> " << Sociologia;
	}
	
	void getMedicina(){
		Medicina = ((4*CIENCIAS) + (2*REDACAO) + (2*PORTUGUES) + (2*MATEMATICA) + HUMANAS) / 11;
		cout << "\n    A media de nota de medicina do aluno eh --> " << Medicina;
	}
	
	void display(){
		
		cout << "\n    --- COMPUTACAO ---";
		cout << "\n    Para passar em computacao, o aluno precisa de 770 de media final!";
		if(Computacao >= 770){
			cout << "\n    PARABEENS! VOCE ESTUDOU MUITO E VAI PASSAR NO VESTIBA!\n";
		}
		else{
			cout << "\n    AFF. Partiu sociologia?? KKK";
		}
		
		cout << "\n\n    --- SOCIOLOGIA ---";
		cout << "\n    Para passar em sociologia, o aluno precisa de 600 de media final!";
		if(Sociologia >= 600 && Computacao < 770){
			cout << "\n    Paaartiiuuu! :b";
		}
		else{
			cout << "\n    Bom, da para fazer sociologia ainda... ";
		}
		
		cout << "\n\n    --- MEDICINA ---";
		cout << "\n    Para passar em medicina, o aluno precisa de 800 de media final!";
		if(Medicina >= 800){
			cout << "\n    #VemMEDICINA!\n";
		}else{
		    cout << "\n    Eu nao queria medicina mesmo!\n";
		}
	}

private:
	string NAME;
	int IDADE;
	int HUMANAS;
	int CIENCIAS;
	int PORTUGUES;
	int MATEMATICA;
	int REDACAO;
	
	int Computacao;
	int Sociologia;
	int Medicina;
};

int main(){

	string nome;
	int idade;
	int notRed, notMat, notCie, notHum, notPort;
	
	cout << "    --- BEM VINDO AO ENEM 2017 ---\n\n";
	
	
	cout << "    Digite o nome do aluno: ";
	cin >> nome;
	cout << "    Digite a idade do aluno: ";
	cin >> idade;
	
	cout <<"\n\n    Digite a nota de Humanas do aluno: ";
	cin >> notHum;
	
	cout << "    Digite a nota de ciencias do aluno: ";
	cin >> notCie;
	cout << "    Digite a nota de Portugues do aluno: ";
	cin >> notPort;
	cout << "    Digite a nota de Matematica do aluno: ";
	cin >> notMat;
	cout << "    Digite a nota de redacao do aluno: ";
	cin >> notRed;
	
	/* cria objetvo chamado alexandre da classe ALUNO */
	ALUNO alexandre(nome, idade, notHum, notCie, notPort, notMat, notRed);
	
	/* verifica se os atributos do objeto foram atribuidos */
	/*
	alexandre.getNotaHumanas();
	alexandre.getNotaMatematica();
	alexandre.getNotaRedacao();
	alexandre.getNotaPortugues();
	alexandre.getNotaCiencias();
	*/
	
	/* diga qual a nota final do aluno para dada matéria */
	cout << "\n    --- MEDIA DO ALUNO --- ";
	alexandre.getSociologia();
	alexandre.getComputacao();
	alexandre.getMedicina();
	
	/* mostrar tudo */
	cout << "\n\n    --- RESULTADOS ENEM 2017 --- \n";
	alexandre.display();
	
	return 0;
}
