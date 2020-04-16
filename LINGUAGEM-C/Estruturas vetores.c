#include <stdio.h> 
/*
	typedef struct {
		int vetor[5];
		int var;
	}name_registro;  name_registro _acessar;

int main(){
	_acessar.var = 10;
	
	int var; for (var=0; var<5; var++){
		scanf ("%d", &_acessar.vetor[var]);
	}
	
	int v; for (v=0; v<5; v++){
		printf ("%d", _acessar.vetor[v]);
	}
	return 0;
}
*/

int main (){
	int tamanho;
	printf ("Digite o tamanho do vetor: ");
	scanf ("%d", &tamanho);
	
	typedef struct{
		int vetor[tamanho];
	}reg; reg variavel;
	
	int var; for (var=0; var<tamanho; var++){
		scanf ("%d", &variavel.vetor[var]);
	}
	
	int v; for (v=0; v<tamanho; v++){
		printf ("%d", variavel.vetor[v]);
	}
	
	return 0;
}