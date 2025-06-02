//conversor de decimal para binario
//inclui o Pilha.h dessa pasta, para compilar digite: "gcc conv_dec_bin.c Pilha.c -o (insira nome do executavel)" para nao haver problemas
#include <stdio.h>
#include "Pilha.h"

int main(){
    pilha* bin = Stack();
    int n;
    scanf("%d", &n);
    while(n){
        push(bin, n%2);
        n/=2;
    }
    while(!isEmpty(bin)){
        printf("%d", pop(bin));
    }
    printf("\n");
    // printStack(bin);
    destroyStack(bin);
    return 0;
}
