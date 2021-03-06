#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <locale.h>

int primo(int n);
int fibonacci(int n);
int fatorial(int n);
int divisaoExata(int dividendo, int divisor);


//Questão 04
int main(){
	setlocale(LC_ALL, "Portuguese");
	
	unsigned int x, n, i, j;
	double Soma;
	
	
	printf("Entre com o valor de x: ");
	scanf("%d", &x);
	printf("Entre com o valor de n: ");
	scanf("%d", &n);
	
	int sinal = 1;
	for(i = 0; i <= n; ++i){
		Soma =  sinal*( ( pow( (x + (sinal*primo(n))) , 1.0/(( primo(n) + fibonacci(n) )*x) ) ) / ( fatorial(fibonacci(n)) ));
		sinal *= (-1);
	}
	
	puts("\tResultado...");
	printf("\tSoma = %.2f", Soma);
	
	return 0;
}

int primo(int n){
	int i, quantDivisores = 0;
	
	for(i = 1; i <= n; i++){
		if(divisaoExata(n,i)){
			quantDivisores++;
		}
	}
	
	if(quantDivisores == 2){
		return 1;
	}else{
		return 0;
	}
}

int divisaoExata(int dividendo, int divisor){
	return(dividendo % divisor) == 0;
}

int fibonacci(int n){
	if(n == 1) return 1;
	else{
		if(n == 2) return 2;
		else return fibonacci(n - 1) + fibonacci(n - 2);
	}
}

int fatorial(int n){
    int resultado;

    if( n == 0){
		resultado = 1;
	}
	else{
		resultado = n * fatorial (n - 1);
	}
	return resultado;
}
