// fonte: https://www.youtube.com/watch?v=WCjtRX4zzpE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct dataNode{
	int id;
} DataNode;

typedef struct node{
	DataNode data;
	struct node* next;
}Node;


typedef struct list{
	int size;
	Node* head;
}List;

List* createList();
void push(List* list, DataNode data);
void printList(List* list);
void pop(List* list);
bool isEmpty(List* list);
Node* atPos(List* list, int index);
int indexOf(List* list, Node* node);
void erase(List* list, int index);
void insert(List* list, DataNode data, int index);

List* createList(){
	List* list = (List *) malloc(sizeof(List));

	list->size = 0;
	list->head= NULL;

	return list;
}

void push(List* list, DataNode data){
	Node* node = (Node*) malloc(sizeof(Node));

	node->data = data;
	node->next = list->head;
	list->head = node;
	list->size++;
}


void printList(List* list){

	if(isEmpty(list)){
		printf("Lista vazia\n");
		return;
	}

	Node* pointer = list->head;

	while(pointer !=NULL){
		printf("%d", pointer->data.id);
		pointer = pointer->next;
	}
	printf("\n");
}

bool isEmpty(List* list){
	return(list->size == 0);
}


void pop(List* list){

	if(!isEmpty(list)){
		Node* pointer = list->head;

		list->head = pointer->next;

		free(pointer);
		list->size--;
	}
}

Node* atPos(List* list, int index){

	if(index >= 0 && index < list->size){
		Node* node = list->head;

		int i;
		for(i=0; i<index; i++){
			node = node->next;
		}

		return node;
	}


	printf("Indice invalido");
	return NULL;
}

int indexOf(List* list, Node* node){

	if(node != NULL){
		Node* pointer = list->head;

		int index = 0;
		while(pointer != node && pointer != NULL){
			pointer = pointer->next;
			index++;
		}

		if(pointer!=NULL){
			return index;
		}
	}

	printf("Nó não pertence a lista\n");
	return -1;
}


void erase(List* list, int index){

	if(index == 0){
		pop(list);
	}
	else{
		Node* current = atPos(list, index);

		if(current != NULL){
			Node* previous = atPost(list, index-1);
			previous->next = current->next;

			free(current);
			list->size--;
		}


	}
}

void insert(List* list, DataNode data, int index){
	if(index ==0){
		push(list, data);
	}
	else{
		Node* current = atPos(list, index);

		if(current != NULL){
			Node* previous = atPos(list, index-1);

			Node* newNode = (Node*) malloc(sizeof(Node));
			newNode->data = data;

			previous->next = newNode;
			newNode->next = current;
			list->size++;
		}
	}
}

void xchgNodes(List* list, Node* nodeA, Node* nodeB){

	if(nodeA == nodeB){
		return;
	}

	int indexA = indexOf(list, nodeA);
	int indexB = indexOf(list, nodeB);

	if(indexA == -1 || indexB == -1){
		return;
	}

	if(indexA > indexB){
		nodeA = nodeB;
		nodeB = atPost(list, indexA);

		indexA = indexB;
		indexB = indexOf(list, nodeB);
	}

	Node* pb = atPos(list, indexB - 1);

	if(nodeA == list->head){
		list->head = nodeB;
	}
	else{
		Node* pa = atPost(list, indexA -1);
		pa->next = nodeB;
	}

	pb->next = nodeA;

	Node* pointer = nodeA->next;
	nodeA->next = nodeB->next;
	nodeB->next = pointer;
}

int main(){

	List* l = createList();
	
	DataNode data;
	

	data.id = 5;
	push(1, data);

	data.id = 9;
	push(1, data);

	//printf("%d %d", l->head->data.id, l->head->next->data.id);
	printList(l);
	//pop(l); // tirar o primeiro elemento da lista
	//printList(l);

	//printf("%d", atPos(1, 0)->data.id); // dado uma posição(index), dizer seu dado equivalente dentro da lista

	//printf("%d", indexOf(l, l->head->next->next));

	data.id = 11;
	insert(l, data, 2);

	printList(l);

	xchgNodes(l, l->head->next, l->head->next->next);

	return 0;
}