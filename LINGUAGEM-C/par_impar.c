#include <stdio.h>
#include <locale.h> 

int main(){
	int num; 
	setlocale (LC_ALL,"Portuguese"); 
	
	printf ("informe um valor inteiro: "); 
	scanf ("%d", &num); 
	
	if (num % 2 == 0){
		printf ("numero PAR\tCONDIÇÃO 1\n");
	 
		if (num >= 10)
			printf ("o Valor PAR é maior que 10\tIF DENTRO DA CONDIÇÃO 1\n"); 
		else if (num >= 8)
			printf ("o valor PAR é maior que 8\t ELSE IF DENTRO DA CONDIÇÃO 1\n" ); 
			
	}else{
		printf ("numero impar \tELSE DA CONDIÇÃO 1\n");
		
		if (num >= 9)
			printf ("Valor é maior que 9\n"); 
		else if (num >= 7)
			printf ("Valor maior que 7\n");
		  
	}
	return 0; 
}