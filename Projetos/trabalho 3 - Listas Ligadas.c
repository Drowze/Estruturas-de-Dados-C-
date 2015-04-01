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

s_aluno *cria_aluno(int novo_ra, char novo_nome[], float nova_nota){
    s_aluno *novo_no;
    novo_no = (s_aluno *)malloc(sizeof(s_aluno));

    novo_no->ra = novo_ra;
    strcpy(novo_no->nome, novo_nome);
    novo_no->nota = nova_nota;
    novo_no->prox = NULL;

    return novo_no;
}

void insere_aluno(s_aluno **pplista, s_aluno *no){ //insere struct no inicio
    if(*pplista != NULL) // verifico se a lista nao ta vazia
        no->prox = *pplista; //se nao tiver, ponteiro do no aponta para onde apontava o ponteiro do inicio da lista
    *pplista = no; //lista agora aponta para o endereço para onde nó aponta
}

void exibe_alunos(s_aluno *pplista){
    s_aluno *p;
    for(p = pplista; p!=NULL; p = p->prox){
        printf("RA: %d\n", p->ra);
        printf("Nome: %s", p->nome);
        printf("Nota: %f\n", p->nota);
    }
}

//REMOVE ALUNO NÃO FUNCIONA
/*
void remove_aluno(s_aluno **pplista, int ra){
    s_aluno *aux = *pplista;

    if(*pplista == NULL)
        printf("Erro: lista vazia");
    else if(pplista->prox == NULL && aux->prox->ra == ra)
        aux->prox = NULL;
    else{
        



    }
}*/

int main(){
    int op;
    int ra; char nome[52]; float nota;
    s_aluno *Lista = NULL; //ponteiro pro começo da lista (que no começo é nula)
    
    
    do{
        puts("\nDigite a opcao desejada:");
        puts("1- Inserir aluno");
        puts("2- Remover aluno (NAO IMPLEMENTADO)");
        puts("3- Buscar aluno por RA (NAO IMPLEMENTADO)");
        puts("4- Buscar aluno por nome (NAO IMPLEMENTADO)");
        puts("5- Exibir dados de todos os alunos cadastrados");
        puts("\n0- Sair");
        scanf("%d", &op);
        switch(op){
            case 1: 
                printf("Digite o RA");
                scanf("%d", &ra);
                printf("Digite o nome");
                getchar(); fgets(nome, 52, stdin);
                printf("Digite a nota");
                scanf("%f", &nota);
                insere_aluno(&Lista, cria_aluno(ra,nome,nota)); //envio começo da lista e um novo nó criado on-the-fly
                break;
            case 5:
                exibe_alunos(Lista);
        }
    }while(op != 0);
    return 0;
}
