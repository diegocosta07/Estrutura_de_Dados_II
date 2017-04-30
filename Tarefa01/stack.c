#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
Pilha* pilha_cria(){
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->prim = NULL;
    return p;
}
void pilha_push(Pilha* p, ArvNo* v){
    Lista* n = (Lista*) malloc(sizeof(Lista));
    n->info = v;
    n->prox = p->prim;
    p->prim = n;
}
ArvNo* pilha_pop(Pilha* p){
    Lista* t;
    ArvNo* v;
    if(pilha_vazia(p)){
        printf("Pilha vazia.\n");
        exit(1);
    }
    t = p->prim;
    v = t->info;
    p->prim = t->prox;
    free(t);
    return v;
}
int pilha_vazia(Pilha* p){
    return (p->prim==NULL);
}
void pilha_libera(Pilha* p){
    Lista* q = p->prim;
    while(q!=NULL){
        Lista* t = q->prox;
        free(q);
        q = t;
    }
    free(p);
}
void pilha_imprime(Pilha* p){
    Lista* q;
    for(q=p->prim; q!=NULL; q=q->prox)
        printf("%d\n",q->info->info);
}