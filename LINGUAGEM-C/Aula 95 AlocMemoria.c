#include <stdio.h>
#include <stdlib.h> 
	
	typedef struct{
		int a; 
		int b; 
	}estrutura;
	 
int main () {
	estrutura teste; 
	estrutura lista[10];
	
	short x = 10;  
	short *pont = &x;
	 
	printf ("%d", sizeof (*pont));  
	
	return 0; 
}