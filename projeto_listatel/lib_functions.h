#ifndef LIB_FUNCTIONS_H_INCLUDED
#define LIB_FUNCTIONS_H_INCLUDED

#define size_nome 32

struct s_registro{
    char nome[size_nome];
    double CPF;
    double numeros[5];
    int qtd_numeros;
};
typedef struct s_registro s_registro;

struct no_registro{
    struct s_registro cadastro;
    struct no_registro *esq;
    struct no_registro *dir;
};
typedef struct no_registro no_registro;

struct linked_list{
	struct no_registro *registro;
	struct linked_list *prox;
};
typedef struct linked_list linked_list;

typedef enum {
    false = 0,
    true = 1,
} bool;

no_registro *g; /* variavel global para a remoção */

int escreve_no_arquivo(no_registro *Lista);
int le_arquivo(no_registro **Lista);
no_registro *struct_para_no(s_registro registro); //CHECK

//Prioridade:
no_registro *cria_no(); //CHECK
void adicionar_registro(no_registro **Lista, no_registro *novo_no, bool *pertence); //CHECK
//
no_registro *busca_registro_cpf(no_registro *Lista, double cpf, int *tempo_execucao, int *profundidade); //CHECK
no_registro *busca_registro_nome(no_registro *Lista, char nome[], int *tempo_execucao, int *profundidade);
no_registro *busca_registro_numero(no_registro *Lista, double numero, int *tempo_execucao, int *profundidade);
void remove_registro (no_registro *no_removido, no_registro **Lista); //CHECK
void remove2_registro (no_registro **aux); //CHECK
//
void altera_registro(no_registro *no_alterado, no_registro **Lista);
//
void exibe_in_ordem(no_registro *Lista, bool oganiza_cpf); //CHECK
void exibe_registro(s_registro registro); //CHECK
//
void exibe_tree(no_registro *Lista);
//
bool cpf_valido(double cpf);

//Lista ligada:
void linked_adiciona(no_registro *novo_no, linked_list **lista);
void linked_remove(no_registro *no_removido, linked_list **lista);

//auxiliares
void imprime_string_sem_n(char string[]);
int debugger_exibe_lista(no_registro *Lista);

#endif