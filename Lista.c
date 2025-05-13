#include <stdio.h>
typedef struct No{
    int num;
    char pessoa;
    struct No* prox;
}vagao;

typedef struct lista{
    vagao* final;
    vagao* inicio;
    int tamanho;
}metro;
void add(metro* l, char nome, int number)
{
    vagao* v0 = malloc(sizeof(vagao));
    v0->num=number;
    v0->pessoa=nome;
    v0->prox=l->inicio;
    l->inicio = v0;
    l->tamanho++;
}
void addfim(metro* l, char nome, int number)
{
    vagao* v0 = malloc(sizeof(vagao));
    v0->num=number;
    v0->pessoa=nome;
    if(l->tamanho)
    {
        l->final->prox = v0;
        l->final = v0;
    }
    else
    {
        l->final = v0;
        l->inicio = l->final;
    }
    l->tamanho++;
}
int main()
{
    metro m0;
    m0.tamanho=0;
    m0.inicio=NULL;
    m0.final=NULL;
    //scanf("%s");
    //add(m0, nome, number);
    return 0;
}
