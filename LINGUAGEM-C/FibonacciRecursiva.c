#include <stdio.h> 
int fibonacci(int val);
 
int main(){
	int num, i; 
	
	printf ("Digite quantos numeros fibonacci: "); 
	scanf ("%d", &num); 	
	
	for (i=0; i<num; i++){
		printf ("%d\n",fibonacci(i+1));    
	}
	return 0; 
}

int fibonacci(int val){
	int resultado; 
	if (val == 1 || val == 2){
		resultado =  1; 
		return resultado;	
	}else {
		resultado = fibonacci(val-2) + fibonacci(val-1); 
		return resultado; 
	}
}