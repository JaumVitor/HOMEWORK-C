#include <stdio.h> 
#include <math.h> 
#include <conio.h> 

int main (){
	int value, soma=0; 
	
	printf ("Digite o numero: "); 
	scanf ("%d", &value);
	
	while ( value > 0){
		soma += value%10; 
		value /= 10; 
	}   	
	printf ("Soma dos algorismos = %d", soma); 
	return 0; 
}