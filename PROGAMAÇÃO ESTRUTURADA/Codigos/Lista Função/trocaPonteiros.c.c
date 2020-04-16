#include <stdio.h> 
//Troca de valores dentro de uma fun��o usando ponteiros!
//Utilizados, quando quero passar o endere�o de uma variavel por exemplo, para dentro de uma fun��o
//Consequentemente, posso alterar o valor dela dentro da fun��o. sem precisar mudar dentro do main. 

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