//Vetor Dinamico 
#include <stdio.h>
#include <stdlib.h>

int main (){
	int *pontVet = (int*) malloc (sizeof (int) *5); 
	//Criar um alocamento de memoria, e retornar o endereço 
	
	//Para acessar o meu valor, preciso usar apenas [ pontVet[indice] = valor ]
	//Caso eu queira passar o endereço de memoria do vetor Dinamico, basta [ &pontVet[indice] ]
	
 	pontVet[0] = 10; 
 	printf ("%d", pontVet[0]); 
	 
	//Não preciso digitar o "*" (ponteiro) para acessar o valor
	return 0; 
}