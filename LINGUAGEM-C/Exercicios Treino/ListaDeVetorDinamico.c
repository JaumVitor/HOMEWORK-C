#include <stdio.h> 
#include <stdlib.h>

typedef struct{
	int ano, mes, dia; 
}tData; 

int main (){
	tData *vet[2];
	tData *valor; 
	/*Necessáriamente precisa ser um ponteiro, pois se for uma variavel normal, assim que for passado o endereço para o vetor
	o msm ira receber o endereço da variavel......e quando eu for passar o outro endereçor de valor, ele vai obter o msm endereço 
	para todos os valores do vetor. 
	Caso analogo, seria eu criar o espaço de memoria uma unica vez, fora do looping....Semelhante a eu criar uma variavel*/ 
	int i; 
	
	for (i=0; i<2; i++){
		//Alocando em um espaço de memoria diferente a cada vez que entra no looping 
		//Quando entrar aqui novamente, outro espaço de memoria sera utilizado 
		valor = (tData*) malloc (sizeof (tData)); 
		//Preenchendo os espaços de memoria alocado 
		scanf ("%d", &valor->ano); 
		scanf ("%d", &valor->mes); 
		scanf ("%d", &valor->dia); 
		vet[i] = valor; //Meu vetor de ponteiros esta armazendando o endereço da variavel valor
		printf ("Enderaçamento: %d", valor); 
	}
	
	for (i=0; i<2; i++){
		printf ("\n%d\n", vet[i]->ano); //Acessando os valores dentro do vetor que armazena endereços
		printf ("%d\n", vet[i]->mes); 
		printf ("%d\n", vet[i]->dia); 
	}
	
	return 0; 
}
/*RESUMO:
Estou criando um vetor que vai armazenar os endereços; 
Para isso, temos uma variavel do tipo tData, que vai gurdar valores que serão preenchidos e dps armazenados no vetor de endereços;
Tendo o vetor de endereço, eu posso acessar o valor armazenado neste endereçor; r
*/