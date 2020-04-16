#include <stdio.h> 

int main(){
	int x, *p1, **p2; 
	x = 10; 
	
	p1 = &x;  
	p2 = &p1; 
	
	printf ("p1: %d\n", p1); //Endere�o x -->> &x;
	printf ("*p1: %d\n", *p1); //Conte�do de p1 (O que esta armazenado no endere�o &x) -->> x; 
	printf ("p2: %d\n", p2); //Endere�o de p1 --->> &p1; 
	printf ("*p2: %d\n", *p2); //Conte�do de p1 -->> &x;  
	printf ("**p2: %d\n", **p2); //Conte�do de *p2, que esta armazenando &x -->> x; 
	
	return 0; 
}