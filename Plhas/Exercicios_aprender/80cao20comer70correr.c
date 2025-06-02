//Le uma frase ate a palavra end e desempilha separadamente as strings e os numeros
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct No{
    char* str;
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

void push(pilha* p, char string[]){
    no* novo=malloc(sizeof(no));
    if (novo == NULL) {
        printf("Erro ao alocar memória para novo nó.\n");
        exit(1);
    }
    novo->str=malloc(strlen(string)+1);
    strcpy(novo->str, string);
    novo->prox=p->topo;
    p->topo=novo;
    p->tam++;
}

bool isEmpty(pilha* p){
    return p->tam == 0;
}

char* pop(pilha* p){ //retorna o valor do nó removido
    if(!isEmpty(p)){
        no* remov = p->topo;
        char* i= malloc(strlen(p->topo->str)+1);
        strcpy(i, p->topo->str);
        p->topo = p->topo->prox;
        free(remov->str);
        free(remov);
        p->tam--;
        return i;
    }
    else{
        printf("Pilha vazia!\n");
        exit(1);
    }
}

void clear(pilha*p){
    while(!isEmpty(p)){
        pop(p);
    }
}

void destroyStack(pilha* p){
    clear(p);
    free(p);
}

int main(){
    pilha* palavras = Stack();
    pilha* num = Stack();
    char texto[101];
    scanf("%s", texto);
    while(strcmp(texto, "end")!=0){
        if(48<=texto[0] && texto[0]<=57){
            push(num, texto);
        }
        else{
            push(palavras, texto);
        }
        scanf("%s", texto);
    }
    printf("Palavras:\n");
    while(!isEmpty(palavras)){
        printf("%s\n", pop(palavras));
    }
    printf("Numeros:\n");
    while(!isEmpty(num)){
        printf("%s\n", pop(num));
    }
    
    destroyStack(num);
    destroyStack(palavras);
    return 0;
}
