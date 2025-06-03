#ifndef FILA_H
#define FILA_H
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

fila* queue(void);

void enqueue(fila* f, int item);

void dequeue(fila* f);

int front(fila* f);

bool isEmpty(fila* f);

void printfQueue(fila* f);

int size(fila* f);

void clear(fila* f);

void destroy(fila* f);

#endif //FILA_H
