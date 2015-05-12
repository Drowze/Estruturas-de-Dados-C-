#include <stdio_ext.h> //consigo usar __fpurge(stdin) sem warnings (warning acusado usando gcc -wall)
#include <stdlib.h>
#include <string.h>
#include "lib_musicas.h"

/* FUNÇÕES QUE MEXEM COM A STRUCT CADASTRO */
void exibe_musica(s_musica musica){
    printf("Titulo: %s", musica.titulo);
    printf("Artista: %s", musica.artista);
    printf("Genero: %s", musica.genero);
    printf("Ano: %d\n", musica.ano);
    printf("Arquivo: %s", musica.nome_arquivo);
}

no_musica *cria_musica(){
    no_musica *novo_no;
    s_musica nova_musica;
    novo_no = (no_musica *)malloc(sizeof(no_musica));

    printf("Digite o nome do artista: ");
    __fpurge(stdin); fgets(nova_musica.artista, 32, stdin);
    printf("Digite o titulo da faixa: ");
    __fpurge(stdin); fgets(nova_musica.titulo, 32, stdin);
    printf("Digite o genero da faixa: ");
    __fpurge(stdin); fgets(nova_musica.genero, 32, stdin);
    printf("Digite o ano da faixa: ");
    scanf("%d", &nova_musica.ano);
    printf("Para finalizar, digite o nome do arquivo: ");
    __fpurge(stdin); fgets(nova_musica.nome_arquivo, 32, stdin);
    
    novo_no->cadastro = nova_musica;
    novo_no->prox = NULL;
    novo_no->ant = NULL;
    return novo_no; //Possível erro: nova_musica = NULL ; Falta de memória.
}

int altera_musica(no_musica **lista, no_musica *no_alterado){
    //Ideia:
    //1) copiar no_alterado -> novo_no
    //2) alterações no novo_no
    //3) remover no_alterado da lista
    //4) adicionar novo_no na lista
    int op;

    no_musica *copia = (no_musica *)malloc(sizeof(no_musica));
    copia->prox = NULL; copia->ant = NULL; copia->cadastro = no_alterado->cadastro;

    do{
        printf("\n Qual campo deseja alterar?\n");
        printf("1- Artista \t\t| atual: %s", copia->cadastro.artista);
        printf("2- Titulo \t\t| atual: %s", copia->cadastro.titulo);
        printf("3- Genero \t\t| atual: %s", copia->cadastro.genero);
        printf("4- Ano \t\t\t| atual: %d\n", copia->cadastro.ano);
        printf("5- Nome do arquivo \t| atual: %s", copia->cadastro.nome_arquivo);
        printf("\n 0: Salvar e terminar alteracoes\n");
        printf("-1: Abandonar alteracoes\n");
        scanf("%d", &op);
        switch(op){
            case 1:
                printf("Digite o novo nome de artista: ");
                __fpurge(stdin); fgets(copia->cadastro.artista, 32, stdin);
                break;
            case 2:
                printf("Digite o novo titulo: ");
                __fpurge(stdin); fgets(copia->cadastro.titulo, 32, stdin);
                break;
            case 3:
                printf("Digite o novo genero: ");
                __fpurge(stdin); fgets(copia->cadastro.genero, 32, stdin);
                break;
            case 4:
                printf("Digite o novo ano: ");
                scanf("%d", &(copia->cadastro.ano));
                break;
            case 5:
                printf("Digite o novo nome do arquivo: ");
                __fpurge(stdin); fgets(copia->cadastro.nome_arquivo, 32, stdin);
                break;
            case 0:
                if(remove_musica(lista, no_alterado) != 0)
                    return 1;
                if(adicionar_musica(lista, copia) != 0)
                    return 1;
                return 0;
            case -1:
                return 0;
        }
    }while(op != 0);
    return 1;
}

//----------------------------------------//

