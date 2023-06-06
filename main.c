#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct no{
    int dado;
    struct no * prox
}tno;

typedef tno * tpilha;

void criar(tpilha ** pp){
    *pp = NULL;
}

bool push(tpilha ** pp,int dado){
    tpilha novo;
    novo = (tno*) malloc(sizeof(tno));
    if(novo == NULL){
        return false;
    }
    else{
        novo->dado = dado;
        novo->prox = *pp;
        *pp = novo;
        return true;
    }
}
bool pop(tpilha * pp,int * valor){
    tpilha aux;
    if(pp == NULL){
        return false;
    }
    else{
        aux = *pp;
        *valor = (*pp)->dado;
        *pp = aux->prox;
        free(aux);
        return true;
    }

}

void main() {

    tpilha p;
    int op, valor = 0, pegaValor = 0;

    criar(&p);

    push(&p,1);
    printf("Pilha[%d]\n",p->dado);
    push(&p,2);
    printf("Pilha[%d]\n",p->dado);
    push(&p,3);
    printf("Pilha[%d]\n",p->dado);
    push(&p,4);
    printf("Pilha[%d]\n",p->dado);
    push(&p,5);
    printf("Pilha[%d]\n",p->dado);

    pop(&p,&pegaValor);
    printf("Valor [%d] retirado da pilha",pegaValor);



}
