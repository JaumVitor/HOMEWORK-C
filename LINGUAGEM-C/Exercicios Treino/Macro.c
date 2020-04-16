#include <stdio.h> 
#define MACRO(x, y) x > y ? 1 : 0 //Se o valor x for maior que y, retorna 1, inverso retorna 0
#define IGUAL(x, y) x == y //Se o resultado do macro for 1, então ele soma, contrario diminue

/*NESTE PROGAMA EU ESTOU INICIALIZANDO UM MACRO: 

Entre parentese é como se fosse um parametro do macro; 
e na frente eu digo como vou usar este parametro....e o resultado é o valor do macro*/ 

int main (){
	int v1=10, v2=10;
	
	printf ("%d\n", MACRO(v1, v2)); 
	
	if (IGUAL (v1, v2))
		printf ("Valor igual"); 
	else
		printf ("Valor diferente"); 
	
	return 0;
}