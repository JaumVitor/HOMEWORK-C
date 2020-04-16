#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

typedef struct{
	char cpf[5], nome[10]; 
	int end, telefone; 
}cliente; 

void menuEsc (int *esc){
	printf ("1- Cadastrar usuário\n2- Verificar Cadastro\n"); 
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
	cliente *aux ; //Variavel que vai ser auxiliadora do vetor de endereços 
	aux = (cliente*) malloc (sizeof (cliente)); //Passando o endereço do espaço de memoria alocado 
	
	//Antes de cadastrar o usuário, é preciso saber se não existe ngn com o msm cpf ja cadastrado...
	printf ("Qual o CPF ? "); 
	scanf ("%s", aux->cpf); //Lendo o cpf e armazenando na minha variavel auxiliadora 
	retorno = verificar ( vetor_cliente, aux->cpf, *ctrl); 
	
	if (retorno != 0){ //Caso o retorno seja diferente de zero, então não existe valores repetidos
		
		/*Caso o cpf não seja encontrado, dentro da lista, essa parte eh execultada:
		E o endereço da variavel será passado para o vetor que esta armazendando os endereços; 
		Caso ele não entre nessa parte do progama, a variavel que leu o cpf, tera sido inutil, pois seu endereço não sera guardado  
		Mas, como entrou....O restante da variavel será preenchida e logo dps seu endereço sera passado como dado do vetor....
		Dessa forma podemos acessar os valores digitados agora, corretamente!*/ 
	
		printf ("Nome: "); 
		scanf ("%s", aux->nome); 
		printf ("Endereço: "); 
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
		printf ("Endereço: %d\n", vetor_cliente[i]->end); 
		printf ("Telefone: %d\n", vetor_cliente[i]->telefone);
	}
}

int main (){
	int ctrl = 0, esc;
	cliente *vetor_cliente[100]; //Vetor responsvel por armazenar endereços 
	
	do{
		menuEsc (&esc); 
		switch (esc){
			case 1: 
				cadastro ( vetor_cliente, &ctrl ); printf ("\n"); //Função que fará o cadastro do usuário
				break; 
			case 2: 
				listar ( vetor_cliente, ctrl ); printf ("\n");
				break; 
			case 0: 
				printf ("\tEncerrando progama! \n"); 
				break; 
			default: 
				printf ("\tEscolha não adequada! \n"); 
		}
	}while (esc != 0); //Quando for igual a zero, ira satisfazer a condição 

	return 0; 
}