#include <stdio.h> 

void contador(int num, int cont);
 
int main(){
	int num = 25, cont= 0 ; 

	contador(num, cont);  //Chamando a fun��o contadora
	   	
	return 0; 
}

void contador(int value, int encremento){ 
	printf ("%d\n", encremento); //Ao entrar dentro da fun��o contador printa na tela
	
	if (value > encremento){
		contador(value, ++encremento); //Fun��o encrementada	
	}
}
/*No progama....ele vai fazer a contagem dos numeros ate que o encremento chegue em num
ate la, esta fun��o entra em um looping, em que essa fun��o entra dentro dela mesma
e fica recebendo um outro valor encrementado! 
Quando acabar os encrementos e ela n�o precisar mais da condi��o, a mesma sair� do looping. 
*/ 

