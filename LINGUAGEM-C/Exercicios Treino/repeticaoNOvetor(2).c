#include <stdio.h> 
#include <string.h> 

/*Logica do exercicio:
Progama deve pecorrer a lista verificando os elemntos. 
Mas ele sempre conta os valores com indices iguais, ex: quando for x==i. 
Outro problema é quando tem valores sendo combinados mais de uma vez no msm vetor

Conclusão: 
Para esses dois casos podemos usar o indice do for mais interno como o antecessor + 1; 
Dessa forma não serão combinados mais de uma vez o msm par, e nem os mesmos indices; 
*/  

typedef struct{
	char string[10]; 
}registro; 

int main (){
	registro vetor[5];  
	int repeat=0, i, x; 
	
	for (x=0; x<5; x++){
	   	scanf ("%s", vetor[x].string); 
	}
	
	for (i=0; i<5; i++){
		for (x=i+1; x<5; x++){ //x+1, pois o valor deve sempre pegar seu posterior 
			if (strcmp (vetor[i].string, vetor[x].string ) == 0){
				++repeat; 
			}
		}
	} 
	
	printf ("repetiu: %d", repeat); 
	return 0; 
}