#include <stdio.h>
#include "ABB.h"

//função para criar/inicializar a árvore de busca binária
void criar(ABB *A) {
     A->raiz=NULL;
}

//função para finalizar árvore de busca binária; deve começar com p=raiz
void finalizar(no **p) {
     if (*p!=NULL) {
        finalizar(&(*p)->esq);
        finalizar(&(*p)->dir);
        free(*p);
     }
}

//imprime os elementos da árvore
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

//função de busca de um elemento na árvore binária de busca; deve começar com p=raiz
int buscar(no **p, elem *x) {
    if (*p==NULL)
       return 0;
    else if (*x<(*p)->info)
         return(buscar(&(*p)->esq,x));
    else if (*x>(*p)->info)
         return(buscar(&(*p)->dir,x));
    else return 1;
}

//função de inserção de um elemento na árvore binária de busca; deve começar com p=raiz
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

//função que retorna o maior elemento de uma subarvore com raiz em p
elem busca_maior(no **p) {
     no *aux;
     aux=*p;
     while (aux->dir!=NULL)
           aux=aux->dir;
     return(aux->info);
}

//função que remove um elemento de uma árvore
int remover(no **p, elem *x) {
    no *aux;
    if (*p==NULL)
       return 0;
    else if (*x<(*p)->info)
         return(remover(&(*p)->esq,x));
    else if (*x>(*p)->info)
         return(remover(&(*p)->dir,x));
    else {
         //caso 1: o nó não tem filhos
         if (((*p)->esq==NULL) && ((*p)->dir==NULL)) {
            free(*p);
            *p=NULL;
            return 1;
         }
         //caso 2a: só há o filho direito
         else if ((*p)->esq==NULL) {
              aux=*p;
              *p=(*p)->dir;
              free(aux);
              return 1;
         }
         //caso 2b: só há o filho esquerdo
         else if ((*p)->dir==NULL) {
              aux=*p;
              *p=(*p)->esq;
              free(aux);
              return 1;
         }
         //caso 3: há os dois filhos
         else {
              (*p)->info=busca_maior(&(*p)->esq);
              return(remover(&(*p)->esq,&(*p)->info));
         }
    }
}
