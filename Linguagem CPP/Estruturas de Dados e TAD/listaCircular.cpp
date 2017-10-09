 /*
 
Cicero Santos 
IFSP - Catanduva
@cicerosnt

*/

#include <conio.h>
#include <iostream>
#include <stdlib.h>
#define tam 5

using namespace std;

void menu(void);

void menu(void);
int inserir(int elem);
void listar(void);
void remover(void);
	
int contador=0;

struct fila{
	int dados[tam];
	int inicio;
	int fim;	
} f;


int main(void){
	menu();
	
}

void menu(void){
	int opcao; char fugir;
	system("color a"); system("cls");
	
	cout << "\n -----------------------------------------\n "
		 << "       Menu de Opcoes"
		 << "\n -----------------------------------------\n";
	cout << "\n 1 - Inserir\t 2 - Remover\t 3 - Listar\t 4 - Sair\n\n -> ";
	cin >> opcao;
	
	switch(opcao){
		case 1:
		system("color a");
		int elem;
		
		
		system("cls");
		cout <<  "\n -----------------------------------------\n "
		     << "       Opcao Iseriri Selecionada"
			 << "\n -----------------------------------------\n";
		cin.ignore();
		cout << "\n Informe o elemento para inserção\n\n -> ";
		cin >> elem;
		//contador = 0;
		inserir(elem);
		
		break;
			
		case 2:
			remover();
			break;
		case 3:
			listar();
			break;
		case 4:
			cout << "\n\n Deseja mesmo sair?\\n\n (SN) ? :: ";
			cin >> fugir;
			if(fugir == 's'){
				exit(0);
			}else{
				system("cls");
				menu();
			}
			break;
		default:
			system("cls");
			cout << "\n\n Por favor, selecione uma das opcoes\n\n";
			getch();
			system("cls");
			menu();
	}
	
	menu();
}

//listar
void listar(void){
	int aux;
	if(contador == 0){
		cout << "\n Não existe elementos para listar!\n";	
	}else{
		for(aux=f.inicio ; aux != f.fim;){
		cout << "\n Elemento " << f.dados[aux];
		aux++;
	
		if(aux == tam){
			aux = 0;
		}
	}
	}
	
	getch();	
}

//remover
void remover(void){
	
	if(contador == 0){
		cout << "\n Desculpe, fila esta vazia.\n";
	}else{	
		cout << "\n Elemento removido -> " << f.dados[f.inicio];
		f.inicio++;
		contador--;
	
		if(f.inicio == tam){ //verifica se na posição 0 existe espaço, então reinicia a contaguem
			f.inicio=0;
		}
	}
	getch();
}

//inserir
int inserir(int elem){
	
	if(contador == tam){ //verifica se esta cheio
		cout << "\n Desculpe não há mais espaco para salvar. \n";
	}else{
		f.dados[f.fim] = elem;
		contador++;
		f.fim++;
		
		if(f.fim == tam){ // verifica se tem espaço e reinicia acontaguem
			f.fim = 0;
		}
	}
	getch();
}
 
