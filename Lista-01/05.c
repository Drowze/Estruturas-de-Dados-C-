#include <stdio.h>
#include <stdlib.h>

int main(void){
  int i, n, *pvetor;
  float media;
  
  //define valor para n, scanf, ou n =
  scanf ("%d", &n);
  
  //aloca espaço na memoria
  pvetor = (int *) malloc(n * sizeof(int));
  if(!pvetor){
    puts("Sem memoria.");
    return 1;
  }
  
  //Voltando a vetores comuns
  
  //aqui uso pvetor, vamos ler um vetor
  for(i=0; i<n; i++)
    scanf("%d", &pvetor[i]);
  
  //faco alguma coisa
    media = 0.0;
    for (i = 0; i < n; i++)
      media += pvetor[i];
    printf("%f", media);
    
    //aqui nao preciso mais do pvetor
    free(pvetor);
    
    return 0;
}
