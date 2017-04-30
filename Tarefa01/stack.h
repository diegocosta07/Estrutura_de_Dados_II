#include <stdlib.h>
#include "arbin.h"
struct lista{
    ArvNo* info;
    struct lista* prox;
}; typedef struct lista Lista;

struct pilha{
    Lista* prim;
}; typedef struct pilha Pilha;

Pilha* pilha_cria();
void pilha_push(Pilha* p, ArvNo* v);
ArvNo* pilha_pop(Pilha* p);
int pilha_vazia(Pilha* p);
void pilha_libera(Pilha* p);
void pilha_imprime(Pilha* p);