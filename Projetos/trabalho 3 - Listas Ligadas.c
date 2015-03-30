#include <stdio.h>
#include <stdlib.h>

struct s_aluno{
    int ra;
    char nome[52];
    float nota;
    struct s_aluno *prox;
};

typedef struct s_aluno s_aluno;

void insere_aluno(s_aluno **pplista, s_aluno *no){
    if(*pplista != NULL) // verifico se a lista nao ta vazia
        no->prox = *pplista; //se nao tiver, ponteiro do no aponta para onde apontava o ponteiro do inicio da lista
    *pplista = no; //lista agora aponta para onde o nó aponta
}

int main(){
    s_aluno *Lista;
    s_aluno *no;
    insere_aluno(&Lista, no);
    return 0;
}
