#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Pilha.h"

// typedef struct No{
//     int num;
//     struct No* prox;
// } no;

// typedef struct pilha{
//     no* topo;
//     int tam;
// } pilha;

pilha* Stack(void){
    pilha* p = malloc(sizeof(pilha));
    if (p == NULL) {
        printf("Erro ao alocar memória para a pilha.\n");
        exit(1);
    }
    p->topo=NULL;
    p->tam=0;
    return p;
}

void push(pilha* p, int item){
    no* novo=malloc(sizeof(no));
    if (novo == NULL) {
        printf("Erro ao alocar memória para novo nó.\n");
        exit(1);
    }
    novo->num=item;
    novo->prox=p->topo;
    p->topo=novo;
    p->tam++;
}

int pop(pilha* p){ //retorna o valor do nó removido
    if(!isEmpty(p)){
        no* remov = p->topo;
        int i=peek(p);
        p->topo = p->topo->prox;
        free(remov);
        p->tam--;
        return i;
    }
    else{
        printf("Pilha vazia!\n");
        return -1;
    }
}

void pop_no_return(pilha* p){ //pop sem retorno
    if(!isEmpty(p)){
        no* remov = p->topo;
        p->topo = p->topo->prox;
        free(remov);
        p->tam--;
    }
    else{
        printf("Pilha vazia!\n");
    }
}

int peek(pilha* p){
    if(isEmpty(p))  printf("Pilha vazia!\n");
    return p->tam>0 ? p->topo->num : -1; 
}

bool isEmpty(pilha* p){
    return p->tam == 0;
}

int size(pilha* p){
    return p->tam;
}

void printStack(pilha* p){
    no* atual = p->topo;
    int i=0;
    while(atual!=NULL){
        printf("Elemento %d: num %d\n", i, atual->num);
        atual=atual->prox;
        i++;
    }
    // Abaixo versao para debugar
    // usar para verificar o topo da pilha mais facilmente
    // para usar, selecione o texto que deseja comentar/retirar o comentário e pressione Ctrl + ;
    // printf("Topo da pilha ->\n");
    // while(atual != NULL){
    //     printf("  %d\n", atual->num);
    //     atual = atual->prox;
    // }
}

void clear(pilha*p){
    while(!isEmpty(p)){
        pop_no_return(p);
    }
}

void destroyStack(pilha* p){
    clear(p);
    free(p);
}
