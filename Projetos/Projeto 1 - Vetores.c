#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define MAX 30

typedef struct{
  int ra;
  char nome[51];
  float nota;
  short em_uso;
}s_aluno;

void insere_nome(s_aluno cadastros[]){
  int i;
  for(i=0; i < MAX; i++){
    if(cadastros[i].em_uso == FALSE){
      printf("Digite o nome: ");
      scanf("%s", &cadastros[i].nome);
      printf("Digite o RA: ");
      scanf("%d", &cadastros[i].ra);
      printf("Digite a nota: ");
      scanf("%f", &cadastros[i].nota);
      cadastros[i].em_uso = TRUE;
      break;
    }
  }
}

void remove_nome(int i, s_aluno cadastros[]){
  cadastros[i].em_uso = FALSE;
}

int procura_por_ra(int ra, s_aluno cadastros[]){
  int i;
  for(i = 0; i < MAX; i++)
    if(cadastros[i].ra == ra) return i; //indice referente
  
  return -1; //percorreu e nao achou
}

int procura_por_nome(char nome[], s_aluno cadastros[]){
  int i;
  for(i = 0; i < MAX; i++)
    if(strcmp(cadastros[i].nome, nome) == 0) return i;
  
  return -1; //percorreu e nao achou
}

void exibe_cadastros(s_aluno cadastros[]){
  int i;
  for(i=0; i<MAX; i++){
    if(cadastros[i].em_uso == TRUE){
      printf("-------------------------------\n");
      printf("Nome: %s\n", cadastros[resultado].nome);
      printf("RA: %d\n", cadastros[resultado].ra);
      printf("Nota: %f\n", cadastros[resultado].nota);
      printf("-------------------------------\n");
    }
  }
}

int main (void){
  int i;
  s_aluno cadastros[MAX]; //MAX cadastros
  for(i= 0; i<MAX; i++){
    cadastros.em_uso = FALSE;
  }
  int op, resultado;
  int ra;
  char nome[51];
  
  do{
    puts("Digite a opcao desejada: \n");
    puts("1. Inserir cadastro de aluno\n");
    puts("2. Remover cadastro de aluno\n");
    puts("3. Buscar aluno por RA\n");
    puts("4. Buscar aluno por nome\n");
    puts("5. Exibir dados de todos os alunos cadastrados\n\n");
    puts("0. Sair\n");
    
    scanf("%d", &op);
    
    switch(op){
      case 1: 
	insere_nome();
	break;
      
      case 2: 
	printf("Escolha a forma que deseja remover o aluno:\n");
	do{ //recebe opções para deletar o aluno
	  printf("1. Pelo nome.\n2. Pelo RA.\n");
	  scanf("%d", &op);
	  if(op == 1){
	    printf("Digite o nome: ");
	    scanf("%s", &nome);
	    resultado = procura_por_nome(nome, cadastros);
	    if(resultado = -1) printf("Nome nao encontrado\n");
	    else remove_nome(resultado, cadastros);
	  }
	  else if(op == 2){
	    printf("Digite o RA: ");
	    scanf("%d", &ra);
	    resultado = procura_por_ra(ra, cadastros);
	    if(resultado = -1) printf("RA nao encontrado");
	    else remove_nome(ra, cadastros);
	  }
	}while(op != 1 && op != 2);
	break;
      
      case 3: 
	printf("Digite o nome: \n");
	scanf("%s", &nome);
	resultado = procura_por_nome(nome, cadastros);
	if(resultado = -1) printf("Nome nao encontrado\n");
	else{
	  printf("-------------------------------\n");
	  printf("Nome: %s\n", cadastros[resultado].nome);
	  printf("RA: %d\n", cadastros[resultado].ra);
	  printf("Nota: %f\n", cadastros[resultado].nota);
	  printf("-------------------------------\n");
	}
	break;
      
      case 4: 
	printf("Digite o ra: \n");
	scanf("%d", &ra);
	resultado = procura_por_ra(ra, cadastros);
	if(resultado = -1) printf("RA nao encontrado\n");
	else{
	  printf("-------------------------------\n");
	  printf("Nome: %s\n", cadastros[resultado].nome);
	  printf("RA: %d\n", cadastros[resultado].ra);
	  printf("Nota: %f\n", cadastros[resultado].nota);
	  printf("-------------------------------\n");
	}
	break;
     
      case 5: 
	exibe_cadastros(cadastros);
	break;      
    }
    
  }while(op != 0 );
  
  
  return 0;
};
