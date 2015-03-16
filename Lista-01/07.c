#include <stdio.h>
#include <stdlib.h>

int main(void){
  int i, n, *pvetor, maiores=0;
  float media;
  
  //defina local para n, scanf, ou n =
  scanf("%d", &n);
  
  //aloca espaço na memoria
  pvetor = (int *) malloc(n*sizeof(int));
  if(!pvetor){
    puts("Sem memoria!");
    return 1;
  }
  
  //aqui uso o pvetor, vamos ler um vetor
  for(i = 0; i<n; i++){
    scanf("%d", pvetor + i);
  }
  
  //faco alguma coisa
  media = 0.0;
  for(i=0; i<n; i++)
    media += *(pvetor + i);
  media /= n;
  
  printf("%f\n", media);
  
  //aqui eu calculo e exibo quantos sao maiores que a media
  for(i=0; i<n; i++)
    if(*(pvetor + i) > media) maiores++;
  printf("Maiores que a media: %d\n",maiores);
  
  //aqui nao preciso mais do pvetor
  free(pvetor);
  
  return 0;
}
