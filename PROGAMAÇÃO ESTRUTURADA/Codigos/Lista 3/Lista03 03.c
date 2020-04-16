#include <stdio.h> 

int main(){
	int value, i; 
	
	printf ("Digite o valor: ");
	scanf ("%d", &value);
	
	for (i=0; i<value +1; i++){
		printf ("%d\n", i); 
	} 
	return 0; 
}