// Alocação dinamica de memória
//Ponteiro de ponteiro
#include <stdio.h>
int main(){
    int var = 10;
    int *intptr = &var;
    int **ptrptr = &intptr;
    printf("var: %d \nAddress of var: %p \n\n",var, &var);
    printf("inttptr: %p \nAddress of inttptr: %p \n\n", intptr, &intptr);
    printf("var: %d \nValue at intptr: %d \n\n", var, *intptr);
    printf("ptrptr: %p \nAddress of ptrtptr: %p \n\n", ptrptr, &ptrptr);
    printf("intptr: %p \nValue at ptrptr: %p \n\n", intptr, *ptrptr);
    printf("var: %d \n*intptr: %d \n**ptrptr: %d\n", var, *intptr, **ptrptr);
    return 0;
}
