#include <stdio.h> 

int main (){
	int vetor[10], i, var; 
	
	for (i=0; i<10; i++ ){
		printf ("Digite o valor: "); 
		scanf ("%d", &vetor[i]);
	}
	
	int cont = 0; 
	for (i=9; i>=0; i-- ){
		var = vetor[i] ;
		vetor[i] = vetor[cont]; 
		vetor[cont] = var;  
		cont++ ; 
	}
	
	for (i=0; i<10; i++ ){
		printf ("%d\n", vetor[i]);
	}
	return 0; 
}