#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
	typedef struct {
		char marca[15]; 
		int ano; 
		char cor[10]; 
		float preco; 
		char placa[8]; 	  		
	}tcarro; 
	
void systemLinha(){
	printf ("\n"); 
}

void menuPrincipal (int *esc){
	printf ("\tMENU PRINCIPAL\n"); 
	printf ("-------------------------------------\n");
	printf ("1. CADASTRAR\n2. REMOVER\n3. LOCALIZAR\n4. LISTAR\n0. SAIR\n"); 	
	printf ("-------------------------------------\n");
	printf ("> Digite sua escolha: "); 
	scanf ("%d", esc); 
	systemLinha(); system("pause"); system("cls"); 
}


//Declaração de funções que serão usadas no menu principal: 
void cadastrar(tcarro listaDados[20], int *id); //Cadastra um unico veiculo por vez; 
	
int main(){
	tcarro listaDados[20]; //Lista do tipo referente a estrutura;
	
	int escolha, indice=0; 

	do{	
		menuPrincipal (&escolha); 
		switch (escolha){
			case 1: 
				cadastrar (listaDados, &indice);
				break; 
			case 2:
				//remover();  
				break ; 
			case 3:
				//Localizar(); 
				break ; 
			case 4:
				//listar();  
				break ; 
			case 0:
				printf ("ENCERRANDO....");  
				break ; 
			default: 
				printf ("Erro, valor não correspondente ao menu!"); 	
				break ; 		
		}
	}while (escolha != 0); 
	
	return 0; 
}

//Usando as funções que serão usadas no menu principal
void cadastrar (tcarro listaDados[20], int *id){
	int i, result, quantErro=0; 
	char aux[8]; 
	printf ("ARMAZENANDO PLACA [%d]: ", *id + 1);
	
	//primeira placa vai ser registrada sem nenhuma vereficação....
	if (*id == 0){ 	
		printf ("Placa: "); 
		scanf ("%s", listaDados[*id].placa); 
		systemLinha(); 
		(*id)++ ; 
	}else{ //Ele vai entrar aqui apartir da segunda placa que sera registrada
		printf ("Placa: "); 
		scanf ("%s", aux); //variavel auxiliadora, vai receber valor que esta sendo informado pelo usuário
		systemLinha(); 
		
		//Verificação da variavel: 
		for (i=0; i<(*id); i++){
			//Esta sendo passado para a função, os valores asmazenados e a variavel auxiliadora
			result = strcmp(listaDados[i].placa, aux); //Retorna zero, se os valores forem iguais
			if ( result == 0 ){
				//Se entrar aqui existe um valor que é iguail....Logo sai imediatamente e não registra nada
				//Posso fazer um (do While) ou retornar ao menu, e pedir pra ele cadastrar a placa novamente; 
				break ;
			}else{
				//Se não for igual, ele vai contar um erro e vai repassar o looping novamente
				quantErro++ ; 
				continue; 
			}
		}
		// Se a quantidade de erros, for igual ao *id, significa que não existe aquele valor dentro do vetor
		//Logo, ele vai adicionar o valor la dentro :) 
		if (quantErro == *id){ 
			strcpy (listaDados[*id].placa, aux); 
			(*id)++ ; 
		}
	}
		
	/*
	printf ("Marca: "); 
	scanf ("%s", listaDados[*indice].marca); 
	printf ("Ano: "); 
	scanf ("%d", &listaDados[*indice].ano);
	printf ("Cor: ");  
	scanf ("%s", listaDados[*indice].cor);
	printf ("Preço: ");  
	scanf ("%f", &listaDados[*indice].preco); 
	systemLinha (); 
	(*indice)++; 
	*/
}	