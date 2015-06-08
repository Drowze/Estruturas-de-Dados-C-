#include <stdio_ext.h> //consigo usar __fpurge(stdin) sem warnings (warning acusado usando gcc -wall)
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include "lib_functions.h"


int main(){
	int op;

	no_registro *tree = NULL;
	no_registro *no = NULL;
	linked_list *lista;

	bool pertence;

	double cpf;
	int profundidade = 0;

    struct timeval before;
    struct timeval after;
    double time_elapsed;

	do{
		puts("Digite a opcao:");
		puts("1- Inserir cadastro");
		puts("2- Remover cadastro");
		puts("3- Alterar cadastro");
		puts("4- Buscar cadastro"); //falta fazer por "parte-do-nome"
		puts("5- Exibir cadastros"); //ordem: CPF crescente, falta ordenar por nome
		puts("6- Exibir arvore de cadastros (NAO IMPLEMENTADO)");
		puts("\n0- Sair");
		scanf("%d", &op);

		switch(op){
			case 1:
				adicionar_registro(&tree, cria_no(), &pertence);
				break;
			case 2:
				printf("\nDigite o CPF a ser removido: ");
				scanf("%lf",&cpf);
				if(cpf_valido(cpf)){
					no = busca_registro_cpf(tree, cpf, &profundidade);
					if(no != NULL){
						remove_registro(busca_registro_cpf(tree, cpf, &profundidade), &tree);
					} else
						printf("Erro: CPF nao encontrado");
				} else
					printf("CPF invalido\n");
				break;
			case 3:
				printf("\nDigite o CPF do cadastro a ser alterado: ");
				scanf("%lf",&cpf);
				if(cpf_valido(cpf)){
					no = busca_registro_cpf(tree, cpf, &profundidade);
					if(no != NULL){
						altera_registro (no, &tree);
					} else
						printf("CPF nao encontrado");
				}
				break;
			case 4:
				printf("\nDigite o CPF a ser buscado: ");
				scanf("%lf", &cpf);
				if(cpf_valido(cpf)){
					profundidade = 0;
					no = busca_registro_cpf(tree, cpf, &profundidade);
					if(no != NULL){
                        gettimeofday(&before, NULL);
						exibe_registro(no->cadastro);
                        gettimeofday(&after, NULL);
                        time_elapsed = time_diff(before, after);
						printf("Profundidade na árvore: %d\n", profundidade);
                        printf("Tempo gasto durante a busca (microssegundos): %lf\n", time_elapsed);
					} else
						printf("Erro: CPF nao encontrado");
				} else
					printf("CPF invalido\n");
				break;
			case 5:
				printf("\n1- Ordem de CPF");
				printf("\n2- Ordem alfabetica");
				printf("\nOpcao: ");
				scanf("%d", &op);
				if(op == 1){
					exibe_in_ordem(tree, true);
				} else if (op == 2){
					exibe_in_ordem(tree, false);
				} else {
					printf("Opcao invalida");
				}


				
				break;
		}

	}while(op != 0);
}