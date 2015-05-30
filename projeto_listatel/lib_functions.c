#include <stdio_ext.h> //consigo usar __fpurge(stdin) sem warnings (warning acusado usando gcc -wall)
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "lib_functions.h"

no_registro *cria_no(){
    s_registro novo_registro;
    
    printf("Digite o nome: ");
    __fpurge(stdin); fgets(novo_registro.nome, size_nome, stdin);
    printf("Digite o CPF: ");
    scanf("%lf", &novo_registro.CPF);
    printf("Telefone para contato: ");
    scanf("%lf", &novo_registro.numeros[0]);

    no_registro *novo_no;
    novo_no = (no_registro *)malloc(sizeof(no_registro));
    novo_no->esq = NULL;
    novo_no->dir = NULL;

    novo_no = struct_para_no(novo_registro);

    return novo_no;
}

no_registro *struct_para_no(s_registro cadastro){
    no_registro *novo_no = (no_registro *)malloc(sizeof(no_registro));
    novo_no->esq = NULL;
    novo_no->dir = NULL;
    novo_no->cadastro = cadastro;

    return novo_no;
}

void adicionar_registro(no_registro **Lista, no_registro *novo_no, bool *pertence){
    if (*lista == NULL) {
        *lista = novo_no;
        *pertence = false;
    }
    else
        if (novo_no->cadastro.CPF == (*lista)->cadastro.CPF)
            *pertence = true;
        else if (novo_no->cadastro.CPF < (*lista)->cadastro.CPF)
            adicionar_registro(novo_no, &((*lista)->esq), pertence);
            else
                adicionar_registro(novo_no, &((*lista)->dir), pertence);
}

void exibe_pos_ordem(No *p){
    if (p != NULL) {
        exibe_pos_ordem(p->esq);
        exibe_pos_ordem(p->dir);
        printf("Info: %d\n", p->info);
    }
}