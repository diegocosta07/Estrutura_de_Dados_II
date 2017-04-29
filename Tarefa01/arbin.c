#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "arbin.h"
#include "stack.h"

ArvNo* arv_criaNo(int c, ArvNo* esq, ArvNo* dir) {
	ArvNo* p = (ArvNo*) malloc(sizeof(ArvNo));
	p->info = c;
	p->esq = esq;
	p->dir = dir;
	return p;
}

Arv* arv_cria(ArvNo* r) {
	Arv* a = (Arv*) malloc(sizeof(Arv));
	a->raiz = r;
	return a;
}

void imprime_No(ArvNo* r) {
	printf("<");
	if(r != NULL) {
		printf(" %d\n", r->info);
		imprime_No(r->esq);
		imprime_No(r->dir);
	}
	printf(">");
}

void imprime_arv(Arv* a) {
	imprime_No(a->raiz);
}

void largura(ArvNo* r) {
	Queue fila;
	queueInit(&fila, sizeof(ArvNo*));
	enqueue(&fila, &r);
	while(getQueueSize(&fila) > 0) {
		ArvNo* aux;
		dequeue(&fila, &aux);
		if(aux) {
			printf("%d\n", aux->info);
			enqueue(&fila, &aux->esq);
			enqueue(&fila, &aux->dir);
		}
	}
	clearQueue(&fila);
}

int tam = 0;
int tamanho(ArvNo* p) {
	if(p != NULL) {
		tam++;
		tamanho(p->esq);
		tamanho(p->dir);
	}
	return tam;
}

ArvNo* busca(ArvNo* r, int c) {
	Queue fila;
	queueInit(&fila, sizeof(ArvNo*));
	enqueue(&fila, &r);
	while(getQueueSize(&fila) > 0) {
		ArvNo* aux;
		dequeue(&fila, &aux);
		if(aux) {
			if(aux->info == c)
				return aux;
			else {
				enqueue(&fila, &aux->esq);
				enqueue(&fila, &aux->dir);
			}
		}
	}
	clearQueue(&fila);
	return NULL;
}

int altura(ArvNo* r) {
	Queue fila;
	int tam = 0;
	queueInit(&fila, sizeof(ArvNo*));
	enqueue(&fila, &r);
	while(getQueueSize(&fila) > 0) {
		ArvNo* aux;
		dequeue(&fila, &aux);
		if(aux) {
				enqueue(&fila, &aux->esq);
				tam++;
			}
	}
	clearQueue(&fila);
	return tam;
}

void minmax(ArvNo* r, int* min, int* max) {
	*min = *max = r->info;
	Queue fila;
	queueInit(&fila, sizeof(ArvNo*));
	enqueue(&fila, &r);
	while(getQueueSize(&fila) > 0) {
		ArvNo* aux;
		dequeue(&fila, &aux);
		if(aux) {
			if(aux->info < *min)
				*min = aux->info;
			else if (aux->info > *max) 
				*max = aux->info;
			enqueue(&fila, &aux->esq);
			enqueue(&fila, &aux->dir);
		}
	}
	clearQueue(&fila);
}

//Impressão agradável

void padding(char ch, int n) {
	int i;
	for(i = 0; i<n; i++)
		putchar(ch);
}

void printfArvPritty(ArvNo* raiz, int level) {
	int i;
	if (raiz == NULL) {
		padding('\t', level);
		puts(" ");
	} else {
		printfArvPritty(raiz->dir, level+1);
		padding('\t', level);
		printf("%c\n", raiz->info);
		printfArvPritty(raiz->esq, level+1);
	}
}

void espelho(ArvNo* r) {
	if(r == NULL) 
		return;
	else {
		ArvNo* temp;

		/*espelha as subarvores*/

		espelho(r->esq);
		espelho(r->dir);

		/*troca os ponteiros desse nodo*/
		temp = r->esq;
		r->esq = r->dir;
		r->dir = temp;
	}

}

void printInOrder(ArvNo* r) {
	stack* pilha;
	void (*freeFn)(stack*);
	freeFn = &stack_destroy;
	stack_new(pilha,sizeof(ArvNo*),(*freeFn)(pilha));

	while(stack_size(&pilha) > 0 || r != NULL) {
		if (r != NULL) {
			stack_push(&pilha,&r);
			r = r->esq;
		}
		else {
			stack_pop(&pilha,&r);
			printf("%d\n",r->info);
			r = r->dir;
		}
	}
}
