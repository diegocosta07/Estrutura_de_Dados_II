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

//No com info tipo int(para questão 4)
typedef struct arvnoint
{
	char info;
	struct arvno* esq;
	struct arvno* dir;
} ArvNoInt;

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

//Criar no tipo int
ArvNo* arv_criaNoInt(int c, ArvNo* esq, ArvNo* dir) {
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


int tamanho(ArvNo* p) {
	if(p != NULL) {
		tam++;
		tamanho(p->esq);
		tamanho(p->dir);
	}
	return tam;
}

ArvNo* busca(ArvNo* raiz, char c) {
	ArvNo* i;
	for(i = raiz; i!=NULL; i=i->esq) {
		if (i->info == c){
			return i;
		}
	} 
	for(i = raiz; i!=NULL; i=i->dir) {
		if (i->info == c){
			return i;
		}
	} 
	return NULL;
}

int altura(ArvNo* raiz) {
	ArvNo* i;
	int alt1, alt2;
	alt1 = alt2 = 0;
	for(i = raiz; i!=NULL; i=i->esq) {
		alt1++;
	} 
	for(i = raiz; i!=NULL; i=i->dir) {
		alt2++;
	}
	if(alt1 > alt2)
		return alt1;
	else
		return alt2;
}

void minmax(ArvNo* raiz, int* min, int* max){
	*min = *max = raiz->info;
	ArvNo* i;

	for(i = raiz->esq; i!=NULL; i=i->esq) {
		if (i->info < *min){
			*min = i->info;
		} else if (i->info > *max) {
			*max = i->info;
		}
	} 
	for(i = raiz->dir; i!=NULL; i=i->dir) {
		if (i->info < *min){
			*min = i->info;
		} else if (i->info > *max) {
			*max = i->info;
		}
	} 
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

	int min, max;
	Arv* arvoreInt = arv_cria(
							arv_criaNoInt(0,
										arv_criaNoInt(1,
											 arv_criaNoInt(2, NULL, NULL),
											 arv_criaNoInt(3, arv_criaNoInt(4, NULL, NULL), NULL)),
										arv_criaNoInt(5,
												arv_criaNoInt(6, NULL,
														arv_criaNoInt(7, NULL, NULL)), NULL)
										)
							);
	//imprime_arv(arvore);
	printf("\n");
	//largura(arvore->raiz);

	//QUESTAO 1
	printf("QUESTAO 1\nQuantidade de nos da arvore %d\n",tamanho(arvore->raiz));

	//QUESTAO 2
	if(busca(arvore->raiz, 'D') != NULL)
		printf("QUESTAO 2\nNo encontrado!\n");
	else
		printf("QUESTAO 2\nNo nao encontrado\n");

	//QUESTAO 3
	printf("QUESTAO 3\nAltura da arvore %d\n",altura(arvore->raiz)+1);

	//QUESTAO 4
	minmax(arvoreInt->raiz,&min,&max);
	printf("QUESTAO 4\nMenor valor da arvore eh %d\n",min);
	printf("Maior valor da arvore eh %d\n",max);

	return 0;
}
