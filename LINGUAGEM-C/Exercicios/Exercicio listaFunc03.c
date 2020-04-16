#include <stdio.h>
#include <locale.h> 

int noNegativo(); //Fica recebendo um par de valores até ficarem positivos! 
int friends(int x, int y); //Verifica se os pares de valores são amigos
int somaDivisores(int value); //Soma os divisores do nuemero

int main(){
	setlocale (LC_ALL, ""); 
    int num1, num2,respAmigo; //Variaveis da função principal!

    do{
        num1 = noNegativo();
        num2 = noNegativo(); 
		
		if (num1 == 0 && num2 == 0){
			printf ("Encerrando..."); 
			break; 
		}
		
        respAmigo = friends(num1, num2); 
        
        if (respAmigo == 1)
        	printf ("S�O AMIGOS!\n\n"); 
        else 
        	printf ("N�O S�O AMIGOS!\n\n"); 	

    }while((num1 != 0) || (num2 != 0)); //Enquanto os pares forem divergentes de zero & zero

    return 0;
}

int noNegativo(){
    int num; 
    int static enumarete = 1; 
/*Estou usando a variavel enumarate como estatica afim de ter um valor constante... assim quando eu retornar
novamente a função, ela permanecerar com o mesmo valor...e so vai mudar caso o valor seja maior que zero!*/
    do{
        printf("Digite o valor %d: ",enumarete);
        scanf("%d", &num); 

        if (num >= 0)
            ++enumarete; 
        	if (enumarete > 2)
        		enumarete = 1; 

    }while (num < 0);

    return num; //Retorna apenas valores positivos, e repete quando for negativo
}

int friends(int x, int y){
    int somaX, somaY; //Recebe soma dos divisores
    
	somaX = somaDivisores(x);
	somaY = somaDivisores(y); 
	
	if (somaX == y && somaY == x) 
		return 1; 
	else 
		return 0; 
}

int somaDivisores(value){
	int somaDiv = 0, i; 
	
	for (i=1; i<value; i++){    //Verifica os divisores do numero 1
        if (value%i == 0)
            somaDiv += i; 
	}
	return somaDiv; 
}
