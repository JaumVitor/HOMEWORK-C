//Quetão para organizar um vetor, dados os numeros desordenados.
//Importante salientar que, iremos fazer outra versão do progama, usando outros metodos de logica.  
#include <stdio.h> 
#include <stdlib.h>

void sort(int vetor[]); //Função para organizar vetor

int main(){
	int vet[10] = {1,5,3,7,8,3,2,9,0,6};
	int x; 
	
	sort(vet); //Ordenar a lista
	
	for (x=0; x<10; x++){ //Pecorrer todos os valores dentro do vetor 
		printf ("%d", vet[x]);
	}
	return 0; 
}

void sort( int vetor[] ){
	int aux, i, k; //Que vai ajudar no momento em que for fazer a troca de valores do vetor
	
	for (i=0; i<10; i++){
		for (k=i; k<10; k++){
			 if (vetor[i] > vetor[k]){
				 aux = vetor[i]; 
				 vetor[i] = vetor[k]; 
				 vetor[k] = aux; 
			 }	
	   	}
	}
}
