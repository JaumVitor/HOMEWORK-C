#include <stdio.h> 

int main (){
	int num, i; 
	
	printf ("Digite o numero: ");
	scanf ("%d", &num);
	
	for (i=1 ;i<11 ;i++){
		printf ("%d x %d = %d\n", num, i, i*num);
	}  
	return 0; 
}