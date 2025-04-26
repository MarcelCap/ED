#include <stdio.h>
int bottle(int n)
{   
    //printf("Cheias = %d\n", n/3);
    if(n<=3) return 1;
    else return bottle(n/3 + n%3)+(n/3);
}
int main()
{
    int n, t=0;
    scanf("%d", &n);
    while(n!=0 && t<11)
    {
        printf("saida: %d\n", bottle(n));
        scanf("%d", &n);
        t++;
    }
    return 0;
}
