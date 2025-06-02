//Nesse exercicio ele pedia para empilhar e desempilhar uma quantidade de anilhas, ate a entrada ser 0
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct No{
    int num;
    struct No* prox;
} no;

typedef struct pilha{
    no* topo;
    int tam;
} pilha;

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

bool isEmpty(pilha* p){
    return p->tam == 0;
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

int peek(pilha* p){
    if(isEmpty(p))  printf("Pilha vazia!\n");
    return p->tam>0 ? p->topo->num : -1; 
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


void clear(pilha*p){
    while(!isEmpty(p)){
        pop_no_return(p);
    }
}

void destroyStack(pilha* p){
    clear(p);
    free(p);
}

int main(){
    pilha* ani = Stack();
    int n =1;
    scanf("%d", &n);
    while(n){
        push(ani, n);
        scanf("%d", &n);
    }
    int anilha;
    scanf("%d", &anilha);
    int pesor=0, anir=0;
    int aux=0;
    aux=pop(ani);
    while(aux!=anilha){
        printf("Peso retirado: %d\n", aux);
        pesor+=aux;
        anir++;
        aux=pop(ani);
    }
    printf("Anilhas retiradas: %d\n", anir);
    printf("Peso retirado: %d\n", pesor);
    destroyStack(ani);
    return 0;
}
