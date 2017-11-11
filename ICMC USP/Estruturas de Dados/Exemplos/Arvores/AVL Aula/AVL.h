//declara��o do n� da �rvore
typedef int elem;

typedef struct bloco {
        elem info;
        int fb;
        struct bloco *esq, *dir;
} no;

typedef struct {
        no *raiz;
} AVL;


//prot�tipos das fun��es
void criar(AVL*);
void finalizar(no**);
void imprimir(no**);
int inserir(no**,int*);
int buscar(no**,int*);
