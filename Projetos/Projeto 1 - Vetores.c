#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define MAX 30 //numero maximo de cadastros

typedef struct{
  int ra;
  char nome[52]; //50 caracteres + \n + \0
  float nota;
  short em_uso;
}s_aluno;

void insere_nome(s_aluno cadastros[]){
  int i;
  for(i=0; i < MAX; i++){
    if(cadastros[i].em_uso == FALSE){
      printf("Digite o nome: ");
      fgets(cadastros[i].nome, 52, stdin);
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
  printf("\n -- RA ENCONTRADO: %d\n", i);
  
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
      printf("Nome: %s\n", cadastros[i].nome);
      printf("RA: %d\n", cadastros[i].ra);
      printf("Nota: %f\n", cadastros[i].nota);
    }
  }
}

int main (void){
  int i; //contador simples
  int op, resultado;
  int ra;
  char nome[52];
  
  s_aluno cadastros[MAX]; //MAX cadastros
  for(i= 0; i<MAX; i++){ //inicializando a flag em_uso como FALSE no vetor todo
    cadastros[i].em_uso = FALSE;
  }
  
  do{
    system("clear");
    puts("\nDigite a opcao desejada:");
    puts("1. Inserir cadastro de aluno");
    puts("2. Remover cadastro de aluno");
    puts("3. Buscar aluno por RA");
    puts("4. Buscar aluno por nome");
    puts("5. Exibir dados de todos os alunos cadastrados\n");
    puts("0. Sair\n");
    
    scanf("%d", &op);
    __fpurge(stdin); //tira "enter" do buffer
    
    switch(op){
      case 1: 
	insere_nome(cadastros);
	break;
      
      case 2: 
	puts("Escolha a forma que deseja remover o aluno:");
	do{ //recebe opções para deletar o aluno
	  puts("1. Pelo nome.\n2. Pelo RA.");
	  scanf("%d", &op);
	  __fpurge(stdin);
	  if(op == 1){
	    printf("Digite o nome: ");
	    fgets(nome, 52, stdin);
	    resultado = procura_por_nome(nome, cadastros);
	    if(resultado == -1) printf("Nome nao encontrado\n");
	    else remove_nome(resultado, cadastros);
	  }
	  else if(op == 2){
	    printf("Digite o RA: ");
	    scanf("%d", &ra);
	    resultado = procura_por_ra(ra, cadastros);
	    if(resultado == -1) printf("RA nao encontrado");
	    else remove_nome(resultado, cadastros);
	  }
	  else printf("Opcao invalida");
	}while(op != 1 && op != 2);
	break;
      
      case 3: 
	printf("Digite o ra: \n");
	scanf("%d", &ra);
	resultado = procura_por_ra(ra, cadastros);
	if(resultado == -1) printf("RA nao encontrado\n");
	else{
	  printf("-------------------------------\n");
	  printf("Nome: %s\n", cadastros[resultado].nome);
	  printf("RA: %d\n", cadastros[resultado].ra);
	  printf("Nota: %f\n", cadastros[resultado].nota);
	}
	break;
      
      case 4: 
	printf("Digite o nome: \n");
	fgets(nome, 52, stdin);
	resultado = procura_por_nome(nome, cadastros);
	if(resultado == -1) printf("Nome nao encontrado\n");
	else{
	  printf("-------------------------------\n");
	  printf("Nome: %s\n", cadastros[resultado].nome);
	  printf("RA: %d\n", cadastros[resultado].ra);
	  printf("Nota: %f\n", cadastros[resultado].nota);
	}
	break;
     
      case 5: 
	exibe_cadastros(cadastros);
	break;      
    }
    
    if (op != 0){ //para esperar pra limpar a tela (mas não exigir espera quando o usuario quiser sair)
      __fpurge(stdin);
      getchar(); 
    }
    
  }while(op != 0 );
  return 0;
};
