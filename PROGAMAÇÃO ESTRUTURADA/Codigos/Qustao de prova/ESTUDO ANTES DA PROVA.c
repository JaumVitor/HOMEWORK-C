#include <stdio.h>
#define max 3

typedef struct{
	int idade, provas; 
	char nome[10]; 
	float notas[10]; 
}DadosAluno; 

void preencherDados (DadosAluno vetor[], int i);
void pecorrerLista (DadosAluno vetor[]); 

int main (){
	DadosAluno vetor[max]; 
	int i;
	
	for (i=0; i<max; i++){
		printf ("ALUNO %d\n", i+1); 
		preencherDados (vetor, i); 
		printf ("\n"); 
	}
	pecorrerLista(vetor);
	
	return 0;
}

void preencherDados (DadosAluno vetor[], int i){	
	int n; 	
	printf ("Nome: "); 
	fgets (vetor[i].nome, 10, stdin); 
	fflush(stdin);
	printf ("Idade: ");    	
	scanf ("%d", &vetor[i].idade);
	fflush(stdin);
	printf ("Quantidade de provas: ");  
	scanf ("%d", &vetor[i].provas);
	fflush(stdin);
	
	if (vetor[i].provas > 0){
		for (n=0; n < vetor[i].provas; n++){
		   	printf ("\tNota %d: ", n+1); 
		   	scanf ("%f", &vetor[i].notas[n]);
			fflush(stdin);    
		}
	}else 
		printf ("Nenhuma prova pra registrar!\n"); 
}

void pecorrerLista (DadosAluno vetor[]){
	int i, n; 
	for (i=0; i<max; i++){	
		printf ("===================================\n"); 
		printf ("ALUNO %d\n", i+1); 
	   	printf ("Nome: %s", vetor[i].nome); 
		printf ("Idade: %d\n", vetor[i].idade);    	
		printf ("Quantidade de provas: %d\n", vetor[i].provas);  
		
		for (n=0; n < vetor[i].provas; n++){
			printf ("Nota: %f\n", vetor[i].notas[n]); 
		}
		printf ("\n"); 
	}
}