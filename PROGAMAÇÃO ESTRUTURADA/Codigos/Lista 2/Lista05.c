#include <stdio.h> 
#include <locale.h> 

int main (){
	setlocale (LC_ALL, "Portuguese"); 
	
	int escolha, n1, n2; 
	
	printf ("1- Soma de 2 números\n");
	printf ("2- Diferença entre 2 números\n");
	printf ("3- Produto entre 2 números\n");
	printf ("4- Divisão entre 2 números (o denominador não pode ser zero)\n\n");
	
	printf ("Escolha uma opção do menu: "); 
	scanf ("%d", &escolha);
	
	if (escolha > 0 && escolha < 5){
		
		printf ("Digite os dois valores para iniciar a operação: "); 
		scanf ("%d%d", &n1,&n2);
		
		switch (escolha){
			case 1: 
				printf ("%d + %d = %d", n1, n2, n1+n2); 
				break ;
			case 2: 
				printf ("%d - %d = %d", n1, n2, n1-n2);
				break ; 
			case 3: 
				printf ("%d x %d =%d", n1, n2, n1*n2); 
				break ;
			case 4: 
				if (n2 == 0){
					printf ("Erro: O Denominador da divisão é igual a ZERO"); 	
					break ;
				}
				printf ("%d / %d = %.1f", n1, n2, (float)n1/n2);  //tratar problema
				break ;	
			//default:
			//	printf ("Sentença");		
		}
	}else
		printf ("Erro: Digite valores entre 1 e 4");
		
	printf ("\n");
	
return 0; 
}