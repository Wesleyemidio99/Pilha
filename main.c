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
void imprimir(tpilha * pp){
    tpilha aux;
    aux = *pp;
    while(aux != NULL){
        printf("Pilha[%d]\n",aux->dado);
        aux = aux->prox;
    }

}
void main() {

    tpilha p;
    int op, valor = 0, pegaValor = 0;

    criar(&p);

    do{
        printf("Entre 1-Empilhar / 2 - Desenpilhar / 3 - imprimir / -1 para sair\n");
        scanf("%d",&op);
        switch(op){
            case 1:do{
                printf("Digite o valor ou -1 para sair\n");
                scanf("%d",&valor);
                if(valor==-1){
                    printf("Saindo...\n");
                }
                else{
                    if(push(&p, valor)){
                        printf("Pilha[%d]\n",p->dado);
                    }
                    else{
                        printf("Nao foi possivel alocar memoria");
                        valor=-1;
                    }

                }
            }while(valor!=-1);
            break;

            case 2:do{
                printf("Digite 1 para desenpilhar e -1 para sair\n");
                scanf("%d",&valor);
                if(valor == -1){
                    printf("Saindo ...\n");
                }
                else{
                    if(valor == 1){
                        if(pop(&p,&pegaValor)){
                            printf("Valor [%d] retirado da pilha\n",pegaValor);
                        }
                        else{
                            printf("\nPilha Vazia! \n");
                        }
                    }
                    else{
                        printf("valor invalido!\n");
                    }
                }
            }while(valor!= -1);
            break;

            case 3:
                imprimir(&p);
                break;

        }
    }while(op!=-1);

    system("pause");

}
