/*
Erros:
Erro -1: Erro desconhecido
Erro 1: Lista vazia
*/

 //consigo usar __fpurge(stdin) sem warnings (warning acusado usando gcc -wall)
#include <time.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdint.h>
#include "lib_musicas.h"



int main(void){
    int op;
    char titulo[32], artista[32];
    no_musica *Lista = NULL; //Ponteiro para lista de músicas inicialmente vazia
    no_musica *ListaRemovidos = NULL; //ponteiro para "lixeira"
    no_musica *no = NULL;

    do{
        puts("\nDigite a opcao desejada:");
        puts("1- Inserir musica");
        puts("2- Remover musica");
        puts("3- Alterar musica");
        puts("4- Buscar musica pelo titulo");
        puts("5- Buscar musicas pelo artista");
        puts("6- Recuperar músicas apagadas (EXTRA)");
        puts("7- Exibir dados de todas as musicas cadastradas");
        puts("\n0- Sair");
        puts("-1 Debugger: Exibir Lista");
        scanf("%d", &op);

        switch(op){
            case 1:
                if(adicionar_musica(&Lista, cria_musica()) != 0){
                    printf("Erro: impossivel adicionar a musica.");
                    __fpurge(stdin); getchar();
                }
                else{
                    printf("Musica adicionada com sucesso.");
                    __fpurge(stdin); getchar();
                }
                break;

            case 2:
                do{
                    puts("\n1- Remover por titulo");
                    puts("2- Remover por artista");
                    scanf("%d", &op);
                    if(op != 1 && op != 2)
                        puts("Erro: opcao invalida");
                }while(op != 1 && op != 2);
                
                if(op == 1){
                    printf("Digite o nome da musica a ser removida: ");
                    __fpurge(stdin); fgets(titulo, 32, stdin);
                    no = busca_musica(Lista, titulo, NULL);
                    if(no == NULL){
                        printf("Erro: elemento nao encontrado");
                        __fpurge(stdin); getchar();
                    }
                    else
                        if(remove_musica(&Lista, &ListaRemovidos, no) != 0){
                            printf("Erro inesperado");
                        }
                        else
                            printf("Removido com sucesso");
                        __fpurge(stdin); getchar();
                }

                else{
                    printf("Digite o nome do artista da musica a ser removida: ");
                    __fpurge(stdin); fgets(artista, 32, stdin);
                    no = busca_musica(Lista, NULL, artista);

                    if(no == NULL){
                        printf("Erro: nenhum elemento encontrado");
                        __fpurge(stdin); getchar();
                    }
                    else{
                        printf("\nResultados: %d \n", exibe_lista(Lista, artista));

                        printf("Digite o titulo da musica do(a) \""); imprime_string_sem_n(artista); printf("\" a ser removida: ");
                        fgets(titulo, 32, stdin);
                        no = busca_musica(Lista, titulo, artista);

                        if(no == NULL)
                            printf("Nenhum elemento encontrado");
                        else
                            if(remove_musica(&Lista, &ListaRemovidos, no) != 0)
                                printf("Erro inesperado");
                            else
                                printf("Removido com sucesso");
                        __fpurge(stdin); getchar();
                    }
                }
                break;

            case 3:
                printf("Digite o nome da musica a alterada: ");
                __fpurge(stdin); fgets(titulo, 32, stdin);
                no = busca_musica(Lista, titulo, NULL);
                if(no == NULL){
                    printf("Erro: elemento nao encontrado");
                    __fpurge(stdin); getchar();
                }
                else
                    if(altera_musica(&Lista, no) != 0){
                        printf("Erro inesperado");
                        __fpurge(stdin); getchar();
                    }
                break;

            case 4:
                printf("Digite o nome da musica a ser buscada: ");
                __fpurge(stdin); fgets(titulo, 32, stdin);
                no = busca_musica(Lista, titulo, NULL);
                if(no == NULL){
                    printf("Erro: elemento nao encontrado");
                    __fpurge(stdin); getchar();
                }
                else{
                    printf("\nExibindo resultado: \n");
                    exibe_musica(no->cadastro);
                    __fpurge(stdin); getchar();
                }
                break;

            case 5:
                printf("Digite o nome do artista: ");
                __fpurge(stdin); fgets(artista, 32, stdin);
                no = busca_musica(Lista, NULL, artista);
                if(no == NULL){
                    printf("Erro: nao foi encontrado nenhum elemento");
                    __fpurge(stdin); getchar();
                }
                else{
                    printf("\nResultados: %d \n", exibe_lista(Lista, artista));
                    __fpurge(stdin); getchar();
                }
                break;

            case 6:
                printf("Musicas previamente apagadas... \n");
                if(exibe_lista(ListaRemovidos, NULL) != 0){
                    printf("Erro: nenhuma musica foi apagada");
                    __fpurge(stdin); getchar();                    
                }
                //terminar
                break;

            case 7:
                printf("Exibindo resultados... \n");
                if(exibe_lista(Lista, NULL) != 0){
                    printf("Erro: Lista vazia");
                    __fpurge(stdin); getchar();                    
                }
                break;
            case -1:
                debugger_exibe_lista(Lista);
        }

    }while(op != 0);
}
