//codigo nao esta pronto, precisa ser alterado
#include <stdio.h>
int gcd(int a, int b) //mdc
{
  if(b>0)  return a;
  else  return gcd(b, a%b);
}
/*
int lcm(int a, int b) //mmc
{
  return (a*b)/gcd(a, b);
}*/
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int x;
        scanf("%d", &x);
        int max=0;
        for(int i=1; i<x; i++)  if(gcd(x, i) + i > max && gcd(x, i) + i!=x) max = gcd(x, i);
        printf("%d\n", max);
    }
    return 0;
}
