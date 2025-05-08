#include <stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    int sum=n, soma=0;
    for(int i=1; i<n; i++)
    {
        int aux;
        scanf("%d" ,&aux);
        soma+=aux;
        sum+=i;
    }
    printf("%d\n", sum-soma);
    return 0;
}
