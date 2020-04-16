#include <stdio.h> 
#include <string.h>

void alpha ( char palavra[] ){
	int i;
	for (i=0; i<strlen(palavra)-1; i++){
		if ( (palavra[i] >= 'a' && palavra[i] <= 'z') || ( palavra[i] >= 'A' && palavra[i] <= 'Z')){
			printf ("Letra Alfabetica\n"); 
		}else 
			printf ("Não eh uma letra\n"); 
	}
}

int main (){
	char palavra[20]; 
	fgets( palavra, 20, stdin);
	fflush (stdin);
	
	alpha (palavra);
	
	return 0;  
}