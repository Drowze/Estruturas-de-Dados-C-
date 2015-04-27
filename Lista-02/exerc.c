#include <stdio_ext.h>
#include <stdlib.h>

struct no {
    int info;
    struct no *prox;
};
typedef struct no No;

No *cria_no(){
    No *novo_no;
    novo_no = (No *)malloc(sizeof(novo_no));

    printf("Digite o campo info: ");
    scanf("%d", &(novo_no->info));

    novo_no->prox = NULL;

    return novo_no;
}

int exibir_tudo(No *Lista){
    if(Lista == NULL)
        return 1;

    system("clear");
    int i = 0;
    while(Lista != NULL){
        printf("Indice: %d\n", i);
        printf("Endereco: %p\n", (void *) Lista);
        printf("info: %d\n", Lista->info);
        printf("Endereco->prox: %p\n\n", (void *) (Lista->prox));
        Lista = Lista->prox;
        i++;
    }
    __fpurge(stdin); getchar();

    return 0;
}

/* COMEÇO DOS EXERCICIOS */

void insere_inicio(No **Lista, No *novo_no){
    if(*Lista != NULL)
        novo_no->prox = *Lista;
    *Lista = novo_no;
}

void insere_fim(No **Lista, No *novo_no){
    No *aux;
    aux = *Lista;
    
    if(aux == NULL)
        *Lista = novo_no;
    else{
        while(aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo_no;
    }
}

int insere_kesima(No **Lista, No *novo_no, int k){
    int i=0;

    No *aux = *Lista;
    No *anterior = NULL;

    if(k == 0){
        novo_no->prox = *Lista;
        *Lista = novo_no;
    }
    else{
        while(i<k){
            if(aux != NULL){
                anterior = aux;
                aux = aux->prox;
            }
            else
                return 1; //pro caso de k ser maior que a quantidade de elementos
            i++;
        }
        anterior->prox = novo_no;
        novo_no->prox = aux;
    }

    return 0;
}

int exibe_primeiro(No *Lista){
    if(Lista == NULL)
        return 1;

    printf("Indice: 0\n");
    printf("Endereco: %p\n", (void *) Lista);
    printf("info: %d\n", Lista->info);
    printf("Endereco->prox: %p\n\n", (void *) (Lista->prox));

    __fpurge(stdin); getchar();

    return 0;
}

int exibe_ultimo(No *Lista){
    if(Lista == NULL)
        return 1;

    int i=0;
    while(Lista->prox != NULL){
        Lista = Lista->prox;
        i++;
    }
 
    printf("Indice: %d\n", i);
    printf("Endereco: %p\n", (void *) Lista);
    printf("info: %d\n", Lista->info);
    printf("Endereco->prox: %p\n\n", (void *) (Lista->prox));

    return 0;
}

int exibe_kesimo(No *Lista, int k){
    if(Lista == NULL)
        return 1;

    int i=0;

    while(i<k){
        if(Lista != NULL){
            Lista = Lista->prox;
            i++;
        }
        else
            return 2; //erro: i não existe
    }

    printf("Indice: %d\n", i);
    printf("Endereco: %p\n", (void *) Lista);
    printf("info: %d\n", Lista->info);
    printf("Endereco->prox: %p\n\n", (void *) (Lista->prox));

    return 0;
}

int exclui_primeiro(No **Lista){
    if(*Lista == NULL)
        return 1;

    No *aux = *Lista;
    *Lista = (*Lista)->prox;
    free(aux);

    return 0;
}

int exclui_ultimo(No **Lista){
    if(*Lista == NULL)
        return 1;

    No *aux = *Lista;
    No *anterior = NULL;

    if((*Lista)->prox == NULL){
        free(*Lista);
        *Lista = NULL;
    }
    else{
        while(aux->prox != NULL){
            anterior = aux;
            aux = aux->prox;
        }
        anterior->prox = NULL;
        free(aux);
    }

    return 0;
}

int exclui_kesimo(No **Lista, int k){
    if(*Lista == NULL)
        return 1;

    int i = 0;
    No *aux = *Lista;
    No *anterior = NULL;

    while(i < k){
        if(aux != NULL){
            anterior = aux;
            aux = aux->prox;
        }
        else
            return 2;
        i++;
    }
    
    if(anterior == NULL){
        *Lista = aux->prox;
        free(aux);
    }
    else{
        anterior->prox = aux->prox;
        free(aux);
    }

    return 0;
}

int procurar_elemento(No *Lista, int info){
    if(Lista == NULL)
        return 0; //lista vazia, logo nao achou lol

    while(Lista->info != info)
        Lista = Lista->prox;

    return 1;
}

int contador_nos(No *Lista){
    int i = 0;

    while(Lista != NULL){
        Lista = Lista->prox;
        i++;
    }

    return i;
}

int soma_info(No *Lista){
    if(Lista == NULL)
        return -1;

    int soma = 0;

    while(Lista != NULL){
        soma += Lista->info;
        Lista = Lista->prox;
    }

    return soma;
}

No *cria_copia(No *Lista){
    No *Copia = NULL;
    No *aux = NULL;

    if(Lista == NULL)
        return Copia;
    else
        while(Lista != NULL){
            aux = (No *)malloc(sizeof(No));
            aux->info = Lista->info;
            aux->prox = NULL;

            insere_fim(&Copia, aux);
            Lista = Lista->prox;
        }


    return Copia;
}

No *cria_copia_invertida(No *Lista){
    No *Copia = NULL;
    No *aux = NULL;

    if(Lista == NULL)
        return Copia;
    else
        while(Lista != NULL){
            aux = (No *)malloc(sizeof(No));
            aux->info = Lista->info;

            insere_inicio(&Copia, aux);
            Lista = Lista->prox;
        }

    return Copia;
}

int compara_listas(No *Lista, No *Copia){
    int iguais = 1; //(true)
    while(Lista != NULL && Copia != NULL){
        if(Lista->info != Copia->info)
            iguais = 0; //false
        Lista = Lista->prox;
        Copia = Copia->prox;
    }
    if(Lista != NULL || Copia != NULL)
        iguais = 0;

    return iguais;
}

int main(void){
    No *Lista = NULL;
    No *Copia = NULL;
    int op, k;

    do{
        puts(" 1 - Insere no inicio");
        puts(" 2 - Insere no final");
        puts(" 3 - Insere elemento na k-esima posicao");
        puts(" 4 - Exibe primeiro elemento da lista");
        puts(" 5 - Exibe ultimo elemento da lista");
        puts(" 6 - Exibe k-esimo elemento da lista");
        puts(" 7 - Excluir primeiro elemento da lista");
        puts(" 8 - Excluir ultimo elemento da lista");
        puts(" 9 - Excluir k-esimo elemento da lista");
        puts("10 - Procurar elemento (retorna 1 se achou, 0 se nao achou)");
        puts("11 - Quantidade de registros");
        puts("12 - Soma dos campos \"INFO\" da lista");
        puts("13 - Cria copia da lista");
        puts("14 - Cria copia invertida da lista");
        puts("15 - Comparar duas listas ligadas (Lista com Copia)");
        //... falta 16~18
        puts("\n0 - Sair");
        puts("-1: Exibir tudo da principal");
        puts("-2: Exibir tudo da copia");
        
        scanf("%d", &op);
        switch(op){
            case -2:
                if(exibir_tudo(Copia) == 1)
                    printf("Erro: Lista vazia");
                break;
            case -1:
                if(exibir_tudo(Lista) == 1)
                    printf("Erro: Lista vazia\n");
                break;
            case 1:
                insere_inicio(&Lista, cria_no());
                break;
            case 2:
                insere_fim(&Lista, cria_no());
                break;
            case 3:
                printf("Digite o valor de k (primeira posicao = 0): ");
                scanf("%d",&k);
                if(insere_kesima(&Lista, cria_no(), k) == 1)
                    printf("Erro: k maior que a quantidade de elementos na lista\n");
                break;
            case 4:
                if(exibe_primeiro(Lista) == 1)
                    printf("Erro: Lista vazia\n");
                break;
            case 5:
                if(exibe_ultimo(Lista) == 1)
                    printf("Erro: Lista vazia\n");
                break;
            case 6:
                printf("Digite o valor de k (primeira posicao = 0): ");
                scanf("%d", &k);

                op = exibe_kesimo(Lista, k); //reutilizando variavel
                if(op == 0) op = -1; //gambiarra pra reutilizar a variavel

                if(op == 1)
                    printf("Erro: Lista vazia\n");
                else if(op == 2)
                    printf("Erro: O elemento %d nao existe\n", k);
                break;
            case 7:
                if(exclui_primeiro(&Lista) == 1)
                    printf("Erro: Lista vazia\n");
                break;
            case 8:
                if(exclui_ultimo(&Lista) == 1)
                    printf("Erro: Lista vazia\n");
                break;
            case 9:
                printf("Digite o valor de k (primeira posicao = 0): ");
                scanf("%d", &k);

                op = exclui_kesimo(&Lista, k); //reutilizando variavel
                if(op == 0) op = -1; //gambiarra pra reutilizar a variavel

                if(op == 1)
                    printf("Erro: Lista vazia\n");
                else if(op == 2)
                    printf("Erro: O elemento %d nao existe\n", k);
                break;
            case 10:
                printf("Digite o valor do campo info do elemento a ser procurado");
                scanf("%d", &k);

                if(procurar_elemento(Lista, k) == 1)
                    printf("Elemento encontrado\n\n");
                else
                    printf("Elemento nao encontrado\n\n");
                break;
            case 11:
                printf("A lista possui %d registros\n\n", contador_nos(Lista));
                break;
            case 12:
                op = soma_info(Lista);
                if(op == -1)
                    printf("Erro: Lista vazia\n");
                else
                    printf("Soma: %d\n",op);
                break;
            case 13:
                Copia = cria_copia(Lista);
                break;
            case 14:
                Copia = cria_copia_invertida(Lista);
                break;
            case 15:
                k = compara_listas(Lista, Copia);
                if(k==1)
                    printf("Sao iguais\n");
                else
                    printf("Sao diferentes\n");

        }

    }while(op != 0);

    return 0;
}
