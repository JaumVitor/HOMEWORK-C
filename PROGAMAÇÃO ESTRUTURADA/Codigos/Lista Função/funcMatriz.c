#include <stdio.h> 
#define ARM 3
#define PRO 3

int main(){
	float vetEmpresa[PRO][ARM] = {{12,34,1},{35,21,5},{43,52,42}}; 
	int quantEstoque[PRO] = {2,3,6}; 
	int i, k,v;
	float somaArmazem, custoTotal; 
	
	printf ("XXXXXXXX !");
	for (v=0; v<PRO; v++){
		printf (" %d-PRO |",v+1); 
	}printf ("\n"); 
	printf ("==================================\n"); 
	
	for (i=0; i<ARM; i++){
		printf ("ARMAZEM %d!", i+1); 
		for (k=0; k<PRO; k++){
			printf ("%7.0f|", vetEmpresa[i][k]); 
		}
		printf ("\n----------------------------------\n"); 
	}
	
	for (i=0; i<PRO; i++){
		printf ("CUSTO UNITARIO (PRODUTO-%d): R$%d\n", i+1, quantEstoque[i]); 
	}printf ("\n"); 
	
	//Segunda parte do progama, agora iremos pecorrer cada matriz encontrada. letra c
	printf ("letra C\n");  
	for (i=0; i<ARM; i++){
		printf ("ARMAZEM %d >\n", i+1); 
		for (k=0; k<PRO; k++){
			printf ("Produto %d, temos >>> %.0f \n",k+1, vetEmpresa[i][k]); 
		}
		printf ("\n"); 
	}
	//Letra D
	printf ("Letra D\n");
	for (i=0; i<ARM; i++){
		somaArmazem = 0; 
		for (k=0; k<PRO; k++){
			somaArmazem += vetEmpresa[i][k];
		}
		printf ("SOMA DOS PRODUTOS DO ARMAZEM %d > %.0f\n", i+1, somaArmazem); 
	}
	//letra E
	printf ("Letra E\n");
	for (i=0; i<ARM; i++){ 
		for (k=0; k<PRO; k++){
			printf ("%0.f\n", vetEmpresa[k][i]); 		
		}
	}
	//Letra F Soma por armazem
	for (i=0; i<ARM; i++){ 
		custoTotal = 0; 
		for (k=0; k<PRO; k++){
			custoTotal += quantEstoque[k] * vetEmpresa[i][k]; 		
		}
		printf ("ARMAZEM %d - R$%f\n", i+1, custoTotal);
	}printf ("\n");
	
	for (i=0; i<ARM; i++){ 
		custoTotal = 0; 
		for (k=0; k<PRO; k++){
			custoTotal += quantEstoque[i] * vetEmpresa[k][i]; 		
		}
		printf ("PRODUTO %d - R$%f\n", i+1, custoTotal);
	}
	
	return 0; 
}