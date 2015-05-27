#include <stdio_ext.h> //consigo usar __fpurge(stdin) sem warnings (warning acusado usando gcc -wall)
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "lib_functions.h"

no_registro *cria_no(){
    s_registro novo_registro;
    
    printf("Digite o nome: ");
    __fpurge(stdin); fgets(nova_musica.titulo, size_nome, stdin);
    printf("Digite o CPF: ")
    scanf("%lf", &novo_registro.CPF);
    printf("Telefone para contato: ")
    scanf("%lf", &novo_registro.numeros[0]);

    no_registro *novo_no;
    novo_no = (no_registro *)malloc(sizeof(no_registro));
    novo_no->esq = NULL;
    novo_no->dir = NULL;

    novo_no = struct_para_no(s_registro);

    return novo_no;
}

no_musica *struct_para_no(s_registro cadastro){
    no_registro *novo_no = (no_registro *)malloc(sizeof(no_registro));
    novo_no->esq = NULL;
    novo_no->dir = NULL;
    novo_no->cadastro = cadastro;

    return novo_no;
}

