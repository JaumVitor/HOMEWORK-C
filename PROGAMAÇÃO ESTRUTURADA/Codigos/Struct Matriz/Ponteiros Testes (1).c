#include <stdio.h> 

int main (){
	
	//Declara��es de ponteiros; 
	int x; 
	x=10; 
	
	/*int *pont;   se eu usasse int *pont; 
	pont = &x;                *pont = &x;
                   >Eu estaria atribuindo para o valor do ponteiro, o endere�o da variavel x;
	int *end_fisico; 
	end_fisico = 6356724; 			    
	*/ 
	  
	int *pont = &x; 
	int *end_fisico = 6356724; //Utilizei o endere�o que estava retornando; 
	
	printf ("%d\n", *pont); //Valor do endere�o de x; 
	printf ("%d %d\n",pont, &x); //passado o endere�o de x;  
	printf ("%d", *end_fisico); //Passando o endere�o de forma automatica; 
		
	return 0; 	
}