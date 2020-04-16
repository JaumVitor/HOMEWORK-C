#include <stdio.h>
int fatorial(int valor);
 
int main(){
	int num, resultado; 
	
	printf ("Infome o valor para o fatorial: "); 
	scanf ("%d", &num); 
	resultado = fatorial(num); 
	printf ("O resultado do fatorial eh: %d", resultado);    
		
return 0; //Fim do progama! 
}

int fatorial(int valor){
	int resultado; 
	static int cont = 0; 	
	
	if (valor == 0){
		++cont; 
		resultado = 1; 
	}else{ 
		++cont; 
		printf ("%d * %d!\t contagem %d\n", valor, valor-1, cont); 
		resultado = valor * fatorial(valor-1); 
	}
	return resultado; 
}