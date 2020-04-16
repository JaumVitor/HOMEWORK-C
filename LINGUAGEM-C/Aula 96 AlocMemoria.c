#include <stdio.h> 
#include <stdlib.h>
 
	typedef struct {
		int a; 
		int b; 
	} estrutura; 
	
int main (){
	/*
	//Usando o malloc para criar um alocamento de memoria
	int *pont;
	pont = (int *) malloc (sizeof (int)); 
	//Passando o endereço do alocamento de memoria, e definir pra que tipo este ponteiro vai apontar
	
	int *x = (int*) malloc (sizeof (int)); //Ponteiro x esta recebendo o mesmo endereço do ponteiro pont - Somente criei o ponteiro
	x = &*pont;     //Passando o endereço - Quando eu altero em um muda o outro tmb
	*x = 130; 
	 
	printf ("Endereco do ponteiro: %d\n", pont);
	printf ("Valor armazenado dentro do ponteiro: %d\n", *pont );
	*/
	int i; 
	estrutura *p = (estrutura*) malloc (sizeof (estrutura) * 5); 
	//*p vai apontar para um alocamento de memoria que aponta para um tipo estrutura
	 
    //p->a = 13; 
	//p->b = 123; 
	//printf ("%d\n", p->a);
	//printf ("%d", p->b);
	
	p[0].a = 9;   //Dessa forma eu consigo atribuir valores para o ponteiro p, alocando varios locais de memoria
	p[1].a = 2; 	//Fica parecido com o uso de vetores
	p[4].a = 5; 
	
	/*for (i=0; i<5; i++){
		scanf ("%d", &p[i].a); 
	}*/ 
		
	for (i=0; i<5; i++){
		printf ("%d\n", p[i].a); 
	}
	
	printf ("\n%d", p->a); //Se eu usar dessa maneira ele pega somente o primeiro elemento
	//printf ("\n%d", (*p).a);
	return 0; 
}