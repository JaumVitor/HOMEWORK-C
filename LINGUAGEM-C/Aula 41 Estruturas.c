//Foi passado um valor da struct para a fun��o, logo dps o valor foi alterado!
#include <stdio.h>
	//Foi declarada como global para usar o d1.idade, dentro da fun��o.
	struct dados{
		int idade; 
		float peso;
	};
	
void init(int *idade){
	//printf ("idade: %d\n", d1.idade);
	printf ("idade: %d\n", *idade); //idade sem a atribui��o
	*idade = 10; //Atribui��o da idade para dentro da estrutura
	printf ("Idade: %d\n", *idade); //Printando a estrutura, ap�s a atribui��o 
}

int main(){
	struct dados d1; //poderia ser feita a declara��o de d1 dessa forma 
	d1.idade = 99;
	
	init(&d1.idade); //Chamando a fun��o
	printf ("Main: %d", d1.idade); //Verifica��o do valor fora da fun��o, para saber se foi alterado! 
	
	return 0;
}