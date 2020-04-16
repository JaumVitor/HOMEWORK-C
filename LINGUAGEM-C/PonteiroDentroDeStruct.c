#include <stdio.h> 
#include <stdlib.h>
#include <locale.h>

//Funções secundarias: 
void printLine ();

//Funçoes menus: 
void menuMain (int *userChoice); 
void menuStart (); 
void menuEndGame (); 

//funções principais:

int main (){
	setlocale (LC_ALL,"Portuguese");
	int userChoice; //Escolha da opção do menu
	
	do{
		menuMain (&userChoice); system ("cls");
		switch (userChoice){
			case 1:
				//Vai para o menuStart, onde vai inicar as escolhas para começar o game
				printf ("Inicando\n");
				break;  
			case 2: 
				printf ("Instruções\n");
				//informa as instruções do game
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
	printLine (); printf ("\t1.INICIAR\n \t2.INSTRUÇÕES\n \t0.EXIT\n"); printLine ();
	printf ("\t>>Digite opção: "); 
	scanf ("%d", userChoice);
	
}

