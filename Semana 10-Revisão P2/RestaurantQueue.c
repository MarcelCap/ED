#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct No{
    int num;
    struct No* prox;
}no;

typedef struct Fila{
    no* inicio;
    no* final;
    int tamanho;
}fila;
//cuidado! sempre inserir o tipo da memória alocada antes do malloc, como na funcao abaixo.
fila* queue(void){
    fila* f = (fila*)malloc(sizeof(fila));
    f->final=NULL;
    f->inicio=NULL;
    f->tamanho=0;
    return f;
}

bool isEmpty(fila* f){
    return f->tamanho==0;
}

void enqueue(fila* f, int item){
    no* add = (no*)malloc(sizeof(no));
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



int main(){
    fila* f = queue();
    int q;
    scanf("%d", &q);
    while(q--){
        int c;
        scanf("%d", &c);
        if(c==1){
            int x;
            scanf("%d", &x);
            enqueue(f, x);
        }
        else if(c==2){
            printf("%d\n", front(f));
            dequeue(f);
        }
    }
    return 0;
}
