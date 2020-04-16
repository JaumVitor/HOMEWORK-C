#include <stdio.h> 
#define elem 2
#define list 2
#define qtd 2

int main(){
	int i, k, x; 
	int array[qtd][list][elem]; 
	
	for (i=0; i<qtd; i++){
		for (k=0; k<list; k++){
			for (x=0; x<elem; x++){
				printf ("Informe o valor para add no vetor: "); 
				scanf("%d", &array[i][k][x]);	
			}	
		} 
	}
	
	for (i=0; i<qtd; i++){
		for (k=0; k<list; k++){
			for (x=0; x<elem; x++){
				printf ("%d|", array[i][k][x]); 
			}
			printf ("\n");
		}
		printf ("\n");
	}

	
	return 0; 	
}