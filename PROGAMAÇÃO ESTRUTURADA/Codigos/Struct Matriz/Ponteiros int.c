#include <stdio.h> 

int main(){
	int x, *p1, **p2; 
	x = 10; 
	
	p1 = &x;  
	p2 = &p1; 
	
	printf ("p1: %d\n", p1); //Endereço x -->> &x;
	printf ("*p1: %d\n", *p1); //Conteúdo de p1 (O que esta armazenado no endereço &x) -->> x; 
	printf ("p2: %d\n", p2); //Endereço de p1 --->> &p1; 
	printf ("*p2: %d\n", *p2); //Conteúdo de p1 -->> &x;  
	printf ("**p2: %d\n", **p2); //Conteúdo de *p2, que esta armazenando &x -->> x; 
	
	return 0; 
}