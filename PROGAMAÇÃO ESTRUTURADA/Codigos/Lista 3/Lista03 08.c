#include <stdio.h> 
#include <locale.h> 
#include <conio.h> 

int main(){
	setlocale (LC_ALL, "Portuguese"); 
	int value, fato, result; char saida = 'N'; 
	
	/*
	printf ("Digite um valor pra saber seu fatorial: ");
	scanf ("%d", &value);
	
	fato= 1, result= value;  // Usando fatorial de Num * 1 * 2...* num - 1  
	while(1){
		result *= fato ;
		fato++ ;    //Vai sofrendo decremento ate chegar no penultimo valor
		
		if (fato >= value){  //Se a var fato chegar no valor ent�o encerra
			break; 
		}
	}
	printf ("O fatorial de %d e %d\n", value, result);*/
	do{
	printf ("\n\nDigite um valor pra saber seu fatorial: ");
	scanf ("%d", &value);
	
	if (!(value <0)){ //N�o recebe valor menor que 0 para fatorial
		
		switch (value){
			case 0: 
				fato = 0, result = 1; 
				printf ("%d! = %d\n",fato, result ); 
				break; 
			case 1: 
				fato = 1, result = 1; 
				printf ("%d! = %d\n",fato, result ); 
				break; 
		}if (!(value == 1 || value == 0)){	// Caso os valores forem 0 ou 1, ent�o...recebem valores do switch e saem
	
			fato= value, result= value;
		
			while(1){
				result *= --fato ; // Mesma pegada da anterior, so que usando o fatorial Num * Num-1 * Num-2....Num * 1
				if ( fato == value - 1){ //Pegar o primeiro fatorial, num*....
					printf ("%d*", value); 	
								
				}if (fato == 1){ // Este vai pegar o 1, alem de imprimir o resultado
					printf ("%d = %d\n",fato, result ); 
					break; 
				}else	//Enquanto fato n�o chegar em 1, continua printando, mas n�o pega o 1
				   	printf ("%d*", fato);
			}
		}
			printf("\nAinda quer continuar ? ");
			saida = getche(); 
			
		if (saida != 'S' && saida != 'N' && saida != 's' && saida != 'n'){
			do{
				printf("\nERRO 401-DIGITE NOVAMENTE: ");
				saida = getche(); 
			}while( saida != 'S' && saida != 'N' && saida != 's' && saida != 'n');	
		}
	}else
	   	printf ("Esse n�mero n�o � natural!\n");	
	   	
	}while ( saida == 's' || saida == 'S'); 
	
	return 0; 
}