#include <stdio.h> 

int function(){
	static int variavel = 2; //S� posso usar a fun��o static, quando o valor da var � constante
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
//Toda vez que eu chamar uma VariavelLocalAutomatica, ela ser descartada dentro da fun��o
//Mas se eu usar o Static, ela vai permanecer....E se tornar uma VariavelLocalEstatica 
//S�o Variaveis locais pelo fato delas s� funcionarem dentro da funciction() 