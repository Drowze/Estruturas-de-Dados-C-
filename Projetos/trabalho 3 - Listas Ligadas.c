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
    p = pplista;
    if(p == NULL)
        printf("Erro, lista vazia\n");        
    else
        for(p = pplista; p!=NULL; p = p->prox){
            printf("RA: %d\n", p->ra);
            printf("Nome: %s", p->nome);
            printf("Nota: %.2f\n", p->nota);
        }
}

            

//Remove funciona. Preciso estudar essa merda.
void remove_aluno(s_aluno **pplista, int ra){
    s_aluno *aux = *pplista;
    s_aluno *anterior = NULL;

    if(aux == NULL)
        printf("Erro: lista vazia");
    else{
        while(aux != NULL && aux->ra != ra){
            anterior = aux;
            aux = aux->prox;
        }
        if(aux == NULL)
            printf("Elemento nao encontrado\n");
        else{ //se ele cair, VAI REMOVER ALGUMA COISA
            if(anterior == NULL)
                *pplista = aux->prox;
            else
                anterior->prox = aux->prox;
            printf("Removido com sucesso!");
        }
    }
}

void procura_ra(s_aluno **pplista, int ra){
    s_aluno *aux = *pplista;
    
    if(aux == NULL)
        printf("Erro: lista vazia");
    else{
        while(aux != NULL && aux->ra != ra){
            aux = aux->prox;
        }
        if(aux == NULL){
            printf("Elemento nao encontrado");
        }
        else{
            printf("Aluno encontrado: \n");
            printf("RA: %d\n", aux->ra);
            printf("Nome :%s", aux->nome);
            printf("Nota :%.2f\n", aux->nota);
        }
    }
}

void procura_nome(s_aluno **pplista, char nome[]){
    s_aluno *aux = *pplista;
    
    if(aux == NULL)
        printf("Erro: lista vazia");
    else{
        while(aux != NULL && strcmp(aux->nome, nome) != 0){
            aux = aux->prox;
        }
        if(aux == NULL){
            printf("Elemento nao encontrado");
        }
        else{
            printf("Aluno encontrado: \n");
            printf("RA: %d\n", aux->ra);
            printf("Nome :%s", aux->nome);
            printf("Nota :%.2f\n", aux->nota);
        }
    }
} 

int main(){
    int op;
    int ra; char nome[52]; float nota;
    s_aluno *Lista = NULL; //ponteiro pro começo da lista (que no começo é nula)
    s_aluno *aux = NULL; //esse cara serve pra mostra as parada
    
    
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
                printf("Digite o RA: ");
                scanf("%d", &ra);
                printf("Digite o nome: ");
                getchar(); fgets(nome, 52, stdin);
                printf("Digite a nota: ");
                scanf("%f", &nota);
                insere_aluno(&Lista, cria_aluno(ra,nome,nota)); //envio começo da lista e um novo nó criado on-the-fly
                break;
            case 2:
                printf("Digite o RA do registro a ser removido: ");
                scanf("%d", &ra);                
                remove_aluno(&Lista, ra);
                break;
            case 3:
                printf("Digite o RA a ser procurado");
                scanf("%d", &ra);
                procura_ra(&Lista, ra);
                break;
            case 4:
                printf("Digite o nome a ser procurado");
                __fpurge(stdin); 
                fgets(nome, 52, stdin);
                procura_nome(&Lista, nome);
                break;
            case 5:
                exibe_alunos(Lista);
                break;
        }
    }while(op != 0);
    return 0;
}
