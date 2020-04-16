#include <stdio.h>
 
struct pessoa{
	int a; 
	int b;
};

int main(){
	struct pessoa var; //var1 - tipo pessoa 
	struct pessoa prox_var; //var2 - tipo pessoa 
	var.a = 1;
	var.b = 2;
	
	struct pessoa retorna (struct pessoa parametro);
	prox_var = retorna(var); //"prox_var" é uma copia de "var", 
	//prox_var = var
	
	//imprimir copias das estruturas 
	printf ("var1: %d\n", var.a);
	printf ("var1: %d\n\n", var.b);
	
	printf ("var2: %d\n", prox_var.a);
	printf ("var2: %d\n", prox_var.b);
	return 0; 
}

struct pessoa retorna (struct pessoa parametro){
	return parametro;
}


