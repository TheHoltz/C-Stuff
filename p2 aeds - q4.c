//Resolução - Q4 P2 Rodolfo DCC
//O trecho de programa abaixo tem um defeito grave. A função f() retorna o endereço de uma variável que
//deixará de existir quando deixar de existir o registro de ativação correspondente. Reescreva a função f()
//preservando o cabeçalho. mas sem este defeito (Sua solução não deve usar variáveis globais nem fazer
//alocação dinâmica de memória).
//https://homepages.dcc.ufmg.br/~rodolfo/aedsi-2-10/prova2%20aedsi%202%202014.pdf

#include <stdio.h>
#include <stdlib.h>

//metodo 1
int *f(int p){
	int i=p*p; 
	int *j; //basta criar um ponteiro
	j = &i; //apontá-lo para o endereço de i
	printf("%d\n",j);
	return j; //retorná-lo
}

//metodo2 por malloc (Não sugerido pelo enunciado)
int *f2(int p){
	int *j;
	j = malloc(sizeof(int));
	*(j) = p*p;
	printf("%d\n",j);
	return j;
}

int main(int argc, char *argv[]){

	int *pi;
	int *pi2;

	pi=f(3);
	pi2=f2(3);

	printf("%d %d\n", *pi, *pi2);
	return 0;
}