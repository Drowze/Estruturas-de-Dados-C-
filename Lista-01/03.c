#include <stdio.h>

void Troca (int *a, int *b){
  int temp;
  
  temp = *a;
  *a = *b;
  *b = temp;
} //fim da troca

int main(void){
  int x,y;
  int *px, *py;
  
  //NÃO USAR ISSO NORMALMENTE, É mó bobeira...
  px = &x;
  py = &y;
  
  //scanf para o valor apontado pelo ponteiro
  scanf("%d %d",px,py);
  
  //trocar o valor apontado pelo ponteiro
  Troca(px, py);
  
  //printf usando o valor apontado pelos ponteiros
  printf("Troquei -----> %d %d\n", *px, *py);
  
  return 0;
}
