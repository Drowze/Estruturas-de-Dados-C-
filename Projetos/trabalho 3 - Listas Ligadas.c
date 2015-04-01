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

s_aluno cria_aluno(int novo_ra, char novo_nome[], float nova_nota){
    s_aluno novo_no;

    novo_no.ra = novo_ra;
    strcpy(novo_no.nome, novo_nome);
    novo_no.nota = nota_nota;
    novo_no.prox = NULL;

    return novo_no;
}

void insere_aluno(s_aluno **pplista, s_aluno *no){ //insere struct no inicio
    

    if(*pplista != NULL) // verifico se a lista nao ta vazia
        no->prox = *pplista; //se nao tiver, ponteiro do no aponta para onde apontava o ponteiro do inicio da lista
    *pplista = no; //lista agora aponta para o endereço do nó
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

    insere_aluno(&Lista, &(cria_aluno(ra,nome,nota)));
    exibe_alunos(Lista);
    return 0;
}
