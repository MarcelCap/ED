#include <stdio.h>
int bottle(int n)
{   
    if(n<=3) return 1;
    else return bottle(n/3 + n%3)+(n/3);
}
int main()
{
    int n;
    scanf("%d", &n);
    while(n!=0)
    {
        printf("%d\n", bottle(n));
        scanf("%d", &n);
    }
    return 0;
}
