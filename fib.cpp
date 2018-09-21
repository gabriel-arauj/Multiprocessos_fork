#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

#define Raiz5 2.2360679775
#define umPorRaiz5 0.4472135955


float pow(float b, int e){
	float m = 1;
	for (int i = 0; i < e; ++i)
	{
		m *= b;
	}
	return m;
}

float fib(int n){
	float a = (1 + Raiz5)/2.0;
	float b = (1 - Raiz5)/2.0;

	return umPorRaiz5 * pow(a, n) - umPorRaiz5* pow(b,n);
	
}

int main(int argc, char const *argv[]){
	int n1, n2, aux;
	int f;
	n1 = 3;
	n2 = 7;

	if (argc != 3){
   		printf("esperado 2 argumentos\n");
   		exit(1);
	} 
	n1 = atoi(argv[1]);
	n2 = atoi(argv[2]);

	if(n1 < 0 || n2 <  0 ){
		printf("esperado 2 números naturais\n");
		exit(1);
	}

	if(n1 > n2){
		aux = n2;
		n2 = n1;
		n1 = aux;
	}

	for (int i = n1 -1; i < n2; i++){
		printf("%.f\n", fib(i));
	}
	return 0;
}