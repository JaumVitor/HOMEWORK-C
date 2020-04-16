#include <stdio.h>
#include <stdlib.h>
#define PRO 4
#define ARM 3

void systemLinha(void); //usado para saltar linha, durante a execução do progama. 
void imprimirProdutos(int arrayEstoque[ARM][PRO]); //Imprime os quantidade de produtos para cada armazem 
void somaProdutos(int arrayEstoque[ARM][PRO]);
void tabela(int arrayEstoque[ARM][PRO], int arrayTable[]);
void produtosQuant(int arrayPro[ARM][PRO]);
void custoTotal( int estoque[ARM][PRO], int table[PRO]);

int main(){
	int estoque[ARM][PRO] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}}; //Array para armazenar produtos/armazem
	int tableEstoque[PRO] = {1,2,3,4}; //Vetor para armazenar Quantidade de produtos
	
	tabela(estoque, tableEstoque); 
	imprimirProdutos(estoque); //Letra C
	somaProdutos(estoque); //Letra D
	produtosQuant(estoque); //Letra E
	custoTotal(estoque, tableEstoque); //Letra F
	
	return 0; 
}

void tabela(int arrayEstoque[ARM][PRO], int arrayTable[]){
	int v,k,i;
	
	printf ("XXXXXXXX !");
	for (v=0; v<PRO; v++){
		printf (" %d-PRO |",v+1); 
	}systemLinha(); 
	printf ("==========================================\n"); 
	
	for (i=0; i<ARM; i++){
		printf ("ARMAZEM %d!", i+1); 
		for (k=0; k<PRO; k++){
			printf ("%7.0d|", arrayEstoque[i][k]); 
		}
		printf ("\n------------------------------------------\n"); 
	}
	system("pause"); 
	systemLinha(); 
	
	for (i=0; i<PRO; i++){
		printf ("CUSTO UNITARIO (PRODUTO-%d): R$%d\n", i+1, arrayTable[i]); 
	}systemLinha(); system("pause");
	
}
void imprimirProdutos(int arrayEstoque[ARM][PRO]){
	system("cls");
	printf ("### (UNIDADE DE CADA TIPO DE PRODUTO \"C\") #### \n\n");
	
	int x, y; for (x=0; x<ARM; x++){
		printf ("=-=-=ARMAZEM [%d]=-=-=\n\n", x+1); 
		for (y=0; y<PRO; y++){
			   printf ("PRODUTO [%d] - QUNT. %d\n",y+1, arrayEstoque[x][y]);
  	  	}	
  	  	systemLinha();
	} 
	system("pause");
}

void somaProdutos(int arrayEstoque[ARM][PRO]){
	system("cls");
	printf ("### (QUANTIDADE DE CADA PRO. EM ARMAZEM \"D\") #### \n\n");
	int x,y;
	
	for (x=0; x<ARM; x++){
		int soma = 0;
		for (y=0; y<PRO; y++){
			soma += arrayEstoque[x][y] ;
		}
		printf ("ARMAZEM [%d] - PRO. %d\n",x+1, soma);
	}
	systemLinha();
	system("pause");
}

void produtosQuant(int arrayPro[ARM][PRO]){
	int fixo, vari, soma;
	
	system("cls");
	printf ("### (QUANTIDADE TOTAL DE PRO. \"E\") #### \n\n");
	for (fixo=0; fixo<PRO; fixo++ ){
		soma = 0;
		printf ("PRODUTO [%d] = ", fixo+1);
		for (vari=0; vari<ARM; vari++){
			soma += arrayPro[vari][fixo];
		}printf ("%d\n", soma); 
	}
	systemLinha();
	system("pause");
}

void custoTotal( int estoque[ARM][PRO], int table[PRO]){
	int fixo, vari, custo;
	
	system("cls");
	printf ("### (CUSTO TOTAL POR ARMAZEM \"F1\") #### \n\n");
	for (fixo=0; fixo<ARM; fixo++){
		custo=0;
		printf ("LUCRO DO ARMAZEM [%d] = ", fixo+1);
		for (vari=0; vari<PRO; vari++){
			custo += table[vari] * estoque[fixo][vari];
		}printf ("%d\n", custo);
	}systemLinha();
	
	printf ("### (CUSTO TOTAL POR ARMAZEM \"F2\") #### \n\n");
	for (fixo=0; fixo<PRO; fixo++){
		custo=0;
		printf ("LUCRO DO PRODUTO [%d] = ", fixo+1);
		for (vari=0; vari<ARM; vari++){
			custo += table[fixo] * estoque[vari][fixo];
		}printf ("%d\n", custo);
	}
	
	systemLinha();
	system("pause");
}

void systemLinha(void){
	printf ("\n");
}