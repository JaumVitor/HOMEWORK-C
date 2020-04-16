#include <stdio.h> 

int main(void){
	int i, cont = 1; 
	float soma; 
	float vetorNotas[5] = {0}; 
	
	for (i=0; i<5; i++){
		printf ("Digite a nota %d: ", cont++); 
		scanf ("%f", &vetorNotas[i]); 
	}
	
	for (i=0; i<5; i++){
		soma += vetorNotas[i]; 
	}
	
	printf ("Media: %.2f", soma/5);  
	
	return 0;
	
}

