//declara��o do n� da �rvore
typedef int elem;

typedef struct bloco {
        elem info;
        struct bloco *esq, *dir;
} no;

typedef struct {
        no *raiz;
} ABB;


//prot�tipos das fun��es
void criar(ABB*);
void finalizar(no**);
void imprimir(no**);
int inserir(no*,elem*);
int remover(no**,elem*);
int buscar(no**,elem*);
