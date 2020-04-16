#include <stdio.h> 
#include <locale.h> 

int main(){
	setlocale (LC_ALL, "Portuguese");  
	int value, cont=1, val=0 ;
	 
	printf ("Informe o valor: "); 
	scanf ("%d", &value);

	while ( cont <= value){
		if ( value%cont == 0)
			val++ ; 
		cont++ ;
	} 
	if ( val == 2)
		printf ("O valor é primo\n"); 
	else
		printf ("O valor não é primo\n"); 
	return 0; 
}