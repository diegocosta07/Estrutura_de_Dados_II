#include <stdio.h>
#include <stdlib.h>

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
	imprime_arv(arvore);

	return 0;
}