#include <stdio.h> 
#define PRO 3
#define ARM 2

		typedef struct {
			int produto[PRO];
			int custo[PRO]; 
		} estoque ; 


void lerCusto (estoque (*Vetor));

int main(){
	estoque gurdaVetor;
	lerCusto (&gurdaVetor);
	 
	int x; 
	for (x=0; x<PRO; x++){
		printf ("fora: %d\n", gurdaVetor.custo[x]); 
	}
	return 0; 
}

void lerCusto (estoque (*Vetor)){
	int x; 
	for (x=0; x<PRO; x++){
		printf ("Digite: "); 
		scanf ("%d", &(*Vetor).custo[x]);
	}printf ("\n"); 
	
	for (x=0; x<PRO; x++){
		printf ("Dentro: %d\n", (*Vetor).custo[x]); 
	}
}