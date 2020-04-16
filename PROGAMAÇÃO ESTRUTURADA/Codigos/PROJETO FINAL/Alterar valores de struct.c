#include <stdio.h> 
#include <string.h>

#define tam 9
	typedef struct {
		int num1, num2;
		char nome[12];  
	}conta; 
	
void eraser (conta lista[tam], int indice){
	int i;
	
	for (i=indice; i<tam; i++){		
		lista[i] = lista[i+1];
	}
}

int main(){
	conta aux; 
	conta lista[tam];
	
	lista[0].num1 = 0; 
	lista[0].num2 = 0;
	strcpy(lista[0].nome, "Fulano"); 
	
	lista[1].num1 = 1;
	lista[1].num2 = 1;  
	strcpy(lista[1].nome, "Cicrano");   
	
	aux = lista[0]; 
	lista[0] = lista[1]; 
	lista[1] = aux; 
	
	printf ("LISTA[0]\nNum1: %d\nNum2:%d\nNome:%s\n\n", lista[0].num1, lista[0].num2,lista[0].nome);
	printf ("LISTA[1]\nNum1: %d\nNum2:%d\nNome:%s\n", lista[1].num1, lista[1].num2,lista[1].nome);
	//int indice = 2, i;
	//eraser (lista, indice); 
	
	//printf ("%d %d\n", lista[1].num, lista[0].num);
	return 0; 
}