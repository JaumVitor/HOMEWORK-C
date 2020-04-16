#include <stdio.h> 
#include <string.h>

//Duvida ? como passar uma string feita para dentro de um struct ?
int main(){
	
	struct escola{
		   char nome[20]; 
		   int vetor[5];
		   float notas ; 
		   int faltas; 	
		   //char letra; 
	}; 
	struct escola dados, abstratos ; //Dados e abstratos são do mesmo tipo. 
//            \> dados é uma variavel do tipo escola;
//                      \> abstratos é uma do tipo escola tmb; 
					
	strcpy(dados.nome, "Fulano");  //Para atribuir um valor para dentro de uma estrutura, usei a biblioteca string.h
	printf ("%s\n", dados.nome);		//Pois é necessário usar, para colocar uma string, sem usar o scanf
	
	int i;
	for (i=0; i<5; i++){
		printf ("Digite um valor: ");
		scanf ("%d", &dados.vetor[i]);
	}
	for (i=0; i<5; i++){
	   printf ("%d\n", dados.vetor[i]);	
	}
	
	/*
	//Passando valores de dados para abstratos. 
	abstratos.notas = 10;
	printf ("Dados abstratos: %f\n", abstratos.notas); 
	 
	scanf ("%s", dados.nome);
	dados.notas = 7.0; 
	dados.faltas = 20; 
	//dados.letra = 'a';
	
	//printf ("%c\n", dados.letra); 
	printf ("%s\n", dados.nome); 
	printf ("%f\n", dados.notas ); 
	printf ("%d\n", dados.faltas);
	*/ 
	return 0; 
}