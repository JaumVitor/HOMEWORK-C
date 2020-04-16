#include <stdio.h> 
#include <stdlib.h> 

int main(){
	int num, cont, somaDiv=0; 
	
	printf ("Digite o numero: ");
	scanf ("%d", &num); 
	
	for (cont=1; cont<num; cont++){
		if ( num%cont == 0){
			somaDiv += cont;
		} 		
	}if (somaDiv == num)
		printf ("O numero e perfeito ;)\n");
	else
		printf ("O numero não e perfeito!\n");
	return 0;
}