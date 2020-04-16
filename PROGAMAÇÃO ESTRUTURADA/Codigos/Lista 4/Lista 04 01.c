#include <stdio.h> 

int main (){
	int num, i; 
	
	printf ("Digite o numero: ");
	scanf ("%d", &num);
	
	if (num < 11 && num > 0){
		for (i=1 ;i<11 ;i++){
			printf ("%d x %d = %d\n", num, i, i*num);
		}   
	}
	return 0; 
}