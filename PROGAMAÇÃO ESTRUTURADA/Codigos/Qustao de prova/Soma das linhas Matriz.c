#include <stdio.h> 
#include <stdlib.h>

#define MAXL 3
#define MAXC 2

int main(){
	int m[MAXL][MAXC];
	int v[MAXC]; 
	int i, x, soma, maior;  
	
	for (i=0; i<MAXL; i++){
		for (x=0; x<MAXC; x++){
			scanf ("%d", &m[i][x]); 
		}printf ("Primeira linha preenchida\n"); 
	}printf ("\n"); 
	system("cls"); 
	
	for (i=0; i<MAXL; i++){
		soma=0;
		for (x=0; x<MAXC; x++){
			//printf ("%d ", m[i][x]);
		
			soma += m[i][x];   
		} 
		v[i] = soma; 
		printf ("%d ", v[i]); 
		if (i==0)
			maior = v[i]; 
		else if (v[i] > maior){
			maior = v[i]; 
		}
	}printf ("\n"); 
	   
	for (i=0; i<MAXL; i++){
		if (maior == v[i])
			printf ("%d eh o maior valor da lista e aparece no linha %d\n", v[i], i+1); 
	}	
	return 0; 
}
/* 
QUESTÃO DA PROVA!!
Criar um array que esta preenchido, além de um vetor....
Vc deve somar cada linha do array, e armazenar a soma de cada linha dentro do vetor
Ao final do promgama deve-se retornar as linhas cujo a soma foi maior....*/ 