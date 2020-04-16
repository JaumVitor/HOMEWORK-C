#include <stdio.h> 

void contador(int num, int cont);
 
int main(){
	int num = 25, cont= 0 ; 

	contador(num, cont);  //Chamando a função contadora
	   	
	return 0; 
}

void contador(int value, int encremento){ 
	printf ("%d\n", encremento); //Ao entrar dentro da função contador printa na tela
	
	if (value > encremento){
		contador(value, ++encremento); //Função encrementada	
	}
}
/*No progama....ele vai fazer a contagem dos numeros ate que o encremento chegue em num
ate la, esta função entra em um looping, em que essa função entra dentro dela mesma
e fica recebendo um outro valor encrementado! 
Quando acabar os encrementos e ela não precisar mais da condição, a mesma sairá do looping. 
*/ 

