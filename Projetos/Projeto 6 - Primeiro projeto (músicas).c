#include <stdio.h> //consigo usar __fpurge(stdin) sem warnings (warning acusado usando gcc -wall)
#include <stdlib.h>
#include <string.h>

struct s_musica{
    char artista[32];
    char titulo[32];
    char genero[32];
    int ano;
    char nome_arquivo[32];
    //data de modificação?
    struct s_musica *prox;
};
typedef struct s_musica s_musica;

/* A PARTIR DAQUI: FUNÇÕES NÃO MODULARES */
s_musica *cria_musica(){
    s_musica *nova_musica;
    nova_musica = (s_musica *)malloc(sizeof(nova_musica));

    printf("Digite o nome do artista: ");
    __fpurge(stdin); fgets(nova_musica->artista, 32, stdin);
    printf("Digite o titulo da faixa: ");
    __fpurge(stdin); fgets(nova_musica->titulo, 32, stdin);
    printf("Digite o genero da faixa: ");
    __fpurge(stdin); fgets(nova_musica->genero, 32, stdin);
    printf("Digite o ano da faixa: ");
    scanf("%d", &(nova_musica->ano));
    printf("Para finalizar, digite o nome do arquivo");
    __fpurge(stdin); fgets(nova_musica->nome_arquivo, 32, stdin);

    return nova_musica;
}
/* FIM DAS FUNÇÕES NÃO MODULARES */


/* DAQUI PRA BAIXO: LOGICA DA LISTA */
void adicionar_musica(s_musica **lista, s_musica *novo_no){ //deve armazenar de forma alfabética

}

//Sobre a remoção: se titulo = NULL, remoção por artista
//void remove_musica(s_musica **lista, char titulo[], char artista[]){}

//void altera_musica(){}

//void busca_musica_titulo(){}

//void busca_musica_artista(){} //opcional

//void recupera_musica(){} //opcional

//void exibe_lista(s_musica **lista){}

int main(void){
    int op;
    s_musica *Lista = NULL; //Ponteiro para lista de músicas inicialmente vazia

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
                adicionar_musica(&Lista, cria_musica());

        }

    }while(op != 0);


}
