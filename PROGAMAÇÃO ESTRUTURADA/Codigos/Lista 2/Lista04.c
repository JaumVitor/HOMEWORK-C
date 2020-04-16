#include <stdio.h> 

int main (){
	int x,y; //cordenadas x e y
	  
	printf ("Digite os as cordenadas do plano: "); 
	scanf ("%d%d", &x,&y); 
	
	//USANDO IF-ELSE
	
	if ( x > 0 && y >0 )
		printf ("Pertence ao PRIMEIRO QUADRANTE"); 
	else if ( x < 0 && y > 0 )
		printf ("Pertence ao SEGUNDO QUADRANTE"); 
	else if ( x < 0 && y < 0 )
		printf ("Pertence ao TERCEIRO QUADRANTE"); 
	else if ( x > 0 && y < 0 )
		printf ("Pertence ao QUARTO QUADRANTE"); 
	
	else{
		printf ("Não pertence a nenhum quadrante\nPORTANTO: ");
		
		if ( (x > 0 || x < 0) && y == 0 )
			printf ("Pertence ao EIXO X"); 
		else 
			printf ("Pertence ao EIXO Y"); 
	}
	
	//USANDO SOMENTE IF 
	/*
	if ( x > 0 && y > 0)
		printf ("Pertence ao PRIMEIRO QUADRANTE");
	if ( x < 0 && y > 0 )
		printf ("Pertence ao SEGUNDO QUADRANTE");
	if ( x < 0 && y < 0 )
		printf ("Pertence ao TERCEIRO QUADRANTE"); 
	if ( x > 0 && y < 0 )
		printf ("Pertence ao QUARTO QUADRANTE"); 
	
	if ( (x > 0 || x < 0) && y == 0 )
		printf ("Pertence ao EIXO X"); 
	
	if (( y > 0 || y < 0) && x == 0)
	//if (!(x > 0 || x < 0) || !(y == 0))
		printf ("Pertence ao EIXO Y");
	*/
 	printf ("\n");
 	
	return 0; 
}