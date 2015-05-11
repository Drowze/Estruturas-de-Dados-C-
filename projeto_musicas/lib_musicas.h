#ifndef LIB_MUSICAS_H_INCLUDED
#define LIB_MUSICAS_H_INCLUDED

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

/* Funções feias e não modulares */
s_musica *cria_musica();
int exibe_musica(s_musica *musica);
int copia_musica(s_musica *destino, s_musica *origem);
int altera_musica(s_musica **lista, s_musica *no_alterado);

/* Funções bonitas e modulares */
int adicionar_musica(s_musica **lista, s_musica *novo_no);
int remove_musica(s_musica **lista, s_musica *no_removido);
s_musica *busca_musica(s_musica *lista, char titulo[], char artista[]);
int exibe_lista(s_musica *lista);

#endif
