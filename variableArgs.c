#include <stdio.h>
#include <stdarg.h>

// modo 1
float media(int n,...){

	float count = 0.0;
	static int out;

	va_list args;
	va_start(args, n);
	while(n != -1){
		out += n;
		n = va_arg(args, int);
		count++;
	}

	va_end(args);
	return(out/count);
}

// modo 2
float media2(int n, ...){
	static int out;
	float count=0.0;
	va_list args;
	va_start(args,n);
	for (int jj = 0; jj < n; ++jj)
	{
		out += va_arg(args, int);
		count++;
	}
	va_end(args);
	return(out/count);
}

int main(int argc, char const *argv[])
{
	printf("%f\n", media(1,2,3,9,10,15,-1)); //modo 1
	printf("%f\n", media2(6,1,2,3,9,10,15)); // modo 2
	return 0;
}