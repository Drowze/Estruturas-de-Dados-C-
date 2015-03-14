#include <stdlib.h>
#include <stdio.h>

int main(void){
  int i=10, j = 20;
  int temp;
  int *p1, *p2;
  
  p1 = &i; //p1 recebe endereço de i
  
  p2 = &j;  //p2 recebe endereço de j
  
  temp = *p1; //recebe conteudo apontado por p1 
  
  *p1 = *p2;  //o conteúdo apontado por p1 recebe o conteúdo apontado por p2
  
  *p2 = temp; //o conteúdo apontado por p1 recebe o conteúdo de temp
  
  //será impresso 20 e 10, respectivamente, indicando que os valores das variáveis se inverteram
  printf("%d %d\n",i,j);
  
  return 0;
}
