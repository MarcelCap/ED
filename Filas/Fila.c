#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Fila.h"

fila* queue(void){
    fila* f = malloc(sizeof(fila));
    f->final=NULL;
    f->inicio=NULL;
    f->tamanho=0;
    return f;
}

bool isEmpty(fila* f){
    return f->tamanho==0;
}

void enqueue(fila* f, int item){
    no* add = malloc(sizeof(no));
    add->num=item;
    add->prox=NULL;
    if(isEmpty(f)){
        f->inicio=add;
        f->final=add;
    }
    else{
        f->final->prox=add;
        f->final=add;
    }
    f->tamanho++;
}

void dequeue(fila* f){ //nao retorna o elemento do inicio
    if(f->tamanho){
        no* remov=f->inicio;
        f->inicio=f->inicio->prox;
        free(remov);
        f->tamanho--;
        if(f->inicio==NULL)
            f->final=NULL;
    }
}

int front(fila* f){ //retorna o elemento do inicio
    if(isEmpty(f)) return -1; //-1 indica erro! lembrar disso marcel!
    return f->inicio->num;
}

int size(fila* f){
    return f->tamanho;
}

void printfQueue(fila* f){
    no* atual = f->inicio;
    int i=0;
    while(atual!=NULL){
        printf("Elemento %d da fila: %d\n", i, atual->num);
        i++;
        atual=atual->prox;
    }
}

void clear(fila* f){
    while(!isEmpty(f)){
        dequeue(f);
    }
}

void destroy(fila* f){
    clear(f);
    free(f);
}
