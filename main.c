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


void main() {

    tpilha p;
    int op, valor = 0, pegaValor = 0;

    criar(&p);

    push(&p,5);
    printf("Pilha[%d]\n",p->dado);

}
