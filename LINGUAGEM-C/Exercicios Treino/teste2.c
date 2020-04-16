#include <stdio.h> 
#include <stdlib.h>

typedef struct{
	int a; 
}tEstrutura; 

int main (){
	tEstrutura *vet[3]; 
	
	int i; 
	for (i=0; i<3; i++){
		vet[i] = (tEstrutura*) malloc (sizeof(tEstrutura)); 
		vet[i]->a = 1+i; 
	}    	
	
	for (i=0; i<3; i++){
		printf ("Valor: %d ", vet[i]->a); 
	}
		

	return 0;
}