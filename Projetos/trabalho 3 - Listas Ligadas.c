#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef struct{
	int ra;
	char nome[52];
	float nota;
	s_aluno *prox;
}s_aluno;

void insere_nome(s_aluno *fim_lista){ //deve receber um ponteiro para o fim da lista
		
		printf("Digite o nome: ");  
  	fgets(fim_lista->nome);
  	printf("Digite o ra: "); 	
		scanf("%i", fim_lista->RA);
 		printf("Digite o ra: ");	
		scanf("%f", fim_lista->nota);
}

void remove_nome(s_aluno *anterior){ //deve receber um ponteiro para a struct anterior ser removida
}

/* recebe um ponteiro para o começo da lista
	 retorna a posição anterior ao procurado */
(s_aluno *) procura_por_ra(int ra, s_aluno *lista){
}

/* recebe um ponteiro para o começo da lista
	 retorna a posição anterior ao procurado */
(s_aluno *) procura_por_nome(char nome[], s_aluno *lista){
}

/* recebe a lista */
void exibe_cadastros(s_aluno *lista){
}

void main(){
	s_aluno *lista, *retorno;
	int op;
	do{
		system("clear");
		puts("\nDigite a opcao desejada:");
		puts("1. Inserir cadastro de aluno");
		puts("2. Remover cadastro de aluno");
		puts("3. Buscar aluno por RA");
		puts("4. Buscar aluno por nome");
		puts("5. Exibir dados de todos os alunos cadastrados\n");
		puts("0. Sair\n");

		printf("Digite a opcao desejada");
		scanf("%d", &op);
		__fpurge(stdin);
		switch(op){
			case 1:
			isere_nome(*);
      break;
			case 2;

			break;
			case 3:

			break;
			case 4:
				retorno = procura_por_nome;

			break;
			case 5:
				exibe_cadastros(lista);
			break;
		}
	}while(	
}
