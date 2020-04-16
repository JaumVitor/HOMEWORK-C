#include <stdio.h>

 
	typedef struct {
		int *pHora; 
		int *pMinuto;
		int *pSegundo; 	  		
	}tHoraio; 
	
int main(){
	int hora = 10; 
	int minuto = 56; 
	int segundo = 13;
	
	tHoraio definir; 
	definir.pHora = &hora; 
	definir.pMinuto = &minuto; 
	definir.pSegundo = &segundo; 
	
	printf ("Valores fora da função: \n"); 
	printf ("%d\n", *definir.pHora);  
	printf ("%d\n", *definir.pMinuto); 
	printf ("%d\n", *definir.pSegundo); 
	
	return 0; 
}

