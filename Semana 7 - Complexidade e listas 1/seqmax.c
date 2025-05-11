//achar a maior sequencia em uma string
#include <stdio.h>
#define max 1000002
int main()
{
    char dna[max];
    scanf("%s", dna);
    int seqmax=0;
    for(int i=1; dna[i]!='\0';)
    {
        int seq=0;
        if(dna[i]==dna[i-1])
        {
            seq++;
            while(dna[i]!='\0' && dna[i]==dna[i-1])
            {
                i++;
                seq++;
            }
            if(seq>seqmax)  seqmax=seq;
        }
        else i++;
    }
    printf("%d\n", seqmax>0 ? seqmax : 1);
    return 0;
}
