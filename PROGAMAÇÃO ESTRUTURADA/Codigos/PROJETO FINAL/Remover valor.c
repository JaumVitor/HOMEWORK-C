#include <stdio.h> 
#define tam 9

void eraser (int vet[tam], int indice){
	int i;
	vet[indice] = 0; 
	
	for (i=indice; i<tam-1; i++){		
		vet[i] = vet[i+1];
	}
}

int main(){
	int vet[tam] = {0,1,2,3,4,5,6,7,8};
	int indice = 5, i; 
	
	eraser (vet, indice);
	printf ("\n\n");
	for (i=0; i<tam-1; i++){
		printf ("%d\n", vet[i]);
	}
	return 0; 
}