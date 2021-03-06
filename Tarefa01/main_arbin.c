#include "arbin.h"
#include <stdio.h>
#include <stdlib.h>
int main() {

	int min, max;
	Arv* arvore = arv_cria(
							arv_criaNo(0,
										arv_criaNo(1,
											 arv_criaNo(2, NULL, NULL),
											 arv_criaNo(3, arv_criaNo(4, NULL, NULL), NULL)),
										arv_criaNo(5,
												arv_criaNo(6, NULL,
														arv_criaNo(7, NULL, NULL)), NULL)
										)
							);
	
	printf("\n");
	//largura(arvore->raiz);
	printf("Arvone preorder\n");
	imprime_No(arvore->raiz);
	//QUESTAO 1
	printf("QUESTAO 1\nQuantidade de nos da arvore %d\n",tamanho(arvore->raiz));

	//QUESTAO 2
	if(busca(arvore->raiz, 3) != NULL)
		printf("QUESTAO 2\n No contrado!\n");
	else
		printf("QUESTAO 2\n No nao encontrado\n");

	//QUESTAO 3
	printf("QUESTAO 3\nAltura da arvore %d\n",altura(arvore->raiz));

	//QUESTAO 4
	minmax(arvore->raiz,&min,&max);
	printf("QUESTAO 4\nMenor valor da arvore eh %d\n",min);
	printf("Maior valor da arvore eh %d\n",max);

	//QUESTAO 5
	printf("QUESTAO 5\n");
	espelho(arvore->raiz);
	printfArvPritty(arvore->raiz,0);

	//QUESTAO 6
	printf("QUESTAO 6\n");
	espelho(arvore->raiz);//reverter o espelho
	printInOrder(arvore->raiz);

	//QUESTAO 7
	printf("QUESTAO 7\n");
	printPosOrder(arvore->raiz);

	//QUESTAO 8
	printf("QUESTAO 8\n");
	printf("Não consegui fazer\n");

	return 0;
}