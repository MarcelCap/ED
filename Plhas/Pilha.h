#ifndef PILHA_H
#define PILHA_H
#include <stdbool.h>
typedef struct No{
    int num;
    struct No* prox;
} no;

typedef struct pilha{
    no* topo;
    int tam;
} pilha;

pilha* Stack(void);

void push(pilha* p, int item);

int pop(pilha* p);

void pop_no_return(pilha* p);

int peek(pilha* p);

bool isEmpty(pilha* p);

int size(pilha* p);

void printStack(pilha* p);

void clear(pilha*p);

void destroyStack(pilha* p);

#endif //PILHA_H
