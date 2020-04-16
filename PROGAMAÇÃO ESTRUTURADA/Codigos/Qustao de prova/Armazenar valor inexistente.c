#include <stdio.h> 

	typedef struct{
		int valor; 
	}tEstrutura; 
	
	void adicionar(tEstrutura lista[5]); 
	void verificar (tEstrutura lista[5], int *valor, int *resp); 
	
int main (){
	tEstrutura lista[5]; 
	
	adicionar(lista); 
	return 0; 
}

void adicionar (tEstrutura lista[5]){
	int i, valor, resp; 
	for (i=0; i<5; i++){
		do{
			//Este looping s� acaba a partir do momento em que n�o houver repeti��o!
			printf ("[%d] Digite o valor para adicionar: ", i+1); 
		   	scanf ("%d", &valor); 	
		   	//Cahamando a fun��o para verificar valor, e se resp = 1, ent�o o looping terminar�
		    verificar (lista,&valor, &resp); 
		}while (resp != 1); //Resposta � dada pela fun��o verificar
		printf ("\t<#> Valor adicionado com suss!\n"); 
		//Valor � adicionardo dentro da estrutura
		lista[i].valor = valor; 
	}
}

void verificar (tEstrutura lista[5], int *valor, int *resp){
	int i, repeat=0; 
	
	for (i=0; i<5; i++){
		if (lista[i].valor == *valor){
			//printf ("Valor ja existe dentro da lista!\n");
			printf ("\t<$> Nao foi possivel add valor!\n");  
			repeat++ ; 	
			*resp = 0; 
			break; // <--- Otimiza��o do codigo
			//Se houver um valor repetido dentro da lista, vai ser add um valor para repeat
		}
	}
	if (repeat == 0){
	   	//printf ("Este valor n�o existe na lista!\n");
		*resp = 1;     
	}	
}




