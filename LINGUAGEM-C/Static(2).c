#include <stdio.h> 

int function(){
	static int variavel = 2; //Só posso usar a função static, quando o valor da var é constante
	printf ("%d\n", variavel); 
	variavel *= 2;  
	
	return variavel; 
}

int valor = 10; 
int main(){
	function(); 
	function(); 
	function(); 
	return 0; 
}
//Toda vez que eu chamar uma VariavelLocalAutomatica, ela ser descartada dentro da função
//Mas se eu usar o Static, ela vai permanecer....E se tornar uma VariavelLocalEstatica 
//São Variaveis locais pelo fato delas só funcionarem dentro da funciction() 