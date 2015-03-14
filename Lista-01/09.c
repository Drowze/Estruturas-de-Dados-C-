#include <stdio.h>
#include <stdlib.h>
 
int main(){
  long int i=0;
  char *alloc;
 
  printf("Vou explodir seu computador\n...\n...\n");
 
  for(i=1024*1024 * 500;; i = i+ 1024*1024){ // Começa tentando alocar 500MB; incrementa de 1MB em 1MB
    alloc = malloc(i * sizeof(char));
    if(!alloc){
      printf("Seu computador permitiu que eu alocasse %ld bytes!\n", i + sizeof(i));
      printf("%ld bytes = %ld kbytes = %ld Mbytes!\n", i + sizeof(i), (i + sizeof(i))/1024, ((i + sizeof(i))/1024)/1024);
      free(alloc);
      return 1;
    }
    else{
      if(i%(1024*1024)==0) printf("... %ld kbytes || %ld Mbytes ...\n", (i + sizeof(i))/1024, ((i + sizeof(i))/1024)/1024); //printa mensagem de MB em MB
      free(alloc);
    }
  }
}
