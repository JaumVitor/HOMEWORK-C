#include <stdio.h> 

int maiorValor(int n1, int n2){
	//Função que retorna o maior valor, entre os dois recebidos como parametro;
	if (n1 > n2)
		return n1; 
	else if (n2 > n1)
		return n2; 
	else 
		return 1; //Retorna 1, quando os valores forem iguais, será usado ao final para o printf(); 
}

int main(){
	int resp; 
	int num1=-1, num2=-1;
	do {
	
		printf ("[1] Digite o numero inteiro: ");
		scanf ("%d",&num1);  
		if (num1 < 0){
			do{
				printf (" > > [1] Digite o valor correto!: "); 
				scanf ("%d", &num1); 
			}while(num1 < 0); 
		}
			
		printf ("[2] Digite outro numero inteiro: ");
		scanf ("%d", &num2);
		if (num2 < 0){
			do{
				printf (" > > [2] Digite o valor correto!: "); 
				scanf ("%d", &num2); 
			}while (num2 < 0);  
		}	
		
		if (maiorValor(num1, num2) == 1)
			printf ("Os valores são iguais!\n\n"); 
		else 	
			printf ("Dentre os valores, %d eh o maior! \n\n", maiorValor(num1, num2)); 
		
		printf ("QUER CONTINUAR ?\n[1] = SIM\n[2] = NAO\n> DIGITE: "); 
		scanf ("%d", &resp); 
		printf ("\n");
		
		if (resp != 1 && resp != 2){
			printf ("<ERRO> INFORME UM VALOR ADEQUADO!\n"); 
			do{
				printf ("\t> Digite certo!: "); 
				scanf ("%d", &resp); 
			}while(resp != 1 && resp != 2); 
		} 
	}while(resp == 1);
	
	printf ("Obrigado pela participação! Volte sempre! \n"); 	
	return 0;
}