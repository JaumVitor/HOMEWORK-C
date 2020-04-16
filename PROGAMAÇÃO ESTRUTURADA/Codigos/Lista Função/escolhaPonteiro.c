#include <stdio.h> 

void escolha(int *esc){
		int escolha = *esc ; 
		scanf ("%d", &escolha); //Ou somente o "esc".
		*esc = escolha; 
		
		/*Podemos fazer isso de 3 formas: usando a variavel escolha ou utilizando o esc diretamente
		ou apenas usando o "&*esc"....Mas adaptável é o mode direto! */
}
int main(){
	int option;
	
	printf ("Digite opcao: "); 
	escolha(&option);
	
	if (option == 1)
		printf ("Verdade!");
	else 
		printf ("Falso!"); 
	return 0; 
}