#include <stdio.h>
int noNegativo(); //Fica recebendo um par de valores até ficarem positivos! 
int friends(int x, int y); //Verifica se os pares de valores são amigos

int main(){
    int num1, num2; //Variaveis da função principal!

    do{
        num1 = noNegativo();
        num2 = noNegativo(); 
      
        friends(num1, num2); 

    }while((num1 != 0) || (num2 != 0)); //Enquanto os pares forem divergentes de zero & zero

    return 0;
}

int noNegativo(){
    int num; 
    int static enumarate = 1; 
/*Estou usando a variavel enumarate como estatica afim de ter um valor constante... assim quando eu retornar
novamente a função, ela permanecerar com o mesmo valor...e so vai mudar caso o valor seja maior que zero!*/
    do{
        printf("Digite o valor %d: ",enumarate);
        scanf("%d", &num); 

        if (num >= 0)
            ++enumarate; 

    }while (num < 0);

    return num; //Retorna apenas valores positivos, e repete quando for negativo
}

int friends(int x, int y){
    int i, somaDiv1 = 0, somaDiv2 = 0; 

    somaDivisores 
    for (i=1; i<x; i++){    //Verifica os divisores do numero 1
        if (x%i == 0)
            somaDiv1 += i; 
    }
    for (i=1; i<y; i++){    //Verifica os divisores do nuemro 2 
        if (y%i == 0)
            somaDiv2 += i; 
    }

    return 0; 
}
