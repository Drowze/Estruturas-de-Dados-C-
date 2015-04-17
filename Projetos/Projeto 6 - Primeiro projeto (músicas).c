#include <stdio_ext.h> //consigo usar __fpurge(stdin) sem warnings (warning acusado usando gcc -wall)
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
    printf("Para finalizar, digite o nome do arquivo: ");
    __fpurge(stdin); fgets(nova_musica->nome_arquivo, 32, stdin);

    return nova_musica;
}
/* FIM DAS FUNÇÕES NÃO MODULARES */


/* DAQUI PRA BAIXO: LOGICA DA LISTA */
void adicionar_musica(s_musica **lista, s_musica *novo_no){ //deve armazenar de forma alfabética
    s_musica *aux = *lista;
    s_musica *anterior = NULL;

    if(aux == NULL){ //caso não exista elementos antes dele
        *lista = novo_no;
        novo_no->prox = NULL;
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
            printf("\nAperte enter para continuar\n");
            __fpurge(stdin); getchar();
    }
}

//Sobre a remoção e alteração: se titulo = NULL, remoção por artista
void remove_musica(s_musica **lista, char titulo[], char artista[]){
    s_musica *aux = *lista;
    s_musica *anterior = NULL;

    if(titulo != NULL){
        if(aux == NULL){
            printf("Erro: lista vazia");
            printf("\nAperte enter para continuar\n");
            __fpurge(stdin); getchar();
        }
        else{
            while(aux != NULL && (strcmp(aux->titulo, titulo) != 0) ){
                anterior = aux;
                aux = aux->prox;
            }
            if(aux == NULL){
                printf("Elemento nao encontrado\n");
                printf("\nAperte enter para continuar\n");
                __fpurge(stdin); getchar();
            }
            else{ //se ele cair, VAI REMOVER ALGUMA COISA
                if(anterior == NULL){ //pro caso de remover o primeiro termo
                    *lista = aux->prox;
                    free(aux);
                }
                else{ //pra outros termos quaisquer
                    anterior->prox = aux->prox;
                    free(aux);
                }
                printf("Removido com sucesso!");
                printf("\nAperte enter para continuar\n");
                __fpurge(stdin); getchar();
            }
        }
    }

    else{} //remoção por artista, aqui o bagulho é loko
}

/*void altera_musica(s_musica **lista, char titulo[], char artista[]){
    s_musica *aux = *lista;
    s_musica *anterior = NULL;

    if(titulo != NULL){
        if(aux == NULL){
            printf("Erro: lista vazia");
            printf("\nAperte enter para continuar\n");
            __fpurge(stdin); getchar();
        }
        else{
            while(aux != NULL && (strcmp(aux->titulo, titulo) != 0) ){
                anterior = aux;
                aux = aux->prox;
            }
            if(aux == NULL){
                printf("Elemento nao encontrado\n");
                printf("\nAperte enter para continuar\n");
                __fpurge(stdin); getchar();
            }
            else{ //se ele cair, ele achou
                if(anterior == NULL){ //pro caso de modificar o primeiro termo
                    printf("1: %s", (*lista)->nome_arquivo);
                    printf("2: Artista: %s", (*lista)->artista);
                    printf("3: Titulo: %s", (*lista)->titulo);
                    printf("4: Genero: %s", (*lista)->genero);
                    printf("5: Ano: %d\n", (*lista)->ano);

                    puts("--------------------");
                }
                else{ //pra outros termos quaisquer
                    printf("1: %s", anterior->nome_arquivo);
                    printf("2: Artista: %s", anterior->artista);
                    printf("3: Titulo: %s", anterior->titulo);
                    printf("4: Genero: %s", anterior->genero);
                    printf("5: Ano: %d\n", anterior->ano);
                }
                printf("Removido com sucesso!");
                printf("\nAperte enter para continuar\n");
                __fpurge(stdin); getchar();
            }
        }
    }

    else{} //remoção por artista, aqui o bagulho é loko
}*/

//s_musica *busca_musica_titulo(){}

//void busca_musica_artista(){} //opcional

//void recupera_musica(){} //opcional

void exibe_lista(s_musica *lista){
    s_musica *p;
    p = lista;

    if(p == NULL){
        printf("Erro: Lista vazia");
        printf("\nAperte enter para continuar\n");
        __fpurge(stdin); getchar();
    }
    else{
        printf("\nImprimindo resultados:\n\n");
        for(p = lista; p!=NULL; p = p->prox){
            printf("%s", p->nome_arquivo);
            printf("Artista: %s", p->artista);
            printf("Titulo: %s", p->titulo);
            printf("Genero: %s", p->genero);
            printf("Ano: %d\n", p->ano);
            printf("---------------------------\n");
        }
        printf("\nAperte enter para continuar\n");
        __fpurge(stdin); getchar();
    }

}

int main(void){
    int op;
    char titulo[32];
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
                break;
            case 2: //falta opcional: remoção por artista (???)
                printf("Digite o nome da musica a ser removida: ");
                __fpurge(stdin); fgets(titulo, 32, stdin);
                remove_musica(&Lista, titulo, NULL);
                break;
            case 3:
                printf("Digite o nome da musica a alterada: ");
                __fpurge(stdin); fgets(titulo, 32, stdin);
            case 7:
                exibe_lista(Lista);
                break;
        }

    }while(op != 0);


}
