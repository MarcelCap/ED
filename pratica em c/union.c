#include <stdio.h>
union ab {
    int a;
    float b;
};
int main()
{
    union ab valor;
    valor.a=10;
    printf("Usando a : %d\nUsando b (mesma memoria): %f\n", valor.a, valor.b);
    valor.b=5.5;
    printf("Usando a (mesma memoria) : %d\nUsando b: %f\n", valor.a, valor.b);
    
    return 0;
}
