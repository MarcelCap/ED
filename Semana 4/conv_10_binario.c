#include <stdio.h>
#include <string.h>
#define max 1001
void bits(int n)
{
    if(n==1)
    {
        printf("1");
        return;
    }
    else if(n==0)
    {
        printf("0");
        return;
    }
    int div2=n/2;
    int resto = n%2;
    bits(div2);
    printf("%d", resto);
}
int main()
{
    int ler=0;
    while(ler!=2)
    {
        printf("Fassa sua escolha abaixo. . .\nDigite:\n1 - binario\n2 - Sair\n");
        scanf("%d", &ler);
        if(ler==1)
        {
            printf("Digite o numero abajo:\n");
            int num;
            scanf("%d", &num);
            printf("%d em binario eh ", num);
            bits(num);
            printf("\n\n");
        }
    }
    return 0;
}
