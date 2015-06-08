#include <stdio_ext.h> //consigo usar __fpurge(stdin) sem warnings (warning acusado usando gcc -wall)
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include "lib_functions.h"


int main(){
	char op;

	no_registro *tree = NULL;
	no_registro *no = NULL;
	linked_list *lista;

	bool pertence;

	double cpf;
	int profundidade = 0;

    struct timeval before;
    struct timeval after;
    double time_elapsed;

    char nome_parcial[size_nome];
    double numero_contato;

	do{
		puts("\nDigite a opcao:");
		puts("1- Inserir cadastro");
		puts("2- Remover cadastro");
		puts("3- Alterar cadastro");
		puts("4- Buscar cadastro"); //falta fazer por "parte-do-nome"
		puts("5- Exibir cadastros"); //ordem: CPF crescente, falta ordenar por nome
		puts("6- Exibir arvore de cadastros (NAO IMPLEMENTADO)");
		puts("\n0- Sair");
		scanf("%c", &op);

		switch(op){
			case '1':
				adicionar_registro(&tree, cria_no(), &pertence);
				break;
			case '2':
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
			case '3':
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
			case '4':
                printf("\n1- Buscar por CPF");
                printf("\n2- Buscar por parte do nome");
                printf("\n3- Buscar por numero");
				printf("\nOpcao: ");
                __fpurge(stdin); scanf("%c", &op);
                switch(op){
                    case '1':
                        printf("Digite o CPF a ser buscado: ");
        				scanf("%lf", &cpf);
        				if(cpf_valido(cpf)) {
        					profundidade = 1;
        					no = busca_registro_cpf(tree, cpf, &profundidade);
        					if(no != NULL) {
                                gettimeofday(&before, NULL);
                                printf("\n\nResultado: \n");
        						exibe_registro(no->cadastro);
                                gettimeofday(&after, NULL);
                                time_elapsed = time_diff(before, after);
        						printf("Profundidade na árvore: %d\n", profundidade);
                                printf("Tempo gasto durante a busca (microssegundos): %lf\n", time_elapsed);
        					} else
        						printf("Nao foram encontrados registros\n\n");
        				} else
        					printf("CPF invalido\n\n");
                        break;
                    case '2':
                        printf("Digite uma parte do nome: ");
                        __fpurge(stdin); scanf("%s", nome_parcial);
                        gettimeofday(&before, NULL);
                        printf("\n\nResultados: \n");
                        printf("\n%d ocorrencias:\n\n", busca_registro_nome(tree, tree, nome_parcial, 0, before));


                        break;
                    case '3':
                        printf("Digite o numero de contato: ");
                        scanf("%lf", &numero_contato);
                        gettimeofday(&before, NULL);
                        printf("\n\nResultados: \n");
                        printf("\n%d ocorrencias:\n\n", busca_registro_numero(tree, tree, numero_contato, 0, before));


                        break;
                    }
				break;
			case '5':
				printf("\n1- Ordem de CPF");
				printf("\n2- Ordem alfabetica");
				__fpurge(stdin); printf("\nOpcao: ");
				scanf("%c", &op);
				if(op == '1'){
                    printf("\n\nResultados: \n");
					exibe_in_ordem(tree, true);
				} else 
                    if (op == '2'){
                        printf("\n\nResultados: \n");
				        exibe_in_ordem(tree, false);
				    } else {
				        printf("Opcao invalida");
				    }


				
				break;
            case '0':
                break;
            default:
                printf("Opcao invalida\n");
                break;
		}
        __fpurge(stdin);

	}while(op != '0');
}