#include <stdlib.h>
#include <stdio.h>
#include "ab.h"

//inicializa a �rvore, fazendo a raiz igual a NULL
void cria(Arvore *A) {
     A->raiz=NULL;
}

//verifica se a �rvore est� vazia
int IsEmpty(Arvore *A) {
    if (A->raiz==NULL)
       return 1;
    else return 0;
}

//busca x na �rvore, devendo iniciar com p=raiz ou outro ponto da �rvore
no* busca(no *p, elem *x) {
    no *aux;
    
    if (p==NULL)
       return(NULL);
    else if (p->info==*x)
         return(p);
    else {
         aux=busca(p->esq,x);
         if (aux==NULL)
            aux=busca(p->dir,x);
         return(aux);
    }    
}

//busca pai de x na �rvore, devendo iniciar com p=raiz ou outro ponto da �rvore
no* busca_pai(no *p, elem *x) {
    no *aux;
    
    if (p==NULL)
       return(NULL);
    else if ((p->esq!=NULL) && (p->esq->info==*x))
         return(p);
    else if ((p->dir!=NULL) && (p->dir->info==*x))
         return(p);
    else {
         aux=busca_pai(p->esq,x);
         if (aux==NULL)
            aux=busca_pai(p->dir,x);
         return(aux);
    }
}

//se poss�vel, insere x � esquerda de pai na �rvore
//se pai=-1, insere na raiz
void inserir_esq(Arvore *A, elem *x, elem *pai, int *erro) {
     no *aux, *p;

     if (*pai!=-1) {
        aux=busca(A->raiz,pai);
        if ((aux!=NULL) && (aux->esq==NULL)) {
           p=(no*) malloc(sizeof(no));
           p->info=*x;
           p->esq=NULL;
           p->dir=NULL;
           aux->esq=p;
           *erro=0;
        }
        else *erro=1;
     }
     else if (A->raiz==NULL) {
          p=(no*) malloc(sizeof(no));
          p->info=*x;
          p->esq=NULL;
          p->dir=NULL;
          A->raiz=p;
          *erro=0;
     }
     else *erro=1;
}

//se poss�vel, insere x � direita de pai na �rvore
//se pai=-1, insere na raiz
void inserir_dir(Arvore *A, elem *x, elem *pai, int *erro) {
     no *aux, *p;
          
     if (*pai!=-1) {
        aux=busca(A->raiz,pai);
        if ((aux!=NULL) && (aux->dir==NULL)) {
           p=(no*) malloc(sizeof(no));
           p->info=*x;
           p->esq=NULL;
           p->dir=NULL;
           aux->dir=p;
           *erro=0;
        }
        else *erro=1;
     }
     else if (A->raiz==NULL) {
          p=(no*) malloc(sizeof(no));
          p->info=*x;
          p->esq=NULL;
          p->dir=NULL;
          A->raiz=p;
          *erro=0;
     }
     else *erro=1;
}

//imprime os elementos da �rvore
void imprimir(no *p) {
     if (p!=NULL) {
        printf("%d(",p->info);
        imprimir(p->esq);
        printf(",");
        imprimir(p->dir);
        printf(")");
     }
     else printf("null");
}

//fun��o para computar a altura de uma �rvore bin�ria; devo come�ar com p
//apontando para a raiz
int altura(no *p) {
    int alt_esq, alt_dir;

    if (p==NULL)
       return(0);
    else {
         alt_esq=1+altura(p->esq);
         alt_dir=1+altura(p->dir);
         if (alt_esq>alt_dir)
            return(alt_esq);
         else return(alt_dir);
    }
}

//libera toda a mem�ria usada na �rvore
void finaliza(no *p) {
     if (p!=NULL) {
        finaliza(p->esq);
        finaliza(p->dir);
        free(p);
     }
}

//fun��o que remove um elemento da �rvore, caso ele esteja nela
void remover(Arvore *A, elem *x, int *erro) {
     no *filho, *pai;
     int eh_filho_esq;
     
     //localizando o n� e o pai dele
     if ((A->raiz!=NULL) && (A->raiz->info==*x)) {
        pai=NULL;
        filho=A->raiz;
     }
     else {
          pai=busca_pai(A->raiz,x);
          if (pai!=NULL) {
             if ((pai->esq!=NULL) && (pai->esq->info==*x)) {
                filho=pai->esq;
                eh_filho_esq=1;
             }
             else {
                  filho=pai->dir;
                  eh_filho_esq=0;
             }
          }
          else filho=NULL;
     }
     
     if (filho==NULL)
        *erro=1;
     else {
          //primeiro caso: o n� n�o tem filhos
          if ((filho->esq==NULL) && (filho->dir==NULL)) {
             if (pai!=NULL) {
                if (eh_filho_esq)
                   pai->esq=NULL;
                else pai->dir=NULL;
             }
             else A->raiz=NULL;
             free(filho);
             *erro=0;
          }
          //segundo caso: o n� tem um ou dois filhos
          else {
               if (filho->esq!=NULL) {
                  filho->info=filho->esq->info;
                  filho->esq->info=*x;
               }
               else {
                    filho->info=filho->dir->info;
                    filho->dir->info=*x;
               }
               remover(A,x,erro);
          }
     }
}

//fun��o de percurso de pre-ordem na �rvore = busca em profundidade
void percurso_pre_ordem(no *p) {
     if (p!=NULL) {
        printf("%d\n",p->info);
        percurso_pre_ordem(p->esq);
        percurso_pre_ordem(p->dir);
     }
}

//fun��o de percurso de em-ordem na �rvore
void percurso_em_ordem(no *p) {
     if (p!=NULL) {
        percurso_em_ordem(p->esq);
        printf("%d\n",p->info);        
        percurso_em_ordem(p->dir);
     }
}

//fun��o de percurso de pos-ordem na �rvore
void percurso_pos_ordem(no *p) {
     if (p!=NULL) {
        percurso_pos_ordem(p->esq);
        percurso_pos_ordem(p->dir);
        printf("%d\n",p->info);        
     }
}

//fun��o que verifica se duas �rvores s�o espelho-similares
int espelho_similares(no *p1, no *p2) {
    if ((p1==NULL) && (p2==NULL))
         return(1);
    else if ((p1==NULL) || (p2==NULL))
         return(0);
    else if ((espelho_similares(p1->esq,p2->dir)) && (espelho_similares(p1->dir,p2->esq)))
         return(1);
    else return(0);
}











