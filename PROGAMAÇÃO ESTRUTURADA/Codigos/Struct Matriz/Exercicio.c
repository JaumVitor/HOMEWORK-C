#include <stdio.h>
#include <stdlib.h>
#define PRO 3
#define ARM 2

		typedef struct EtqEstoque{
			int produto[PRO];
			int custo[PRO]; 
		} estoque ; 
		
		void systemLinha(){
			printf ("\n");
	   	}
	   	void validarEsc (int *escFunc){
			//Do etc...   
  	    }
	    void menuPrincipal (int *esc){
			validarEsc(*esc); 
			//Volta a escolha do menu principal	, pros cases....lá eles chamam uma função adequada	   
	    }
			  		
//Armazem (vet) vai ser um tipo composto, cujo dentro de cada elemento temos, porduto(Vet) e custo;
//Porem, neste caso, custo não esta sendo usado, junto com o vetor armazem....
void lerEstoque (estoque armazem[]);
void lerCusto (estoque (*str_Custo));
void QuantArmazem (estoque armazem[]);
void QuantProduto (estoque armazem[]); 
void calcularCusto  (estoque armazem[], estoque vetCusto); //CALCULA O CUSTO ARM/PRO

int main(){
	estoque armazem[ARM]; //Vetor do tipo estoque 
	estoque gitVetorCusto; //Caso explicado em [Teste.Exe.c]   GURDA O CUSTO DOS PRODUTOS....FORMA COMPLEXA
	
	//criar um switch case, para esses casos
	int escolha;  
	menuPrincipal(&escolha);
	switch (escolha){
		case 1: break ;
		case 2: break ; 
		case 3: break ; 
		case 4: break ;  
	}
	lerEstoque (armazem); system("pause"); system("cls");
	lerCusto (&gitVetorCusto); system("pause"); system("cls");
	QuantArmazem(armazem); system("pause"); system("cls");
	QuantProduto(armazem);
	calcularCusto (armazem, gitVetorCusto);
	
	return 0;
}

void lerEstoque (estoque armazem[ARM]){
	int x, i;
	printf (">> LENDO QUANTIDADE DE VALORES p/ ARMAZEM\n\n"); 	
	for (x=0; x<ARM; x++){
		printf ("-=-=-=-=-ARMAZEM %d-=-=-=-=-=-\n", x+1);
		for (i=0; i<PRO; i++){
			printf ("PRODUTO %d: ", i+1);
			scanf ("%d", &armazem[x].produto[i]);
		}systemLinha();
	} 
}

void lerCusto (estoque (*strCusto)){
	int y; 
	for (y=0; y<PRO; y++){
		printf ("Digite o custo PRODUTO %d: ", y+1); 
		scanf ("%d", &(*strCusto).custo[y]); 
	}
}

void QuantArmazem (estoque armazem[]){
	int x, i;
	printf (">> IMPRIMINDO A QUANTIDADE PRO/ARMAZEM (unidade):\n\n");
	for (x=0; x<ARM; x++){
		printf ("-=-=-=-=-VERIFICANDO ARMAZEM %d-=-=-=-=-=-\n", x+1);
		for (i=0; i<PRO; i++){
			printf (">> QUANT.PRODUTO %d: %d\n", i+1,armazem[x].produto[i]);
		}
	}systemLinha();
} 

void QuantProduto (estoque armazem[]){
	int x, i, soma;
	printf (">> TOTAL DE PRODUTOS EM CADA ARMAZEM\n\n"); 
	for (x=0; x<ARM; x++){
		printf ("QUANT PROD no ARMAZEM %d: ", x+1);
		soma =0;
		for (i=0; i<PRO; i++){
			soma += armazem[x].produto[i];
		}printf ("%d\n",soma );
	}systemLinha();
}

void calcularCusto (estoque armazem[], estoque vetCusto){
	//Por armazem
	int fixo,var, soma; 
	printf (">> CALCULANDO CUSTO POR ARMAZEM: \n\n");
	for (fixo=0; fixo<ARM; fixo++){
		soma=0;
		for (var=0; var<PRO; var++){
			soma += (armazem[fixo].produto[var]) * vetCusto.custo[var]; 
		}printf ("ARMAZEM %d: %d\n", fixo + 1, soma); 
	}systemLinha(); 
	
	//por tipo de produto
	printf (">> CALCULANDO CUSTO POR PRODUTO: \n\n");
	for (fixo=0; fixo<PRO; fixo++){
		soma=0;
		for (var=0; var<ARM; var++){
			soma += (armazem[var].produto[fixo]) * vetCusto.custo[fixo]; 
		}printf ("PRODUTO %d: %d\n", fixo + 1, soma); 
	}systemLinha(); 
	
}

