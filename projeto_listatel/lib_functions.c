//Pra diferença de tempo em micros: gettimeofday(); difftime();

#include <stdio_ext.h> //consigo usar __fpurge(stdin) sem warnings (warning acusado usando gcc -wall)
#include <stdlib.h>
#include <string.h>
#include "lib_functions.h"

no_registro *cria_no(){
    s_registro novo_registro;
    int i;
    
    printf("Digite o nome: ");
    __fpurge(stdin); fgets(novo_registro.nome, size_nome, stdin);
    printf("Digite o CPF: ");
    do{
        scanf("%lf", &novo_registro.CPF);
        if(!cpf_valido(novo_registro.CPF))
            printf("CPF invalido, digite novamente");
    }while(!cpf_valido(novo_registro.CPF));
    do{
        printf("Quantidade de numeros para contato: ");
        scanf("%d", &novo_registro.qtd_numeros);
        if(novo_registro.qtd_numeros < 1 && novo_registro.qtd_numeros > 5)
            printf("Quantidade invalida");
    }while(novo_registro.qtd_numeros < 1 && novo_registro.qtd_numeros > 5);
    for(i = 0; i < novo_registro.qtd_numeros; i++){
        printf("%dº telefone para contato: ", i+1);
        scanf("%lf", &novo_registro.numeros[i]);
    }


    no_registro *novo_no;

    novo_no = struct_para_no(novo_registro);

    return novo_no;
}

//Utilidade principal: converter as structs de um arquivo para nós de uma lista
no_registro *struct_para_no(s_registro cadastro){
    no_registro *novo_no = (no_registro *)malloc(sizeof(no_registro));
    novo_no->esq = NULL;
    novo_no->dir = NULL;
    novo_no->cadastro = cadastro;

    return novo_no;
}

void adicionar_registro(no_registro **Lista, no_registro *novo_no, bool *pertence){
    if (*Lista == NULL) {
        *Lista = novo_no;
        *pertence = false;
    } else
        if (novo_no->cadastro.CPF == (*Lista)->cadastro.CPF){
            *pertence = true;
        } else 
            if (novo_no->cadastro.CPF < (*Lista)->cadastro.CPF)
                adicionar_registro(&((*Lista)->esq), novo_no, pertence);
            else
                adicionar_registro(&((*Lista)->dir), novo_no, pertence);
}

void remove_registro (no_registro *no_removido, no_registro **Lista) {
    if (*Lista == NULL) 
        printf("Nao ha chave k\n") ;
    else
        if (no_removido->cadastro.CPF < (*Lista)->cadastro.CPF) 
            remove_registro (no_removido, &(*Lista)->esq) ;
        else
            if (no_removido->cadastro.CPF > (*Lista)->cadastro.CPF)
                remove_registro (no_removido, &(*Lista)->dir) ;
            else { /* remover */
                g = *Lista ;
                if (g->dir == NULL) 
                    *Lista = g->esq ; /* soh tem um...filho ? */
                else 
                    if (g->esq == NULL) 
                        *Lista = g->dir ;
                    else /* troca pelo mais a dir da subarvore esq */
                        remove2_registro (&g->esq) ;
                    free (g) ;
            }
}

void remove2_registro (no_registro **r) {
    if ((*r)->dir != NULL) 
        remove2_registro (&(*r)->dir) ;
    else {
        g->cadastro = (*r)->cadastro ;
        g = *r ;
        *r = (*r)->esq ;
    }
}

void altera_registro (no_registro *no_alterado, no_registro **Lista){
    //1) copiar no_alterado->cadastro para copia
    //2) alterações no copia
    //3) remover no_alterado da lista
    //4) criar no_copia e colocar na lista

    int op, i, aux, aux1;
    s_registro copia = no_alterado->cadastro;
    no_registro *no_copia;
    bool auxiliar_boolean = false;

    do{
        printf("\n Qual campo deseja alterar?\n");
        printf("1- Nome \t| atual: %s", copia.nome);
        printf("2- CPF \t\t| atual: %.0lf\n", copia.CPF);
        printf("3- Numeros de telefone\n");
        printf("\n 0: Salvar e sair");
        printf("\n-1: Sair sem salvar\n");
        printf("Sua opcao: ");
        scanf("%d", &op);
        switch(op){
            case 1:
                printf("Digite o novo nome: ");
                __fpurge(stdin); fgets(copia.nome, size_nome, stdin);
                break;
            case 2:
                printf("Digite o novo CPF: ");
                do{
                    scanf("%lf", &copia.CPF);
                    if(!cpf_valido(copia.CPF))
                        printf("CPF invalido, digite novamente");
                }while(!cpf_valido(copia.CPF));
                break;
            case 3:
                printf("\n  Operacoes:\n");
                printf("1- Adicionar\n");
                printf("2- Alterar existente\n");
                printf("3- Remover existente\n");
                printf("\n0- Cancelar\n");
                printf("Sua opcao: ");
                scanf("%d", &aux1);
                do{
                    if(aux1 < 0 && aux1 > 3)
                        printf("Erro: opcao invalida. Tente novamente: ");
                }while(aux1 < 0 && aux1 > 3);
                if(aux1 == 1){
                    if(copia.qtd_numeros < 5){
                        scanf("%lf", &copia.numeros[copia.qtd_numeros]);
                        copia.qtd_numeros++;
                    } else
                        printf("Erro: voce nao pode adicionar mais que 5 numeros");
                } else
                        if(op != 0){
                            printf("\n Numeros de telefone: \n");
                            for(i = 0; i < copia.qtd_numeros; i++){
                                printf("%d: %.0lf\n", i+1, copia.numeros[i]);
                            }
                            printf("\nNumero a ser alterado (escolha a opcao correspondente): ");
                            scanf("%d", &aux);
                            if(aux-1 < 0 || aux-1 > copia.qtd_numeros)
                                printf("Numero invalido\n");
                            else{
                                if(aux1 == 2){
                                    printf("Digite o novo numero: ");
                                    scanf("%lf", &(copia.numeros[aux-1]));
                                } else
                                    if(aux1 == 3){
                                        if(copia.qtd_numeros > 1){
                                            for(; aux < 4; aux++)
                                                copia.numeros[i] = copia.numeros[i+1];
                                            copia.qtd_numeros--;
                                        } else
                                            printf("Erro: voce nao pode apagar o unico contato do cliente\n");
                                    }
                            }
                        }
                break;
            case 0:
                no_copia = struct_para_no(copia);
                remove_registro(no_alterado, Lista);
                adicionar_registro(Lista, no_copia, &auxiliar_boolean);
                break;
            case -1:
                break;
        }
    }while(op != 0 && op != -1);
}

