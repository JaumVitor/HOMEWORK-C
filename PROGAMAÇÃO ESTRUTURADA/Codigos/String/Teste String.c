#include <stdio.h>
#include <string.h>
#include <locale.h> 

	typedef struct {
		char marca[15]; 
		int ano; 
		char cor[10]; 
		float preco; 
		char placa[8]; 	  		
	}tcarro; 

int main(){
	setlocale (LC_ALL, ""); 
	tcarro listaDados[20]; 
	
	int id=0; 
	char aux[5] = "areq"; 
	
	strcpy(listaDados[id].placa, aux);
	printf ("%s", listaDados[id].placa);
	
	return 0; 
}