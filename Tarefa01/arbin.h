typedef struct arvno
{
	int info;
	struct arvno* esq;
	struct arvno* dir;
} ArvNo;

typedef struct arv
{
	ArvNo* raiz;
} Arv;

ArvNo* arv_criaNo(int c, ArvNo* esq, ArvNo* dir);
Arv* arv_cria(ArvNo* r);
void imprime_No(ArvNo* r);
void imprime_arv(Arv* a);
void largura(ArvNo* r);
int tamanho(ArvNo* p);
ArvNo* busca(ArvNo* r, int c);
int altura(ArvNo* r);
void minmax(ArvNo* r, int* min, int* max);
void padding(char ch, int n);
void printfArvPritty(ArvNo* raiz, int level);
void espelho(ArvNo* r);
