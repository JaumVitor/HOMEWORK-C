//Foi passado um valor da struct para a função, logo dps o valor foi alterado!
#include <stdio.h>
	//Foi declarada como global para usar o d1.idade, dentro da função.
	struct dados{
		int idade; 
		float peso;
	};
	
void init(int *idade){
	//printf ("idade: %d\n", d1.idade);
	printf ("idade: %d\n", *idade); //idade sem a atribuição
	*idade = 10; //Atribuição da idade para dentro da estrutura
	printf ("Idade: %d\n", *idade); //Printando a estrutura, após a atribuição 
}

int main(){
	struct dados d1; //poderia ser feita a declaração de d1 dessa forma 
	d1.idade = 99;
	
	init(&d1.idade); //Chamando a função
	printf ("Main: %d", d1.idade); //Verificação do valor fora da função, para saber se foi alterado! 
	
	return 0;
}