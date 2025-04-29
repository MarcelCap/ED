#include <stdio.h>
#include <string.h>
#define M 100001
void super(char str[], int number)
{
    long long int sum=0;
    for(int i=0; str[i]!='\0'; i++) sum+=str[i]-48;
    sum*=number;
    //printf("Teste soma: %lld\n", sum);
    if(sum<10)
    {
        printf("%lld\n", sum);
        return;
    }
    else
    {
        char k[M];
        sprintf(k, "%lld", sum);
        super(k, 1);
    }
}
int main()
{
    char n[M];
    int k;
    scanf("%s", n);
    scanf("%d", &k);
    super(n, k);
    return 0;
}
