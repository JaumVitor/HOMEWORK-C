#include <stdio.h>
#include <locale.h> 

int main(){
	int value;
	setlocale (LC_ALL, "Portuguese");  
	
	for (;;){
		printf ("Digite os valores: "); 
		scanf ("%d", &value);
		
		if ( value < 0){
			printf ("Encerrando...\n");
			break; 
		
		}if (value%2 == 0)
			printf ("O numero %d � para\n\n", value); 
		else 
	  		printf ("O numero %d � impar\n\n", value); 
	}
	return 0; 
}