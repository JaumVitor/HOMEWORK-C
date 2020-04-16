#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

typedef struct{
	char cpf[5], nome[10]; 
	int end, telefone; 
}cliente; 

void menuEsc (int *esc){
	printf ("1- Cadastrar usu�rio\n2- Verificar Cadastro\n"); 
	printf ("\tEscolha: ");
	scanf ("%d", esc); 
	printf ("\n");
}

int verificar (cliente *vetor_cliente[], char cpf[], int ctrl){
	int i; 
	for (i=0; i<ctrl; i++){
		if (strcmp (vetor_cliente[i]->cpf, cpf) == 0){
			return 0; 
		}		
	}
	return 1; 
}

void cadastro ( cliente *vetor_cliente[], int *ctrl){
	int retorno; 
	cliente *aux ; //Variavel que vai ser auxiliadora do vetor de endere�os 
	aux = (cliente*) malloc (sizeof (cliente)); //Passando o endere�o do espa�o de memoria alocado 
	
	//Antes de cadastrar o usu�rio, � preciso saber se n�o existe ngn com o msm cpf ja cadastrado...
	printf ("Qual o CPF ? "); 
	scanf ("%s", aux->cpf); //Lendo o cpf e armazenando na minha variavel auxiliadora 
	retorno = verificar ( vetor_cliente, aux->cpf, *ctrl); 
	
	if (retorno != 0){ //Caso o retorno seja diferente de zero, ent�o n�o existe valores repetidos
		
		/*Caso o cpf n�o seja encontrado, dentro da lista, essa parte eh execultada:
		E o endere�o da variavel ser� passado para o vetor que esta armazendando os endere�os; 
		Caso ele n�o entre nessa parte do progama, a variavel que leu o cpf, tera sido inutil, pois seu endere�o n�o sera guardado  
		Mas, como entrou....O restante da variavel ser� preenchida e logo dps seu endere�o sera passado como dado do vetor....
		Dessa forma podemos acessar os valores digitados agora, corretamente!*/ 
	
		printf ("Nome: "); 
		scanf ("%s", aux->nome); 
		printf ("Endere�o: "); 
		scanf ("%d", &aux->end); 
		printf ("Telefone: ");
		scanf ("%d", &aux->telefone ); 	
	
		vetor_cliente[*ctrl] = aux; //Passando o local de apontamento do vetor do tipo ponteiro (Aponta para um tipo Clinete) 
		(*ctrl)++; 
	}else{
		printf ("CPF JA FOI REGISTRADO\n"); 
	}	
}

void listar ( cliente *vetor_cliente[], int ctrl ){
	int i; 
	for (i=0; i<ctrl; i++){
	   	printf ("\n=-=-=-=CLIENTE=-=-=-=- %d", i+1); 
		printf ("\nCPF: %s\n", vetor_cliente[i]->cpf); //Ou o valor do vetor poderia ser acessado -> (*vetor_cliente).cpf
		printf ("Nome: %s\n", vetor_cliente[i]->nome); 
		printf ("Endere�o: %d\n", vetor_cliente[i]->end); 
		printf ("Telefone: %d\n", vetor_cliente[i]->telefone);
	}
}

int main (){
	int ctrl = 0, esc;
	cliente *vetor_cliente[100]; //Vetor responsvel por armazenar endere�os 
	
	do{
		menuEsc (&esc); 
		switch (esc){
			case 1: 
				cadastro ( vetor_cliente, &ctrl ); printf ("\n"); //Fun��o que far� o cadastro do usu�rio
				break; 
			case 2: 
				listar ( vetor_cliente, ctrl ); printf ("\n");
				break; 
			case 0: 
				printf ("\tEncerrando progama! \n"); 
				break; 
			default: 
				printf ("\tEscolha n�o adequada! \n"); 
		}
	}while (esc != 0); //Quando for igual a zero, ira satisfazer a condi��o 

	return 0; 
}