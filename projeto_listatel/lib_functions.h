#ifndef LIB_FUNCTIONS_H_INCLUDED
#define LIB_FUNCTIONS_H_INCLUDED

#define size_nome 32

struct s_registro{
    char nome[size_nome];
    double CPF;
    double numeros[5];
};
typedef struct s_registro s_registro;

struct no_registro{
    struct s_registro cadastro;
    struct no_registro *esq;
    struct no_registro *dir;
};
typedef struct no_registro no_registro;

typedef enum {
    false = 0,
    true = 1,
} bool;

int escreve_no_arquivo(no_registro *Lista);
int le_arquivo(no_registro **Lista);
no_registro *struct_para_no(s_registro registro);

//Prioridade:
no_registro *cria_registro();
int adicionar_registro(no_registro **lista, no_registro *novo_no);
//
no_registro *busca_registro(no_registro *lista, char nome[], double cpf, double numero, int *tempo_execucao, int *profundidade);
int remove_registro(no_registro **lista, no_registro *no_removido);
//
int altera_registro(no_registro **lista, no_registro *no_alterado);
//
int exibe_lista(no_registro *lista, bool oganiza_cpf);
void exibe_registro(s_registro registro);
//
void exibe_tree(no_registro *lista);

//auxiliares
void imprime_string_sem_n(char string[]);
int debugger_exibe_lista(no_registro *Lista);

#endif
