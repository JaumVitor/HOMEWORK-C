#include <stdio.h> 

int main(){
	int i, num;
	printf ("Digite um valor: "); 
	scanf ("%d", &num); 
	 
	for (i=1; i<100; i++){
		if (num%i == 0)
			printf ("%d, ", i); 
	}
	printf ("Fim"); 
	
	return 0; 
}