/*Modificações:
> Espaço a cada 4 bits
> Long long int para conseguir usar 2^32-1 e números 
negativos na mesma variável (unsigned int vai até 2^32-1,
mas isso implicaria em não conseguir usar números
negativos para parar o programa) (não entendi porque
não consegui usar long int para 2^32-1).
*/

#include <stdio.h>

void Converter (long long int numeroBase10, int numberoBase2[32]);

int main(int argc, char *argv[]){
	long long int nb10;
	int nb2[32], i, teste = 1;
	
	while(i){
		printf("Base 10: ");
		scanf("%lld", &nb10);
		if (nb10 < 0) break;
		
		Converter(nb10, nb2);
		
		printf("Teste %d\n", teste++);
		printf("%lld\n", nb10);
		
		//imprimir vetor:
		for(i=0;i<32;i++){
			if((i)%4==0 && i != 0) printf(" ");
			printf("%d",nb2[i]);
		}
		
		printf("\n\n");
	}
	return 0;
}

void Converter (long long int numeroBase10, int numeroBase2[32]){
	int i;
	
	//Limpa o vetor e coloca zeros na esquerda
	for(i = 0; i < 32; i++) numeroBase2[i] = 0;
	//i = 31;
	i--;
	
	//Preenche o vetor com o resultado da conversao
	while(numeroBase10 > 1){
		numeroBase2[i] = numeroBase10%2;
		numeroBase10 /= 2;
		i--;
	}
	numeroBase2[i] = numeroBase10%2;
}
