#include <stdio.h> 
void contador(int num, int final); 

int main(){
	int n = 0, f=10; 
	contador(n, f);
	
	return 0; 
}

void contador(int num, int final){
	printf ("%d\n", num);
	
	if (num < final)
		contador(++num, final);
} 

//Sgunda forma de fazer contagem usando recursividade!