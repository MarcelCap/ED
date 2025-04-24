#include <stdio.h>
int gcd(int a, int b) //mdc
{
  if(b==0)  return a;
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
      int aux, x;
      scanf("%d", &x);
      int max=0;
      for(int i=1; i<x; i++)
      {
        //printf("i = %d >> gcd(%d,%d) = %d; max = %d\n", i, i, x, gcd(i, x), max);
        if(gcd(x, i) + i > max)
        {
          max = gcd(x, i) + i;
          aux=i;
        }
      }
      printf("%d\n", aux);
    }
    return 0;
}
