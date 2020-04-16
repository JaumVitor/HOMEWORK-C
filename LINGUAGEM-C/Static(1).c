#include <stdio.h> 

void function(){
	static int variavel=0;  //Com essa função static, variavel continua com o mesmo valor
	variavel++ ;  			//Quando a função é chamada novamente, valor da var continua o mesmo 
	printf ("VAR1= %d\n", variavel);
	return; 
}

void function2(){
	int variavel2=0; 		//Função variavel esta sendo descartada, a cada vez que a função é chamada
	variavel2++ ;  
	printf ("VAR2= %d\n", variavel2);
	return; 
} 

int main(){
	int i; 
	for (i=0; i<10; i++){
		function();
	}
	for (i=0; i<10; i++){
		function2(); 
	}

	return 0; 
}