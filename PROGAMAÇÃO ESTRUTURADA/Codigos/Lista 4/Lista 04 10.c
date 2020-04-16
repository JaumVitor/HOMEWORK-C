#include <stdio.h> 

int main(){
	int i, x, num; 
	
	printf ("Digite o numero: "); 
	scanf ("%d", &num); 
	
	for (i=1; i<=num; i++ ){
		for (x=1; x<=i; x++){
			printf ("%d ",i*x);
		}
		printf("\n");
	}
	return 0; 
}