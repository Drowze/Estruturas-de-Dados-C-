#include <stdio_ext.h> //consigo usar __fpurge(stdin) sem warnings (warning acusado usando gcc -wall)
#include <stdlib.h>
#include <string.h>
#include "lib_musicas.h"

/* FUNÇÕES RELACIONADAS A STRUCT */
int exibe_musica(s_musica *musica){
    if(musica != NULL){
        printf("Arquivo: %s", musica->nome_arquivo);
        printf("Artista: %s", musica->artista);
        printf("Titulo: %s", musica->titulo);
        printf("Genero: %s", musica->genero);
        printf("Ano: %d\n", musica->ano);
        return 0;
    }
    else return 1;
}

s_musica *cria_musica(){
    s_musica *nova_musica;
    nova_musica = (s_musica *)malloc(sizeof(s_musica));

    printf("Digite o nome do artista: ");
    __fpurge(stdin); fgets(nova_musica->artista, 32, stdin);
    printf("Digite o titulo da faixa: ");
    __fpurge(stdin); fgets(nova_musica->titulo, 32, stdin);
    printf("Digite o genero da faixa: ");
    __fpurge(stdin); fgets(nova_musica->genero, 32, stdin);
    printf("Digite o ano da faixa: ");
    scanf("%d", &(nova_musica->ano));
    printf("Para finalizar, digite o nome do arquivo: ");
    __fpurge(stdin); fgets(nova_musica->nome_arquivo, 32, stdin);
    
    nova_musica->prox = NULL;
    return nova_musica; //Possível erro: nova_musica = NULL ; Falta de memória.
}

int copia_musica(s_musica *destino, s_musica *origem){
    if(destino == NULL || origem == NULL)
        return 1;
    strcpy(destino->artista, origem->artista);
    strcpy(destino->titulo, origem->titulo);
    strcpy(destino->genero, origem->genero);
    strcpy(destino->nome_arquivo, origem->nome_arquivo);
    destino->ano = origem->ano;
    // destino->ano = origem->ano;
    return 0;
}

int altera_musica(s_musica **lista, s_musica *no_alterado){
    //Ideia:
    //1) copiar no_alterado -> novo_no
    //2) alterações no novo_no
    //3) remover no_alterado da lista
    //4) adicionar novo_no na lista
    char op;
    s_musica *novo_no = (s_musica *)malloc(sizeof(s_musica));

    copia_musica(novo_no, no_alterado);
    novo_no->prox = NULL;

    //começa modificação:
    printf("Nome do arquivo: %s", novo_no->nome_arquivo);

    //artista:
    printf("Deseja modificar o artista <s/n>? Artista atual: %s", novo_no->artista);
    do{
        __fpurge(stdin); scanf("%c", &op);
        if(op != 's' && op != 'S' && op != 'n' && op != 'N')
            printf("Erro: opcao invalida");
    }while(op != 's' && op != 'S' && op != 'n' && op != 'N');
    if(op == 's' || op == 'S'){
        __fpurge(stdin); fgets(novo_no->artista, 32, stdin);
    }

    //titulo:
    printf("Deseja modificar o titulo <s/n>? Titulo atual: %s", novo_no->titulo);
    do{
        __fpurge(stdin); scanf("%c", &op);
        if(op != 's' && op != 'S' && op != 'n' && op != 'N')
            printf("Erro: opcao invalida");
    }while(op != 's' && op != 'S' && op != 'n' && op != 'N');
    if(op == 's' || op == 'S'){
        __fpurge(stdin); fgets(novo_no->titulo, 32, stdin);
    }

    //genero:
    printf("Deseja modificar o genero <s/n>? Genero atual: %s", novo_no->genero);
    do{
        __fpurge(stdin); scanf("%c", &op);
        if(op != 's' && op != 'S' && op != 'n' && op != 'N')
            printf("Erro: opcao invalida");
    }while(op != 's' && op != 'S' && op != 'n' && op != 'N');
    if(op == 's' || op == 'S'){
        __fpurge(stdin); fgets(novo_no->genero, 32, stdin);
    }

    //ano:
    printf("Deseja modificar o ano <s/n>? Ano atual: %d\n", novo_no->ano);
    do{
        __fpurge(stdin); scanf("%c", &op);
        if(op != 's' && op != 'S' && op != 'n' && op != 'N')
            printf("Erro: opcao invalida");
    }while(op != 's' && op != 'S' && op != 'n' && op != 'N');
    if(op == 's' || op == 'S'){
        scanf("%d", &(novo_no->ano));
    }

    //nome do arquivo:
    printf("Deseja modificar o nome do arquivo <s/n>? Nome atual: %s", novo_no->nome_arquivo);
    do{
        __fpurge(stdin); scanf("%c", &op);
        if(op != 's' && op != 'S' && op != 'n' && op != 'N')
            printf("Erro: opcao invalida");
    }while(op != 's' && op != 'S' && op != 'n' && op != 'N');
    if(op == 's' || op == 'S'){
        __fpurge(stdin); fgets(novo_no->nome_arquivo, 32, stdin);
    }

    if(remove_musica(lista, no_alterado) != 0)
        return 1;
    else if(adicionar_musica(lista, novo_no) != 0)
        return 1;
    else 
        return 0;
}
/* FIM DAS FUNÇÕES RELACIONADAS A STRUCT */

