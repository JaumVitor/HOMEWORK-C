#include <stdio.h> 
#include <stdlib.h>
#include <locale.h>

//Fun��es secundarias: 
void printLine ();

//Fun�oes menus: 
void menuMain (int *userChoice); 
void menuStart (); 
void menuEndGame (); 

//fun��es principais:

int main (){
	setlocale (LC_ALL,"Portuguese");
	int userChoice; //Escolha da op��o do menu
	
	do{
		menuMain (&userChoice); system ("cls");
		switch (userChoice){
			case 1:
				//Vai para o menuStart, onde vai inicar as escolhas para come�ar o game
				printf ("Inicando\n");
				break;  
			case 2: 
				printf ("Instru��es\n");
				//informa as instru��es do game
				break;
			case 0:	
				printf ("Saindo do game\n");
				break;
			default: 
				printf ("# ERRO: TENTE NOVAMENTE #\n");	
		} 
	}while (userChoice != 0); 
	
	return 0; 
}

void printLine (){
	printf ("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
}

void menuMain (int *userChoice){
	printLine (); printf ("\t1.INICIAR\n \t2.INSTRU��ES\n \t0.EXIT\n"); printLine ();
	printf ("\t>>Digite op��o: "); 
	scanf ("%d", userChoice);
	
}

