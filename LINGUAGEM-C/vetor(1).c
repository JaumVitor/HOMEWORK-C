#include <stdio.h> 
#define elem 3 
#define list 3

int main (void){
	int i, k; 
	int vetor[list][elem] = {1,2,3,4,5,6,7,8,9};  //Pelo fato do vetor esta defenido como 3x3, ele faz a divisão automática. 
	//Vetor não muito didático. 
	
	for (i=0; i<list; i++){
		for (k=0; k<elem; k++){
			//printf ("Digite os valores do vetor: "); 
			//scanf ("%d", &vetor[i][k] ); 
		}
	}
	
	for (i=0; i<list; i++){
		for (k=0; k<elem; k++){
			printf ("%d|", vetor[i][k]); 
		}
		printf ("\n"); 
	}
	return 0; 
}