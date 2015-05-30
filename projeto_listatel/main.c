#include <stdio_ext.h> //consigo usar __fpurge(stdin) sem warnings (warning acusado usando gcc -wall)
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "lib_functions.h"

int main(){
	int op;

	no_registro *Lista = NULL;
	no_registro *no = NULL;

	do{
		puts("Digite a opcao:");
		puts("1- Inserir cadastro");
		puts("2- Remover cadastro (NAO IMPLEMENTADO)");
		puts("3- Alterar cadastro (NAO IMPLEMENTADO)");
		puts("4- Buscar cadastro (NAO IMPLEMENTADO)");
		puts("5- Exibir cadastros (NAO IMPLEMENTADO)");
		puts("6- Exibir arvore de cadastros (NAO IMPLEMENTADO)");
		puts("\n0- Sair");
		scanf("%d", &op);

		switch(op){
			case 1:
				adicionar_registro(&Lista, cria_no());
				break;
			case 5:
				exibe_pos_ordem(Lista);
		}while(op != 0);

	}
}