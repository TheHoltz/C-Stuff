#include <stdio.h>
#include <stdlib.h>

int _sum(int **m1, int **m2, int _l, int _c, int verbose){

	if(verbose >= 1)
		verbose = 1;
	else
		verbose = 0;

	int **out;
	out = (int **) malloc(_c * sizeof(int *));

	//criando uma matriz para saída, e a preenchendo com zeros
	for (int i = 0; i < _c; ++i)
	{
		*(out+i) = (int *) malloc(_l * sizeof(int));
		for (int ii = 0; ii < _l; ++ii)
		{
			*(*(out+i)+ii) = 0;
		}
	}

	// realizando a soma das matrizes inseridas nos parametros
	for (int j = 0; j < _l; ++j)
	{
		for (int jj = 0; jj < _c; ++jj)
		{
			*(*(out+j)+jj) = *(*(m1+j)+jj) + *(*(m2+j)+jj);
		}
	}

	//printando saída
	if(verbose){
		printf("%s\n", "\nMatriz gerada na soma:");
		for (int i = 0; i < _c; ++i)
		{
			for (int ii = 0; ii < _l; ++ii)
			{
				printf("%d\t", *(*(out+i)+ii));
			}
			printf("\n");
		}
	}

	return out;
}


int main(int argc, char const *argv[])
{
	int **p, _n=3;
	p = (int **) malloc(_n * sizeof(int *)); // matriz 1
	// criei um ponteiro que armazena _n ponteiro para inteiro
	
	int k=1; //variável apenas para adicionar valores nas matrizes

	//criando primeira matriz
	for (int j = 0; j < _n; ++j)
	{
		p[j] = (int *) malloc(_n * sizeof(int));
		for (int jj = 0; jj < _n; ++jj)
		{
			*(*(p+j)+jj) = k;
			k++;
		}
	}

	//printando valores da primeira matriz
	for (int j = 0; j < _n; ++j)
	{
		for (int jj = 0; jj < _n; ++jj)
		{
			printf("%d\t", *(*(p+j)+jj));
		}
		printf("\n");
	}

	printf("\n");

	//criando segunda matriz
	int **pp;
	pp = (int **) malloc(_n * sizeof(int *));

	for (int j = 0; j < _n; ++j)
	{
		*(pp+j) = (int *) malloc(_n * sizeof(int));
	}

	for (int j = 0; j < _n; ++j)
	{
		for (int jj = 0; jj < _n; ++jj)
		{
			*(*(pp+j)+jj) = k + k;
			--k;
		}
	}

	for (int j = 0; j < _n; ++j)
	{
		for (int jj = 0; jj < _n; ++jj)
		{
			printf("%d\t", *(*(pp+j)+jj));
		}
		printf("\n");
	}

	//somar as matrizes
	int **soma;
	soma = _sum(p,pp,3,3,1);

	printf("\n%d\n",*(*(soma+2)+1));
	return 0;
}