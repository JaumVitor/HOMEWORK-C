//Vetor Dinamico 
#include <stdio.h>
#include <stdlib.h>

int main (){
	int *pontVet = (int*) malloc (sizeof (int) *5); 
	//Criar um alocamento de memoria, e retornar o endere�o 
	
	//Para acessar o meu valor, preciso usar apenas [ pontVet[indice] = valor ]
	//Caso eu queira passar o endere�o de memoria do vetor Dinamico, basta [ &pontVet[indice] ]
	
 	pontVet[0] = 10; 
 	printf ("%d", pontVet[0]); 
	 
	//N�o preciso digitar o "*" (ponteiro) para acessar o valor
	return 0; 
}