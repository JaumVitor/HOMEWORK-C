#include <stdio.h> 

int main (){
	
	//Declarações de ponteiros; 
	int x; 
	x=10; 
	
	/*int *pont;   se eu usasse int *pont; 
	pont = &x;                *pont = &x;
                   >Eu estaria atribuindo para o valor do ponteiro, o endereço da variavel x;
	int *end_fisico; 
	end_fisico = 6356724; 			    
	*/ 
	  
	int *pont = &x; 
	int *end_fisico = 6356724; //Utilizei o endereço que estava retornando; 
	
	printf ("%d\n", *pont); //Valor do endereço de x; 
	printf ("%d %d\n",pont, &x); //passado o endereço de x;  
	printf ("%d", *end_fisico); //Passando o endereço de forma automatica; 
		
	return 0; 	
}