//----------------------------------------//

/* LOGICA DA LISTA (FUNÇÕES RELACIONADAS A LIGACAO DAS STRUCTS) */
int adicionar_musica(s_musica **lista, s_musica *novo_no){ //deve armazenar de forma alfabética
    s_musica *aux = *lista;
    s_musica *anterior = NULL;

    if(aux == NULL){ //caso não exista elementos antes dele
        *lista = novo_no;
        novo_no->prox = NULL;
        return 0;
    }
    else{
        while(aux != NULL && strcmp(aux->titulo, novo_no->titulo) < 0){ //eqnt aux->titulo for anterior a no->titulo, ande; http://i.imgur.com/4Q7oKLG.png
            anterior = aux;
            aux = aux->prox;
        }
        if(aux == NULL){ //se ele cai aqui, insere novo_no final
            anterior->prox = novo_no;
            novo_no->prox = NULL;
        }
        else{
            if(anterior == NULL){ //se ele cai aqui, insere antes do primeiro
                novo_no->prox = aux;
                *lista = novo_no;
            }
            else{ //se ele cai aqui, pode ser em qualquer outro espaço
                novo_no->prox = anterior->prox;
                anterior->prox = novo_no;
            }
        }
        return 0;
    }
    return 1; //Erro: não foi possível adicionar na lista (?)
}

int remove_musica(s_musica **lista, s_musica *no_removido){
    s_musica *aux = *lista;
    s_musica *anterior = NULL;

    while(aux != NULL && aux != no_removido){
        anterior = aux;
        aux = aux->prox;
    }
    if(aux == no_removido){ //sem erros?
        if(anterior == NULL){
            *lista = aux->prox;
            free(aux);
        }
        else{
            anterior->prox = aux->prox;
            free(aux);
        }
        return 0;
    }
    return 1;
}

//Sobre a procura: se titulo = NULL, remoção por artista, caso contrário artista = NULL
s_musica *busca_musica(s_musica *lista, char titulo[], char artista[]){
    s_musica *aux = lista;
    s_musica *anterior = NULL;

    if(aux == NULL)
        return NULL;
    else{
        while(aux != NULL && strcmp(aux->titulo, titulo) < 0){
            anterior = aux;
            aux = aux->prox;
        }
        if(aux == NULL || strcmp(aux->titulo, titulo) != 0)
            return NULL;
        else
            return aux;
    }
}

//void busca_musica_artista(){} //opcional

//void recupera_musica(){} //opcional

int exibe_lista(s_musica *lista){
    s_musica *p;
    p = lista;

    if(p == NULL)
        return 1;
    else{
        for(p = lista; p!=NULL; p = p->prox){
            exibe_musica(p);
            printf("\t ---\n");
        }
        return 0;
    }
}
