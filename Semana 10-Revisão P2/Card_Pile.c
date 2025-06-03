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
    pilha* p = (pilha*)malloc(sizeof(pilha));
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
    no* novo=(no*)malloc(sizeof(no));
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

int size(pilha* p){
    return p->tam;
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

int main(){
    pilha* cards = Stack();
    int test;
    scanf("%d", &test);
    for(int i=0; i<100; i++) push(cards, 0);
    //printf("Teste => tam(cards) : %d\tTopo(cards) = %d\n", size(cards), peek(cards));
    while(test--){
        int cons;
        scanf("%d", &cons);
        if(cons==1){
            int x; 
            scanf("%d", &x);
            push(cards, x);
        }
        else if(cons==2){
            printf("%d\n", pop(cards));
        }
    }
    return 0;
}
