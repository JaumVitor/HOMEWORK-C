#include <stdio.h>
#define PROD 3
#define ARM 2
typedef struct {
	int armazem[ARM];
	float custo;
}tProduto;

void lerEstoque(tProduto prod[PROD]){
    int i, j;
    for(i=0; i<PROD; i++){
		printf("PRODUTO %d\n", i+1);
		for(j=0; j<ARM; j++){
			printf("Digite a quantidade no ARMAZEM %d: ", j+1);
			scanf("%d", &prod[i].armazem[j]);
		}
	}
}

void lerCusto(tProduto prod[PROD]){
	int i;
	printf("\n");
	for(i=0; i<PROD; i++){
		printf("Digite o custo do PRODUTO %d: ", i+1);
		scanf("%f", &prod[i].custo);
	} 
}

void menuRelatorio(int *pOpcao){
	int opcao; //= *pOpcao;
    printf("\nMENU RELATORIO\n1-c\n2-d\n3-e\n4-f1\n5-f2\n0-Sair\n");
    printf("Digite uma opcao do menu: ");
    scanf("%d", &opcao); 	
	*pOpcao = opcao;
}

void totalPorProduto(tProduto prod[PROD]){
    int i, j;
	int soma;
	printf("Quantidade total de produtos por tipo:\n");
    for (i=0; i<PROD; i++){
		//soma = prod[i].armazem[0] + prod[i].armazem[1] + prod[i].armazem[2];
		soma = 0;
		for(j=0; j<ARM; j++){
			soma = soma + prod[i].armazem[j];
		}
		printf("Produto %d: %d\n", i+1, soma); 
	}
}

void relatorio(tProduto prod[PROD]){
	int opcao;
	do{	
		menuRelatorio(&opcao);
		switch(opcao){
			case 1: 
			        break;
			case 2: 
			        break;
			case 3: totalPorProduto(prod);
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
	
}

void menuPrincipal(int *pOpcao){
	int opcao;
    printf("\nMENU PRINCIPAL\n1-Cadastro\n2-Relatorio\n0-Sair\n");
    printf("Digite uma opcao do menu: ");
    scanf("%d", &opcao); 	
	*pOpcao = opcao;
	
}
int main(){
 	tProduto prod[PROD]; 
	int opcao;
	lerEstoque(prod);
	lerCusto(prod);
	
	do{
		menuPrincipal(&opcao);
		switch(opcao){
			case 1: //cadastro(prod);
			        break;
			case 2: relatorio(prod);
			        break;
			case 0: 
			        break;
			default: printf("Opcao invalida!\n");    
		}
	}while(opcao != 0);

	return 0;    	
}