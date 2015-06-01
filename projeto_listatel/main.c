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
		puts("2- Remover cadastro (NAO IMPLEMENTADO)");
		puts("3- Alterar cadastro (NAO IMPLEMENTADO)");
		puts("4- Buscar cadastro");
		puts("5- Exibir cadastros"); //ordem: CPF crescente, falta fazer por "parte-do-nome"
		puts("6- Exibir arvore de cadastros (NAO IMPLEMENTADO)");
		puts("\n0- Sair");
		scanf("%d", &op);

		switch(op){
			case 1:
				adicionar_registro(&Lista, cria_no(), &pertence);
				break;
			case 4:
				scanf("%lf", &cpf);
				if(cpf_valido(cpf))
					printf("CPF invalido\n");
				else {
					no = busca_registro_cpf(Lista, cpf, &tempo_execucao, &profundidade);
					if(no != NULL)
						exibe_registro(no->cadastro);
					else
						printf("ERRO: Nao encontrado");
				}
				break;
			case 5:
				exibe_in_ordem(Lista, true);
				break;
		}

	}while(op != 0);
}