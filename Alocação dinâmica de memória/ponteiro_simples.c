// Alocação dinamica de memória
//Ponteiro de ponteiro
#include <stdio.h>
int main(){
    int var = 10;
    int *a=&var;
    printf("endereco de a: %p\nendereco de var: %p\nvalor armazenado em a: %p\nvalor armazenado em a: %d\nvalor de var: %d\n", &a, &var, a,  *a, var);
 /*saida:
  endereco de a: 0x7fff93afa8a0
  endereco de var: 0x7fff93afa89c
  valor armazenado em a: 0x7fff93afa89c
  valor armazenado em a: 10
  valor de var: 10
*/
    return 0;
}
