#include <stdio.h> 
#include <locale.h>
#include <stdlib.h> 

	typedef struct{
		int matricula; 
		char nome[20]; 
		int ano; 
		float salario; 
	}STR; //Criando um tipo para a variavel;
	
//Fun��es principais:
void DadosFunc (STR listaFunc[50], int *pos); //Op��o 1;
void ExibirDados (STR listaFunc[50], int pos, int *esc2); //Op��o 2; 
	//Fun��es dentro de ExibirDados: 
		//>   	
				
//Fun��es auxiliares: 
void menuPrincipal(int *esc); 	
void menu2 (int *esc2); 
void DefLinha();
void systemLinha(); 

int main (){
	setlocale (LC_ALL, "Portuguese"); 
	STR listaFunc[50]; //Lista para armazenar todos os funcion�rios  
	int escolha, escolha2; //Usada para menuPrincipal 
	int pos=0; 
	
	do{
		menuPrincipal(&escolha);
		switch (escolha){
			case 0: 
				printf ("FIM DE PORCESSAMENTO....VOLTE SEMPRE\n\n");
				break ;  
			case 1:
				DadosFunc (listaFunc, &pos); 
				system("pause"); system("cls"); 
				break ;
			case 2:
				ExibirDados (listaFunc, pos, &escolha2); 
	   	   	   	system("pause"); system("cls");
				break ; 		  
			case 3:
				//calcularMedia 
			case 4:
				//consultar 
			case 5: 	
				//listarTodosFunc		 
				
			default: 
				printf ("<$> Erro, op��o escolhida n�o esta adequada!\n\n"); 
				break ; 	 		  
		}
	}while (escolha != 0); 
	
	printf ("Valor de escolha 2: %d", escolha2 ); 
	return 0; 
}

//Fun��es principais: 
void DadosFunc (STR listaFunc[50], int *pos){
	printf ("     CADASTRANDO FUNCIONARIOS\n"); DefLinha();  
	listaFunc[*pos].matricula = *pos + 1;
	printf (">>INFORME OS DADOS DO FUNCION�RIO [%d]: \n", *pos + 1); 
	
	printf ("Nome: "); 
	scanf ("%s", listaFunc[*pos].nome);
	printf ("Ano: "); 
	scanf ("%d", &listaFunc[*pos].ano);
	printf ("Salario: ");   
	scanf ("%f", &listaFunc[*pos].salario); 
	(*pos)++ ; //Incrementando pos, a cada vez que a fun��o � chamada 
	systemLinha(); 
}

void ExibirDados (STR listaFunc[50], int pos, int *esc2){
	float inicio, fim; //Faixa salarial 

	do{	
		menu2 (&*esc2);
		switch (*esc2){
			case 1: 
				//gitMaiorSal(); 
				break ; 
			case 2: 
				//gitMenorSal();
				break ;  
			case 3: 
				//gitIgualSal();
				break ;  
			case 4: 
				printf (">>  ESCOLHA UMA FAIXA SAL�RIAL ABAIXO!\n"); 
				DefLinha(); 
				printf ("Inicio: ");
				scanf ("%f", &inicio);
				printf ("T�rminio: ");  
				scanf ("%f", &fim); 
				
				systemLinha(); 
				printf ("Sal�rios ---> CUJO EST�O ENTRE %.2f E %.2f \n", inicio, fim); 
				system("pause"); system("cls"); 
				//gitFaixaSal(); 
				break ;
			case 0: 
				printf ("\t<#> Retornando ao menu principal\n\n"); 
				break ; 	
			default: 
				printf ("\t<$> Erro, Digite um valor correspondente ao menu!\n");
				break ;  				
		}
	}while (*esc2 != 0); 
}

//Fun��es auxiliares: 
void menuPrincipal(int *esc){
	printf ("\tMENU PRINCIPAL\n"); 
	DefLinha(); 
	printf ("1. cadastrar funcion�rios\n"
			"2. exibir funcion�rios por salario\n"
			"3. calcular media salarial\n"
			"4. consultar\n"
			"5. listar todos\n"
			"0.Sair\n");
	DefLinha(); 
	printf ("Digite: "); 	 
	scanf ("%d", esc); 	
	system("cls"); 
}

void menu2 (int *esc2){
	printf (">>\tMENU PARA ESCOLHER SAL�RIO\n"); 
	DefLinha(); 
	printf ("1. Maior sal�rio\n"
			"2. Menor Sal�rio\n"
			"3. Sal�rio igual\n"
			"4. Escolher faixa de sal�rio\n"
			"0. Retornar ao MENU PRINCIPAL\n");
	DefLinha(); 		
	printf ("Digite: "); 		
	scanf("%d", esc2); 
	system("cls"); 	
}

void DefLinha(){
	printf ("--------------------------------------\n");    	
}

void systemLinha(){
	printf ("\n"); 
}
