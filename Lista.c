
#include <stdio.h>
typedef struct No{
    int num;
    char pessoa;
    struct No* prox;
}no;

typedef struct Lista{
    no* final;
    no* inicio;
    int tamanho;
}lista;
void criarlista(lista* l)
{
    l->tamanho=0;
    l->inicio=NULL;
    l->final=NULL;
}
void add(lista* l, char nome, int number)
{
    no* v0 = malloc(sizeof(no));
    v0->num=number;
    v0->pessoa=nome;
    v0->prox=l->inicio;
    l->inicio = v0;
    l->tamanho++;
}
void addfim(lista* l, char nome, int number)
{
    no* v0 = malloc(sizeof(no));
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
void remove(lista* l, int index)
{
    if(l->tamanho){
        no* atual = malloc(sizeof(no));
        no* anterior = malloc(sizeof(no));
        atual=l->inicio;
        while(atual->num != index){
            if(atual==l->final) break;
            if(atual->prox->num==index){
                anterior=atual;
            }
            atual=atual->prox;
        }
        if(atual->num!=index){
            printf("Elemento nao existe na lista!!!\n");
            return;
        }
        else{
            anterior->prox=atual->prox;
        }
    }
}
int main()
{
    lista m0;
    criarlista(&m0);
    //scanf("%s");
    //add(m0, nome, number);
    return 0;
}
