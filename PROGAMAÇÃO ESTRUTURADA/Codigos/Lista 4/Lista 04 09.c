#include <stdio.h>

int main (){
	int soma=0, ant=0, pos=1;
	
	printf ("%d\n", ant); 
	while (pos <100){
		soma = 0; 
		printf ("%d\n", pos); 
		soma = ant + pos;
		ant = pos; 
		pos = soma;
	}
	return 0;
}