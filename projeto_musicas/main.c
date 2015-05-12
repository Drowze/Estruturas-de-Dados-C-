/*
Erros:
Erro -1: Erro desconhecido
Erro 1: Lista vazia
*/

 //consigo usar __fpurge(stdin) sem warnings (warning acusado usando gcc -wall)
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "lib_musicas.h"

int main(void){
    int op;
    char titulo[32];
    s_musica *Lista = NULL; //Ponteiro para lista de músicas inicialmente vazia
    s_musica *removidas = NULL;
    s_musica *musica = NULL;

    do{
        puts("\nDigite a opcao desejada:");
        puts("1- Inserir musica");
        puts("2- Remover musica");
        puts("3- Alterar musica");
        puts("4- Buscar musica pelo titulo");
        puts("5- Buscar musicas pelo artista (EXTRA)");
        puts("6- Recuperar músicas apagadas (EXTRA)");
        puts("7- Exibir dados de todas as musicas cadastradas");
        puts("\n0- Sair");
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
                printf("Digite o nome da musica a ser removida: ");
                __fpurge(stdin); fgets(titulo, 32, stdin);
                musica = busca_musica(Lista, titulo, NULL);
                if(musica == NULL){
                    printf("Erro: elemento nao encontrado");
                    __fpurge(stdin); getchar();
                }
                else
                    if(remove_musica(&Lista, musica) != 0){
                        printf("Erro inesperado");
                        __fpurge(stdin); getchar();
                    }
                break;

            case 3:
                printf("Digite o nome da musica a alterada: ");
                __fpurge(stdin); fgets(titulo, 32, stdin);
                musica = busca_musica(Lista, titulo, NULL);
                if(musica == NULL){
                    printf("Erro: elemento nao encontrado");
                    __fpurge(stdin); getchar();
                }
                else
                    if(altera_musica(&Lista, musica) != 0){
                        printf("Erro inesperado");
                        __fpurge(stdin); getchar();
                    }
                break;

            case 4:
                printf("Digite o nome da musica a ser buscada");
                __fpurge(stdin); fgets(titulo, 32, stdin);
                musica = busca_musica(Lista, titulo, NULL);
                if(musica == NULL){
                    printf("Erro: elemento nao encontrado");
                    __fpurge(stdin); getchar();
                }
                else{
                    printf("Exibindo resultado: \n");
                    exibe_musica(musica);
                    __fpurge(stdin); getchar();
                }
                break;

            case 7:
                printf("Exibindo resultados... \n");
                if(exibe_lista(Lista) == 1){
                    printf("Erro: Lista vazia");
                    __fpurge(stdin); getchar();                    
                }
                break;
        }

    }while(op != 0);
}