/* FUNÇÕES QUE MEXEM COM OS NÓS */
int adicionar_musica(no_musica **lista, no_musica *novo_no){ //deve armazenar de forma alfabética
    /*
        considerei eliminar o *anterior, mas isso me seria um problema
        na hora de adicionar um elemento ao final da lista, já que aux
        apontaria para NULL e eu não poderia fazer aux->ant->prox = novo_no,
        como seria desejado.
        Para resolver esse problema, o ideal seria implementar uma lista
        circular, possivelmente com nó cabeça.

        Fica pra próxima.
    */

    no_musica *aux = *lista;
    no_musica *anterior = NULL;

    if(aux == NULL){ //Anteriormente, lista vazia
        *lista = novo_no;
        novo_no->prox = NULL;
        novo_no->ant = NULL;
        return 0;
    }
    else{
        while(aux != NULL && (strcmp(aux->cadastro.titulo, novo_no->cadastro.titulo) < 0 ) ) { //eqnt aux->titulo for anterior a no->titulo, ande; http://i.imgur.com/4Q7oKLG.png
            anterior = aux;
            aux = aux->prox;
        }
        if(aux == NULL){ //Insere no final
            anterior->prox = novo_no;
            novo_no->ant = anterior;
            novo_no->prox = NULL;
        }
        else{
            if(anterior == NULL){ //se ele cai aqui, insere antes do primeiro
                *lista = novo_no;
                novo_no->ant = NULL; //ou igual anterior
                novo_no->prox = aux;
                aux->ant = novo_no;
            }
            else{ //se ele cai aqui, pode ser em qualquer outro espaço
                anterior->prox = novo_no;
                novo_no->ant = anterior;
                novo_no->prox = aux;
                aux->ant = novo_no;
            }
        }
        return 0;
    }
    return 1; //Erro: não foi possível adicionar na lista (?)
}

int remove_musica(no_musica **lista, no_musica *no_removido){

    if(no_removido == NULL) //é inesperado cair nesse erro
        return 1;

    if(no_removido == *lista){ //Checa se é o primeiro da lista
        *lista = no_removido->prox; //lista aponta pro seguinte ao removido
        if(no_removido->prox != NULL) //Checo se não é o único elemento na lista
            no_removido->prox->ant = NULL; // (*ant) do seguinte ao removido aponta pra NULL (ele agora é o primeiro elemento)
        free(no_removido);
        return 0;
    }

    else 
        if(no_removido->ant != NULL && no_removido->prox != NULL){ //Checo se tá no meio (não é primeiro nem último)
            no_removido->ant->prox = no_removido->prox; // (*prox) do anterior ao removido aponta para o seguinte ao removido
            no_removido->prox->ant = no_removido->ant; // (*ant) do seguinte ao removido aponta para o anterior ao removido
            free(no_removido);
            return 0;
        }
        else
            if(no_removido->prox == NULL){ //Checo se é o último
                no_removido->ant->prox = NULL; //(*prox) do anterior ao removido aponta pra NULL (ele agora é o último elemento)
                free(no_removido);
                return 0;
            }

    return 1; //se chegou aqui deu um erro cabuloso na moral
}

//void recupera_musica(){} //opcional

//Sobre a procura: se titulo = NULL, remoção por artista, caso contrário artista = NULL
no_musica *busca_musica(no_musica *lista, char titulo[], char artista[]){
    no_musica *aux = lista;

    if(aux == NULL)
        return NULL;
    while(aux != NULL && strcmp(aux->cadastro.titulo, titulo) < 0)
        aux = aux->prox;

    if(aux == NULL || strcmp(aux->cadastro.titulo, titulo) != 0)
        return NULL;
    else
        return aux;
    
}

int exibe_lista(no_musica *Lista){

    if(Lista == NULL)
        return 1;

    while(Lista != NULL){
        exibe_musica(Lista->cadastro);
        printf("\t --- \n");
        Lista = Lista->prox;
    }

    return 0;
}

int debugger_exibe_lista(no_musica *Lista){

    if(Lista == NULL)
        return 1;

    int i = 0;
    while(Lista != NULL){
        printf("Indice: %d\n", i);
        printf("Endereco: %p\n", (void *) Lista);
        printf("Endereco (struct): %p\n", (void *) &(Lista->cadastro));
        printf("Nome da musica: %s", Lista->cadastro.titulo);
        printf("Endereco->ant: %p\n", (void *) (Lista->ant));
        printf("Endereco->prox: %p\n\n", (void *) (Lista->prox));
        Lista = Lista->prox;
        i++;
    }
    __fpurge(stdin); getchar();

    return 0;
}