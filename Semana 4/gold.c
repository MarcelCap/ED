#include <stdio.h>
int res3(int q, int k)
{
    if(q==k)    return 1;
    if(q%3!=0)  return 0;
    if(q<k) return 0;
    int a, b;
    b=q/3;
    a=2*(q/3);
    return res3(a, k) || res3(b, k);
    /*else if(q%3==0)
    {
    ignorar oq esta comentado, esta errado
        int a, b;
        b=q/3;
        a=2*(q/3);
        if(a==k || b==k)  return 1;
        else if(k<b && b%3==0) return res3(b, k);
        else if(k<a)
        {
            if(a%3==0)  return res3(a, k);
            else    return 0;
        }
        else   return 0;
    }
    else    return 0;*/
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        if(n<m)    printf("No\n");
        else if(n==m)   printf("Yes\n");
        else if(res3(n, m)) printf("Yes\n");
        else    printf("No\n");
    }
    return 0;
}
