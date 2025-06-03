//Arquivo criado na mesma pasta que contem fila.h e fila.c, anexados aqui.
//Ao usar, lembre-se de alterar os tipos int para char* ou char (e definir o tamanho máximo da string)
#include <stdio.h>
#include <string.h>
#include "Fila.h"


int main(){
    fila* f = queue();
    int num;
    printf("Digite o numero de pessoas: ");
    scanf("%d", &num);
    printf("Digite os nomes das pessoas: \n");
    getchar();
    while(num--){
        char nome[101];
        scanf("%s", nome);
        enqueue(f, nome);
    }
    int n;
    printf("Digite o numero de contagem p eliminar as pessoas: ");
    scanf("%d", &n);
    while(!isEmpty(f)){
        for(int i=0; i<n; i++){
        enqueue(f, front(f));
        dequeue(f);
        }
        printf("Eliminado %s\n", front(f));
        dequeue(f);
    }
    return 0;
}
