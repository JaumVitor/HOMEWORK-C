#include <stdio.h> 
#include <stdlib.h>

typedef struct {
	int ValorA, ValorB; 
}VALORES; 

int main (){
	int i; 
	VALORES *vetor[100]; //Criando vetor para armazernar endereços, e meu vetor vai apontar para um tipo struct VALORES
	VALORES *Valor = (VALORES*) malloc (sizeof (VALORES*)); 
	//Ponteiro que vai apontar para um tipo VALORES, e que seu endereço vai ser passado para o vetor acima
	
	/*Vamos demostrar apenas com os 3 primeiros elementos (Explicação de como acessar esta: Testes vetor de ponteiros(2)																			  valor struct dinamico & vetor dinamico   */		
	
	Valor->ValorA = 1; 
	Valor->ValorB = 2; 
	vetor[0] = Valor;	//Valor é o endereço do meu ponteiro
	
	Valor->ValorA = 3; 
	Valor->ValorB = 4; 
	vetor[1] = Valor;	//Valor é o endereço do meu ponteiro
	
	printf ("%d ", vetor[0]->ValorB); 
	
	Valor->ValorA = 5; 
	Valor->ValorB = 6; 
	vetor[2] = Valor;	//Valor é o endereço do meu ponteiro
	
	return 0; 
}