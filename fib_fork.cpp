#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include<sys/wait.h> 

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

void fib_fork(int n1, int n2){
	int pid;
	pid = fork();
	if (pid == -1){
		perror("impossivel de criar processo.\n") ;
	}else if (pid == 0){ 	//Filho
		if(n1 != n2){
			n1++;
			fib_fork(n1, n2);
			exit(0);		//Comente essa linha para poder ver os processos por mais tempo
		}
	}else{ //Pai
		printf("%.f\n", fib(n1));
		wait(NULL);
	}
}

int main(int argc, char const *argv[]){
	int n1, n2, aux;
	int f;

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
	fib_fork(n1-1, n2-1);
	
	return 0;
}