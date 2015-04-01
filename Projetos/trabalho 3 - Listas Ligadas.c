#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s_aluno{
    int ra;
    char nome[52];
    float nota;
    struct s_aluno *prox;
};

typedef struct s_aluno s_aluno;

void insere_aluno(s_aluno **pplista, int novo_ra, char novo_nome[], float nova_nota){ //insere struct no inicio

    s_aluno *no = (s_aluno *)malloc(sizeof(s_aluno));
    no->ra = novo_ra;
    strcpy(no->nome, novo_nome);
    no->prox = NULL;

    if(*pplista != NULL) // verifico se a lista nao ta vazia
        no->prox = *pplista; //se nao tiver, ponteiro do no aponta para onde apontava o ponteiro do inicio da lista
    pplista = &no; //lista agora aponta para onde o nó aponta
}

void exibe_alunos(s_aluno *pplista){
    s_aluno *p;
    for(p = pplista; p!=NULL; p = p->prox)
        printf("%s",p->nome);    
}

int main(){
    int ra; char nome[52]; float nota;
    s_aluno *Lista = NULL; //ponteiro pro começo da lista (que no começo é nula)
    
    ra = 104;
    strcpy(nome, "Rafael");
    nota = 10;

    insere_aluno(&Lista, ra, nome, nota);
    exibe_alunos(Lista);
    return 0;
}
