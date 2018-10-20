//este arquivo contém um exemplo de definição posterior a declaração de uma função
//além de um exemplo de ponteiro para função


#include <stdio.h>
#include <stdlib.h>

int fat();
int fatR();

int main(int argc, char const *argv[])
{
	int (*p) (int);
	p = &fat; 	//ponteiros para função permitem adicionar lógica nas entradas.
				//Está também sendo usado o açucar sintático &.

	printf("%d\n", p(5)); //irá retornar 120
	printf("%d\n",fatR(5)); //irá retornar 120
	printf("%d\n",fat(5)); //irá retornar 120
	return 0;
}

int fatR(int n){
	if(n==1 || n==0)
		return 1;
	else
		return fatR(n-1)*n;
}

int fat(int n){
	int m = n-1;
	do{
		n = n * (m--);
	}while(m);
	return(n);
}