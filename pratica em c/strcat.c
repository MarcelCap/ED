#include <stdio.h>
#include <string.h>
int main()
{
    char str1[1001], str2[1001];
    printf("Digite duas palavras abaixo:\n");
    scanf("%s", str1);
    scanf(" %s", str2);
    strcat(str1, str2); //strcat : concatena as duas strings e junta na primeira
    printf("Teste\nstr1 : %s\nstr2 : %s\n", str1, str2);
    return 0;
}