//se organiza_cpf = true, exibe in-ordem por CPF, se não, exibe por nome (vai dar treta isso)
void exibe_in_ordem(no_registro *p, bool organiza_cpf) {
    if(organiza_cpf) {
        if(p != NULL) {
            exibe_in_ordem(p->esq, organiza_cpf);
            exibe_registro(p->cadastro);
            printf("----\n");
            exibe_in_ordem(p->dir, organiza_cpf);
        }
    }
    else{
        linked_list *lista = NULL;
        tree_to_linked(p, &lista);
        exibe_linked(lista);
    }
}

void exibe_registro(s_registro registro){
    int i;
    printf("Nome: %s", registro.nome);
    printf("CPF: %.0lf\n", registro.CPF);
    for(i = 0; i < registro.qtd_numeros; i++)
        printf("%dº numero para contato: %.0lf\n", i+1, registro.numeros[i]);
}

no_registro *busca_registro_cpf(no_registro *Lista, double cpf, int *tempo_execucao, int *profundidade){
    if(Lista == NULL){
        return NULL; // não rolou :(
    } else 
        if(cpf < Lista->cadastro.CPF) {
            (*profundidade)++;
            return busca_registro_cpf(Lista->esq, cpf, tempo_execucao, profundidade);
        } else
            if(cpf > Lista->cadastro.CPF){
                (*profundidade)++;
                return busca_registro_cpf(Lista->dir, cpf, tempo_execucao, profundidade);
            } else {
                //*tempo_execucao = ?
                //profundidade = ?
                return Lista; // achooo~
            }
}

/* LINKED LIST FUNCTIONS */
//Exibindo em ordem alfabetica: tree_to_linked, exibe_linked, linked_wipe

void tree_to_linked(no_registro *tree, linked_list **lista){
    if(*lista == NULL){
        *lista = (linked_list *)malloc(sizeof(linked_list));
        tree_to_linked(tree, lista);
    }
    else if (tree != NULL) {
        tree_to_linked(tree->esq, lista);
        linked_adiciona(tree, lista);
        tree_to_linked(tree->dir, lista);
    }
}

int linked_adiciona(no_registro *novo_no, linked_list **lista){
    linked_list *aux = *lista;
    linked_list *anterior = NULL;
    
    linked_list *new_node = (linked_list *)malloc(sizeof(linked_list));
    if(new_node == NULL)
        return -1;
    new_node->registro = novo_no;
    new_node->prox = NULL;

    if(*lista == NULL){
        *lista = new_node;
        (*lista)->prox = NULL;
        return 0;
    } else {
        while((aux != NULL) && strcmp(aux->registro->cadastro.nome, new_node->registro->cadastro.nome) < 0){
            anterior = aux;
            aux = aux->prox;
        }
        if(aux == NULL){
            anterior->prox = new_node;
            new_node->prox = NULL;
        }
        else{
            if(anterior == NULL){
                *lista = new_node;
                new_node->prox = aux;
            }
            else{
                anterior->prox = new_node;
                new_node->prox = aux;
            }
        }
        return 0;
    }
}

int linked_wipe(linked_list **lista) {
    if(*lista == NULL)
        return -1;

    linked_list *aux = *lista;
    linked_list *proximo;

    while(aux != NULL){
        proximo = aux->prox;
        free(aux);
        aux = proximo;
    }

    return 0;

    *lista = NULL;
}

// int linked_remove(no_registro *no_removido, linked_list **lista){
//     linked_list *aux = *lista;
//     linked_list *anterior = NULL;

//     if(aux == NULL)
//         return -1;
//     else{
//         while(aux != NULL && aux->registro->cadastro.CPF != no_removido->cadastro.CPF){
//             anterior = aux;
//             aux = aux->prox;
//         }
//         if(aux == NULL)
//             return -1;
//         else{ //se ele cair, VAI REMOVER ALGUMA COISA
//             if(anterior == NULL){
//                 *lista = aux->prox;
//                 free(aux);
//             }
//             else{
//                 anterior->prox = aux->prox;
//                 free(aux);
//             }
//             return 0;
//         }
//     }
// }

//seg-faul aqui
int exibe_linked(linked_list *lista){
    if(lista == NULL)
        return -1;
    else{
        //while(lista != NULL){
            exibe_registro(lista->registro->cadastro);
            if(lista->prox != NULL) 
                printf("\t --- \n");
            lista = lista->prox;
        //}
        return 0;
    }
}


//apenas uma ideia; o professor falou que vai dar nota pra isso. Podemos implementar depois
bool cpf_valido(double cpf){
    return true;
    //referência: http://www.geradorcpf.com/algoritmo_do_cpf.htm
}