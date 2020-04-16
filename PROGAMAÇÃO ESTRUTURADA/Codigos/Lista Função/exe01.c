#include <stdio.h>
 
float valorGanho(float venda, float custo, int quant){
	return (venda - custo)*quant; 
}

int main(){
	float venda, custo, resultado;
	int quant; 
	
	printf ("Venda da unidade R$ "); 
	scanf ("%f", &venda); 
	printf ("Custo da unidade R$ "); 
	scanf ("%f", &custo); 
	printf ("Quantidade de vendas: "); 
	scanf ("%d", &quant);
	
	resultado = valorGanho(venda, custo, quant);
	
	printf ("Ganho do comerciante: R$%.2f", resultado) ; 
	
	return 0; 
}