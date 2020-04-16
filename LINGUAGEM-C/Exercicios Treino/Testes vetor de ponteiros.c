#include <stdio.h> 
	typedef struct {
		int a; 
		int b; 
		int c; 
	}tAnalist; 
	
int main(){
	tAnalist p; //Da pra passar um ponteiro tmb, para dentro de uma struct, mas na hora de atribuir os valores tem que ser diferente
	tAnalist *end[10];
	end[0] = &p; 
	
	p.a = 100; 
	p.b = 200; 
	p.c = 43;
	
	printf ("%d\n", end[0]->a);
	
	return 0; 
}