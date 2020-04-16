//A estrutura vai ser passada para dentro da função
#include <stdio.h>

struct estrutura{
	int tipo1;
	float tipo2; 
	char tipo3;
}var_doTipo_estrutura,var_estrutura1, var_estrutura2; //Declarando a variavel que é do tipo estrutura, quando cria a struct....

         //Tipo do parametro... Parametro = (var_doTipo_estrutura)
void imprimir(struct estrutura parametro1, struct estrutura parametro2 , struct estrutura parametro3 ){
	printf ("%d\n", parametro1.tipo1); // "Parametro" tem o é do tipo estrutura
	printf ("%f\n", parametro2.tipo2); 
	printf ("%c\n", parametro3.tipo3); //Ou poderia usar "var_estrutura2.tipo3" ja que a estrutura é global!
}

int main(){
	
	//struct estrutura var_doTipo_estrutura; //Declarando a estrutura "var_doTipo_estrutura" do tipo "estrutura"
	var_doTipo_estrutura.tipo1 = 999;  //Passando o valor para a estrutura
	var_estrutura1.tipo2 = 1.342;
	var_estrutura2.tipo3 = 'a';
	
	imprimir(var_doTipo_estrutura, var_estrutura1, var_estrutura2); //Chamando a função que vai printar o valor da estrutura, que foi passado
	
	return 0; 
}