#include <stdio.h> 
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
 	char string[20]; 
}tString; 

void upper (char string[]); 
int alpha (char palavra[]); 
int validarPalavra (char palavra[], tString vetorString[]); 
int getMenorLetra (tString vetorString[], char *menorLetra, int *quant, int *id);
void ordemFinal (tString vetorSecundario[], tString vetorFinal[],  int *id, int *quantSec, int *quantFinal);
void ordemAlpha (tString vetorString[], tString vetorSecundario[], tString vetorFinal[], int *id, int *quant, int *quantSec, int *quantFinal);

int main (){
	setlocale (LC_ALL, "portuguese");   	
	tString vetorString[100]; //Vetor de strings Inicial 
	tString vetorSecundario[100]; //Vetor de strings Secundario 
	tString vetorFinal[100]; //Vetor organizado
	char palavra[20]; 
	int esc, retornoMain, quant=0, quantSec=0,quantFinal=0, id=0; 
	
	do{
		fflush (stdin);
		printf ("Type word: "); //Digitar a palavra para ir pro vetor
		fgets( palavra, 20, stdin);
		fflush (stdin);
		retornoMain = validarPalavra( palavra, vetorString ); //Verficar se a palavra digitada é uma string 
		
		if (retornoMain == 0){
			upper (palavra); 
			strcpy (vetorString[quant].string, palavra ); //Adiocionando a palavra dentro do vetor 
			++quant; 
		}else
			printf ("\t>>IT'S NOT A STRING\n");
			
		printf ("\nDo you still want continue ? "); //Pergunta se ainda quer continuar digitando 
		printf ("\n     1) SIM or 2) NÃO - ");  
		scanf ("%d", &esc);
		printf ("\n"); 
	}while (esc != 2); 
	
	ordemAlpha (vetorString, vetorSecundario, vetorFinal, &id, &quant, &quantSec, &quantFinal);
	
	system("pause");
	return 0;  
}

void upper (char string[]){
	//Pegando toda string que foi mandada pra função e tranformando todos os caracteres em maiusculas
	int i; 
	for (i=0; i<strlen(string); i++){
		string[i] = toupper (string[i]); 
	}
}

int alpha ( char palavra[] ){
	int i;
	for (i=0; i<strlen(palavra)-1; i++){
		//Negação da preposição....Morgan etc e tals
		if ( !(palavra[i] >= 'a' && palavra[i] <= 'z') && !(palavra[i] >= 'A' && palavra[i] <= 'Z')){
			return 1; 
		} 		
	}
	return 0; 	
}
 
int validarPalavra (char palavra[], tString vetorString[]){
	//Verificando se a string é uma palavra, caso tenha todos seus caracteres sendo uma letra, ira funcioanar
	int retorno; 
	retorno = alpha (palavra);
   	if (retorno == 0){
		return 0;  
   	}else
		return 1; 
}

int getMenorLetra (tString vetorString[], char *menorLetra, int *quant, int *id){
	int i;  
	for (i=0; i<*quant; i++){
		if (i==0) //Primeira vez, add a letra primogenita, da palavra
			*menorLetra = vetorString[i].string[*id];

		if (vetorString[i].string[*id] < *menorLetra)
			*menorLetra = vetorString[i].string[*id]; 
	}return 1;
}	

void ordemAlpha (tString vetorString[], tString vetorSecundario[], tString vetorFinal[], int *id, int *quant, int *quantSec, int *quantFinal) {
	char menorLetra; 
	int i; 
	getMenorLetra (vetorString, &menorLetra, quant, id ); 
	//Pecorrendo a lista, caso alguma palavra tenha a letra correspondente ao id, ele adiciona no vetorsec
	for (i=0; i<*quant; i++){ 
		if (vetorString[i].string[*id] == menorLetra){
			strcpy (vetorSecundario[*quantSec].string, vetorString[i].string);
			++(*quantSec);  
		}
	}
	 //Um dos casos eh se o vetorSec tiver apenas um valor armazenado, neste caso ele sai direto
	if (*quantSec == 1){
		strcpy (vetorFinal[*quantFinal].string, vetorSecundario[*quantSec-1].string); 
		++(*quantFinal);
		//O valor que esta sendo armazenado no vetor final, deve ser excluido do vetorPrimario	
	}else{
		//Entrando nesse caso, ira entrar numa recursão ate que a lista fique com apenas um elemento ou "XXX"
		++(*id); 
		ordemFinal (vetorSecundario,vetorFinal, id, quantSec, quantFinal);
	}	   	
}

void ordemFinal (tString vetorSecundario[], tString vetorFinal[],  int *id, int *quantSec, int *quantFinal){
	char menorLetra; 
	int i; 
	printf ("-> %d\n", *id ); 
	getMenorLetra (vetorSecundario, &menorLetra, quantSec, id);
	for (i=0; i<*quantSec; i++){ 
		//Fazendo a coleta, de valores armazenados no vetor, que contem a menor letra, baseada no id
		if (vetorSecundario[i].string[*id] != menorLetra){
			
		} 
	}
	
	if (*quantSec == 1){ //Se a quantidade for igual a 1, então add valor na lista final 
		strcpy (vetorFinal[*quantFinal].string, vetorSecundario[*quantSec-1].string);
		++(*quantFinal);
	}else{ 
		++(*id); 
	   	ordemFinal (vetorSecundario, vetorFinal, id, quantSec, quantFinal); 
	}
} 







