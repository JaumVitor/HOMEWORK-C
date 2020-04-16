#include <stdio.h>

void imprimir(int lista[2][2]){
	int i,k; 
	
	for (i=0; i<2; i++){
		for (k=0; k<2; k++){
			printf ("%d", lista[i][k]);
		}
		printf ("\n");
	}
}

int main(){
	int vetor[2][2] = {{1,2},{1,3}};
	imprimir(vetor); 
	
	return 0;
}