#include <stdio.h>
#include <stdlib.h>
#include "pilha_encadeada.h"
int main()
{
    Pilha* p = pilha_cria();
    pilha_push(p, 4);
    pilha_push(p, 44);
    pilha_push(p, 22);
    pilha_push(p, 3);
    pilha_imprime(p);
    printf("----------------------\n");
    pilha_pop(p);
    pilha_pop(p);
    pilha_imprime(p);
}
