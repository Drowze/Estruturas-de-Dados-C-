#include <stdio.h>
#include <stdlib.h>

struct no {
	int info;
	struct no *esq, *dir;
};
typedef struct no No;

void inicializa_arvore(No *raiz){
	raiz->info = -1;
	raiz->esq = NULL;
	raiz->dir = NULL;
}


int main () {
	No *raiz;
	inicializa_arvore(raiz);


}