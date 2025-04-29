#include <stdio.h>
int main()
{
    int a;
    char t[411];
    scanf("%d", &a);
    char teste[21];
    scanf("%s", teste);
    sprintf(t, "%s tem %d anos", teste, a);
    printf("String: %s\n", t);
    return 0;
}
