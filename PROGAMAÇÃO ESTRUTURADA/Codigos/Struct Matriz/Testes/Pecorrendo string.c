#include <stdio.h> 
//Cuidado com tamanho das strings!

void pecorrerString (char string1[10], char string2[10]){
	int i, soma=0; 
	
	for (i=0; i<10; i++){
		if (string1[i] != string2[i]){
			printf ("somando"); 	
			soma += 1 ; 
			break;
		}
	}
	printf ("%d\n", soma); 
	if (soma == 0)
		printf ("Strings iguais!"); 
	else 
		printf ("Strings diferentes"); 
}

int main(){
	char stringFixa[10] = "ABCDEFGHA";
	char stringAnalize[10]; 
	
	printf ("Digite uma string: "); 
	scanf ("%s", stringAnalize);  
	
	pecorrerString ( stringFixa, stringAnalize );
	return 0;    	
}