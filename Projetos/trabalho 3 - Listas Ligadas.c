#include <stdio.h>
#include <stdlib.h>

struct s_aluno{
    int ra;
    char nome[52];
    float nota;
    struct s_aluno *prox;
};
typedef struct s_aluno s_aluno;

/*pplista: ponteiro para o ponteiro que
aponta para o começo da lista
no: ponteiro que aponta para o novo nó */
void insere_nome (s_aluno *pplista, s_aluno *no){
    pplista; //quero que apontem pro mesmo endereço

    if(pplista == NULL) //Se a lista estiver vazia
        *pplista = *no; //a lista agora aponta para o novo nó
    else //Senão, a tento no bagulho seguinte
        insere_nome(&(*pplista->prox), no); //<<<<aqui pode dar merda no *prox
}

void remove_nome (s_aluno *pplista, int ra_removido){
    s_aluno *p = pplista;
    if(p != NULL){
        if(p->ra == ra_removido){
            pplista = p->prox;
            free(p);
        }
        else remove_nome(&(*p->prox), ra_removido); //VAI DAR MERDA
    }
}

void imprime_lista(s_aluno *pplista){
    if(pplista == NULL)
        printf("Lista vazia\n");
    else{
        printf("Nome: %s\n", pplista->nome);
        printf("RA: %d\n", pplista->ra);
        printf("Nota: %f\n", pplista->nota);
        imprime_lista(pplista->prox); //VAI DAR MERDA
    }
}
            
int main(void){
    s_aluno lista;
    lista.prox = NULL;
    
    s_aluno *Lista = NULL; //inicializando a lista
    s_aluno *No = (s_aluno *)malloc(sizeof(s_aluno));
    
    int op;
    
    puts("Digite a opcao desejada:");
    puts("1- Inserir cadastro");
    puts("2- Remover cadastro");
    puts("3- Buscar por RA");
    puts("4- Buscar por Nome");
    puts("Exibir dadps de todos alunos cadastrados");
    
    switch(op){
    case 1:
        printf("Digite o nome: ");
        fgets(lista.nome, 52, stdin);
        printf("Digite o RA: ");
        scanf("%d",&lista.ra);
        printf("Digite a nota: ");
        scanf("%f",&lista.nota);
        insere_aluno(Lista, &lista);
        break;
   }
   
   return 0;
 }
