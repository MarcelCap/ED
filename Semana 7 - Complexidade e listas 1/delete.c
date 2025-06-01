#include <stdio.h>
#include <stdlib.h>
typedef struct No {
    int num;
    struct No* prox;
} no;

typedef struct Lista {
    no* final;
    no* inicio;
    int tamanho;
} lista;

lista* create_list(void) {
    lista* l = malloc(sizeof(lista));
    l->tamanho = 0;
    l->inicio = NULL;
    l->final = NULL;
    return l;
}
void addend(lista* l, int number) {
    no* v0 = malloc(sizeof(no));
    v0->num = number;
    v0->prox = NULL;
    if (l->tamanho > 0) {
        l->final->prox = v0;
        l->final = v0;
    } else {
        l->inicio = l->final = v0;
    }
    l->tamanho++;
}

void print_list(lista* l) {
    no* atual = l->inicio;
    int i = 0;
    while (atual) {
        printf((i+1 == l->tamanho) ? "%d\n" : "%d ", atual->num);
        atual = atual->prox;
        i++;
    }
}
void popPos(lista* l, int pos) {
    if (!l->tamanho) {
        printf("Lista vazia!!!\n");
        return;
    }

    if (pos >= l->tamanho) {
        printf("Lista nao possui posicao %d\n", pos);
        return;
    }

    no* remov;
    if (pos == 0) {
        remov = l->inicio;
        l->inicio = remov->prox;
        if (!l->inicio) l->final = NULL;
    } else {
        no* anterior = l->inicio;
        for (int i = 0; i < pos - 1 ; i++) anterior = anterior->prox;
        remov = anterior->prox;
        anterior->prox = remov->prox;
        if (remov == l->final) l->final = anterior;
    }
    free(remov);
    l->tamanho--;
    return;
}

int main(){
    lista* l = create_list();
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int aux;
        scanf("%d", &aux);
        addend(l, aux);
    }
    int k;
    scanf("%d", &k);
    popPos(l, k);
    print_list(l);
    return 0;
}
