#include <stdio.h> 

int main(){
	/* Esse modo eu tenho o nome do tipo de estrutura, assim eu posso usar em outras variaveis 
	struct pessoa{
		   int idade; 
		   float peso; 
	}; struct pessoa p1, p2; 

	//Dessa maneira funciona, eu declarando as variaveis logo apos a estrutura, mas não tenho o nome 
	//da estrutura, dessa forma eu não posso usar em outro lugar.
	struct {
		int idade; 
		float peso;
	} p1, p2;
	*/
	
	typedef struct{
			int idade; 
			float peso; 
	} pessoa; //Ao final da estrutura coloca o nome dela; 
	pessoa p1,p2; //Variaveis do tipo da estrutura; 
	
	p1.idade = 12; 
	p2.idade = p1.idade + 10;
	printf ("idade p1: %d\nidade p2: %d\n\n", p1.idade, p2.idade);
	
	p1.peso = 56;
	p2.peso = p1.peso ;
	printf ("Peso p1: %f\nPeso p2 %f ", p1.peso, p2.peso);
	
	return 0; 
}