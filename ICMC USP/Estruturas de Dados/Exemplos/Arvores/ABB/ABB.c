#include <stdio.h>
#include "ABB.h"

//fun��o para criar/inicializar a �rvore de busca bin�ria
void criar(ABB *A) {
     A->raiz=NULL;
}

//fun��o para finalizar �rvore de busca bin�ria; deve come�ar com p=raiz
void finalizar(no **p) {
     if (*p!=NULL) {
        finalizar(&(*p)->esq);
        finalizar(&(*p)->dir);
        free(*p);
     }
}

//imprime os elementos da �rvore
void imprimir(no **p) {
     if (*p!=NULL) {
        printf("%d(",(*p)->info);
        imprimir(&(*p)->esq);
        printf(",");
        imprimir(&(*p)->dir);
        printf(")");
     }
     else printf("null");
}

//fun��o de busca de um elemento na �rvore bin�ria de busca; deve come�ar com p=raiz
int buscar(no **p, elem *x) {
    if (*p==NULL)
       return 0;
    else if (*x<(*p)->info)
         return(buscar(&(*p)->esq,x));
    else if (*x>(*p)->info)
         return(buscar(&(*p)->dir,x));
    else return 1;
}

//fun��o de inser��o de um elemento na �rvore bin�ria de busca; deve come�ar com p=raiz
int inserir(no **p, elem *x) {
     if (*p==NULL) {
        *p=(no*) malloc(sizeof(no));
        (*p)->info=*x;
        (*p)->esq=NULL;
        (*p)->dir=NULL;
        return 1;
     }
     else if (*x<(*p)->info)
          return(inserir(&(*p)->esq,x));
     else if (*x>(*p)->info)
          return(inserir(&(*p)->dir,x));
     else return 0;
}

//fun��o que retorna o maior elemento de uma subarvore com raiz em p
elem busca_maior(no **p) {
     no *aux;
     aux=*p;
     while (aux->dir!=NULL)
           aux=aux->dir;
     return(aux->info);
}

//fun��o que remove um elemento de uma �rvore
int remover(no **p, elem *x) {
    no *aux;
    if (*p==NULL)
       return 0;
    else if (*x<(*p)->info)
         return(remover(&(*p)->esq,x));
    else if (*x>(*p)->info)
         return(remover(&(*p)->dir,x));
    else {
         //caso 1: o n� n�o tem filhos
         if (((*p)->esq==NULL) && ((*p)->dir==NULL)) {
            free(*p);
            *p=NULL;
            return 1;
         }
         //caso 2a: s� h� o filho direito
         else if ((*p)->esq==NULL) {
              aux=*p;
              *p=(*p)->dir;
              free(aux);
              return 1;
         }
         //caso 2b: s� h� o filho esquerdo
         else if ((*p)->dir==NULL) {
              aux=*p;
              *p=(*p)->esq;
              free(aux);
              return 1;
         }
         //caso 3: h� os dois filhos
         else {
              (*p)->info=busca_maior(&(*p)->esq);
              return(remover(&(*p)->esq,&(*p)->info));
         }
    }
}
