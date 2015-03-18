#include <stdio.h>
#include <stdlib.h>

int main(void){
  int i, j, n, *pvetor, *temp;
  float media;
  
  scanf("%d", &n);
  
  //Alocando espaço na memmoria para os ponteiros
  temp = (int *) malloc(sizeof(int));
  pvetor = (int *) malloc(n*sizeof(int));
  if(!pvetor){
    puts("Sem memoria!");
    return 1;
  }
  
  //Inicializando os espaços de memória apontados pelo vetor
  for(i = 0; i<n; i++){
    scanf("%d", pvetor + i);
  }
  
  //Fazendo alguma coisa (organizando vetor)
  for(i=0; i<n-1; i++)
    for(j=i+1; j<n; j++)
      if( *(pvetor + i) > *(pvetor + j)){
	*temp = *(pvetor + j);
	*(pvetor + (j)) = *(pvetor + i);
	*(pvetor + i) = *temp;
      }
  
  //Imprimindo o vetor;
  for(i=0; i<n; i++)
    printf("%d ", *(pvetor + i));
  printf("\n");
  
  //aqui nao preciso mais do pvetor nem da temp
  free(pvetor);
  free(temp);
  
  return 0;
}
