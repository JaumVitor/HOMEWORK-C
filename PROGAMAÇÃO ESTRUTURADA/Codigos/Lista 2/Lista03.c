#include <stdio.h>
#include <locale.h> 

int main (){
	float valor_produto, vFinal;
	int pagamento, desconto=0, juros=0; 	//Default var zero
	setlocale (LC_ALL, "Portuguese"); 	
	
	printf ("\t     FAÇA SUA COMPRA NO MERCADO OLINE\n"); 
	printf ("-----------------------------------------------------------\n");
	
	printf ("\n1- (A VISTA) DINHEIRO OU CHEQUE");
	printf ("\n2- (A VISTA) CARTÃO DE CREDITO");
	printf ("\n3- EM DUAS VEZES, SEM JUROS");
	printf ("\n4- EM DUAS VEZES COM JUROS\n\n"); 
	
	printf (">> Qual metodo de pagamento ? ");
	scanf ("%d", &pagamento);
	
	if (pagamento >= 1 && pagamento <=4){ // Verificação para saber se o valor digitado esta correspondente
		
		printf (">> Informe o valor do produto R$"); 
		scanf ("%f", &valor_produto); 
 	
 		if( pagamento == 1){
 			vFinal = valor_produto * 0.90; 
 			desconto = 10;
	 	 }else if( pagamento == 2){
			vFinal = valor_produto * 0.85; 
	 		desconto = 15;
	 	 }else if ( pagamento == 3){
			vFinal = valor_produto;
	 	 }else if ( pagamento == 4){
			vFinal = valor_produto * 1.10; 
			juros = 10;		
	 	 }
		printf ("O valor que o cliente deve pagar é R$%.2f (DESCONTO DE %d%%) ", vFinal, desconto);
		 
		if ( juros != 0)		//So vai aparecer o valor do juros se houver
		 printf ("+ (JUROS DE %d%%)",juros);
	  
	}else{
		printf ("VALOR NÃO CORRESPODENTE AOS DECLARADOS!");  // Caso o usuário digitar valor diferente
	}
	
	printf ("\n-----------------------------------------------------------\n");
	
	return 0; 
}