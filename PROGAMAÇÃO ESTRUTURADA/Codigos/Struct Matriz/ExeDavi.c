#include <stdio.h>
	typedef struct{
		char nameFilme[20];
		int ano;
		float preco;
	}registro;
	
	void systemLinha(){
		printf ("\n");
	}

void lerFilmes(registro filme_Func[], int quant);
 
int main(){
	int QuantFilme; 
	printf ("Quatos filmes quer analizar: "); 
	scanf ("%d", &QuantFilme); 
	registro filme[QuantFilme]; systemLinha(); //vetor do tipo registro; 
	
	//Inicio do chamamento das funções: 
	int saida;  
	do{
		lerFilmes(filme, QuantFilme);
		printf ("Quer continuar analizando ? \n[1] Para proceguir\n[2] Para encerrar\nDigite opção: "); 
		scanf ("%d", &saida); 
		
		if (saida != 1 && saida != 2){
			printf ("\t<#> Erro, Valor incoerente!\n");
			do{
				printf ("Digite novamente: ");
				scanf ("%d", &saida);
			}while (saida != 1 && saida != 2);
		}
	}while (saida != 2);
	//Repare que os filmes são da mesma quantidade que o usuario pediu
	//Então....quando eu chamar novamente lerFilmes, ela vai continuar armazenando a mesma quantidade  
	
	return 0; 
}

void lerFilmes(registro filme_Func[], int quant){
	
	int i; for (i=0; i<quant; i++){
		printf ("-=-=-=- FILME %d -=-==-=-=\n", i+1); 
		printf ("Nome do filme: "); 
		scanf ("%s", filme_Func[i].nameFilme); 
		printf ("Ano de lançamento: ");
		scanf ("%d", &filme_Func[i].ano);
		printf ("Preço: "); 
		scanf ("%f", &filme_Func[i].preco);
	}systemLinha();	   
}