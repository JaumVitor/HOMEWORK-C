#include <stdio.h>
#define PROD 3
#define ARM 2

void lerEstoque(int est[ARM][PROD]){
	//est[0][0]=2121;
	int i,j;
	printf("Digite o estoque:\n");
	for(i=0; i<ARM; i++){//linha
		printf("ARMAZEM %d\n", i+1);
		for(j=0; j<PROD; j++){//coluna
			printf("Produto %d: ", j+1);
			scanf("%d", &est[i][j]);
		}
	}
	
}
void totalPorProduto(int est[ARM][PROD]){
	int i, j;
	int soma;
	printf("Quantidade total de produtos por tipo:\n");
	for (i=0; i<PROD; i++){//coluna
	    soma=0;
		for(j=0; j<ARM; j++)//linha 
		   soma = soma + est[j][i];
	    printf("Produto %d: %d\n", i+1, soma); 
	}
}

/*
int menu(){
   int opcao;	
   printf("MENU\n1-c\n2-d\n3-e\n4-f1\n5-f2\n0-Sair\n");
   printf("Digite uma opcao do menu: ");
   scanf("%d", &opcao);   
   return opcao;
}
*/

void menu(int *pOpcao){
	int opcao; //= *pOpcao;
    printf("MENU\n1-c\n2-d\n3-e\n4-f1\n5-f2\n0-Sair\n");
    printf("Digite uma opcao do menu: ");
    scanf("%d", &opcao); 	
	*pOpcao = opcao;
}

/*
void menu(int *pOpcao){
    printf("MENU\n1-c\n2-d\n3-e\n4-f1\n5-f2\n0-Sair\n");
    printf("Digite uma opcao do menu: "); 
	scanf("%d", pOpcao); //mesmo efeito que scanf("%d", &*pOpcao);
}

*/


int main(){
    int estoque[ARM][PROD];
	float custo[PROD];
	int opcao;
	lerEstoque(estoque);

	//lerCusto(custo);
	do{
		//opcao = menu();
		menu(&opcao);
		switch(opcao){
			case 1: 
			        break;
			case 2: 
			        break;
			case 3: totalPorProduto(estoque);
			        break;
			case 4: 
			        break;
			case 5: 
			        break;
			case 0: 
			        break;
			default: printf("Opcao invalida!\n");    
		}
	}while(opcao != 0);

	return 0;
}