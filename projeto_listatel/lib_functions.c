#include <stdio_ext.h> //consigo usar __fpurge(stdin) sem warnings (warning acusado usando gcc -wall)
#include <stdlib.h>
#include <string.h>
#include "lib_functions.h"

no_registro *cria_no(){
    s_registro novo_registro;
    int i;
    
    printf("Digite o nome: ");
    __fpurge(stdin); fgets(novo_registro.nome, size_nome, stdin);
    printf("Digite o CPF: ");
    scanf("%lf", &novo_registro.CPF);
    do{
        printf("Quantidade de numeros para contato: ");
        scanf("%d", &novo_registro.qtd_numeros);
        if(novo_registro.qtd_numeros < 1 && novo_registro.qtd_numeros > 5)
            printf("Quantidade invalida");
    }while(novo_registro.qtd_numeros < 1 && novo_registro.qtd_numeros > 5);
    for(i = 0; i < novo_registro.qtd_numeros; i++){
        printf("%dº telefone para contato: ", i+1);
        scanf("%lf", &novo_registro.numeros[i]);
    }


    no_registro *novo_no;

    novo_no = struct_para_no(novo_registro);

    return novo_no;
}

//Utilidade principal: converter as structs de um arquivo para nós de uma lista
no_registro *struct_para_no(s_registro cadastro){
    no_registro *novo_no = (no_registro *)malloc(sizeof(no_registro));
    novo_no->esq = NULL;
    novo_no->dir = NULL;
    novo_no->cadastro = cadastro;

    return novo_no;
}

void adicionar_registro(no_registro **Lista, no_registro *novo_no, bool *pertence){
    if (*Lista == NULL) {
        *Lista = novo_no;
        *pertence = false;
    } else
        if (novo_no->cadastro.CPF == (*Lista)->cadastro.CPF){
            *pertence = true;
        } else 
            if (novo_no->cadastro.CPF < (*Lista)->cadastro.CPF)
                adicionar_registro(&((*Lista)->esq), novo_no, pertence);
            else
                adicionar_registro(&((*Lista)->dir), novo_no, pertence);
}

//se organiza_cpf = true, exibe in-ordem por CPF, se não, exibe por nome (vai dar treta isso)
void exibe_in_ordem(no_registro *p, bool organiza_cpf) {
    if(organiza_cpf){
        if(p != NULL) {
            exibe_in_ordem(p->esq, organiza_cpf);
            exibe_registro(p->cadastro);
            printf("----\n");
            exibe_in_ordem(p->dir, organiza_cpf);
        }
    }
    else{

    }
}

void exibe_registro(s_registro registro){
    int i;
    printf("Nome: %s", registro.nome);
    printf("CPF: %lf\n", registro.CPF);
    for(i = 0; i < registro.qtd_numeros; i++)
        printf("%dº numero para contato: %lf\n", i+1, registro.numeros[i]);
}

no_registro *busca_registro_cpf(no_registro *Lista, double cpf, int *tempo_execucao, int *profundidade){
    if(Lista == NULL){
        return NULL; // não rolou :(
    } else 
        if(cpf < Lista->cadastro.CPF) {
            return busca_registro_cpf(Lista->esq, cpf, tempo_execucao, profundidade);
        } else
            if(cpf > Lista->cadastro.CPF){
                return busca_registro_cpf(Lista->dir, cpf, tempo_execucao, profundidade);
            } else
                return Lista; // achooo~
}





//apenas uma ideia; o professor falou que vai dar nota pra isso. Podemos implementar depois
bool cpf_valido(cpf){
    return true;
    //referência: http://www.geradorcpf.com/algoritmo_do_cpf.htm
}

    //Prioridade:
    //Busca é por CPF? (não == -1)
    //Busca é por por nome? (não == NULL)
    //Busca é por numero? (não == -1)
    //Foi encontrado: retorna ponteiro pro bangue
    //Não foi encontrado: retorna NULL
    //Erro: retorna NULL