#ifndef LIB_MUSICAS_H_INCLUDED
#define LIB_MUSICAS_H_INCLUDED

struct s_musica{
    char artista[32];
    char titulo[32];
    char genero[32];
    int ano;
    char nome_arquivo[32];
    struct tm data_cria;
    struct tm data_mod;
};
typedef struct s_musica s_musica;

struct no_musica{
    struct s_musica cadastro;
    struct no_musica *prox;
    struct no_musica *ant;
};
typedef struct no_musica no_musica;

/* Arquivo */
int escreve_no_arquivo(no_musica *Lista);
int le_arquivo(no_musica **Lista);
int cria_musica_do_arquivo(s_musica musica, no_musica **Lista);

/* Funções feias e não modulares */
no_musica *cria_musica(); //CHECK
void exibe_musica(s_musica musica); //CHECK
//int copia_musica(no_musica *destino, no_musica *origem); //depreciated
int altera_musica(no_musica **lista, no_musica *no_alterado); //CHECK
void imprime_string_sem_n(char string[]);

/* Funções bonitas e modulares */
int adicionar_musica(no_musica **lista, no_musica *novo_no); //CHECK
int remove_musica(no_musica **lista, no_musica **lista_removidos, no_musica *no_removido); //CHECK
int hard_delete(no_musica **lista, no_musica *no_removido);
no_musica *busca_musica(no_musica *lista, char titulo[], char artista[]); //CHECK
int exibe_lista(no_musica *lista, char artista[]); // CHECK

/* Funções de debug */
int debugger_exibe_lista(no_musica *Lista);

#endif
