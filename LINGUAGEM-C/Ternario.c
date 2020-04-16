#include <stdio.h> 

int main (){
	int num; 
	
	printf ("Digite o numero: "); 
	scanf ("%d", &num); 
	
	num > 0 ? printf ("Positivo") : printf ("Negativo"); 
	return 0; 	
}