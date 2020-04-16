#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int a, b; 
}tvalor; 

int main (){
	int i; 
	tvalor *pontVet = (tvalor*) malloc (sizeof (tvalor*) *5); 
 	/*
 	for (i=0; i<5; i++){
		pontVet[i].a = 10+i;
    }
 	
 	for (i=0; i<5; i++){
		printf ("%d\n", pontVet[i].a); 
	}*/
	
	printf ("Digite o valor: ");   
	scanf ("%d", &pontVet[0].a);  
	
	printf ("%d", pontVet[0].a);
	return 0; 
}