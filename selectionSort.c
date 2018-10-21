#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void ordenar(int _n, int *vetor){
	int aux, min;
	for (int ii = 0; ii < _n; ++ii){
		min = ii;
		for (int jj = ii+1; jj < _n; ++jj){
			if(vetor[jj] < vetor[min]){
				min = jj;
			}
		}
		if(vetor[ii] != vetor[min]){
			aux = vetor[ii];
			vetor[ii] = vetor[min];
			vetor[min] = aux;
		}
	}
	return;
}

int main(int argc, char const *argv[])
{
	int valores[] = {17,10,9,7,30,5,55,12,25,1,1,1,1,1,3,51,34,11,21};
	ordenar(15,valores);
	for (int i = 0; i < 15; ++i)
	{
		printf("%d\t",valores[i]);
	}
	return 0;
}
