#include <stdio.h> 
#include <stdlib.h>

typedef struct{
	int ano, mes, dia; 
}tData; 

int main (){
	tData *vet[2];
	tData *valor; 
	/*Necess�riamente precisa ser um ponteiro, pois se for uma variavel normal, assim que for passado o endere�o para o vetor
	o msm ira receber o endere�o da variavel......e quando eu for passar o outro endere�or de valor, ele vai obter o msm endere�o 
	para todos os valores do vetor. 
	Caso analogo, seria eu criar o espa�o de memoria uma unica vez, fora do looping....Semelhante a eu criar uma variavel*/ 
	int i; 
	
	for (i=0; i<2; i++){
		//Alocando em um espa�o de memoria diferente a cada vez que entra no looping 
		//Quando entrar aqui novamente, outro espa�o de memoria sera utilizado 
		valor = (tData*) malloc (sizeof (tData)); 
		//Preenchendo os espa�os de memoria alocado 
		scanf ("%d", &valor->ano); 
		scanf ("%d", &valor->mes); 
		scanf ("%d", &valor->dia); 
		vet[i] = valor; //Meu vetor de ponteiros esta armazendando o endere�o da variavel valor
		printf ("Endera�amento: %d", valor); 
	}
	
	for (i=0; i<2; i++){
		printf ("\n%d\n", vet[i]->ano); //Acessando os valores dentro do vetor que armazena endere�os
		printf ("%d\n", vet[i]->mes); 
		printf ("%d\n", vet[i]->dia); 
	}
	
	return 0; 
}
/*RESUMO:
Estou criando um vetor que vai armazenar os endere�os; 
Para isso, temos uma variavel do tipo tData, que vai gurdar valores que ser�o preenchidos e dps armazenados no vetor de endere�os;
Tendo o vetor de endere�o, eu posso acessar o valor armazenado neste endere�or; r
*/