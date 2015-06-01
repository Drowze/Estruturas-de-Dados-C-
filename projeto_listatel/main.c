#include <stdio_ext.h> //consigo usar __fpurge(stdin) sem warnings (warning acusado usando gcc -wall)
#include <stdlib.h>
#include <string.h>
#include "lib_functions.h"

int main(){
	int op;

	no_registro *Lista = NULL;
	no_registro *no = NULL;
	bool pertence;

	double cpf;
	int tempo_execucao = 0;
	int profundidade = 0;

	do{
		puts("Digite a opcao:");
		puts("1- Inserir cadastro");
		puts("2- Remover cadastro");
		puts("3- Alterar cadastro (NAO IMPLEMENTADO)");
		puts("4- Buscar cadastro"); //falta fazer por "parte-do-nome"
		puts("5- Exibir cadastros"); //ordem: CPF crescente, falta ordenar por nome
		puts("6- Exibir arvore de cadastros (NAO IMPLEMENTADO)");
		puts("\n0- Sair");
		scanf("%d", &op);

		switch(op){
			case 1:
				adicionar_registro(&Lista, cria_no(), &pertence);
				break;
			case 2:
				printf("\nDigite o CPF a ser removido: ");
				scanf("%lf",&cpf);
				if(cpf_valido(cpf)){
					no = busca_registro_cpf(Lista, cpf, &tempo_execucao, &profundidade);
					if(no != NULL){
						remove_registro(busca_registro_cpf(Lista, cpf, &tempo_execucao, &profundidade), &Lista);
					} else
						printf("Erro: CPF nao encontrado");
				} else
					printf("CPF invalido\n");
				break;
			case 3:
				printf("\nDigite o CPF do cadastro a ser alterado: ");
				scanf("%lf",&cpf);
				if(cpf_valido(cpf)){
					no = busca_registro_cpf(Lista, cpf, &tempo_execucao, &profundidade);
					if(no != NULL){
						altera_registro (no, &Lista);
					} else
						printf("CPF nao encontrado");
				}
				break;
			case 4:
				printf("\nDigite o CPF a ser buscado: ");
				scanf("%lf", &cpf);
				if(cpf_valido(cpf)){
					profundidade = 0;
					no = busca_registro_cpf(Lista, cpf, &tempo_execucao, &profundidade);
					if(no != NULL){
						exibe_registro(no->cadastro);
						printf("Profundidade na árvore: %d\n", profundidade);
					} else
						printf("Erro: CPF nao encontrado");
				} else
					printf("CPF invalido\n");
				break;
			case 5:
				exibe_in_ordem(Lista, true);
				break;
		}

	}while(op != 0);
}