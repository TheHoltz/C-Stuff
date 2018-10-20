//este arquivo contém um exemplo de atribuição de arranjos como estruturas

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	struct lampiao{int a1[2];}; //definindo uma estrutura arbitrária
	struct lampiao k={{1,2}}; //defindo uma variável da estrutura anterior e a inicializando
	struct lampiao n; //definindo uma segunda variável da mesma estrutura porem sem inicializacao
	n=k; //atribuindo os valores da primeira a variável gerada anteriormente.
	printf("Valor: %d\n", n.a1[0]);
	return 0;
}
