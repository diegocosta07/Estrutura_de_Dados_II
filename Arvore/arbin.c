#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


int tam = 0; //variavel para o tamanho da arvore

//No com info tipo char
typedef struct arvno
{
	char info;
	struct arvno* esq;
	struct arvno* dir;
} ArvNo;


typedef struct arv
{
	ArvNo* raiz;
} Arv;

ArvNo* arv_criaNo(char c, ArvNo* esq, ArvNo* dir) {
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
		printf(" %c\n", r->info);
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
			printf("%c\n", aux->info);
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

//constroi a partir da string
int operador(char c) {
	switch(c) {
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
			return 1;
	}
	return 0;
}

ArvNo* constroi(char* pre, int* i) {
	char c;
	ArvNo *p;

	c = pre[(*i)++]; /*lê e avança*/

	printf("c: %c\n", c);

	p = malloc(sizeof(ArvNo));
	p->info = c;

	if(operador(c)) {
		p->esq = constroi(pre, i);
		p->dir = constroi(pre, i);
	}
	else
		p->esq = p->dir = NULL;
	return p;
}


int main() {
	Arv* arvore = arv_cria(
							arv_criaNo('A',
										arv_criaNo('B',
											 arv_criaNo('D', NULL, NULL),
											 arv_criaNo('E', arv_criaNo('G', NULL, NULL), NULL)),
										arv_criaNo('C',
												arv_criaNo('F', NULL,
														arv_criaNo('H', NULL, NULL)), NULL)
										)
							);
	//imprime_arv(arvore);
	//largura(arvore->raiz);

	int i=0;
	ArvNo* raiz;
	char pre[20] = "*+ab/cd";
	raiz = constroi(pre,&i);
	printfArvPritty(arvore->raiz, 0);

	printf("\n");

	return 0;
}
