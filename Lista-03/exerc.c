#include <stdio.h>
#include <stdlib.h>

struct no {
    int info;
    struct no *esq, *dir;
};
typedef struct no No;

struct fila {
    int info;
    struct fila *prox;
};
typedef struct fila Fila;

typedef enum {
    false = 0,
    true = 1,
} bool;

void inicializa_fila(Fila **nova_fila){
    *nova_fila = NULL;
}

void insere_fila(Fila **minha_fila, Fila novo_no){
    if(*minha_fila == NULL)

}

void inicializa_arvore(No **raiz){
    *raiz = NULL;
}

No *cria_no(){
    No *novo_no;
    novo_no = (No *)malloc(sizeof(No));
    printf("Digite o valor de info: ");
    scanf("%d", &(novo_no->info));
    novo_no->esq = NULL;
    novo_no->dir = NULL;

    return novo_no;
}

void insere_arvore(No *novo_no, No **p, bool *pertence){
    if (*p == NULL) {
        *p = novo_no;
        *pertence = false;
    }
    else
        if (novo_no->info == (*p)->info)
            *pertence = true;
        else if (novo_no->info < (*p)->info)
            insere_arvore(novo_no, &((*p)->esq), pertence);
            else
                insere_arvore(novo_no, &((*p)->dir), pertence);
}

void exibe_in_ordem(No *p) {
    if(p != NULL) {
        exibe_in_ordem(p->esq);
        printf("Info: %d\n", p->info);
        exibe_in_ordem(p->dir);
    }
}

void exibe_pre_ordem(No *p){
    if (p != NULL) {
        printf("Info: %d\n", p->info);
        exibe_pre_ordem (p->esq);
        exibe_pre_ordem (p->dir);
    }
}

void exibe_pos_ordem(No *p){
    if (p != NULL) {
        exibe_pos_ordem(p->esq);
        exibe_pos_ordem(p->dir);
        printf("Info: %d\n", p->info);
    }
}

void exibe_largura()

int main () {
    No *raiz;
    inicializa_arvore(&raiz);

    int op;
    bool pertence = false;

    do{
        puts("1- Insercao em lista binaria");
        puts("2- Exibir usando \"in ordem\"");
        puts("3- Exibe usando \"pre-ordem\"");
        puts("4- Exibe usando \"pos-ordem\"");
        scanf("%d", &op);

        switch(op){
            case 1:
                insere_arvore(cria_no(), &raiz, &pertence);
                break;
            case 2:
                exibe_in_ordem(raiz);
                break;
            case 3:
                exibe_pre_ordem(raiz);
                break;
            case 4:
                exibe_pos_ordem(raiz);
                break;

        }

    }while(op != 0);

}