#include <stdio.h>
#include <time.h>
typedef long long ll;
ll fib(ll n)
{
    if(n==0 || n==1)
        return 1;
    else if(n==2)
        return 2;
    else if(n==3)
        return 3;
    else if(n==4)
        return 5;
    else if(n==5)
        return 8;
    else if(n==6)
        return 13;
    else if(n==7)
        return 21;
    else if(n==8)
        return 34;
    else if(n==9)
        return 55;
    else if(n==10)
        return 89;
    else    return fib(n-1)+fib(n-2);
}
int main()
{
    double tempo;
    ll n;
    scanf("%lld", &n);
    clock_t inicio, fim;
    inicio=clock();
    printf("%lld\n", fib(n));
    fim=clock();
    tempo=((double)(fim-inicio))/CLOCKS_PER_SEC;
    printf("Tempo de processamento: %lf segundos\n", tempo);
}
