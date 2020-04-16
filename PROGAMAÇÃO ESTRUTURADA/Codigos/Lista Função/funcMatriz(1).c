#include <stdio.h> 
//Troca de valores dentro de uma função usando ponteiros!
//Utilizados, quando quero passar o endereço de uma variavel por exemplo, para dentro de uma função
//Consequentemente, posso alterar o valor dela dentro da função. sem precisar mudar dentro do main. 

void troca(int *end_x, int *end_y){
		int aux = *end_x; 
		*end_x = *end_y;
		*end_y = aux; 		 
		printf ("Func torca: %d, %d\n", *end_x,*end_y);
}

int main(){
	int x, y; 
	
	printf ("Digite o valor x: "); 
	scanf ("%d", &x); 
	printf ("Digite o valor y: "); 
	scanf ("%d", &y); 
	
	troca(&x,&y); 
	printf ("Func main: %d,%d",x,y); 
	return 0; 
}