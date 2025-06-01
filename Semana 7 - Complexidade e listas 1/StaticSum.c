#include <stdio.h>
int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    long long int v[n];
    for(int i=0; i<n; i++){
        scanf("%lld", &v[i]);
        if(i) v[i]+=v[i-1];
    }
    while(q--){
        long long int a, b;
        scanf("%lld%lld", &a, &b);
        a-=1;
        b-=1;
        printf("%lld\n", a==0 ? v[b] : v[b]-v[a-1]);
    }
    return 0;
}
