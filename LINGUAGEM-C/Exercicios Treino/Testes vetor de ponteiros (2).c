#include <stdio.h> 
#include <stdlib.h>

	typedef struct {
		int a; 
		int b; 
		int c; 
	}tAlt; 
	
int main(){	
	tAlt *p = (tAlt*) malloc(sizeof (tAlt*) *10); //Vetor Dinamico
	tAlt *x = p; //Caso eu altere o valor usando x, tmb vai alterar nos valores de p  
	
	(*p).a = 10; //Acessando apenas o primeiro elemento do vetor dinamico, que tmb é igual a expressão logo abaixo  (1)
	//p[0].a = 10; Nestes dois casos estão alterando o primeiro elemento do vetor dinamico							(2)
	
	(*x).a = 20;  //Alterei valor pelo ponteiro x, que alterou valor no ponteiro p    (1)
	//x[0].a = 20; //Outra forma de acessar o valor								      (2)
	
	printf ("%d\n", p->a); 
	//printf ("%d\n", p[0].a); 
	return 0; 
}
/*
Caso eu preencha os outros valores do alocamento de memoria....E peça usando o modo (1), só poderá ser printado o primeiro elemento 
do Vetor dinamico....então pra mim acessar os outros indices eu preciso utilizar o modo (2)
*/