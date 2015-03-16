#include <stdio.h>

void misterio (char *n);
int main (void){
	char nome [41];
	gets(nome);
	
	printf("%p (Pode-se verificar que esse ponteiro aponta alguma(s) casas antes)\n",nome);
	misterio(nome);
	
	return 0;
}

void misterio (char *n){
	while (*n != ' ') n++;
	n++;
	puts(n);
	printf("%p (e esse depois)\n",n);
}

//Conclusão: o ponteiro criado no procedimento misterio aponta para a primeira letra do sobrenome, enquanto o ponteiro no main aponta para a primeira letra no primeiro nome.
